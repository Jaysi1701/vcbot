# Team Syncc Voice Controlled Robotic Vehicle

## Introduction
TSyncc AIOT Serbot project.

## Role
This project details the design and implementation of a Voice-Controlled Robotic Vehicle managed remotely via voice commands. The system comprises two main blocks—transmitter and receiver—each powered by an ESP32 microcontroller and a battery. The transmitter block is equipped with a Bluetooth transmitter module interfaced through an encoder, alongside a voice-recognition module and push-button switches for command input. Voice or button-activated commands are encoded and transmitted via Bluetooth to the receiver, which decodes them to control the robot’s movement: forward, backward, left, or right.

## Hardware Pin Configuration
| Name        | Datatype | Pinout | Role                   |
|-------------|----------|--------|------------------------|
| ENA         | Int      | 23     | Right motor speed (PWM)|
| ENB         | Int      | 22     | Left motor speed (PWM) |
| IN1         | Int      | 16     | Right motor forward    |
| IN2         | Int      | 17     | Right motor backward   |
| IN3         | Int      | 18     | Left motor forward     |
| IN4         | Int      | 19     | Left motor backward    |
| motorSpeed  | Int      | -      | Speed (0-255)          |

## Tech Stack
- **Microcontroller**: ESP32
- **Communication**: Bluetooth
- **Voice Recognition**: Voice-recognition module
- **Motor Control**: PWM for motor speed control
- **Software**: Arduino IDE for programming

## Installation

### Prerequisites
- Install Arduino IDE for programming the ESP32 microcontrollers.
- Install necessary libraries for Bluetooth and voice recognition modules.

### Steps to Run the Project

1. **Clone the repository** to your local machine:
    ```bash
    git clone https://github.com/yourusername/TeamSynccVoiceControlledRoboticVehicle.git
    ```
2. **Navigate into the project folder**:
    ```bash
    cd TeamSynccVoiceControlledRoboticVehicle
    ```
3. **Open the Arduino IDE** and load the code for both the transmitter and receiver ESP32 microcontrollers.
4. **Upload the code** to the respective ESP32 microcontrollers.
5. **Assemble the hardware** according to the pin configuration table provided above.
6. **Power on the system** and ensure both the transmitter and receiver blocks are operational.
7. **Use voice commands** or button inputs on the transmitter block to control the robotic vehicle's movement.

