/*
HMI Nextion Library
Itead NX4827T043_011
http://imall.itead.cc/nextion-nx2432t043.html

Bentley Born
bentley@crcibernetica.com

Ricardo Mena C
ricardo@crcibernetica.com


http://crcibernetica.com

 License
 **********************************************************************************
 This program is free software; you can redistribute it 
 and/or modify it under the terms of the GNU General    
 Public License as published by the Free Software       
 Foundation; either version 3 of the License, or        
 (at your option) any later version.                    
                                                        
 This program is distributed in the hope that it will   
 be useful, but WITHOUT ANY WARRANTY; without even the  
 implied warranty of MERCHANTABILITY or FITNESS FOR A   
 PARTICULAR PURPOSE. See the GNU General Public        
 License for more details.                              
                                                        
 You should have received a copy of the GNU General    
 Public License along with this program.
 If not, see <http://www.gnu.org/licenses/>.
                                                        
 Licence can be viewed at                               
 http://www.gnu.org/licenses/gpl-3.0.txt

 Please maintain this license information along with authorship
 and copyright notices in any redistribution of this code
 **********************************************************************************
 */

#ifndef __NEXTION_H__
#define __NEXTION_H__

#include <Arduino.h>
#include <SoftwareSerial.h>

class Nextion{
 private:
  void flushSerial();
  SoftwareSerial *nextion;
 public:
  Nextion(){};//Empty contructor
  Nextion(SoftwareSerial &next, uint32_t baud);//Constructor

  void buttonToogleEvent(boolean &buttonState, String buttonId ,uint8_t picDefualtId, uint8_t picPressedId);

  uint8_t buttonOnOff(String find_component, String unknown_component, uint8_t pin, int btn_prev_state);

  boolean setComponentValue(String component, int value);

  boolean ack(void);

  const char* _ack(void);

  unsigned int getComponentValue(String component);

  boolean setComponentText(const char *component, const char *txt);


  String listenNextion(unsigned long timeOut);

  void sendCommand(const char* cmd);

  boolean nextionInit(const char* pageId);

};
#endif





