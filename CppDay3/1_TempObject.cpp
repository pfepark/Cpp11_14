// "3����"
// 1_�ӽð�ü.cpp - ���� 1-6 rvalue.

#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b)
	{
		std::cout << "Point()" << std::endl;
	}

	~Point()
	{
		std::cout << "~Point()" << std::endl;
	}
};


int main()
{
	//Point p(1, 2);	// �̸� �ִ� ��ü.. ��({})�� ������ �Ҹ�ȴ�.

	// unnamed object
	//Point(1, 2);	// Ŭ���� �̸�() : �ӽ� ��ü, �Ҹ��ڰ� �Ҹ��� ������ �����ݷ�;�� ��������. �̸��� ���� ��ü�̹Ƿ� �ٷ� �ı�

	Point(1, 2), std::cout << "X" << std::endl;		// Point() X ~Point() �� ����� ��µ�.

	std::cout << "------------" << std::endl;

	return 0;
}
