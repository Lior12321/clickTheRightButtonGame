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

1. The game lights up one of several LEDs at random.
2. The user must press the corresponding button as quickly as possible.
3. If correct – the game gives feedback (e.g., score or sound).
4. If wrong or delayed – an error indication is shown.
5. The game may keep track of score, reaction time, or rounds.

---

## 🔧 Hardware Used

- 1× Arduino Uno (or compatible board)
- Multiple push buttons
- LEDs (x3 or more)
- Resistors (10kΩ for buttons, 220Ω for LEDs)
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

## ✅ Future Improvements

- Add a score display (using an LCD or 7-segment display)
- Implement multiple difficulty levels
- Add sound or vibration feedback
- Use interrupts for improved responsiveness

---