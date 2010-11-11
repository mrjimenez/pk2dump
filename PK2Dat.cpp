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

#include "PK2Dat.h"

#include "pickit2dat.h"

#include <sstream>
#include <stdio.h>

PK2Dat::PK2Dat(const char *filename)
:
m_deviceFileParams(),
m_deviceFamilyParams(),
m_devicePartParams(),
m_deviceScripts()
{
	size_t num;
	size_t ret;
	FILE *fin;

	/* Open the file. */
	fin = fopen(filename, "r");
	if (!fin)
		throw EPK2Dat(-1, "error opening file", __FILE__, __LINE__);
	/* Read device file parameters. */
	ret = readDeviceFileParams(fin, &m_deviceFileParams);
	if (!ret)
		throw EPK2Dat(-1, "error reading device file parameters", __FILE__, __LINE__);
	/* Read device family parameters. */
	num = m_deviceFileParams.p2.NumberFamilies;
	m_deviceFamilyParams.resize(num);
	ret = readDeviceFamilyParams(fin, num, &m_deviceFamilyParams[0]);
	if (!ret)
		throw EPK2Dat(num, "error reading device family parameters", __FILE__, __LINE__);
	/* Read device part parameters. */
	num = m_deviceFileParams.p2.NumberParts;
	m_devicePartParams.resize(num);
	ret = readDevicePartParams(fin, num, &m_devicePartParams[0]);
	if (!ret)
		throw EPK2Dat(num, "error reading device part parameters", __FILE__, __LINE__);
	/* Read device script parameters. */
	num = m_deviceFileParams.p2.NumberScripts;
	m_deviceScripts.resize(num);
	ret = readDeviceScripts(fin, num, &m_deviceScripts[0]);
	if (!ret)
		throw EPK2Dat(num, "error reading device script parameters", __FILE__, __LINE__);
	/* The end. */
	fclose(fin);
}

EPK2Dat::EPK2Dat(
	size_t n,
	const char *message,
	const char *filename,
	int line)
:
std::runtime_error("PICkit2 Data"),
m_n(n),
m_message(),
m_filename(),
m_line(line)
{
	if (message) {
		m_message = message;
	} else {
		m_message = "<empty>";
	}
	if (filename) {
		m_filename = filename;
	} else {
		m_filename = "<empty>";
	}
	std::ostringstream o;
	o << "Error(" <<
		m_filename << ":" << m_line <<
		"): n = " << m_n << ", " <<
		m_message << std::endl;
	m_message = o.str();
}

const char *EPK2Dat::what() const throw()
{
	return m_message.c_str();
}

