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

// T& : ���ڷ� lvalue�� ����.
// T&& : ���ڷ� lvalue, rvalue ��� ����.
template<typename T>
typename std::remove_reference<T>::type&& xmove(T&& obj)
{
	return static_cast<typename std::remove_reference<T>::type &&>(obj);
}

int main()
{
	Data d1;
	Data d2 = d1;	// ����
	Data d3 = static_cast<Data&&>(d1);	// move
	Data d4 = xmove(d2);			// move
									// lvalue ���޵Ǹ� T : Data&, T&& -> Data&�ȴ�. �׷��� casting�� lvalue�� �ȴ�.

	Data d5 = xmove(Data());	// �ӽð�ü�� move�� ����� �ʿ� ������ move�� ����Ҽ��� �־�� �Ѵ�.
}