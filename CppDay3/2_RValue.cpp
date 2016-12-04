#include <iostream>

int x = 10;
int	 foo() { return x; }
int& goo() { return x; }

// lvalue : =의 왼쪽과 오른쪽에 모두올 수 있다. 
//			이름이 있다. 단일식을 넘어서 메모리에 존재.
//			참조를 리턴하는 함수
//			주소연산자로 주소를 구할 수 있다.

// rvalue : =의 오른쪽에만 올 수 있다.
//			이름이 없다. 단일식에서만 사용.
//			값을 리턴하는 함수
//			주소연산자로 주소를 구할 수 없다.
//			임시객체, literal
int main()
{
	int v1 = 10;
	int v2 = 20;

	v1 = 10;
	//10 = v2;	// error
	v2 = v1;

	//foo() = 20;	// error
	goo() = 20;	// ok.
	std::cout << &v1 << std::endl;
	//std::cout << &10 << std::endl;

	const int c = 10;
	//c = 20;		// error. c는 nonmodified lvalue.

	// rvalue는 상수이다. ?
	Point(1, 2).x = 10;		// error
	Point(1, 2).Set(10, 20)	// ok. 임시객체라도 멤버 함수를 호출해서 값을 변경 할 수 있다.
							// 그러므로 rvalue가 모두 상수인 것은 아니다.
}