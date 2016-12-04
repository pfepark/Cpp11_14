// �Ϻ��� �������� ����
#include <vector>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b)
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
	std::vector<Point> v;

	// vector�� ��ҳֱ�
	//Point p(1, 2);
	//v.push_back(p);

	// 2. �ӽð�ü�� �ֱ�. �ӽð�ü �Ҹ�, ����� ��ü �Ҹ�. 2�� �Ҹ��� ȣ��. �����ڴ� ������ �ѹ�, ��������� �ѹ�.
	//v.push_back(Point(1, 2));

	// 3. Point�� ����� ���� ���ڸ� ������ vector�� Point�� ����� ����.
	v.emplace_back(1, 2);	// ��, ���ڴ� Point �����ڷ� �Ϻ��ϰ� ���޵Ǿ�� �Ѵ�.
}