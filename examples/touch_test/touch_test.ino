#include <CST816S.h>


CST816S touch(21, 22, 4, 5);

void setup(){
	Serial.begin(115200);
	
	touch.begin();
	
	    Serial.print(touch.data.version);
    Serial.print("\t");
    Serial.print(touch.data.versionInfo[0]);
    Serial.print("-");
    Serial.print(touch.data.versionInfo[1]);
    Serial.print("-");
    Serial.println(touch.data.versionInfo[2]);
	
}


void loop(){
	
	if (touch.available()){
	Serial.print(touch.data.gesture);
    Serial.print("\t");
    Serial.print(touch.data.points);
    Serial.print("\t");
    Serial.print(touch.data.event);
    Serial.print("\t");
    Serial.print(touch.data.x);
    Serial.print("\t");
    Serial.println(touch.data.y);
		
	}
	
	
}