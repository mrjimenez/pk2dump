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

#include <endian.h>
#include <stdio.h>
#include <stdlib.h>

#include "macros.h"
#include "pickit2dat.h"

static void endianConvDeviceFileParams1(struct DeviceFileParams1 *p)
{
	p->VersionMajor = le32toh(p->VersionMajor);
	p->VersionMinor = le32toh(p->VersionMinor);
	p->VersionDot = le32toh(p->VersionDot);
}

static void endianConvDeviceFileParams2(struct DeviceFileParams2 *p)
{
	p->NumberFamilies = le32toh(p->NumberFamilies);
	p->NumberParts = le32toh(p->NumberParts);
	p->NumberScripts = le32toh(p->NumberScripts);
	/*p->Compatibility = ;*/
	/*p->UNUSED1A = ;*/
	p->UNUSED1B = le16toh(p->UNUSED1B);
	p->UNUSED2 = le32toh(p->UNUSED2);
}

static void endianConvDeviceFamilyParams1(struct DeviceFamilyParams1 *p)
{
	p->FamilyID = le16toh(p->FamilyID);
	p->FamilyType = le16toh(p->FamilyType);
	p->SearchPriority = le16toh(p->SearchPriority);
}

static void endianConvDeviceFamilyParams2(struct DeviceFamilyParams2 *p)
{
	p->ProgEntryScript = le16toh(p->ProgEntryScript);
	p->ProgExitScript = le16toh(p->ProgExitScript);
	p->ReadDevIDScript = le16toh(p->ReadDevIDScript);
	p->DeviceIDMask = le32toh(p->DeviceIDMask);
	p->BlankValue = le32toh(p->BlankValue);
	/*p->BytesPerLocation = ;*/
	/*p->AddressIncrement = ;*/
	/*p->PartDetect = ;*/
	p->UNUSED1 = le32toh(p->UNUSED1);
	/*p->EEMemBytesPerWord = ;*/
	/*p->EEMemAddressIncrement = ;*/
	/*p->UserIDHexBytes = ;*/
	/*p->UserIDBytes = ;*/
	/*p->ProgMemHexBytes = ;*/
	/*p->EEMemHexBytes = ;*/
	/*p->ProgMemShift = ;*/
	p->TestMemoryStart = le32toh(p->TestMemoryStart);
	p->TestMemoryLength = le16toh(p->TestMemoryLength);
	p->Vpp = le32toh(p->Vpp);
}

