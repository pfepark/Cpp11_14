// rvalue�� ���� ����

int main()
{
	int n = 10;

	// ��Ģ 1. �Ϲ� ������ lvalue�� ������ �� �ִ�.
	int& r1 = n;	// ok
	int& r2 = 10;	// error

	// ��Ģ 2. ��� ������ lvalue�� rvalue�� ��� ������ �� �ִ�.
	//			��, ������� �߰��ȴ�.
	const int& r3 = n;	// ok
	const int& r4 = 10;	// ok
	//	const Point& r = Point(1, 2); //ok

	// ��Ģ 3. C++11 rvalue reference�� rvalue�� ������ �� �ִ�.
	int&& r3 = n;	// error
	int&& r4 = 10;	// ok
}