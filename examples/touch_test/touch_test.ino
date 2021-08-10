#include <CST816S.h>


CST816S touch(21, 22, 4, 5);

void setup(){
	Serial.begin(115200);
	
	touch.begin();
	
}


void loop(){
	
	if (touch.available()){
		
		
	}
	
	
}