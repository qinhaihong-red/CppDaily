#include "strfile.h"
#include <cstdio>

bool strfiletools::is_fileexists(const std::string &filename)
{
	std::ifstream ifs(filename);
	if (!ifs)
	{
		return false;
	}
	return true;
}

bool strfiletools::empty_file(const std::string &filename)
{
	if (!is_fileexists(filename))
	{
		return false;
	}

	std::ofstream ofs(filename,std::ios::trunc);
	if (!ofs)
	{
		return false;
	}

	return true;
}



bool strfiletools::remove_file(const std::string &filename, int *err)
{

	return std::remove(filename.c_str()) == 0;

}

bool strfiletools::rename_file(const std::string &filename, const std::string &newname, int *err )
{

	return std::rename(filename.c_str(), newname.c_str()) == 0;
}

long long strfiletools::get_filesize(const std::string &filename, int *err )
{
	std::ifstream ifs(filename,std::ios::binary|std::ios::ate);
	if (!ifs)
	{
		return -1;
	}

	return (long long)ifs.tellg();
}

std::vector<std::string> strfiletools::split(const std::string& str, const std::string& regex)
{
	return {std::sregex_token_iterator(str.begin(), str.end(), std::regex(regex), -1), std::sregex_token_iterator()};
}
