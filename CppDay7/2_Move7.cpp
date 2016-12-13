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

class Test
{
	Data data;
public:
	Test() {}
	
	// setter 만들기
	//void SetData(Data d) { data = d; }
	//void SetData(const Data& d) { data = d; }

	//복사와 move를 모두 지원하는 setter 만들기 
	//   1. 함수 오버로딩
	//void SetData(const Data& d) { data = d; }				// 복사 1회
	//void SetData(Data&& d)		{ data = std::move(d); }	// move 1회

	// call by value는 어떨까?
	void SetData(Data d) { data = std::move(d); }
					// 복사로 보낼때 : 복사1회, move 1회
					// move로 보낼때 : move 2회
};


int main()
{
	Test t1;
	Data d1, d2;

	// 복사와 move를 모두 지원하는 setter
	t1.SetData(d1);				// d1은 전달후에도 계속 사용하겠다는 것
	t1.SetData(std::move(d2));	// d2는 전달후에는 사용하지 않겠다는 것
}