/*This function follows the temp in the beer and adjusts the temp in the chamber to push the beer temperature down if it gets too warm

The table illustrates how the low vs high temp limits shift based on beer temperature. The Preferred beer temp remains constant but the warmer the beer gets, the cooler the air surrounding the vessel must be. 
          Actual beer temp     Preferred beer temp     Low temp limit     High temp limit
 case 1:  19                   20                      20                 21
 case 2:  20                   20                      19                 20
 case 3:  21                   20                      18                 19
 case 4:  22                   20                      13                 14                 

*/

void autoTempAdjustment(byte preferredTemp){
//case 1
if(tempValueBeer < preferredTemp){

 lowTempLimit = preferredTemp;
 highTempLimit = preferredTemp + 1;
  
}
//case 2
if(tempValueBeer == preferredTemp){ 
   lowTempLimit = preferredTemp - 1;
   
 highTempLimit = preferredTemp - 0;
 
}

//case 3
if(tempValueBeer > preferredTemp + 1){

   lowTempLimit = (preferredTemp - 2);
 highTempLimit = (preferredTemp - 1);
 
}
 //case 4
if(tempValueBeer > preferredTemp + 2 && preferredTemp > 15){ 
  
  lowTempLimit = (preferredTemp - 7);
  highTempLimit = (preferredTemp - 6); 
}
}