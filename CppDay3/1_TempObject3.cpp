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
};

// �ӽð�ü�� �Լ� ����
void foo(const Point& p)
{

}

int main()
{
	//Point p(1, 2);
	//foo(p);

	foo(Point(1, 2));	// �ӽð�ü�� ���� �Լ����� ����.
						// ��, foo������ �ݵ�� cosnt &�� �޾ƾ� �Ѵ�.

	std::cout << "----------" << std::endl;
}
