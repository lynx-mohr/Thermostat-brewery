

void nexaControl(){

unsigned long sender = 27756734; //This is the code that the remote control for the outlet sends out. 
  unsigned int recipient = 0; //Don't know what this is. 
  bool command; //This variabel states if the remote sends the command on (true) or off (false)
  bool group = false; //Don't know what this is


if(tempValueChamber > lowTempLimit){
  command = true;


}

else if(tempValueChamber < highTempLimit){
  command = false;



//else{
//  command = false;

}
homeEasy.sendAdvancedProtocolMessage(sender, recipient, command, group); //control the nexa outlet

}