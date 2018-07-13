#pragma once
#include "common.h"
#include <sstream>

/************************************************************************/
/*
序列化与反序列化

io stream在进行二进制的序列化与反序列化时，只能通过ostream和istream的成员函数write与read进行.
而操纵符<<与>>只进行文本的读写.
现定义ibinstream与obinstream，通过<<与>>完成序列化与反序列化.

优点：
1.结构清晰，使用简单.通过streambuf管理指针在读写时的移动，不必手动控制.
2.扩展性强.对任意类或结构体，只需要定义该结构对i/obinstream序列化操作符的重载，即可完成序列化.
示例见Daily0712.

注意：
由于是逐一对数据结构进行序列化，因此不必再对结构体进行push与pop的对齐工作.

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





