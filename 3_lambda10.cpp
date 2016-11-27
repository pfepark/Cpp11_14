#include <iostream>

void goo(int a, int b)
{
	int c;
	auto f = [=]() {return a + b + c; };	//ok

	std::cout << sizeof(f) << std::endl;	// 12
}

// 35page
class Test
{
	int data;
public:
	void foo()	// void foo(Test* this)
	{
		// 맴버 data접근
		//auto f = [](int a) { return data; };	// error
		//auto f = [data](int a) { return data; };	// error. data는 지역변수 아님

		//auto f = [=](int a) { return this->data; };	// ok 모든 지역변수 켭쳐인데 지역변수중 this 캡쳐.
		//auto f = [this](int a) { return data; };	// ok.. this만 캡쳐

		auto f = [=](int a) { data = 30; };	// 될까요?? 됨.
		// this 캡쳐시 컴파일러가 생성하는 코드를 예측해보세요

		f(0);	// 맴버 변수 data 원본 변경

		std::cout << data << std::endl;	// 30

		auto f1 = [this](int a) { data = 30; };	// 역시 원본 변경
		// C++17 부터는 *this 캡쳐 가능
		//auto f2 = [*this](int a) mutable { data = 30; };	// 복사본 변경?
	}
};


int main()
{
	Test t;
	t.foo();	// foo(&t)
}