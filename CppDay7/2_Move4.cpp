#include <iostream>
#include <string>

class Data
{
	std::string str;
public:
	Data(std::string s = "abc") : str(s)
	{

	}

	// 복사 계열에서는 복사를
	Data(const Data& s) : str(s.str)
	{
		std::cout << "copy" << std::endl;
	}
	
	Data& operator=(const Data& s)
	{
		std::cout << "copy=" << std::endl;
		str = s.str;
		return *this;
	}

	// move 계열함수 : 모든 맴버를 move로 옮겨야 한다.
	Data(Data&& s) : str(std::move(s.str))
	{
		std::cout << "move" << std::endl;
	}

	Data& operator=(Data&& s)
	{
		std::cout << "move=" << std::endl;
		str = std::move(s.str);
		return *this;
	}
};

// 알고리즘 만들기
/*
template<typename T> void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
*/
template<typename T> void Swap(T& a, T& b)
{
	T tmp = std::move(a);		// move버전을 만들기 않아도 복사버전으로 호출하여 swap을 수행한다.
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{

	Data d1("AAA");
	Data d2("BBB");

	Swap(d1, d2);
	std::swap(d1, d2);
}