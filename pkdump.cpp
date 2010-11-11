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

#include "pickit2dat.h"
#include "PK2Dat.h"

int main(void)
{
	const char *version = "1.0";
	const char *datFileName = "PK2DeviceFile.dat";
	FILE *fout = stdout;

	try {
		PK2Dat pk2dat(datFileName);

		/* Dump the contents to fout. */
		fprintf(fout,
			"pk2dump version %s\n"
			"Copyright (c) 2010 Marcelo Roberto Jimenez - All rights reserved\n\n"
			"File name: %s\n"
			"----------------------------------------------------------\n",
			version, datFileName);
		printDeviceFileParams(fout, &pk2dat.m_deviceFileParams);
		printDeviceFamilyParams(fout,
			pk2dat.m_deviceFamilyParams.size(),
			&pk2dat.m_deviceFamilyParams[0]);
		printDevicePartParams(fout,
			pk2dat.m_devicePartParams.size(),
			&pk2dat.m_devicePartParams[0]);
		printDeviceScripts(fout,
			pk2dat.m_deviceScripts.size(),
			&pk2dat.m_deviceScripts[0]);
	} catch(EPK2Dat &e) {
	}

	return 0;
}