static void endianConvDevicePartParams1(struct DevicePartParams1 *p)
{
	int i;

	p->Family = le16toh(p->Family);
	p->DeviceID = le32toh(p->DeviceID);
	p->ProgramMem = le32toh(p->ProgramMem);
	p->EEMem = le16toh(p->EEMem);
	p->EEAddr = le32toh(p->EEAddr);
	/*p->ConfigWords = ;*/
	p->ConfigAddr = le32toh(p->ConfigAddr);
	/*p->UserIDWords = ;*/
	p->UserIDAddr = le32toh(p->UserIDAddr);
	p->BandGapMask = le32toh(p->BandGapMask);
	for (i = 0; i < 8; ++i)
		p->ConfigMasks[i] = le16toh(p->ConfigMasks[i]);
	for (i = 0; i < 8; ++i)
		p->ConfigBlank[i] = le16toh(p->ConfigBlank[i]);
	p->CPMask = le16toh(p->CPMask);
	/*p->CPConfig = ;*/
	/*p->OSCCALSave = ;*/
	p->IgnoreAddress = le32toh(p->IgnoreAddress);
	p->VddMin = le32toh(p->VddMin);
	p->VddMax = le32toh(p->VddMax);
	p->VddErase = le32toh(p->VddErase);
	/*p->CalibrationWords = ;*/
	p->ChipEraseScript = le16toh(p->ChipEraseScript);
	p->ProgMemAddrSetScript = le16toh(p->ProgMemAddrSetScript);
	/*p->ProgMemAddrBytes = ;*/
	p->ProgMemRdScript = le16toh(p->ProgMemRdScript);
	p->ProgMemRdWords = le16toh(p->ProgMemRdWords);
	p->EERdPrepScript = le16toh(p->EERdPrepScript);
	p->EERdScript = le16toh(p->EERdScript);
	p->EERdLocations = le16toh(p->EERdLocations);
	p->UserIDRdPrepScript = le16toh(p->UserIDRdPrepScript);
	p->UserIDRdScript = le16toh(p->UserIDRdScript);
	p->ConfigRdPrepScript = le16toh(p->ConfigRdPrepScript);
	p->ConfigRdScript = le16toh(p->ConfigRdScript);
	p->ProgMemWrPrepScript = le16toh(p->ProgMemWrPrepScript);
	p->ProgMemWrScript = le16toh(p->ProgMemWrScript);
	p->ProgMemWrWords = le16toh(p->ProgMemWrWords);
	/*p->ProgMemPanelBufs = ;*/
	p->ProgMemPanelOffset = le32toh(p->ProgMemPanelOffset);
	p->EEWrPrepScript = le16toh(p->EEWrPrepScript);
	p->EEWrScript = le16toh(p->EEWrScript);
	p->EEWrLocations = le16toh(p->EEWrLocations);
	p->UserIDWrPrepScript = le16toh(p->UserIDWrPrepScript);
	p->UserIDWrScript = le16toh(p->UserIDWrScript);
	p->ConfigWrPrepScript = le16toh(p->ConfigWrPrepScript);
	p->ConfigWrScript = le16toh(p->ConfigWrScript);
	p->OSCCALRdScript = le16toh(p->OSCCALRdScript);
	p->OSCCALWrScript = le16toh(p->OSCCALWrScript);
	p->DPMask = le16toh(p->DPMask);
	/*p->WriteCfgOnErase = ;*/
	/*p->BlankCheckSkipUsrIDs = ;*/
	p->IgnoreBytes = le16toh(p->IgnoreBytes);
	p->ChipErasePrepScript = le16toh(p->ChipErasePrepScript);
	p->UNUSED3 = le32toh(p->UNUSED3);
	p->UNUSED4 = le32toh(p->UNUSED4);
	p->ProgMemEraseScript = le16toh(p->ProgMemEraseScript);
	p->EEMemEraseScript = le16toh(p->EEMemEraseScript);
	p->ConfigMemEraseScript = le16toh(p->ConfigMemEraseScript);
	p->reserved1EraseScript = le16toh(p->reserved1EraseScript);
	p->reserved2EraseScript = le16toh(p->reserved2EraseScript);
	p->TestMemoryRdScript = le16toh(p->TestMemoryRdScript);
	p->TestMemoryRdWords = le16toh(p->TestMemoryRdWords);
	p->EERowEraseScript = le16toh(p->EERowEraseScript);
	p->EERowEraseWords = le16toh(p->EERowEraseWords);
	/*p->ExportToMPLAB = ;*/
	p->DebugHaltScript = le16toh(p->DebugHaltScript);
	p->DebugRunScript = le16toh(p->DebugRunScript);
	p->DebugStatusScript = le16toh(p->DebugStatusScript);
	p->DebugReadExecVerScript = le16toh(p->DebugReadExecVerScript);
	p->DebugSingleStepScript = le16toh(p->DebugSingleStepScript);
	p->DebugBulkWrDataScript = le16toh(p->DebugBulkWrDataScript);
	p->DebugBulkRdDataScript = le16toh(p->DebugBulkRdDataScript);
	p->DebugWriteVectorScript = le16toh(p->DebugWriteVectorScript);
	p->DebugReadVectorScript = le16toh(p->DebugReadVectorScript);
	p->DebugRowEraseScript = le16toh(p->DebugRowEraseScript);
	p->DebugReserved4Script = le16toh(p->DebugReserved4Script);
	p->DebugReserved5Script = le16toh(p->DebugReserved5Script);
	p->DebugReserved6Script = le16toh(p->DebugReserved6Script);
	p->DebugReserved7Script = le16toh(p->DebugReserved7Script);
	p->DebugReserved8Script = le16toh(p->DebugReserved8Script);
	p->DebugReserved9Script = le16toh(p->DebugReserved9Script);
}

