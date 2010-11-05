/*
 * Copyright (c) 2010 Marcelo Roberto Jimenez <mroberto@cpti.cetuc.puc-rio.br>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef PICKIT2DAT_H
#define PICKIT2DAT_H

#include "datfile.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

int readString(FILE *fin, int maxSize, int *size, char *buf);
int readDeviceFileParams(FILE *fin, struct DeviceFileParams *filePars);
int readDeviceFamilyParams(FILE *fin, size_t num, struct DeviceFamilyParams famPars[]);
int readDevicePartParams(FILE *fin, size_t num, struct DevicePartParams partPars[]);
int readDeviceScripts(FILE *fin, size_t num, struct DeviceScripts scripts[]);
void printDeviceFileParams(FILE *fout, struct DeviceFileParams *filePars);
void printDeviceFamilyParams(FILE *fout, size_t num, struct DeviceFamilyParams famPars[]);
void printDevicePartParams(FILE *fout, size_t num, struct DevicePartParams partPars[]);
void printDeviceScripts(FILE *fout, size_t num, struct DeviceScripts scripts[]);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PICKIT2DAT_H */

