typedef int&  LR;
typedef int&& RR;

int main()
{
	int n = 10;

	LR r1 = n;
	RR r2 = 10;

	// reference collapsing 이라고 합니다. && &&의 경우만 &&이다.
	LR& r3 = n;		// int& & => int&
	RR& r4 = n;		// int&& &	=> int&

	LR&& r5 = n;	// int& && => int&
	RR&& r6 = 10;	// int&& && => int&&

	int& & r7 = n;	// error. 사용자가 직접 참조 충돌을 사용하면 안된다.
					// template이 typedef에서 컴파일러가 추론하기 위해 필요
}

template<typedef T> void foo(T& a) {}

foo<int&>(n);	// int& &	=> int&