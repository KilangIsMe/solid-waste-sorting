#include <Servo.h>

Servo servos[6];
int servoPins[6] = {5, 6, 7, 9, 10, 11};
String inputString = "";
int angles[6];

void setup() {
  Serial.begin(9600);
      
  int home_angles[6] = {90, 135, 135, 90, 90, 25};
  int current_angles[6] = {90, 90, 150, 90, 90, 25};
  for (int i = 0; i < 6; i++) {
    servos[i].attach(servoPins[i]);
  }
  for (int step = 0; step <= 60; step++) { // 60 steps for smooth motion
    for (int i = 0; i < 6; i++) {
      int current_angle = current_angles[i];
      int target = home_angles[i];
      int intermediate = current_angle + (target - current_angle) * step / 60;
      servos[i].write(intermediate);
    }
    delay(20); // control speed of transition
  }
}

void loop() {
  if (Serial.available()) {
    inputString = Serial.readStringUntil('\n');

    int idx = 0;
    int lastPos = 0;
    inputString.trim();

    for (int i = 0; i < 6; i++) {
      int commaIndex = inputString.indexOf(',', lastPos);
      if (commaIndex == -1 && i < 5) break;

      String value = (i < 5) ? inputString.substring(lastPos, commaIndex)
                             : inputString.substring(lastPos);
      angles[i] = value.toInt();
      lastPos = commaIndex + 1;
    }

    for (int i = 0; i < 6; i++) {
      int current = servos[i].read();
      int target = angles[i];
      int step = (target > current) ? 1 : -1;
      
      for (int pos = current; pos != target; pos += step) {
        servos[i].write(pos);
        delay(20);  // Adjust this for speed: 5 = faster, 15 = slower
      }
    }
  }
}