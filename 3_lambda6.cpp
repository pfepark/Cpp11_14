int main()
{
	// ���ٿ� ���� Ÿ�� - 33page

	// 1. ��Ȯ�� ���
	auto f1 = [](int a, int b) -> int { return a + b; };

	// 2. ���Ϲ����� �ϳ���� ���� ����.
	auto f2 = [](int a, int b) { return a + b; };

	// 3. ���� ������ 2���̻��� ���
	auto f3 = [](int a, int b) { if (a == 1) return a; else return a + b; };

	// 4. �ٸ� Ÿ���� ��� - �ݵ�� ���� Ÿ���� ����ؾ� �Ѵ�.
	auto f4 = [](int a, double b) -> double { if (a == 1) return a; else return b; };
}