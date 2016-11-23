#include "stdafx.h"

#include <iostream>

// malloc	: �޸� �Ҵ�
// new		: ��ü ���� (�޸� �Ҵ� + ������ ȣ��) -> ������ ȣ���� �� ū��...�������� ���� �����ڿ��� �� �� �ִ�.

// new Point : ���ο� �޸𸮿� ��ü�� ������ �޶�
// new(&p) Point : �̹� �����ϴ� �޸𸮿� (&p) ��ü�� ������ �޶�.

class Point
{
	int x, y;

public:
	Point() { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// �߿�!
// Placement new (��ġ ���� new) : �����ڸ� ��������� ȣ���ϱ� ���� ���� ��.
/* �̹� ǥ�ؿ� �����Ƿ� �Ʒ� �ڵ�� placement new �� ȣ���ϸ� ��������� �����ڸ� ȣ���� �� �ִ�. (C++ 98)
void* operator new(size_t sz, Point* p)
{
	return p;
}
*/

int main()
{
	Point p;

	// new Point;	// ���ڰ� 1���� operator new() ȣ��

	new (&p) Point;	// ���� operator new() ȣ��
					// new�� 3���� ���� ù��° �޸� �Ҵ��� ������ ������(�� �ּ� �״�� ����, 0�� �ƴ�)
					// ���� �̾ �����ڸ� ȣ���Ѵ�. �� ������ ĳ���� �ϰ���...

	//p.Point();	// error �����ڴ� ����� ȣ��ȵ�.
	p.~Point();		// ok. �Ҹ��ڴ� ����� ȣ�Ⱑ��.
}