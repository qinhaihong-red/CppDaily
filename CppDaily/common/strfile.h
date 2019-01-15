#pragma once
#include "common.h"
#include <fstream>
/************************************************************************/
/* 
�ַ���--�ļ����ߺ���

�ַ�����
--ȥ��ͷβ�ո�
--�ָ�

�ļ���
--��ȡcsv�ļ�
--���ļ��ĵ�һ��
--���ļ������һ��

--����ļ�
--�ж��ļ��Ƿ����
--����ļ��Ĵ�С
--ɾ���ļ�
--�������ļ�
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

}