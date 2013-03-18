/*
 * HMC6352.h
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
 
#ifndef HMC6352_H
#define HMC6352_H

#ifdef RETURNDECIDEGREES //To get the heading in decidegrees; 31,5 degrees read => 315 decidegrees response
#define DIVIDOR 10
#else  //To get the heading in degrees; 31,5 degrees read => 31 degrees response
#define DIVIDOR 1
#endif



class HMC6352Class
{
  public:
    int GetHeading();
    void Wake();
    void Sleep();
  private:
  
};

#endif
