#pragma once
#include "common.h"
#include <fstream>
/************************************************************************/
/* 
字符串--文件工具函数

字符串：
--去除头尾空格
--分割

文件：
--读取csv文件
--读文件的第一行
--读文件的最后一行

--清空文件
--判断文件是否存在
--获得文件的大小
--删除文件
--重命名文件
*/
/************************************************************************/

namespace strfiletools
{
	bool is_fileexists(const std::string &filename);
	bool empty_file(const std::string &filename);
	bool remove_file(const std::string &filename,int *err=nullptr);
	bool rename_file(const std::string &filename,const std::string &newname, int *err = nullptr);
	long long get_filesize(const std::string &filename, int *err = nullptr);
	bool read_csv(const std::string &filename,std::vector<std::string> data);

	bool get_nlines(const std::string &filename,std::vector<std::string> &lines,bool fromtop=true,int *err=nullptr);
	std::string get_lastline(const std::string &filename);
	std::string get_firstline(const std::string &filename);

	std::string trim_left(const std::string &str);
	std::string trim_right(const std::string &str);
	std::string trim(const std::string &str);
	std::vector<std::string> split(const std::string& str, const std::string& regex);
}
