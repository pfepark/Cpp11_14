// ����ǥ������ �Լ����� �޴� ���
#include <functional>

void foo( int(*f)(int, int) )	// 1. �Լ� ������, �ζ��� ġȯ �ȵ�.
{

}

void foo(std::function<int(int, int)> f)	// 2. STL function �ζ��� ġȯ �ȵ�.
{

}

// ���� auto�� �Լ� ���� Ÿ������ ���� �� ����.
void foo(auto f)
{

}

template<typename T>		//3.ok �ζ��� ġȯ��
void foo(T f)
{

}

int main()
{
	foo([](int a, int b) {return a + b; });
}