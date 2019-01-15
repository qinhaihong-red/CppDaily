//daily0726
/************************************************************************/
/* 
stringstream��Ҫ��ɸ�ʽ���ַ���(istringstream)�뷴��ʽ���ַ���(ostringstream)�Ĺ���.
������Ϊ���ַ����汾�Ķ��������л��뷴���л���ʵ��.

������԰��Զ���Ľṹ��ͨ��stringstream���и�ʽ���뷴��ʽ��.

��Ȼ��stringstreamҲ����ͨ����read��write��ɶ��������л��뷴���л�.
ibinstream��obinstream������stringstream�ĸ�ʽ��������>>��<<������ʵ�����л��뷴���л�.
*/
/************************************************************************/

#include "common/common.h"
#include <sstream>

void func_algor_format_and_deformat()
{
	//1.��ʽ��
	std::ostringstream oss;
	oss << "James" << " " << 33 << " " << "Power Forward" << " " << 9.9 << std::endl;
	oss << "Harden" << " " << 29 << " " << "Score Guard" << " " << 9.7 << std::endl;


	std::string csv = oss.str();
	std::cout << "now players csv lists:\n" << csv << std::endl;

	//2.����ʽ��
	std::istringstream iss(csv);
	std::string s;
	int n = 0;
	std::string name, position;
	int age = 0;
	float rank = 0;
	while (std::getline(iss, s))
	{
		//���������ķ���ʽ���в�ͨ
		//��Ȼ>>��wsΪ�����������������ַ����ڲ��ֺ��пո񣬾ͻ��>>�Ľ����γɸ���
		//���������Power Forward��ΪPower_Forward�Ϳ�������������.
		std::istringstream line(s);
		line >> name >> age >> position >> rank;

		std::cout << ++n << "." << name << " " << age << " " << position << " " << rank << std::endl;
	}
}

void func_algor_parse_csv_0726()
{
	//1.��ʽ��
	std::ostringstream oss;
	oss << "James" << "," << 33 << "," << "Power Forward" <<","<< 9.9 << std::endl;
	oss << "Harden" << "," << 29 << "," << "Score Guard" << ","<<9.7 << std::endl;
	oss << "Durant" << "," << 30 << "," << "Small Forward" << ","<<9.8 << std::endl;

	std::string csv = oss.str();
	std::cout << "now players csv lists:\n" << csv<<std::endl;

	//2.����ʽ��
	std::istringstream iss(csv);
	std::string s;
	int n = 0;
	std::string name, position;
	int age = 0;
	float rank = 0;
	while (std::getline(iss,s))
	{
		//>>���������ķ���ʽ���в�ͨ����Ϊline��һ�����ַ�����stringstream��֪�������������(Ĭ��ʹ��ws).
		//std::istringstream line(s);
		//line >> name >> age >> position >> rank;

		//>>����ͨ���ָ�������һ����ʽ��
		std::istringstream line(s);
		std::string i;
		int col = 0;
		while (std::getline(line,i,','))
		{
			std::istringstream _temp(i);
			if (col==0)
			{
				_temp >> name;
			}
			else if (col==1)
			{
				_temp >> age;
			}
			else if (col==2)
			{
				_temp >> position;
			}
			else if(col==3)
			{
				_temp >> rank;
			}


			++col;
		}

		std::cout << ++n << "." << name << " " << age << " " << position << " " << rank << std::endl;
	}

}


int main0726()
{
	func_algor_format_and_deformat();
	//func_algor_parse_csv_0726();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}
