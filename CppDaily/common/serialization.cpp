#include"serialization.h"

ibinstream::ibinstream()
{

}

ibinstream::ibinstream(std::string &str) :std::istringstream(str)
{
}

ibinstream::~ibinstream()
{

}

ibinstream& operator>> (ibinstream &ibs, int &i)
{
	ibs.read((char*)&i, sizeof(i));
	return ibs;
}

ibinstream& operator>>(ibinstream &ibs, double &d)
{
	ibs.read((char*)&d, sizeof(d));
	return ibs;

}

ibinstream& operator>>(ibinstream &ibs, std::string &s)
{
	int len = 0;
	ibs.read((char*)&len, sizeof(len));

	std::unique_ptr<char[]> p(new char[len+1]);
	p[len] = '\0';
	ibs.read(&p[0], len);
	s = std::string(p.get());
	return ibs;
}



obinstream::obinstream()
{

}

obinstream::~obinstream()
{

}


obinstream& operator<< (obinstream &os, const int &i)
{
	os.write((char*)&i, sizeof(i));
	return os;
}

obinstream& operator<<(obinstream &os, const double &d)
{
	os.write((char*)&d, sizeof(d));
	return os;
}

obinstream& operator<<(obinstream &os, const std::string &s)
{
	int len = s.length();
	os.write((char*)&len, sizeof(len));
	os.write(s.c_str(), s.length());
	return os;
}
