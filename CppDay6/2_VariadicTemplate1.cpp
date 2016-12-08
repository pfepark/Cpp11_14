// 2_가변인자 템플릿 - C++11 추가문법

// 가변인자 클래스 템플릿
template<typename ...T> class tuple {};

// 가변인자 함수 템플릿
template<typename ... T> void foo(T ... a) {}

int main()
{
	tuple<> t0;
	tuple<int, double, char> t;

	foo(10);
	foo();
	foo(10, "all", 4.5f);
}