/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//  MAY NEED TO REMOVE JUCE
struct LookAndFeel : juce::LookAndFeel_V4 {
    void drawRotarySlider(juce::Graphics&,
        int x, int y, int width, int height,
        float sliderPosProportional,
        float rotaryStartAngle,
        float rotaryEndAngle,
        juce::Slider&) override;
};

struct RotarySliderWithLabels : juce::Slider 
{
    RotarySliderWithLabels(juce::RangedAudioParameter& rap, const juce::String& unitSuffix) : 
        juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag,
                     juce::Slider::TextEntryBoxPosition::NoTextBox),
        param(&rap),
        suffix(unitSuffix)
    {
        setLookAndFeel(&lnf);
    }

    ~RotarySliderWithLabels() {
        setLookAndFeel(nullptr);
    }

    struct LabelPos {
        float pos;
        juce::String label;
    };

    juce::Array<LabelPos> labels;

    void paint(juce::Graphics& g) override;
    juce::Rectangle<int> getSliderBounds() const;
    int getTextHeight() const { return 14;  }
    juce::String getDisplayString() const;
private:
    LookAndFeel lnf;

    juce::RangedAudioParameter* param;
    juce::String suffix;
};

struct ResponseCurveComponent : juce::Component,
    juce::AudioProcessorParameter::Listener,
    juce::Timer
{
    ResponseCurveComponent(GarethsEQAudioProcessor&);
    ~ResponseCurveComponent();

    void parameterValueChanged(int parameterIndex, float newValue) override;

    void parameterGestureChanged(int parameterIndex, bool gestureIsStarting) override { }

    void timerCallback() override;
    
    void paint(juce::Graphics& g) override;
    void resized() override;
private:
    GarethsEQAudioProcessor& audioProcessor;
    juce::Atomic<bool> parametersChanged{ false };

    MonoChain monoChain;

    void updateChain();

    juce::Image background;

    juce::Rectangle<int> getRenderArea();

    juce::Rectangle<int> getAnalysisArea();
};

//==============================================================================
/**
*/
class GarethsEQAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    GarethsEQAudioProcessorEditor (GarethsEQAudioProcessor&);
    ~GarethsEQAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GarethsEQAudioProcessor& audioProcessor;


    RotarySliderWithLabels peakFreqSlider1,
        peakGainSlider1,
        peakQualitySlider1,
        peakFreqSlider2,
        peakGainSlider2,
        peakQualitySlider2,
        peakFreqSlider3,
        peakGainSlider3,
        peakQualitySlider3,
        lowCutFreqSlider,
        highCutFreqSlider,
        lowCutSlopeSlider,
        highCutSlopeSlider;

    ResponseCurveComponent responseCurveComponent;

    using APVTS = juce::AudioProcessorValueTreeState;
    using Attatchment = APVTS::SliderAttachment;

    Attatchment peakFreqSlider1Attatchment,
        peakGainSlider1Attatchment,
        peakQualitySlider1Attatchment,
        peakFreqSlider2Attatchment,
        peakGainSlider2Attatchment,
        peakQualitySlider2Attatchment,
        peakFreqSlider3Attatchment,
        peakGainSlider3Attatchment,
        peakQualitySlider3Attatchment,
        lowCutFreqSliderAttatchment,
        highCutFreqSliderAttatchment,
        lowCutSlopeSliderAttatchment,
        highCutSlopeSliderAttatchment;

    std::vector<juce::Component*> getComps();

    //LookAndFeel lnf;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GarethsEQAudioProcessorEditor)
};
