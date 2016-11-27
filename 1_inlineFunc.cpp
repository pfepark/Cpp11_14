// 1_인라인함수.cpp
// cl [파일명] /FAs	/FAs 옵션이 어셈블리 소스를 만들라는 옵션. /Ob1 최적화 옵션

// 장점 : 빠르다.
// 단점 : 목적코드가 커진다.
//		단, 1~2줄의 작은 함수는 목적 코드를 줄이기도 한다.

int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2);
	int n2 = Add2(1, 2);
	return 0;
}