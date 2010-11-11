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

#ifndef PK2DAT_H
#define PK2DAT_H

#include "datfile.h"

#include <stdexcept>
#include <vector>

class PK2Dat
{
public:
	struct DeviceFileParams m_deviceFileParams;
	std::vector<struct DeviceFamilyParams> m_deviceFamilyParams;
	std::vector<struct DevicePartParams> m_devicePartParams;
	std::vector<struct DeviceScripts> m_deviceScripts;

public:
	PK2Dat(const char *filename);
	~PK2Dat() {}
	// Not assignable, not copyable
	PK2Dat(const PK2Dat &p);
	PK2Dat &operator=(const PK2Dat &rhs);
};

class EPK2Dat
:
public std::runtime_error
{
private:
	size_t m_n;
	std::string m_message;
	std::string m_filename;
	int m_line;

public:
	EPK2Dat(size_t n,
		const char *message,
		const char *filename = "",
		int line = 0);
	virtual ~EPK2Dat() throw() {}
	virtual const char *what() const throw();
	void setFilename(const char *filename) throw()
		{ m_filename = filename; }
};

#endif /* PK2DAT_H */

