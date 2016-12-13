#include <iostream>
#include <string>
#include <vector>

class Data
{
	std::string str;
public:
	Data(std::string s = "abc") : str(s)
	{
		//std::cout << "ctor" << std::endl;
	}

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

//----------------------------------
// Rule of 3 : 소멸자, 복사 생성자, 대입연산자
// Rule of 5 : 소멸자, 복사 생성자, 대입연산자, move 생성자, move 대입연산자

// 규칙 1. 5개의 함수를 모두 만들지 않으면 컴파일러가 제공해 준다.
//      2. 복사 계열의 함수를 제공하면..move계열은 자동생성되지 않는다. 내가 복사 방법을 결정했으니 컴파일러가 move를 만들어줄수가없..
//      3. move 계열의 함수만 제공하면..복사계열은 자동생성되지 않는다. move도 사용할 수 없다.
//			반드시 사용자가 직접 복사 계열을 제공해야 한다.
class Test
{
	Data data;
public:
	Test() {}

	//Test(const Test& t) : data(t.data) {}
	Test(Test&& t) : data(std::move(t.data)) {}
};


int main()
{
	Test t1;
	Test t2 = t1;
	Test t3 = std::move(t1);
}