int main()
{
	int v1, v2;

	auto f1 = [=](int a) { return a + v1 + v2; };
	auto f2 = [&](int a) { return a + v1 + v2; };

	auto f3 = [v1](int a) { return a + v1 + v2; };	// v1�� ĸ��(��)
	auto f4 = [&v1](int a) { return a + v1 + v2; };	// v1�� ĸ��(����)

	// ��� ���������� ��, v1�� ����
	auto f5 = [=, &v1](int a) { return a + v1 + v2; };

	// ��� ���������� ����, v1�� ��
	auto f6 = [&, v1](int a) { return a + v1 + v2; };

	//auto f6 = [&, &v1](int a) { return a + v1 + v2; };	// error �տ� ����Ʈ ĸ�ĸ� ����ϰ� ������ ���ٸ� ������ ����
}