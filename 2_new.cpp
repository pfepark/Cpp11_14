#include "stdafx.h"

#include <iostream>

// 2_new.cpp
// new ��Ȯ�� ���� ���
// 1. operator new() �Լ��� ����ؼ� �޸� �Ҵ�
// 2. 1�� �����ϰ� ����� Ÿ���̸� ������ ȣ��
// 3. �޸� �ּҸ� �ش� Ÿ������ ĳ�����ؼ� ����
class Point
{
	int x, y;

public:
	Point() { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	// ������ ȣ����� �޸𸮸� �Ҵ��ϴ� �ڵ�.
	Point* p1 = static_cast<Point*>(operator new(sizeof(Point)));

	operator delete(p1);
	//Point* p1 = new Point();	// new�� keyword�� 3���� ���� �Ѵ�.
	//delete p1;
}