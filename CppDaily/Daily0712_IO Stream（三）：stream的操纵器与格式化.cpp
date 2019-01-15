//daily0712
/************************************************************************/
/* 
1.������(manipulator)
�����������ж�:
>1.�����޸�stream���ﵽ���⹦��.
��endl:�����򻺳������뻻�з���ˢ�»�����;
ws:��ȡʱ���Կհ��ַ�(white space)
>2.���ڸ�ʽ���Ŀ�ݲ�����������ĸ�ʽ�����֣�

2.��ʽ��
��ν��ʽ������Ӱ����������ı��֣���ֵ���ȡ�����ַ���������ʾ��.
��Ϊ�����֣�
>1.��ʽ�������ĳ�Ա������
	setf(flags,[grp])
	unsetf(flags)
	flags()
	flags(flags)
	copyfmt(stream)

	width()
	fill()

	precision([val])

>2.��ʽ�Ĳ�������flags�Լ�mask����
�磺
	ios::showpos,ios::uppercase

������ֵ�flags:
	mask	   flags
 basefield	  oct/dec/hex
adjustfield   left/right/internal
floatfield	  fixed/scientific

>3.������ʽ�����Ĳ�����(��������ͬһ�������������д���ʹ�ã�������ʽ�����޸ĸ�ʽ�ĳ�Ա����)
�磺
setw()
setfill()
left
right
internal
showpos
skipws
��
*/
/************************************************************************/


#include "common/common.h"
#include <iomanip>
#include "common/serialization.h"



struct data0712
{
	int i;
	double d;
	std::string str;
	friend ibinstream& operator>>(ibinstream &ibs, data0712 &data);
	friend obinstream& operator<<(obinstream &obs,const data0712& data);

};

//�����л�
//ע���������������л��뷴���л�ʱ��˳��Ҫ����.
ibinstream& operator>>(ibinstream &ibs, data0712 &data)
{
	ibs >> data.i;
	ibs >> data.d;
	ibs >> data.str;

	return ibs;
}

//���л�
obinstream& operator<<(obinstream &obs, const data0712& data)
{
	obs << data.i;
	obs << data.d;
	obs << data.str;

	return obs;
}


void test0712()
{
	data0712 data;
	data.i = 100;
	data.d = 99.999;
	data.str = "data0712";

	obinstream obs;
	obs << data;



	std::string str = obs.str();
	ibinstream ibs(str);
	
	data0712 d2;
	d2.i = 0;
	d2.d = 0;
	d2.str = "";

	ibs >> d2;

	std::cout << "now d2 is:" << d2.i << " " << d2.d << " "<<d2.str << std::endl;
}

