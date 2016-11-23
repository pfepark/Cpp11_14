#include "stdafx.h"

#include <iostream>

// ��� �ɹ� �Լ� - C++98 �����̾߱�

class Point
{
public:
	int x = 0, y = 0; // C++11 ���� �̷��� ��밡��

	void set(int a, int b) { x = a; y = b; }
	void print() const	// ��� �ɹ� �Լ�.
	{
		// �Լ��ȿ� �ɹ������� ��� ���
		//x = 10;	// error
		std::cout << x << ", " << y << std::endl;
	}
};

int main()
{
	const Point p;
	p.x = 10;		// error. p�� ����̴�.
	p.set(10, 20);	// error.
	p.print();		// ȣ��� �� �ְ� �Ϸ��� print()�� ��� �Լ��̾�� �Ѵ�.
					// "�����ü�� ��� �Լ��� ȣ���� �� �ִ�." �����Ϸ� ���忡�� ����θ� ���⿡..
}