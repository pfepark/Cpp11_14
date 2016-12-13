#include <iostream>
#include <string>
#include <vector>

class Data
{
	std::string str;
public:
	Data(std::string s = "abc") : str(s)
	{
		std::cout << "ctor" << std::endl;
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
	// 되도록이면 move 계열 함수를 만들때는 예외가 없음을 컴파일러에게 알려야 한다.
	// 대부분의 C++ 컴파일러의 STL은 예외가 없을때만 move를 사용한다.
	Data(Data&& s) noexcept : str(std::move(s.str))
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


int main()
{
	//std::vector<Data> v(5);

	//v.resize(10);		// 버퍼를 10개로 늘려야 한다. VC++에서만 move호출. 예외가 없음을 보장해야 move로 호출. g++에서는 복사한다.
/*
	Data d1;
	Data d2 = d1;	// 복사
	Data d3 = std::move(d1);	// move
	Data d4 = std::move_if_noexcept(d2);		// 예외가 없을때만 move
	*/
	Data d5 = Data("adf");
}