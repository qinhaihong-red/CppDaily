#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <set>
#include <map>

#include <memory>

#include <functional>
#include <iterator>
#include <algorithm>

#include <initializer_list>


namespace common
{
	enum class PrintFormat:int{s,t,n};

	template<typename T>
	void print_elems(const T &t,PrintFormat pf=PrintFormat::s)
	{
		for (auto &i : t)
		{
			if (pf == PrintFormat::s)
			{
				std::cout << i << " ";
			}
			else if (pf == PrintFormat::n)
			{
				std::cout << i << "\n";
			}
			
		}
	}

	template<typename T1,typename T2>
	void print_elems(const std::map<T1, T2> &t, PrintFormat pf = PrintFormat::s)
	{
		for (auto &i : t)
		{
			if (pf == PrintFormat::s)
			{
				std::cout << "["<<i.first << ","<<i.second<<"]"<<" ";
			}
			else if (pf == PrintFormat::n)
			{
				std::cout << "[" << i.first << "," << i.second << "]" << "\n";
			}

		}
	}
	template<typename T>
	void insert_element(T &t, int first, int last)
	{
		for (int i=first;i<=last;++i)
		{
			t.insert(std::end(t),i);
		}
	}

}

	class vecWrapper
	{
	public:
		vecWrapper();
		~vecWrapper() {};
		void pushback(int n);
		void pushback(std::initializer_list<int> &&il);
		void print();
	private:
		std::vector<int> m_vec;
	};


	class CPlayer
	{
	public:
		CPlayer(const std::string&,int nRank=0);
		~CPlayer() {};
		CPlayer(const CPlayer&cp);

		std::string getName()const;
		int getRank()const;
		friend std::ostream& operator<<(std::ostream &os, const CPlayer &player);
	private:
		std::string m_strName;
		int m_nRank;
	};
