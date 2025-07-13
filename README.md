# 🎮 Click The Right Button – Arduino Project

An interactive Arduino-based reaction game where the player must press the correct button as quickly as possible in response to LED prompts.
This project was designed to explore real-time behavior, embedded programming in C++, hardware-software integration, and basic game mechanics using Arduino.

---

## 🧠 What This Project Demonstrates

- Real-time reaction logic using Arduino.
- Integration of digital components: LEDs, push buttons, resistors.
- C++ code for managing user input, delays, and I/O control.
- Hardware debugging and signal flow validation.
- Understanding of timing, feedback, and simple state machines in embedded systems.

---

## 🖼️ Final Breadboard Setup

![Final Breadboard](media/board_and_wires.jpg)

---

## 🎥 Demo Video

See the game in action:  
[📽️ Click to download demo (MP4)](https://github.com/Lior12321/clickTheRightButtonGame/raw/refs/heads/master/media/gameplay.mp4)

---

## 📂 Project Structure

```
clickTheRightBottonGame/
├── game.ino 				# Main Arduino sketch
├── media/
│ ├── board_and_wires.jpg 	# Breadboard image
│ └── gameplay.mp4 			# Demo video
└── README.md 				# Project documentation
```

---

## 🚀 How It Works

1. The game starts by prompting the player to select a difficulty level.
2. A countdown screen shows “3, 2, 1” before the game begins.
3. The player starts with 5 lives.
4. LEDs light up in sequence, and the player must press the correct corresponding button as quickly as possible.
5. If the player is too slow or presses the wrong button, they lose one life.
6. The game continues until all lives are lost, then it ends.

---

## 🔧 Hardware Used

- Arduino Uno (or compatible board)
- push buttons x3
- LEDs x3
- Resistors (10kΩ for buttons, 220Ω for LEDs)
- 7-segment display
- Breadboard + jumper wires

---

## 🧩 Learning Outcomes

- Embedded systems fundamentals
- Timing control in real-time environments
- Basic game logic design
- Digital input/output management in C++
- Hands-on troubleshooting and wiring

---

## 📌 Notes

> This project was created as part of a personal initiative to learn embedded systems through practical, hands-on work.  
> Developed by **Lior Masas**, 2025.

---