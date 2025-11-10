

void connectingWifi(){

   unsigned char check_connection=0;
    unsigned char times_check=0;
    Serial.println(F("Connecting to Wifi"));
  while(check_connection==0)
  {

   Serial.print(F(".."));
   ser.print("AT+CWJAP=\"A41B4B_EXTEND\",\"d4f3cf1d174d8332dbd2655b95b92c23f738829ec0aa60f6f265ae3657e5a42a\"\r\n");
   // ser.print("AT+CWJAP=\"TN_wifi_A41B4B\",\"PFDL6X3GWW\"\r\n");
   ser.setTimeout(5000);
   if(ser.find("WIFI CONNECTED\r\n")==1 )
   {
   Serial.println(F("WIFI CONNECTED"));
tone(buzzer, 1000, 250);  
delay(500);


   break;
   }
  times_check++;
   if(times_check>3) 
   {
    times_check=0;
    Serial.println(F("Trying to Reconnect.."));
    }

  }
}
