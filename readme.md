# Teleop Software for Robot Locomotion using Keyboard Inputs

The program is a client server setup.

## Client
* The client is a robot with an arduino connected to a Jetson Nano.
* The Jetson Nano receives the pwm commands from server by TCP protocol.
* It transmits the PWM commands to the Arduino using serial communication

##  Server
* The server program is installed on an Ubuntu based laptop.
* The server picks up keyboard inputs using NCURSES library and updates PWM values.
* It sends the Updated pwm values via TCP Comm

### Dependencies
* NCURSES
* Boost ASIO and serialization 1.73

### Build Instructions:
* Edit CMAKE for Boost path.
* Edit IP address in TCP constructor of Client, to that of the respective server.  