void func_algor_0712()
{

	//1.������
	//���ö�˵��endl������õĲ�����.
	//��ʱ������Ҫ�Զ������������ʽ���£�
	//ostream& my_manipulator (ostream &strm){...}

	//2.��ʽ��
	//>1.������ͨ����Ա�����޸ĸ�ʽ
	
	int x = 100;
	std::cout << "x is:" << x << std::endl;
	std::ios::fmtflags oldflgs = std::cout.flags();//����ɸ�ʽ.

	std::cout.setf(std::ios::showpos|std::ios::showbase|std::ios::uppercase);
	std::cout.setf(std::ios::internal,std::ios::adjustfield);
	std::cout << std::setw(20)<<std::hex << "now x is:" << x << std::endl;//setwֻ��һ��������. hex�Ժ���һֱ������.
	std::cout << "x is:" << x << std::endl;
	std::cout.flags(oldflgs);//��ԭ�ɸ�ʽ
	std::cout << "now x is:" << x << std::endl;

	//>2.bool��ʽ������
	bool b = true;
	std::cout << "\nb is:" << std::boolalpha << b << std::endl;
	std::cout<<"b is:"<< std::boolalpha << b << std::endl;//�Ժ�����������.
	auto restore_flgs = [&oldflgs](std::ostream *os)
	{
		os->flags(oldflgs);
	};

	

	//>3.��ʾ��ȣ��ַ���䣬λ�� �ȵĸ�ʽ����
	//��Щ����ֻ��һ��������.
	//����ͬʱʹ�ó�Ա����������������ø�ʽ����ʾ������ֻʹ�ò�����.
	//Ҫ������20���ַ���ȣ��ַ����Ϊ_��λ��Ϊ�Ҷ���
	{
		//1.ʹ�ó�Ա������ɣ�
		std::cout << "\nʹ�ó�Ա�������:\n";
		std::cout << "-42\n";
		std::cout << "Q" << std::endl;
		
		//����ʱ�Զ��ָ��ɸ�ʽ
		std::unique_ptr<std::ostream, decltype(restore_flgs)> cout_restore(&std::cout, restore_flgs);
		std::cout.width(20);
		std::cout.fill('_');
		std::cout.setf(std::ios::right, std::ios::adjustfield);
	
		std::cout << "-42\n";
		std::cout << "Q" << std::endl;
		std::cout << "width is:" << std::cout.width() << std::endl;
	}
	{
		//2.ʹ�ò�������ɣ�
		std::cout << "\nʹ�ò��������:\n";
		std::cout << "-42\n";
		std::cout << "Q" << std::endl;

		//����ʱ�Զ��ָ��ɸ�ʽ
		std::unique_ptr<std::ostream, decltype(restore_flgs)> cout_restore(&std::cout, restore_flgs);

		std::cout << std::setw(20) << std::setfill('_') << std::right << "-42\nQ"<<std::endl;
		std::cout << "width is:" << std::cout.width() << std::endl;
		
	}
	
	//4.������ֵ���������д��ʽ
	{
		std::unique_ptr<std::ostream, decltype(restore_flgs)> cout_restore(&std::cout, restore_flgs);
		int x = 104;
		std::cout << "\nnow x is:" << x << std::endl;
		
		std::cout << std::showpos << x << std::endl;//�����Ժ�����Ч
		std::cout << x << std::endl;

		std::cout << std::hex << std::showbase << x << std::endl;//Ĭ��0xСд
		std::cout << std::uppercase<< x << std::endl;//0X��д. ��������ó�����Ч.

		
	}

	//5.������ֵ���������Ƶ���ʾ
	{
		std::unique_ptr<std::ostream, decltype(restore_flgs)> cout_restore(&std::cout, restore_flgs);
		int x = 105;
		std::cout << "\nnow x is:" << x << std::endl;

		//���û���
		std::cout << std::oct << x << std::endl;
		std::cout << std::hex << x << std::endl;

		//���ý���
		std::cout << std::oct << std::showbase << x << std::endl;
		std::cout << std::hex << x << std::endl;//��һ��������showbase,���в���������.

	}

	//6.��������ʾ��ʽ������
	{
		std::unique_ptr<std::ostream, decltype(restore_flgs)> cout_restore(&std::cout, restore_flgs);
		float x = 106.60;
		std::cout << "\nnow x is:" << x << std::endl;

		std::cout << std::showpoint << x << std::endl;//������Ч
		std::cout <<  x+1 << std::endl;

		std::cout << std::setprecision(5) << x << std::endl;//����5λ����
		std::cout << x + 1 << std::endl;//������Ч

		double y = 0.01234567;
		std::cout << "\nnow y is:" << y << std::endl;//�������õ�5λ���������￪ʼ��Ч.���׸���0λ��ʼ�ƣ�����ʾ5λ������Ľ�����������ض�.
		std::cout << std::scientific << y << std::endl;//��ѧ������
		std::cout << y + 1 << std::endl;//������Ч.
		std::cout << std::fixed << y + 1 << std::endl;//С��������.
	}

	//7.������ʽ����
	{
		//��������
		//skipws:ʹ��>>ʱ�������հ�
		//noskipws:�����������෴
		//unitbuf:ÿ��д��ˢ��output������
		//nounitbuf:�����������෴
	}

	//8.���ʻ�
	{
		//��Ա������
		//getloc():���ص�ǰ��locale����
		//imbue(loc):����locale����
		//>>ĳЩ�����ַ�ת��������
		//widen(c):��char�����ַ�cת��Ϊstream�ַ����ڵ��ַ�
		//narrow(c,def):��stream�ַ����ڵ��ַ�cת��Ϊһ��char�ַ�������޶�Ӧ�ַ����򷵻�def��
	}


}


int maindaily0712()
{
	//test0712();
	func_algor_0712();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}

