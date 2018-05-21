#include "common.h"

void vecWrapper::pushback(int n)
{
	m_vec.push_back(n);
}

void vecWrapper::pushback(std::initializer_list<int> &&il)
{
	for (auto &i : il)
	{
		pushback(i);
	}
}

vecWrapper::vecWrapper()
{

}

void vecWrapper::print()
{
	if (m_vec.empty())
	{
		return;
	}
	common::print_elems(m_vec);
}


std::ostream& operator<<(std::ostream& os, const CPlayer &player)
{
	os << player.m_strName << " " << player.m_nRank;
	return os;
}


CPlayer::CPlayer(const std::string& name,int nRank/* =0 */) :m_strName(name),m_nRank(nRank)
{

}


CPlayer::CPlayer(const CPlayer &cp)
{
	m_nRank   = cp.m_nRank;
	m_strName = cp.m_strName;
}

std::string CPlayer::getName()const
{
	return m_strName;
}

int CPlayer::getRank()const
{
	return m_nRank;
}