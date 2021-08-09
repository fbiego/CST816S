/*
   MIT License

  Copyright (c) 2021 Felix Biego

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <MpesaSTK.h>
//#include <Arduino_JSON.h>

//get your credentials from;
//https://developer.safaricom.co.ke/user/me/apps
//https://developer.safaricom.co.ke/test_credentials
String consumer_key = "__consumer_key__";
String consumer_secret = "__consumer_secret__";
String pass_key = "__pass_key__";

WiFiMulti wifiMulti;

//MpesaSTK mpesa(consumer_key, consumer_secret, pass_key);	//defaults to SANDBOX environment
MpesaSTK mpesa(consumer_key, consumer_secret, pass_key, SANDBOX);	//environment can be SANDBOX(default) or PRODUCTION


char * WIFI_SSID = "__ssid__";
char * WIFI_PASS = "__password__";


void setup() {
  Serial.begin(115200);
  wifiMulti.addAP(WIFI_SSID, WIFI_PASS);

  Serial.print("Waiting for WiFi to connect...");
  while ((wifiMulti.run() != WL_CONNECTED)) {
    Serial.print(".");
  }
  Serial.println(" connected");
  
  mpesa.begin(TEST_CODE, PAYBILL, "http://mycallbackurl.com/checkout.php");   //call this in setup after connected to the internet



  String result = mpesa.pay("2547XXXX__", 20, "Arduino", "Test");	//STK request
  //you can also implement this in the loop but remember each call performs an STK Request
  //Serial.println(result);
  //parseJson(result);

}

void loop() {
  //nothing here
}

/*
void parseJson(String json) {
  JSONVar myObject = JSON.parse(json);
  if (JSON.typeof(myObject) == "undefined") {
    Serial.println("Parsing input failed!");
  } else {
    JSONVar keys = myObject.keys();
    for (int i = 0; i < keys.length(); i++) {
      JSONVar value = myObject[keys[i]];
      Serial.print(keys[i]);
      Serial.print(" = ");
      Serial.println(value);
    }
  }
}
*/