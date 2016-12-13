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
	// �ǵ����̸� move �迭 �Լ��� ���鶧�� ���ܰ� ������ �����Ϸ����� �˷��� �Ѵ�.
	// ��κ��� C++ �����Ϸ��� STL�� ���ܰ� �������� move�� ����Ѵ�.
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

	//v.resize(10);		// ���۸� 10���� �÷��� �Ѵ�. VC++������ moveȣ��. ���ܰ� ������ �����ؾ� move�� ȣ��. g++������ �����Ѵ�.
/*
	Data d1;
	Data d2 = d1;	// ����
	Data d3 = std::move(d1);	// move
	Data d4 = std::move_if_noexcept(d2);		// ���ܰ� �������� move
	*/
	Data d5 = Data("adf");
}