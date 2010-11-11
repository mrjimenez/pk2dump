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

/*
 * Structure of data in binary PK2DeviceFile.dat file
 * Jeff Post, j_post <AT> pacbell <DOT> net
 * Last update: 2007/09/16
 *
 * Modified by Marcelo Roberto Jimenez <mroberto@cpti.cetuc.puc-rio.br>
 * to use gcc pragma pack.
 *
 * Based on information provided by Microchip, Inc.
 * PIC, PICkit2 are registered trademarks of Microchip, Inc.
 */

#ifndef DATFILE_H
#define DATFILE_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define	byte		unsigned char
#define	ushort		unsigned short
#define	uint		unsigned int
/*
 * Defining bool sucks because it will conflict with C++, but the orginal file
 * was not written by me and I suppose that leaving it like that will make it
 * easier to port changes to this file.
 */
#ifndef __cplusplus
	#define	bool		byte
#endif

#pragma pack(push, 1)

/******************************************************************************/

struct DeviceFileParams1 {
	int VersionMajor;
	int VersionMinor;
	int VersionDot;
};

struct DeviceFileParams2 {
	uint NumberFamilies;
	uint NumberParts;
	uint NumberScripts;
	byte Compatibility;
	byte UNUSED1A;
	ushort UNUSED1B;
	uint UNUSED2;
};

#define MAX_VERSION_NOTES_SIZE	512
struct DeviceFileParams {
	struct DeviceFileParams1 p1;
	size_t VersionNotesSize;
	char VersionNotes[MAX_VERSION_NOTES_SIZE + 1];
	struct DeviceFileParams2 p2;
};

/******************************************************************************/

struct DeviceFamilyParams1 {
	ushort FamilyID;
	ushort FamilyType;
	ushort SearchPriority;
};

struct DeviceFamilyParams2 {
	ushort ProgEntryScript;
	ushort ProgExitScript;
	ushort ReadDevIDScript;
	uint DeviceIDMask;
	uint BlankValue;
	byte BytesPerLocation;
	byte AddressIncrement; 
	bool PartDetect;
	uint UNUSED1;
	byte EEMemBytesPerWord;
	byte EEMemAddressIncrement;
	byte UserIDHexBytes;
	byte UserIDBytes;
	byte ProgMemHexBytes;
	byte EEMemHexBytes;
	byte ProgMemShift;
	uint TestMemoryStart;
	ushort TestMemoryLength;
	float Vpp;
};

/* Apparently the maximum value stated (16) is false. */
#define MAX_FAMILY_NAME_SIZE	32
struct DeviceFamilyParams {
	struct DeviceFamilyParams1 p1;
	size_t FamilyNameSize;
	char FamilyName[MAX_FAMILY_NAME_SIZE + 1];
	struct DeviceFamilyParams2 p2;
};

/******************************************************************************/

struct DevicePartParams1 {
	/* references FamilyID in DeviceFamilyParams. */
	ushort Family;
	uint DeviceID;
	uint ProgramMem;
	ushort EEMem;
	uint EEAddr;
	byte ConfigWords;
	uint ConfigAddr;
	byte UserIDWords;
	uint UserIDAddr;
	uint BandGapMask;
	ushort ConfigMasks[8];
	ushort ConfigBlank[8];
	ushort CPMask;
	byte CPConfig;
	bool OSCCALSave;
	uint IgnoreAddress;
	float VddMin;
	float VddMax;
	float VddErase;
	byte CalibrationWords;
	ushort ChipEraseScript;
	ushort ProgMemAddrSetScript;
	byte ProgMemAddrBytes;
	ushort ProgMemRdScript;
	ushort ProgMemRdWords;
	ushort EERdPrepScript;
	ushort EERdScript;
	ushort EERdLocations;
	ushort UserIDRdPrepScript;
	ushort UserIDRdScript;
	ushort ConfigRdPrepScript;
	ushort ConfigRdScript;
	ushort ProgMemWrPrepScript;
	ushort ProgMemWrScript;
	ushort ProgMemWrWords;
	byte ProgMemPanelBufs;
	uint ProgMemPanelOffset;
	ushort EEWrPrepScript;
	ushort EEWrScript;
	ushort EEWrLocations;
	ushort UserIDWrPrepScript;
	ushort UserIDWrScript;
	ushort ConfigWrPrepScript;
	ushort ConfigWrScript;
	ushort OSCCALRdScript;
	ushort OSCCALWrScript;
	ushort DPMask;
	bool WriteCfgOnErase;
	bool BlankCheckSkipUsrIDs;
	ushort IgnoreBytes;
	ushort ChipErasePrepScript;
	uint UNUSED3;
	uint UNUSED4;
	ushort ProgMemEraseScript;
	ushort EEMemEraseScript;
	ushort ConfigMemEraseScript;
	ushort reserved1EraseScript;
	ushort reserved2EraseScript;
	ushort TestMemoryRdScript;
	ushort TestMemoryRdWords;
	ushort EERowEraseScript;
	ushort EERowEraseWords;
	bool ExportToMPLAB;
	ushort DebugHaltScript;
	ushort DebugRunScript;
	ushort DebugStatusScript;
	ushort DebugReadExecVerScript;
	ushort DebugSingleStepScript;
	ushort DebugBulkWrDataScript;
	ushort DebugBulkRdDataScript;
	ushort DebugWriteVectorScript;
	ushort DebugReadVectorScript;
	ushort DebugRowEraseScript;
	ushort DebugReserved4Script;
	ushort DebugReserved5Script;
	ushort DebugReserved6Script;
	ushort DebugReserved7Script;
	ushort DebugReserved8Script;
	ushort DebugReserved9Script;
};

#define MAX_PART_NAME_SIZE	20
struct DevicePartParams {
	size_t PartNameSize;
	char PartName[MAX_PART_NAME_SIZE + 1];
	struct DevicePartParams1 p1;
};

/******************************************************************************/

struct DeviceScripts1 {
	ushort ScriptNumber;
};

struct DeviceScripts2 {
	ushort ScriptVersion;
	uint UNUSED1;
	ushort ScriptLength;
};

#define MAX_SCRIPT_NAME_SIZE	20
#define MAX_SCRIPT_SIZE		128
#define MAX_COMMENT_SIZE	512
struct DeviceScripts {
	struct DeviceScripts1 p1;
	size_t ScriptNameSize;
	char ScriptName[MAX_SCRIPT_NAME_SIZE + 1];
	struct DeviceScripts2 p2;
	ushort Script[MAX_SCRIPT_SIZE];
	size_t CommentSize;
	char Comment[MAX_COMMENT_SIZE + 1];
};

#pragma pack(pop)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DATFILE_H */

