/*
 * HMC6352.cpp
 * 
 * Copyright (c) 2009 Ruben Laguna <ruben.laguna at gmail.com>. All rights reserved.
 * 
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Wire.h>
#include "Arduino.h"
#include "HMC6352.h"


#define HMC6352SlaveAddress  0x21
#define HMC6352ReadCommand  'A'  	// A command is: "Get Data" command
#define HMC6352SleepCommand 'S' 	// S command is: "Sleep" command
#define HMC6352WakeCommand  'W' 		// W command is: "Wake" command


int HMC6352Class::GetHeading()
{
  int headingSum;

  Wire.beginTransmission(HMC6352SlaveAddress);
  Wire.write(HMC6352ReadCommand);		// The "Get Data" command
  Wire.endTransmission();
  delay(8); //6000 microseconds minimum 6 ms

  Wire.requestFrom(HMC6352SlaveAddress, 2);
  
  //"The heading output data will be the value in tenths of degrees
  //from zero to 3599 and provided in binary format over the two bytes."
  byte MSB = Wire.read();
  byte LSB = Wire.read();

  headingSum = (MSB << 8) + LSB; //(MSB / LSB sum)
  
  return (headingSum /DIVIDOR );
}


void HMC6352Class::Wake()
{
  Wire.beginTransmission(HMC6352SlaveAddress);
  Wire.write(HMC6352WakeCommand); //W wake up exit sleep mode
  Wire.endTransmission();
  
}


void HMC6352Class::Sleep()
{
  Wire.beginTransmission(HMC6352SlaveAddress);
  Wire.write(HMC6352SleepCommand); //S enter sleep mode
  Wire.endTransmission();
}

