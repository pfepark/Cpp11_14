// 지연된 인스턴스화 lazy instantiation

/*
class A
{
	int data;
public:
	void foo(int a)
	{
		*a = 10;	// error
	}
};
*/

// 사용하지 않은 함수 템플릿은 실제 C++ 코드로 생성되지 않는다.
template<typename T>
class A
{
	T data;
public:
	void foo(T a)
	{
		*T = 10;	// error
	}
};

int main()
{
	A<int> a;		// why? template은 class틀. foo를 호출한 적이 없으므로 아직 만들지 않았다.
					// 맴버변수 data는 만들어진다. 메모리 크기를 알아야하므로..

	a.foo(0);		// 사용했으므로 template에서 실제 클래스를 만들때
					// foo도 포함된다.
}