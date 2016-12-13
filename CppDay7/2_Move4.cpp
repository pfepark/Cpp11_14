#include <iostream>
#include <string>

class Data
{
	std::string str;
public:
	Data(std::string s = "abc") : str(s)
	{

	}

	// ���� �迭������ ���縦
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

	// move �迭�Լ� : ��� �ɹ��� move�� �Űܾ� �Ѵ�.
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

// �˰��� �����
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
	T tmp = std::move(a);		// move������ ����� �ʾƵ� ����������� ȣ���Ͽ� swap�� �����Ѵ�.
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