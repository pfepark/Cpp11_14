#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

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

// T& : 인자로 lvalue만 가능.
// T&& : 인자로 lvalue, rvalue 모두 가능.
template<typename T>
typename std::remove_reference<T>::type&& xmove(T&& obj)
{
	return static_cast<typename std::remove_reference<T>::type &&>(obj);
}

int main()
{
	Data d1;
	Data d2 = d1;	// 복사
	Data d3 = static_cast<Data&&>(d1);	// move
	Data d4 = xmove(d2);			// move
									// lvalue 전달되면 T : Data&, T&& -> Data&된다. 그래서 casting이 lvalue가 된다.

	Data d5 = xmove(Data());	// 임시객체는 move를 사용할 필요 없지만 move를 사용할수도 있어야 한다.
}