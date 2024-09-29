#include <CST816S.h>

CST816S touch(21, 22, 5, 4);  // sda, scl, rst, irq
int doubleClickCount = 0;     // Counter for double clicks

void setup() {
  Serial.begin(115200);
  touch.begin();
  touch.enable_double_click(); // Enable double-click detection
}

void loop() {
  if (touch.available()) {
    if (touch.gesture() == "DOUBLE CLICK") {
      doubleClickCount++;
      Serial.print("Double Click Count: ");
      Serial.println(doubleClickCount);
    }
  }
}
