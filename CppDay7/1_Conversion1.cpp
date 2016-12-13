// 7����
// conversion

#include <iostream>

// Point => int : ��ȯ�����ڰ� �ʿ�. operator int()
// int => Point : ��ȯ�����ڰ� �ʿ�. Point(int) ������.
class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) : x(a), y(b) {}

	// ��ȯ ������ : ���ڰ� �Ѱ��� ������
	//				�ٸ� Ÿ���� ��ü�� �Ͻ��� ��ȯ �ǰ� �Ѵ�.
	Point(int a) : x(a), y(0) {}

	// ��ȯ ������ �Լ�
	// Ư¡ : ����Ÿ���� ǥ�� ���� �ʴ´�.
	operator int() { return x; }
};

int main()
{
	Point p1;
	Point p2(1, 2);

	int n1 = 0;

	int n = p2;	// p2.operator int() �Լ��� ������ �ȴ�.
	p2 = n1;		// n1.operator Point() �Լ��� ������ �Ǵµ�...
					// n1�� ��ü�� �ƴϴ�.
}