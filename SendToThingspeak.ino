
void sendDataThingSpeak(){ 


if(millis() > timeNowThingSpeak + timeInterval){

  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149"; // api.thingspeak.com
  cmd += "\",80";
  ser.println(cmd);
  if(ser.find("Error")){
    Serial.println(F("AT+CIPSTART error"));
    return;
  }
  // prepare GET string
  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr +="&field1=";
  getStr += String(tempValueBeer);
  getStr +="&field2=";
  getStr += String(tempValueChamber);
  getStr += "\r\n\r\n";

  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  ser.println(cmd);

  if(ser.find(">")){
    ser.print(getStr);



}

  timeNowThingSpeak = millis(); // updating timeNow after sending data to Thingspeak

}

  else{
    ser.println("AT+CIPCLOSE");
 //   Serial.println("CIPCLOSE");
  }
}