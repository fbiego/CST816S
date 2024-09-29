#include <CST816S.h>

CST816S touch(21, 22, 5, 4);  // sda, scl, rst, irq

void setup() {
  Serial.begin(115200);
  touch.begin();
  touch.enable_auto_standby(5000); // Set auto standby mode to 5000 milliseconds (5 seconds)
  Serial.println("Auto standby enabled for 5 seconds of inactivity.");
}

void loop() {
  // Check for touch events to reset inactivity timer
  if (touch.available()) {
    Serial.println("Touch detected, reset standby timer.");
  }
  // Standby mode will activate automatically based on inactivity
  delay(100); // Small delay to avoid excessive loop cycles
}
