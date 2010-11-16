//
// IniFileConfiguration.cpp
//
// $Id: //poco/1.3/Util/src/IniFileConfiguration.cpp#4 $
//
// Library: Util
// Package: Configuration
// Module:  IniFileConfiguration
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "Poco/Util/IniFileConfiguration.h"
#include "Poco/Exception.h"
#include "Poco/String.h"
#include "Poco/Path.h"
#include "Poco/FileStream.h"
#include <cctype>
#include <set>


using Poco::icompare;
using Poco::trim;
using Poco::Path;


namespace Poco {
namespace Util {


IniFileConfiguration::IniFileConfiguration()
{
}


IniFileConfiguration::IniFileConfiguration(std::istream& istr)
{
	load(istr);
}

	
IniFileConfiguration::IniFileConfiguration(const std::string& path)
{
	load(path);
}


IniFileConfiguration::~IniFileConfiguration()
{
}


void IniFileConfiguration::load(std::istream& istr)
{
	_map.clear();
	_sectionKey.clear();
	while (!istr.eof())
	{
		parseLine(istr);
	}
}
	

void IniFileConfiguration::load(const std::string& path)
{
	Poco::FileInputStream istr(path);
	if (istr.good())
		load(istr);
	else
		throw Poco::OpenFileException(path);
}


bool IniFileConfiguration::getRaw(const std::string& key, std::string& value) const
{
	IStringMap::const_iterator it = _map.find(key);
	if (it != _map.end())
	{
		value = it->second;
		return true;
	}
	else return false;
}


void IniFileConfiguration::setRaw(const std::string& key, const std::string& value)
{
	throw Poco::NotImplementedException("Setting a property in an IniFileConfiguration");
}


void IniFileConfiguration::enumerate(const std::string& key, Keys& range) const
{
	std::set<std::string> keys;
	std::string prefix = key;
	if (!prefix.empty()) prefix += '.';
	std::string::size_type psize = prefix.size();
	for (IStringMap::const_iterator it = _map.begin(); it != _map.end(); ++it)
	{
		if (icompare(it->first, psize, prefix) == 0)
		{
			std::string subKey;
			std::string::size_type end = it->first.find('.', psize);
			if (end == std::string::npos)
				subKey = it->first.substr(psize);
			else
				subKey = it->first.substr(psize, end - psize);
			if (keys.find(subKey) == keys.end())
			{
				range.push_back(subKey);
				keys.insert(subKey);
			}
		}
	}
}


bool IniFileConfiguration::ICompare::operator () (const std::string& s1, const std::string& s2) const
{
	return icompare(s1, s2) < 0;
}


void IniFileConfiguration::parseLine(std::istream& istr)
{
	static const int eof = std::char_traits<char>::eof(); 

	int c = istr.get();
	while (c != eof && std::isspace((char) c)) c = istr.get();
	if (c != eof)
	{
		if (c == ';')
		{
			while (c != eof && c != '\n') c = istr.get();
		}
		else if (c == '[')
		{
			std::string key;
			c = istr.get();
			while (c != eof && c != ']' && c != '\n') { key += (char) c; c = istr.get(); }
			_sectionKey = trim(key);
		}
		else
		{
			std::string key;
			while (c != eof && c != '=' && c != '\n') { key += (char) c; c = istr.get(); }
			std::string value;
			if (c == '=')
			{
				c = istr.get();
				while (c != eof && c != '\n') { value += (char) c; c = istr.get(); }
			}
			std::string fullKey = _sectionKey;
			if (!fullKey.empty()) fullKey += '.';
			fullKey.append(trim(key));
			_map[fullKey] = trim(value);
		}
	}
}


} } // namespace Poco::Util
