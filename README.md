# Phineas & Ferb Inspired Rube Goldberg Machine 🤖🎢

This project was developed as part of **Perpetuum**, an engineering competition organized by the Faculty of Automatic Control and Computer Science at **National University of Science and Technology POLITEHNICA Bucharest**.

## 🛠️ Project Description

In the spirit of the animated world of **Phineas and Ferb**, this project aimed to build a **Rube Goldberg Machine** powered by an Arduino board. Our goal was to create a complex chain reaction mechanism that captures the secret agent combining electronics, mechanics, and creativity into a playful yet technically sound invention. 

## 🚀 How It Works

1. **Initialization**: The servos are set to default positions, and the sensors are primed.
2. **Start Detection**: The initial ultrasonic sensor waits for an object to be within a certain distance.
3. **Triggering Mechanism**: Once the object is detected, the first servo is activated.
4. **Chain Reaction**: The TT motor begins spinning for a short duration.
5. **Final Detection**: A second distance sensor detects when the object passes the final point.
6. **Trap Activation**: The second servo is triggered to close the mechanism.

This process simulates a real-time reaction chain, showcasing both logic control and mechanical synchronization.

## 🧠 Technologies & Components Used

- **Arduino Uno**
- **2x Servo motors**
- **1x TT DC motor + L298N driver**
- **2x Ultrasonic distance sensors (HC-SR04)**
- **Custom physical mechanism for chain reaction**
- **C++ (Arduino IDE)**
