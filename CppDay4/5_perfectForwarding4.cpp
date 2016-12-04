template<typename T> struct identity // 이건 클래스 템플릿이므로..명시적으로 사용해야함.
{
	typedef T Type;
};

// 아래 함수는 왜 인자를 이렇게 만들었을까요?
// foo를 사용할때 반드시 명시적으로 타입을 지정해야 한다는 의미입니다.
// 암시적으로 사용하면 컴파일 에러 발생..
template<typename T> void foo(typename identity<T>::Type a)	// foo(T a)와 의미는 동일합니다.
{

}

int main()
{
	foo<int>(3);	// ok
	//foo(3);		// error
}