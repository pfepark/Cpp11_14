// rvalue와 참조 문법

int main()
{
	int n = 10;

	// 규칙 1. 일반 참조는 lvalue만 참조할 수 있다.
	int& r1 = n;	// ok
	int& r2 = 10;	// error

	// 규칙 2. 상수 참조는 lvalue와 rvalue를 모두 참조할 수 있다.
	//			단, 상수성이 추가된다.
	const int& r3 = n;	// ok
	const int& r4 = 10;	// ok
	//	const Point& r = Point(1, 2); //ok

	// 규칙 3. C++11 rvalue reference는 rvalue만 참조할 수 있다.
	int&& r3 = n;	// error
	int&& r4 = 10;	// ok
}