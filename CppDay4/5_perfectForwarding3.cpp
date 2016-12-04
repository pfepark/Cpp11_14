template<typename T>
class List
{
public:
	List(int sz, T value)
	{

	}
};

template<typename T> void foo(T a)
{

}

int main()
{
	// 함수 템플릿은 암시적/명시적 인스턴스화가 모두 가능하다.
	foo<int>(3);	// ok
	foo(3);			// ok

	// 클래스 템플릿은 명시적 인스턴스화만 가능하다.
	List<int> s1(10, 3);
	List s2(10, 3);
}