static void endianConvDeviceScripts1(struct DeviceScripts1 *p)
{
	p->ScriptNumber = le16toh(p->ScriptNumber);
}

static void endianConvDeviceScripts2(struct DeviceScripts2 *p)
{
	p->ScriptVersion = le16toh(p->ScriptVersion);
	p->UNUSED1 = le32toh(p->UNUSED1);
	p->ScriptLength = le16toh(p->ScriptLength);
}

static void endianConvScript(int n, ushort s[])
{
	int i;

	for (i = 0; i < n; ++i) {
		s[i] = le16toh(s[i]);
	}
}

size_t readString(FILE *fin, size_t maxSize, size_t *size, char *buf)
{
	DECLARE_ERROR_VARS;
	size_t n = 0;
	size_t ret = 0;
	size_t i;
	size_t j;

	*size = 0;
	n = fread(&j, 1, 1, fin);
	TEST_FOR_ERROR(!n, -1, error1, "error reading first byte of size of string");
	j &= 0xff;
	if (j > 127) {
		n = fread(&i, 1, 1, fin);
		TEST_FOR_ERROR(!n, -1, error1, "error reading second byte of size of string");
		i &= 0xff;
		--i;
		j += i * 128;
	}
	TEST_FOR_ERROR(j > maxSize, j, error1, "string size in file is bigger than maximum");
	if (j > 0) {
		n = fread(buf, j, 1, fin);
		TEST_FOR_ERROR(!n, -1, error1, "error reading string bytes");
	}
	buf[j] = 0;
	*size = j;
	ret = 1;

error1:
	CHECK_FOR_ERROR;
	return ret;
}

size_t readDeviceFileParams(FILE *fin, struct DeviceFileParams *filePars)
{
	DECLARE_ERROR_VARS;
	size_t ret = 0;
	size_t n;

	n = fread(&filePars->p1, sizeof filePars->p1, 1, fin);
	TEST_FOR_ERROR(!n, -1, error1, "error reading deviceFileParams.p1");
	endianConvDeviceFileParams1(&filePars->p1);
	n = readString(fin, MAX_VERSION_NOTES_SIZE,
		&filePars->VersionNotesSize,
		filePars->VersionNotes);
	TEST_FOR_ERROR(!n, -1, error1,
		"error reading deviceFileParams.VersionNotes");
	n = fread(&filePars->p2, sizeof filePars->p2, 1, fin);
	TEST_FOR_ERROR(!n, -1, error1, "error reading deviceFileParams.p2");
	endianConvDeviceFileParams2(&filePars->p2);

	ret = 1;
	return ret;

error1:
	CHECK_FOR_ERROR;
	return ret;
}

size_t readDeviceFamilyParams(FILE *fin, size_t num, struct DeviceFamilyParams famPars[])
{
	DECLARE_ERROR_VARS;
	size_t ret = 0;
	size_t i;
	size_t n;

	for (i = 0; i < num; ++i) {
		n = fread(&famPars[i].p1,
			sizeof famPars[i].p1, 1, fin);
		TEST_FOR_ERROR(!n, i, error1,
			"error reading deviceFamilyParams[i].p1");
		endianConvDeviceFamilyParams1(&famPars[i].p1);
		n = readString(fin, MAX_FAMILY_NAME_SIZE,
			&famPars[i].FamilyNameSize,
			famPars[i].FamilyName);
		TEST_FOR_ERROR(!n, i, error1,
			"error reading deviceFamilyParams[i].FamilyName");
		n = fread(&famPars[i].p2,
			sizeof famPars[i].p2, 1, fin);
		TEST_FOR_ERROR(!n, i, error1,
			"error reading deviceFamilyParams[i].p2");
		endianConvDeviceFamilyParams2(&famPars[i].p2);
	}

	ret = 1;
	return ret;

error1:
	CHECK_FOR_ERROR;
	return ret;
}

