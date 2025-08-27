# Solid Waste Sorting Using Computer Vision-Based Robotic Arm

## Project Overview
This project demonstrates an automated solid waste sorting system using a 5-DOF robotic arm integrated with computer vision. The system identifies recyclable waste using a YOLOv8 model and sorts it accordingly.

---

## Technologies Used
- **Python** (Jupyter Notebook for model development)
- **Arduino** (Robotic arm control)
- **YOLOv8** (Object detection)
- **OpenCV** (Image processing)
- **Servo Motors** (Arm movement)

---

## How It Works
1. The Yolo model detects waste objects (e.g., plastic, metal, paper).
2. Coordinates of the detected object are sent to the Arduino.
3. The robotic arm sorts the waste based on the detected class.
