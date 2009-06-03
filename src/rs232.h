/*
 
Public platform independent Near Field Communication (NFC) library
Copyright (C) 2009, Roel Verdult
 
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
 
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
*/

#ifndef _LIBNFC_RS232_H_
#define _LIBNFC_RS232_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defines.h"
#include "types.h"

// Handle platform specific includes
#ifndef _WIN32
  #include <termios.h>
  #include <sys/ioctl.h>
  #include <unistd.h>
  #include <fcntl.h>
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <limits.h>
#else
  #include <windows.h>
#endif

// Define shortcut to types to make code more readable
typedef void* serial_port;
#define INVALID_SERIAL_PORT (void*)(~1)
#define CLAIMED_SERIAL_PORT (void*)(~2)

serial_port rs232_open(const char* pcPortName);
void rs232_close(const serial_port sp);
bool rs232_cts(const serial_port sp);
bool rs232_receive(const serial_port sp, byte* pbtRx, ui32* puiRxLen);
bool rs232_send(const serial_port sp, const byte* pbtTx, const ui32 uiTxLen);

#endif // _LIBNFC_RS232_H_

