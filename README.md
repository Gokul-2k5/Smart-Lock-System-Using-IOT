# 🔐 Smart Lock System

## Overview
The **Smart Lock System** is an IoT-based solution designed to enhance home and office security by enabling remote access control through a mobile application. It replaces traditional keys with smart technology, offering convenience, real-time monitoring, and robust authentication.

### Features
- 📱 **Remote Access**: Lock and unlock doors from anywhere using the Blynk mobile app.
- 🔒 **User Authentication**: Supports PIN-based access with potential for biometric upgrades.
- 👀 **Buzzer Noise**: Beep sound when in unlock status.
- 🚨 **Instant Alerts**: Get notified immediately of unauthorized access attempts.
- 📊 **Access Logs**: Maintain detailed records of lock activity for security audits.

### Benefits
- Eliminates the risk of lost or duplicated physical keys.
- Enhances security with customizable access control.
- Offers a scalable solution for both residential and commercial use.

### Technologies Used
- **Hardware**: ESP8266 (NodeMCU), Solenoid Lock(12V), Relay Module(12V), Buzzer(5V), Power Supply
- **Software**: Arduino IDE, Blynk IoT App, WiFi & Blynk Libraries

### Getting Started
To build and deploy this system:
1. Assemble the hardware components as per the circuit diagram.
2. Flash the ESP8266 with the provided code using Arduino IDE.
3. Configure the Blynk app with your template ID and authentication token.
4. Connect the system to Wi-Fi and test lock/unlock functionality.

### Future Enhancements
- Biometric authentication (fingerprint, face recognition)
- Temporary access codes for guests
- Offline mode via Bluetooth
- Smart doorbell integration
- Auto-lock and emergency unlock features

### License

This project is open-source and available for educational and non-commercial use.
