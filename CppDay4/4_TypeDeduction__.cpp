//

// 규칙 1. 값타입 : 인자가 가진 const, volatile, reference를 모두 제거 하고 T결정
//					lvalue, rvalue 모두 받을 수 있다. 하지만 원본이 아닌 복사본이다.!!

template<typename T> void foo(T a) {}


// 규칙 2. 참조타입(lvalue reference)
//						: 인자가 가진 const, volatile은 유지하고 reference만 제거하고 T결정
//						lvalue 만 받을 수 있다.

template<typename T> void foo(T& a) {}


// 규칙 3. forward reference 일때
//						: 인자가 lvalue이면 T는 lvalue 참조로 결정, 그리고 규칙2 적용
//								rvalue이면 T는 값타입 결정,			그리고 규칙1 적용

template<typename T> void foo(T&& a) {}

// 주의 .. 템플릿 만들때
template<typename T> void goo(T& a) {}		// 인자로 lvalue만 허용
template<typename T> void goo(T&& a) {}		// 인자로 lvalue, rvalue 모두 가능하게...

int main()
{
	int n = 10;
	foo(n);
	foo(10);
}