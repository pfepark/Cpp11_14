#include <iostream>
#include <set>
#include <functional>

//typedef std::set<int, std::greater<int>> SET;
//typedef std::set<double, std::greater<double>> SET_DOUBLE;

// �Ʒ� ó�� �Ǹ� ���� ������?
template<typename T> typedef std::set<T, std::greater<T>> SET;

// C++11 using�� ���ø� ���� = "Template typedef" ��� �θ��ϴ�.
template<typename T> using SET = std::set<T, std::greater<T>>;

int main()
{
	//std::set<int, std::greater<int>> s;	// tree ( redblack tree )

	SET<int> s;

	s.insert(10);
	s.insert(15);
	s.insert(6);

	for (auto n : s)
		std::cout << n << std::endl;
}