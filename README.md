# Ultrasonic-Intruder-Alert
The Ultrasonic Intruder Alert System is a compact, solid-state security application built using the Arduino ecosystem. Designed to mimic high-security laser tripwires found in banks and museums, this system monitors a fixed zone and triggers an instant multi-sensory alarm if an unauthorized entry is detected.

<img width="1152" height="864" alt="1069ad14-9afe-42c2-b0fd-e606975e88e7" src="https://github.com/user-attachments/assets/eb76893b-e63c-4a78-8f8c-666d473131df" />
<img width="1599" height="1200" alt="fa35302d-58e1-40f5-b270-e8dcb5e9e1e9" src="https://github.com/user-attachments/assets/33f54940-c51e-4497-ade3-9175cd56cc73" />

## 📹 Project Demo


https://github.com/user-attachments/assets/67329315-b6d5-4a5c-8ee7-1b2af04c94a1



---

## 🛠️ Features
* **Real-time Object Detection:** Uses an ultrasonic sensor to calculate distances dynamically.
* **Dual-Alert System:** Visual warning via a blinking **Red LED** and an audible alarm via a **Buzzer**.
* **Live Status Display:** Shows the real-time distance and current security status (`SECURE` or `ALERT!!`) on a 16x2 I2C LCD screen.
* **Solid-State Design:** Completely stable setup with optimized code delays to prevent system crashes.

---

## 🔌 Components Used
* Arduino Uno (or compatible board)
* HC-SR04 Ultrasonic Sensor
* 16x2 I2C LCD Display
* Red LED
* 220Ω Resistor (for LED protection!)
* Piezo Buzzer
* Breadboard & Jumper Wires

---

## 🚀 How It Works
1. The system continually pings the surroundings using the Ultrasonic Sensor.
2. If the path is clear (distance > 15cm), the LCD displays **"Status: SECURE"**.
3. If an object or hand comes closer than **15cm**, the system immediately switches to **"Status: ALERT!!"**, blinking the Red LED and sounding the Buzzer synchronously.
