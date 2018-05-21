//daily0301
/************************************************************************/
/* 
weak_ptr:
1.��ֹ����ѭ�����õ��µ���Դ�޷��ͷ�
2.�빲����Դ���ֲ���ӵ�е��龰:��ȫ��callback

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <vector>

auto funcPrint = [](const std::string &str)
{
	std::cout << str << std::endl;
};

class CPerson : public std::enable_shared_from_this<CPerson>
{
public:
	CPerson() {};
	CPerson(const std::string &strName);
	~CPerson() {};
	void SetToOthers(std::shared_ptr<CPerson> pOther,bool bShared = false);
	void GetName(std::string &strName);
	void PrintAll(const std::function<void(const std::string&)> &func);
private:
	std::vector<std::weak_ptr<CPerson>> m_vecOthers;
	std::vector<std::shared_ptr<CPerson>> m_vecOhtersShared;
	std::string m_strName;
};


void CPerson::PrintAll(const std::function<void(const std::string&)> &func)
{
	func(m_strName);
	for (auto iter:m_vecOthers)
	{
		std::shared_ptr<CPerson> p = iter.lock();
		if (p)
		{
			std::string strName;
			p->GetName(strName);
			func(strName);
		}
		
	}

	for (auto iter : m_vecOhtersShared)
	{
		std::shared_ptr<CPerson> p = iter;
		if (p)
		{
			std::string strName;
			p->GetName(strName);
			func(strName);
		}

	}
}

CPerson::CPerson(const std::string &strName)
{
	m_strName = strName;
}

void CPerson::GetName(std::string &strName)
{
	strName = m_strName;
}

void CPerson::SetToOthers(std::shared_ptr<CPerson> pOther, bool bShared)
{
	//�����ʹ��shared_from_this����ֱ��ʹ��this����ôЧ����ͬ��
	//int *p = new int(1);
	//shared_ptr<int> p1(p);
	//shared_ptr<int> p2(p);
	//������2�Σ���������Դ�ͷ�����

	if (bShared)
	{
		pOther->m_vecOhtersShared.push_back(shared_from_this());
	}
	else
	{
		
		std::cout << "In SetToOthers , usecount of " << m_strName << " :" << shared_from_this().use_count() << std::endl;
		std::shared_ptr<CPerson> p = shared_from_this();
		pOther->m_vecOthers.push_back(p);

		std::cout << "In SetToOthers , usecount of " << m_strName << " :" << p.use_count() << std::endl;
	}
	
}

void func_weakptr_inside(std::shared_ptr<CPerson> pMama)
{
	
	std::shared_ptr<CPerson> pPapa = std::make_shared<CPerson>("Peter");
	std::shared_ptr<CPerson> pKid = std::make_shared<CPerson>("Tom");
	std::shared_ptr<CPerson> pKid2 = std::make_shared<CPerson>("Harry");

	std::cout << "usecount of Tom:" << pKid.use_count() << std::endl;
	std::cout << "usecount of Harry:" << pKid2.use_count() << std::endl;
	std::cout << "usecout of Peter:" << pPapa.use_count() << std::endl;
	std::cout << std::endl;

	pKid->SetToOthers(pMama);
	//pKid->SetToOthers(pPapa);
	pKid2->SetToOthers(pMama);//�����ã���������
	pPapa->SetToOthers(pMama,true);//ǿ���ã�����+1

	std::cout << "Inside func:" << std::endl;
	pMama->PrintAll(funcPrint);
	std::cout << std::endl;
	std::cout << "usecount of Tom:" << pKid.use_count() << std::endl;
	std::cout << "usecount of Harry:" << pKid2.use_count() << std::endl;
	std::cout << "usecout of Peter:" << pPapa.use_count() << std::endl;
}


int maindaily0301()
//int main()
{
	std::shared_ptr<CPerson> pMama = std::make_shared<CPerson>("Lily");
	func_weakptr_inside(pMama);

	std::cout << std::endl <<"Outside func:" << std::endl;
	pMama->PrintAll(funcPrint);

	std::string strInput;
	std::getline(std::cin,strInput);

	return 0;
}