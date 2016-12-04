typedef int&  LR;
typedef int&& RR;

int main()
{
	int n = 10;

	LR r1 = n;
	RR r2 = 10;

	// reference collapsing �̶�� �մϴ�. && &&�� ��츸 &&�̴�.
	LR& r3 = n;		// int& & => int&
	RR& r4 = n;		// int&& &	=> int&

	LR&& r5 = n;	// int& && => int&
	RR&& r6 = 10;	// int&& && => int&&

	int& & r7 = n;	// error. ����ڰ� ���� ���� �浹�� ����ϸ� �ȵȴ�.
					// template�� typedef���� �����Ϸ��� �߷��ϱ� ���� �ʿ�
}

template<typedef T> void foo(T& a) {}

foo<int&>(n);	// int& &	=> int&