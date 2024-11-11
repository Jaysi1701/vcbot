# Team Syncc Voice Controlled Robotic Vehicle


## Introduction
Team Syncc AIOT Serbot project.


### Role 
This project details the design and implementation of a Voice-Controlled Robotic Vehicle managed remotely via voice commands. The system comprises two main blocks—transmitter and receiver—each powered by an ESP32 microcontroller and a battery. The transmitter block is equipped with a Bluetooth transmitter module interfaced through an encoder, alongside a voice-recognition module and push-button switches for command input. Voice or button-activated commands are encoded and transmitted via Bluetooth to the receiver, which decodes them to control the robot’s movement: forward, backward, left, or right.


Name	Datatype	Pinout	Role
ENA	Int	23	Right motor speed (PWM)
ENB	Int	22	Left motor speed (PWM)

IN1	Int	16	Right motor forward

IN2	Int	17	Right motor backward

IN3	Int	18	Left motor forward

IN4	Int	19	Left motor backward

motorSpeed Int	_ 	Speed (0-255)

