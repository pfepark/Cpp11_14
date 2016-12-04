// "3����"
// 1_�ӽð�ü.cpp - ���� 1-6 rvalue.

#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b)
	{
		std::cout << "Point()" << std::endl;
	}

	~Point()
	{
		std::cout << "~Point()" << std::endl;
	}

	Point(const Point& p)
	{
		std::cout << "copy ctor" << std::endl;
	}
};

// �ӽð�ü�� �Լ� ����

Point p(0, 0);		// ���� ����

//Point foo()		// ������ : �ӽð�ü�� ���ϵȴ�.
Point& foo()		// �������� : ���Ͽ� �ӽð�ü�� ������ ����� �ǹ�.
{						// ����, ���������� ���������ϸ� �ȵȴ�.
	return p;
}

int main()
{

	foo().x = 10;		// 

	std::cout << p.x << std::endl;
}
