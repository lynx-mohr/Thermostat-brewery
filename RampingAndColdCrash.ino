/*This function checks if there is a lager being fermented, which means that it ferments at a lower temperature, below 15. And if so it starts to ramp the temperature over a week. This is done to get rid of diacetyl and to get a fully fermented beer. And a lager is fermented for longer because of the lower temperature so it needs more time after the peak of fermentation. If on the other hand there is an ale being fermented, that time period is shorter and there is also a shorter ramp period before sending it into cold crash, which means lowering the temp to near freezing to let the beer clarify by making the yeast settle at the bottom of the fermentation vessel.*/

void ramping(){

if(peakBeerTemp <= tempValueBeer){
peakBeerTemp = tempValueBeer;

  } else if(peakBeerTemp > tempValueBeer){
peakFerm = rtc.now(); 
}

int peakFermDay = peakFerm.unixtime() / 86400; 

if(preferredTemp < 15){

if(daysPassed == peakFermDay + 9){

preferredTemp = 16;
  
}
else if(daysPassed == peakFermDay + 10){
  
  preferredTemp = 17;
}
 
else if(daysPassed == peakFermDay + 11){

preferredTemp = 19;
}

else if(daysPassed == peakFermDay + 12){

  preferredTemp = 21;
}

else if(daysPassed == peakFermDay + 13){ 

  preferredTemp = 23;
}

else if(daysPassed == peakFermDay + 14){ 

  coldCrash();
}

 
}

else if(preferredTemp > 15){ 

  if(daysPassed == peakFermDay + 5){

    preferredTemp = 22;
  }

      
else if(daysPassed == peakFermDay + 6){ 

  preferredTemp = 24;
  }

  else if(daysPassed == peakFermDay + 7){

  coldCrash();
  }

 } 
  }  


/*This function starts the cold crash. Right now it just takes the temp down in one go but I aim to experiment with ramping down to get the yeast to go into hibernation gradually. There are benefits to this, it is believed.*/

void coldCrash(){ 

  preferredTemp = 2;
  EEPROM.write(5, preferredTemp);

}