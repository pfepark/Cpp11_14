#include <algorithm>
#include <functional>	// less<>, greater<> ���� �Լ���ü�� ����

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// 1. �Լ��� ����� ��å ����
	std::sort(x, x + _countof(x), cmp1);

	// 2. �Լ���ü�� ����� ��å ����
	std::less<int> f;
	std::sort(x, x + _countof(x), f);

	// 3. C++11�� ���� ǥ������ ����� ��å ����
	// [] : Lambda introducer
	std::sort(x, x + _countof(x), [](int a, int b) {return a < b; });

	// �� ������ �����Ϸ��� �Ʒ� �ڵ带 ����
	class LambdaClass
	{
	public:
		inline bool operator()(int a, int b) const	// ����Լ�!!
		{
			return a < b;
		}
	};

	//LambdaClass closure;
	//std::sort(x, x + _countof(x), closure);
	std::sort(x, x + _countof(x), LambdaClass()); // ClassName() : �ӽð�ü ����
}