size_t readDevicePartParams(FILE *fin, size_t num, struct DevicePartParams partPars[])
{
	DECLARE_ERROR_VARS;
	size_t ret = 0;
	size_t i;
	size_t n;

	for (i = 0; i < num; ++i) {
		n = readString(fin, MAX_PART_NAME_SIZE,
			&partPars[i].PartNameSize,
			partPars[i].PartName);
		TEST_FOR_ERROR(!n, i, error1,
			"error reading devicePartParams[i].PartName");
		n = fread(&partPars[i].p1,
			sizeof partPars[i].p1, 1, fin);
		TEST_FOR_ERROR(!n, i, error1,
			"error reading devicePartParams[i].p1");
		endianConvDevicePartParams1(&partPars[i].p1);
	}

	ret = 1;
	return ret;

error1:
	CHECK_FOR_ERROR;
	return ret;
}

size_t readDeviceScripts(FILE *fin, size_t num, struct DeviceScripts scripts[])
{
	DECLARE_ERROR_VARS;
	size_t ret = 0;
	size_t i;
	size_t n;

	for (i = 0; i < num; ++i) {
		n = fread(&scripts[i].p1,
			sizeof scripts[i].p1, 1, fin);
		TEST_FOR_ERROR(!n, i, error1,
			"error reading deviceScripts[i].p1");
		endianConvDeviceScripts1(&scripts[i].p1);
		n = readString(fin, MAX_SCRIPT_NAME_SIZE,
			&scripts[i].ScriptNameSize,
			scripts[i].ScriptName);
		TEST_FOR_ERROR(!n, i, error1,
			"error reading deviceScripts[i].ScriptName");
		n = fread(&scripts[i].p2,
			sizeof scripts[i].p2, 1, fin);
		TEST_FOR_ERROR(!n, i, error1,
			"error reading deviceScripts[i].p2");
		endianConvDeviceScripts2(&scripts[i].p2);
		/* Read the script. */
		TEST_FOR_ERROR(scripts[i].p2.ScriptLength > MAX_SCRIPT_SIZE,
			scripts[i].p2.ScriptLength,
			error1, "size of script is too big");
		n = fread(&scripts[i].Script,
			sizeof scripts[i].Script[0],
			scripts[i].p2.ScriptLength, fin);
		endianConvScript(scripts[i].p2.ScriptLength, scripts[i].Script);
		TEST_FOR_ERROR(n != scripts[i].p2.ScriptLength, i,
			error1, "error reading deviceScripts[i].Script");
		/* Read the comment. */
		n = readString(fin, MAX_COMMENT_SIZE,
			&scripts[i].CommentSize,
			scripts[i].Comment);
		TEST_FOR_ERROR(!n, i, error1,
			"error reading deviceScripts[i].Comment");
	}

	ret = 1;
	return ret;

error1:
	CHECK_FOR_ERROR;
	return ret;
}

void printDeviceFileParams(FILE *fout, struct DeviceFileParams *filePars)
{
	fprintf(fout,
		"Version Major = %d\n"
		"Version Minor = %d\n"
		"Version Dot   = %d\n"
		"Number of Families = %d\n"
		"Number of Parts    = %d\n"
		"Number of Scripts  = %d\n"
		"Compatibility      = 0x%02X\n"
		"Verson Notes Size  = %zd\n"
		"Version Notes:\n%s\n"
		,
		filePars->p1.VersionMajor,
		filePars->p1.VersionMinor,
		filePars->p1.VersionDot,
		filePars->p2.NumberFamilies,
		filePars->p2.NumberParts,
		filePars->p2.NumberScripts,
		filePars->p2.Compatibility,
		filePars->VersionNotesSize,
		filePars->VersionNotes
	);
}

