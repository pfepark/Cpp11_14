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
// Rule of 3 : �Ҹ���, ���� ������, ���Կ�����
// Rule of 5 : �Ҹ���, ���� ������, ���Կ�����, move ������, move ���Կ�����

// ��Ģ 1. 5���� �Լ��� ��� ������ ������ �����Ϸ��� ������ �ش�.
//      2. ���� �迭�� �Լ��� �����ϸ�..move�迭�� �ڵ��������� �ʴ´�. ���� ���� ����� ���������� �����Ϸ��� move�� ������ټ�����..
//      3. move �迭�� �Լ��� �����ϸ�..����迭�� �ڵ��������� �ʴ´�. move�� ����� �� ����.
//			�ݵ�� ����ڰ� ���� ���� �迭�� �����ؾ� �Ѵ�.
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