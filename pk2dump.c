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

#include <stdio.h>
#include <stdlib.h>

#include "macros.h"
#include "pickit2dat.h"

static struct DeviceFileParams deviceFileParams;
static struct DeviceFamilyParams *deviceFamilyParams;
static struct DevicePartParams *devicePartParams;
static struct DeviceScripts *deviceScripts;

int readPK2DeviceFile(const char *filename)
{
	DECLARE_ERROR_VARS;
	int ret = 0;
	size_t num;
	FILE *fin;

	/* Open the file. */
	fin = fopen(filename, "r");
	TEST_FOR_ERROR(!fin, -1, error1, "error opening file");
	/* Read device file parameters. */
	ret = readDeviceFileParams(fin, &deviceFileParams);
	TEST_FOR_ERROR(!ret, -1, error2, "error reading device file parameters")
	/* Read device family parameters. */
	num = deviceFileParams.p2.NumberFamilies;
	deviceFamilyParams = calloc(num, sizeof deviceFamilyParams[0]);
	TEST_FOR_ERROR(!deviceFamilyParams, -1, error2, "error in calloc()");
	ret = readDeviceFamilyParams(fin, num, deviceFamilyParams);
	TEST_FOR_ERROR(!ret, -1, error3, "error reading device file parameters");
	/* Read device part parameters. */
	num = deviceFileParams.p2.NumberParts;
	devicePartParams = calloc(num, sizeof devicePartParams[0]);
	TEST_FOR_ERROR(!devicePartParams, -1, error3, "error in calloc()");
	ret = readDevicePartParams(fin, num, devicePartParams);
	TEST_FOR_ERROR(!ret, -1, error4, "error reading device part parameters");
	/* Read device script parameters. */
	num = deviceFileParams.p2.NumberScripts;
	deviceScripts = calloc(num, sizeof deviceScripts[0]);
	TEST_FOR_ERROR(!deviceScripts, -1, error4, "error in calloc()");
	ret = readDeviceScripts(fin, num, deviceScripts);
	TEST_FOR_ERROR(!ret, -1, error5, "error reading device script parameters");
	/* The end. */
	fclose(fin);
	ret = 1;
	return ret;

error5:
	free(deviceScripts);
error4:
	free(devicePartParams);
error3:
	free(deviceFamilyParams);
error2:
	fclose(fin);
error1:
	CHECK_FOR_ERROR;
	return ret;
}

int main(int argc, char *argv[])
{
	DECLARE_ERROR_VARS;
	const char *version = "1.0";
	const char *datFileName = "PK2DeviceFile.dat";
	FILE *fout = stdout;
	int n;

	n = readPK2DeviceFile(datFileName);
	TEST_FOR_ERROR(!n, -1, error1, "error reading dat file");
	/* Dump the contents to fout. */
	fprintf(fout,
		"pk2dump version %s\n"
		"Copyright (c) 2010 Marcelo Roberto Jimenez - All rights reserved\n\n"
		"File name: %s\n"
		"----------------------------------------------------------\n",
		version, datFileName);
	printDeviceFileParams(fout, &deviceFileParams);
	printDeviceFamilyParams(fout, deviceFileParams.p2.NumberFamilies,
		deviceFamilyParams);
	printDevicePartParams(fout, deviceFileParams.p2.NumberParts,
		devicePartParams);
	printDeviceScripts(fout, deviceFileParams.p2.NumberScripts,
		deviceScripts);
	/* Free all alloc'd memory. */
	free(deviceFamilyParams);
	free(devicePartParams);
	free(deviceScripts);

error1:
	CHECK_FOR_ERROR;
	return 0;
}

