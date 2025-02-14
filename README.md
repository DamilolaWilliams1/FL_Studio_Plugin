🎛️ FL Studio VST Plugin - Spring 2024<br>

📝 Project Overview<br>
This project is a custom VST plugin designed for FL Studio, developed as part of the Spring 2024 semester. The plugin suite includes an Equalizer, Synthesizer, and Timer, each built to enhance digital audio workflows with real-time processing capabilities.

🚀 Features<br>

🔹 Equalizer (equalizerv2)<br>
Multi-band frequency control for precise sound shaping.<br>
Self-balancing BSTs used to optimize frequency band calculations.<br>
Real-time audio processing with low latency.<br>

🎵 Synthesizer (synthesiser)<br>
Custom waveform generation for rich, dynamic sound synthesis.<br>
Circular buffers & FIFO queues for smooth playback and performance.<br>
Cross-platform support for seamless integration into different DAWs.<br>

⏳ Timer (timer)<br>
Real-time BPM synchronization for accurate timing control.<br>
Latency optimization for live performances and recordings.<br>
Multi-threaded processing to ensure smooth execution.<br>

🛠️ Technologies Used<br>
C++ & JUCE: Core development framework for VST plugin creation.<br>
FL Studio SDK: Ensures compatibility with FL Studio’s architecture.<br>
Audio DSP: Implements digital signal processing techniques for optimal sound performance.<br>

📂 Project Structure<br>

📦 FL_Studio_VSTplugin_Spring_2024<br>
 ┣ 📜 FL_Studio_VSTplugin_Spring_2024-equalizerv2  
 ┣ 📜 FL_Studio_VSTplugin_Spring_2024-synthesiser  
 ┣ 📜 FL_Studio_VSTplugin_Spring_2024-timer  
 ┣ 📜 FL_Studio_VSTplugin_Spring_2024-notes  
 ┗ 📜 README.md  
 
🔧 Installation & Usage<br>
Clone the repository: git clone https://github.com/DamilolaWilliams1/FL_Studio_VSTplugin_Spring_2024.git<br>
Build the project using JUCE or an IDE supporting VST development.<br>
Load the compiled plugin into FL Studio.<br>
Test and tweak using the FL Studio interface.
