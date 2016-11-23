#include <iostream>
#include <vector>

std::vector<int> a;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// ���� Point �Ѱ��� ����� ������
	Point* p1 = new Point(0, 0);

	// ���� Point 10���� ����� ������
	//Point* p2 = new Point[10];

	// �޸� �Ҵ�� ������ ȣ���� �и�����.
	Point* p2 = static_cast<Point*>(operator new (sizeof(Point) * 10));

	// �̹� �����ϴ� �޸𸮿� ��ü�� �����Ѵ�.
	for (int i = 0; i < 10; i++)
	{
		new (&p2[i]) Point(0, 0);	// placement new
	}

	// ------
	// ���� p2 ���
	// STL�� vector�� ���������� ���۸� ���鶧 ��ó��
	// �޸� �Ҵ�� ������ ȣ���� �и��ϰ� �ִ�.
}