// 1_인라인함수2.cpp

// 1. 인라인 함수는 컴파일 시간 문법이다.
// 2. 인라인 함수라도 함수포인터에 담아서 호출하면 인라인 치환될 수 없다. 
//		(함수포인터로 가르키는 것이 변경가능하므로 컴파일 타임에 알 수 없음)

	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2);		// 호출
	int n2 = Add2(1, 2);		// 치환

	int(*f)(int, int);

	f = &Add2;
	int n3 = f(1, 2);	// 호출? 치환?

	return 0;
}