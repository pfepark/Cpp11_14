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
Point foo()
{
	// NRVO ( Named RVO ) : �̸��ִ� ��ü�� �����Ϸ��� RVO���� �� �ִٴ� �ǹ�
	Point p(1, 2);
	return p;		// ���Ͽ� �ӽð�ü�� �����ȴ�.
					//return temp(p);	���� p�� �ı��ǰ� temp�� ����. ��������� ȣ��.

	// ����� �������� ����.. ����鼭 ��������.
	//return Point(1, 2);			// �ӽð�ü�� ����� ����.
								// RVO (Return Value Optimization)�̶�� ���.

	// �ֱ� �����Ϸ��� ������� ��,�Ʒ� ���� ���� ����ȭ�� ���ش�.
}

int main()
{
	Point p1(0, 0);

	p1 = foo();		// foo���� ������� �ӽð�ü�� ���⼭ ;�� ���� �ı��ȴ�.

	std::cout << "----------" << std::endl;
}