void printDeviceFamilyParams(FILE *fout, size_t num, struct DeviceFamilyParams famPars[])
{
	size_t i;

	fprintf(fout,
		"Families listing (%zd members):\n"
		"----------------------------------------------------------\n",
		num);
	for (i = 0; i < num; ++i) {
		fprintf(fout,
			"Family ID   = %u\n"
			"Family type = %u\n"
			"Search priority = %u\n"
			"Family name size = %zd\n"
			"Family name = %s\n"
			"Program entry script  = %u\n"
			"Program exit script   = %u\n"
			"Read device ID script = %u\n"
			"Device ID mask = 0x%08x\n"
			"Blank value    = 0x%08x\n"
			"Bytes per location = %u\n"
			"Address increment  = %u\n"
			"Part detect = %u\n"
			"EE bytes per word = %u\n"
			"EE address increment = %u\n"
			"User ID hex bytes = %u\n"
			"User ID bytes = %u\n"
			"Program hex bytes = %u\n"
			"EE hex bytes = %u\n"
			"Program mem shift = %u\n"
			"Test memory start = 0x%08x\n"
			"Test memory length = %u\n"
			"Vpp = %.2f\n"
			"----------------------------------------------------------\n"
			,
			famPars[i].p1.FamilyID,
			famPars[i].p1.FamilyType,
			famPars[i].p1.SearchPriority,
			famPars[i].FamilyNameSize,
			famPars[i].FamilyName,
			famPars[i].p2.ProgEntryScript,
			famPars[i].p2.ProgExitScript,
			famPars[i].p2.ReadDevIDScript,
			famPars[i].p2.DeviceIDMask,
			famPars[i].p2.BlankValue,
			famPars[i].p2.BytesPerLocation,
			famPars[i].p2.AddressIncrement,
			famPars[i].p2.PartDetect,
			famPars[i].p2.EEMemBytesPerWord,
			famPars[i].p2.EEMemAddressIncrement,
			famPars[i].p2.UserIDHexBytes,
			famPars[i].p2.UserIDBytes,
			famPars[i].p2.ProgMemHexBytes,
			famPars[i].p2.EEMemHexBytes,
			famPars[i].p2.ProgMemShift,
			famPars[i].p2.TestMemoryStart,
			famPars[i].p2.TestMemoryLength,
			famPars[i].p2.Vpp
		);
	}
}

