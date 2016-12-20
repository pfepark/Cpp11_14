#include <iostream>
#include <vector>

struct Point3D
{
	int x = 1;
	int y = 2;
	int z = 3;
};

int* begin(Point3D& p) { return &(p.x); }
int* end(Point3D& p) { return &(p.z) + 1; }

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	for (auto n : v)
		std::cout << n << std::endl;

	// �� �ڵ带 ���� �����Ϸ��� �Ʒ� �ڵ带 �����մϴ�.
	for (auto p = begin(v); p != end(v); ++p)
	{
		auto n = *p;
		//--------
		std::cout << n << std::endl;	// ����� �ڵ�
	}

	Point3D p3d;
	
	for (auto a : p3d)
	{
		std::cout << a << std::endl;
	}
}