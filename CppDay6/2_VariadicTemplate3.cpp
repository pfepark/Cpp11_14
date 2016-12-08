#include <iostream>

// step 3. �������� ���޵� ���� ������

// �ٽ� : ���� ���� ���ø����� �Լ�(Ŭ����)���ø��� ���鶧, 1��° ���ڴ� �ݵ�� ������ Ÿ������ �޾ƾ� �Ѵ�.
template<typename T, typename ... Types> void foo(T value, Types ... args)
{
	static int n = 0;
	n++;
	std::cout << n << " : ";
	std::cout << typeid(T).name() << " : " << value << std::endl;

	foo(args...);		// foo(4.5, "hello") value : 4.5, args : "hello"
						// foo("hello")
						// foo()		// �Լ��� �������� ������ŭ ��������Ƿ� �����ʿ�
}

// ��͸� �����ϱ� ���� ���� ���� �Լ� �ʿ�.
void foo() {}

int main()
{
	foo(3, 4.5, "hello");	// value : 3, args : 4.5, "hello"
}