void printDevicePartParams(FILE *fout, size_t num, struct DevicePartParams partPars[])
{
	size_t i;
	size_t j;

	fprintf(fout,
		"Parts listing (%zd members):\n"
		"----------------------------------------------------------\n",
		num);
	for (i = 0; i < num; ++i) {
		fprintf(fout,
			"Part name size = %zd\n"
			"Part name = %s\n"
			"Family = %u\n"
			"Device ID = 0x%08x\n"
			"Program memory = %u\n"
			"EE memory = %u\n"
			"EE address = 0x%04x\n"
			"Config words = %u\n"
			"Config address = 0x%04x\n"
			"User ID words = %u\n"
			"User ID address = %u\n"
			"Bandgap mask = 0x%04x\n"
			"Config masks ="
			,
			partPars[i].PartNameSize,
			partPars[i].PartName,
			partPars[i].p1.Family,
			partPars[i].p1.DeviceID,
			partPars[i].p1.ProgramMem,
			partPars[i].p1.EEMem,
			partPars[i].p1.EEAddr,
			partPars[i].p1.ConfigWords,
			partPars[i].p1.ConfigAddr,
			partPars[i].p1.UserIDWords,
			partPars[i].p1.UserIDAddr,
			partPars[i].p1.BandGapMask
		);
		for (j = 0; j < 8; ++j)
			fprintf(fout, " 0x%04x",
				partPars[i].p1.ConfigMasks[j]);
		fprintf(fout, "\nConfig blank = ");
		for (j = 0; j < 8; ++j)
			fprintf(fout, " 0x%04x",
				partPars[i].p1.ConfigBlank[j]);
		fprintf(fout,
			"\n"
			"CP mask = 0x%04x\n"
			"CP config = %u\n"
			"OSCCAL save = %u\n"
			"Ignore address = 0x%04x\n"
			"VddMin = %.2f\n"
			"VddMax = %.2f\n"
			"VddErase = %.2f\n"
			"Calibration words = %u\n"
			"Chip erase script = %u\n"
			"Program mem address set script = %u\n"
			"Program mem address bytes = %u\n"
			"Program mem read script = %u\n"
			"Program mem read words = %u\n"
			"EE read prep script = %u\n"
			"EE read script = %u\n"
			"EE read locations = %u\n"
			"User ID read prep script = %u\n"
			"User ID read script = %u\n"
			"Config read prep script = %u\n"
			"Config read script = %u\n"
			"Program mem write prep script = %u\n"
			"Program mem write script = %u\n"
			"Program mem write words = %u\n"
			"ProgMemPanelBufs = %u\n"
			"ProgMemPanelOffset = %u\n"
			"EE write prep script = %u\n"
			"EE write script = %u\n"
			"EE write locations = %u\n"
			"User ID write prep script = %u\n"
			"User ID write script = %u\n"
			"Config write prep script = %u\n"
			"Config write script = %u\n"
			"OSCCAL read script = %u\n"
			"OSCCAL write script = %u\n"
			"DP mask = %u\n"
			"Write config on erase = %u\n"
			"Blank check skip user IDs = %u\n"
			"Ignore bytes = %u\n"
			"Chip erase prep script = %u\n"
			"UNUSED3 = %u\n"
			"UNUSED4 = %u\n"
			"Program mem erase script = %u\n"
			"EE mem erase script = %u\n"
			"Config mem erase script = %u\n"
			"Reserved1 erase script = %u\n"
			"Reserved2 erase script = %u\n"
			"Test mem read script = %u\n"
			"Test mem read words = %u\n"
			"EEPROM row erase script = %u\n"
			"EEPROM row erase words = %u\n"
			"Export to MPLab = %u\n"
			"Debug halt script = %u\n"
			"Debug run script = %u\n"
			"Debug status script = %u\n"
			"Debug read exec ver script = %u\n"
			"Debug single step script = %u\n"
			"Debug bulk write data script = %u\n"
			"Debug bulk read data script = %u\n"
			"Debug write vector script = %u\n"
			"Debug read vector script = %u\n"
			"Debug row erase script = %u\n"
			"DebugReserved4Script = %u\n"
			"DebugReserved5Script = %u\n"
			"DebugReserved6Script = %u\n"
			"DebugReserved7Script = %u\n"
			"DebugReserved8Script = %u\n"
			"DebugReserved9Script = %u\n"
			"----------------------------------------------------------\n"
			,
			partPars[i].p1.CPMask,
			partPars[i].p1.CPConfig,
			partPars[i].p1.OSCCALSave,
			partPars[i].p1.IgnoreAddress,
			partPars[i].p1.VddMin,
			partPars[i].p1.VddMax,
			partPars[i].p1.VddErase,
			partPars[i].p1.CalibrationWords,
			partPars[i].p1.ChipEraseScript,
			partPars[i].p1.ProgMemAddrSetScript,
			partPars[i].p1.ProgMemAddrBytes,
			partPars[i].p1.ProgMemRdScript,
			partPars[i].p1.ProgMemRdWords,
			partPars[i].p1.EERdPrepScript,
			partPars[i].p1.EERdScript,
			partPars[i].p1.EERdLocations,
			partPars[i].p1.UserIDRdPrepScript,
			partPars[i].p1.UserIDRdScript,
			partPars[i].p1.ConfigRdPrepScript,
			partPars[i].p1.ConfigRdScript,
			partPars[i].p1.ProgMemWrPrepScript,
			partPars[i].p1.ProgMemWrScript,
			partPars[i].p1.ProgMemWrWords,
			partPars[i].p1.ProgMemPanelBufs,
			partPars[i].p1.ProgMemPanelOffset,
			partPars[i].p1.EEWrPrepScript,
			partPars[i].p1.EEWrScript,
			partPars[i].p1.EEWrLocations,
			partPars[i].p1.UserIDWrPrepScript,
			partPars[i].p1.UserIDWrScript,
			partPars[i].p1.ConfigWrPrepScript,
			partPars[i].p1.ConfigWrScript,
			partPars[i].p1.OSCCALRdScript,
			partPars[i].p1.OSCCALWrScript,
			partPars[i].p1.DPMask,
			partPars[i].p1.WriteCfgOnErase,
			partPars[i].p1.BlankCheckSkipUsrIDs,
			partPars[i].p1.IgnoreBytes,
			partPars[i].p1.ChipErasePrepScript,
			partPars[i].p1.UNUSED3,
			partPars[i].p1.UNUSED4,
			partPars[i].p1.ProgMemEraseScript,
			partPars[i].p1.EEMemEraseScript,
			partPars[i].p1.ConfigMemEraseScript,
			partPars[i].p1.reserved1EraseScript,
			partPars[i].p1.reserved2EraseScript,
			partPars[i].p1.TestMemoryRdScript,
			partPars[i].p1.TestMemoryRdWords,
			partPars[i].p1.EERowEraseScript,
			partPars[i].p1.EERowEraseWords,
			partPars[i].p1.ExportToMPLAB,
			partPars[i].p1.DebugHaltScript,
			partPars[i].p1.DebugRunScript,
			partPars[i].p1.DebugStatusScript,
			partPars[i].p1.DebugReadExecVerScript,
			partPars[i].p1.DebugSingleStepScript,
			partPars[i].p1.DebugBulkWrDataScript,
			partPars[i].p1.DebugBulkRdDataScript,
			partPars[i].p1.DebugWriteVectorScript,
			partPars[i].p1.DebugReadVectorScript,
			partPars[i].p1.DebugRowEraseScript,
			partPars[i].p1.DebugReserved4Script,
			partPars[i].p1.DebugReserved5Script,
			partPars[i].p1.DebugReserved6Script,
			partPars[i].p1.DebugReserved7Script,
			partPars[i].p1.DebugReserved8Script,
			partPars[i].p1.DebugReserved9Script
		);
	}
}

void printDeviceScripts(FILE *fout, size_t num, struct DeviceScripts scripts[])
{
	size_t i;
	size_t j;

	fprintf(fout,
		"Scripts listing (%zd members):\n"
		"----------------------------------------------------------\n",
		num);
	for (i = 0; i < num; ++i) {
		fprintf(fout,
			"Script number = %d\n"
			"Script name size = %zd\n"
			"Script name = %s\n"
			"Script version = %u\n"
			"Script length = %u\n"
			"Script code = "
			,
			scripts[i].p1.ScriptNumber,
			scripts[i].ScriptNameSize,
			scripts[i].ScriptName,
			scripts[i].p2.ScriptVersion,
			scripts[i].p2.ScriptLength
		);
		for (j = 0; j < scripts[i].p2.ScriptLength; ++j)
			fprintf(fout, " %04X", scripts[i].Script[j]);
		fprintf(fout,
			"Script comment size = %zd\n"
			"Script comment = %s\n"
			"----------------------------------------------------------\n"
			,
			scripts[i].CommentSize,
			scripts[i].Comment
		);
	}
}

