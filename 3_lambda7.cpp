// 3_람다표현식7

#include <iostream>

int g = 0;

int main()
{
	int v1 = 10;
	int v2 = 10;

	auto f1 = [](int a) { return a + g; };	// 전역변수 사용. ok

	//auto f2 = [](int a) { return a + v1 + v2; };	// 지역변수 사용. error
	
	// [=] : acapture variable by value
	//auto f2 = [=](int a) { return a + v1 + v2; };	// ok
	//auto f3 = [=](int a) { v1 = 20; };	// error. 쓰기는 안됨


	//-----------------------------------------------------
	//auto f4 = [=](int a) { v1 = 20;  return a + v1 + v2; };	// error
	// mutable 람다 : () 연산자를 비상수 함수로 만들어 달라는 의미.
	auto f4 = [=](int a) mutable { v1 = 20;  return a + v1 + v2; };	// ok

	f4(0);	// v1 = 20이 실행되었지만 복사본 변경
	std::cout << v1 << std::endl;	// 10

	std::cout << sizeof(f4) << std::endl;	// 8. 아래보면 맴버변수 int형 2개.

	// 위 한줄의 정확한 원리!! 35page
	/*
	class LambdaClass
	{
		int v1;
		int v2; //지역변수의 값을 캡쳐(보관)하기 위한 맴버 변수

	public:
		LambdaClass(int a, int b) : v1(a), v2(b) {}
		inline int operator()(int a) const	// 상수 함수이다!!!!
		{
			return a + v1 + v2;
		}
	};

	auto f4 = LambdaClass(v1, v2);	//지역변수를 클로져객체(람다가 만드는 임시객체)로 전달
	*/
}