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
	
	// setter �����
	//void SetData(Data d) { data = d; }
	//void SetData(const Data& d) { data = d; }

	//����� move�� ��� �����ϴ� setter ����� 
	//   1. �Լ� �����ε�
	//void SetData(const Data& d) { data = d; }				// ���� 1ȸ
	//void SetData(Data&& d)		{ data = std::move(d); }	// move 1ȸ

	// call by value�� ���?
	void SetData(Data d) { data = std::move(d); }
					// ����� ������ : ����1ȸ, move 1ȸ
					// move�� ������ : move 2ȸ
};


int main()
{
	Test t1;
	Data d1, d2;

	// ����� move�� ��� �����ϴ� setter
	t1.SetData(d1);				// d1�� �����Ŀ��� ��� ����ϰڴٴ� ��
	t1.SetData(std::move(d2));	// d2�� �����Ŀ��� ������� �ʰڴٴ� ��
}