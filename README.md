# Open-Source Digital Braille Display (Prototype)
Open-source ESP32-based Digital Braille Display prototype for real-time tactile text output using embedded systems. An embedded systems prototype demonstrating real-time conversion of digital text into tactile Braille output using affordable hardware.

**Project Overview**- This project showcases how an ESP32 microcontroller can control micro actuators to generate a dynamic 6-dot Braille cell. It is designed as a learning-focused open hardware initiative for developers exploring assistive technology.

**System Architecture**
Text Input → ESP32 Processing → Braille Mapping → Actuator Control → Tactile Output

**Features**

1. Real-time text-to-Braille conversion
2. Single-cell dynamic Braille display
3. Modular and scalable design
4. Open firmware (Arduino compatible)
5. Python serial testing tool

**Hardware Used**
1. ESP32
2. 6 Micro Linear Actuators
3. Motor Driver IC
4. Custom PCB
5. 3D Printed Enclosure

**How to Run**
1. Upload firmware to ESP32 using Arduino IDE
2. Install Python 3 and pyserial
3. Run send_text.py
4. Enter text
5. Observe Braille cell actuation

**Future Improvements**
1. Multi-cell scaling
2. I2C GPIO expansion
3. Wireless text streaming
4. Power optimization
