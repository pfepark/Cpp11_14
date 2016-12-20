#include <iostream>

/*
int n = 0;
const int* p1 = &n;	// p1�� ���󰡸� const�� �ִ�. p1�� const�� �ƴϴ�.
int* const p2 = &n; // p2�� const�̴�.
int const* p3 = &n; // p1�� ����.
*/
// �ٽ� : �����Լ� �����ǽ� �Ǽ��� ���� ���ؼ� override�� ǥ������.
template<typename T> class Base
{
public:
	// �Ʒ� �ڵ�� 'a�� const�̴�.
	//virtual void foo(const T a)
	virtual void foo(T const a)		// �� �Ʒ� ���� �ڵ��ε� �Ʒ� �����ǽ� int*�� ���̸� �Ǵ�... const�� �ڿ� �����ڴ� �ǰߵ� ����.
	{
		std::cout << "Base foo" << std::endl;
	}
};

class Dericed : public Base<int*>
{
public:
	// foo ������ �ؼ� Derived foo ����غ�����.
	// a�� ���󰡸� const�̴�.
	//virtual void foo(const int* a) override
	virtual void foo(int* const a) override
	{
		std::cout << "Derived foo" << std::endl;
	}
};

int main()
{
	Base<int*>* p = new Dericed;
	p->foo(0);		// "Derived foo" ������ �غ�����.
}