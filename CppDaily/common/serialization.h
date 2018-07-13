#pragma once
#include "common.h"
#include <sstream>

/************************************************************************/
/*
���л��뷴���л�

io stream�ڽ��ж����Ƶ����л��뷴���л�ʱ��ֻ��ͨ��ostream��istream�ĳ�Ա����write��read����.
�����ݷ�<<��>>ֻ�����ı��Ķ�д.
�ֶ���ibinstream��obinstream��ͨ��<<��>>������л��뷴���л�.

�ŵ㣺
1.�ṹ������ʹ�ü�.ͨ��streambuf����ָ���ڶ�дʱ���ƶ��������ֶ�����.
2.��չ��ǿ.���������ṹ�壬ֻ��Ҫ����ýṹ��i/obinstream���л������������أ�����������л�.
ʾ����Daily0712.

ע�⣺
��������һ�����ݽṹ�������л�����˲����ٶԽṹ�����push��pop�Ķ��빤��.

*/
/************************************************************************/


class obinstream :public std::ostringstream
{
public:
	obinstream();
	~obinstream();


	friend obinstream& operator<< (obinstream &os, const int &i);
	friend obinstream& operator<<(obinstream &os, const double &d);
	friend obinstream& operator<<(obinstream &os, const std::string &s);

private:


};

class ibinstream :public std::istringstream
{
public:
	ibinstream();
	ibinstream(std::string &str);
	~ibinstream();


	friend ibinstream& operator>> (ibinstream &ibs, int &i);
	friend ibinstream& operator>>(ibinstream &ibs, double &d);
	friend ibinstream& operator>>(ibinstream &ibs, std::string &s);

private:


};





