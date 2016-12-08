// 템플릿 부분 전문화 2

#include <iostream>

template<typename T, typename U>
struct Test
{
	void foo() { std::cout << "T, U" << std::endl; }
};

template<typename T, typename U>
struct Test<T*, U*>
{
	void foo() { std::cout << "T*, U*" << std::endl; }
};

// primary 버전의 템플릿인자가 2개라도 부분전문화시에는 다를 수 있다.
// 단 Test<T, T> 처럼 뒷부분은 반드시 2개로 표현되어야 한다.
template<typename T>
struct Test<T, T>
{
	void foo() { std::cout << "T, T" << std::endl; }
};

template<typename T>
struct Test<T, short>
{
	void foo() { std::cout << "T, short" << std::endl; }
};

template<>
struct Test<char, short>
{
	void foo() { std::cout << "char, short" << std::endl; }
};

int main()
{
	Test<int, double> t1;
	t1.foo();		// "T, U"

	Test<int*, double*> t2;
	t2.foo();		// "T*, U*"

	Test<int, int> t3;
	t3.foo();		// "T, T"

	Test<int, short> t4;
	t4.foo();		// "T, short"

	Test<char, short> t5;
	t5.foo();		// "char, short"
}