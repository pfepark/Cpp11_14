#include <functional>

// ����ǥ������ ��� ���� - 31page
int main()
{
	auto f1				= [](int a, int b) { return a + b; };

	int(*f2)(int, int)	= [](int a, int b) { return a + b; };
						// class LambdaClass{}; LambdaClass();

	// 3. STL�� function
	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; };

	// �Ʒ� �ڵ���� �ζ��� ġȯ���� �����غ�����
	f1(1, 2);	// �ζ��� ġȯ
	f2(1, 2);	// ġȯ �ȵ�.
	f3(1, 2);	// ġȯ �ȵ�. ����Ű�� ���� �ٲ� �� ����
}