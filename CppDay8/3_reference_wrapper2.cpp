#include <iostream>

// C++ 참조 : 대입연산시 값이 이동한다. 한번 초기화된 참조는 변경할 수 없다.
// reference_wrapper : 대입연산시 참조가 이동한다.이동 가능한 참조

// 결국 정체는 "참조로 변환 가능한 포인터" 입니다. - 아주 중요한 도구.

template<typename T> class xreference_wrapper
{
	T* obj;
public:
	xreference_wrapper(T& o) : obj(&o) {}

	// 기존 참조 문법과 호환(변환)되게 한다.
	operator T&() { return *obj; }

};

int main()
{
	int n1 = 10;
	int n2 = 20;

	xreference_wrapper<int> r1 = n1;
	xreference_wrapper<int> r2 = n2;

	r1 = r2;		// 참조의 이동? 값의 이동
	
	int& r3 = r1;	// xreference_wrapper과 진짜 참조는 호환된다.

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
	std::cout << r1 << std::endl;
	std::cout << r1 << std::endl;
}