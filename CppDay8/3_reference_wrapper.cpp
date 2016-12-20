#include <iostream>

// C++ 참조 : 대입연산시 값이 이동한다. 한번 초기화된 참조는 변경할 수 없다.
// reference_wrapper : 대입연산시 참조가 이동한다.이동 가능한 참조
int main()
{
	int n1 = 10;
	int n2 = 20;

	//int& r1 = n1;
	//int& r2 = n2;

	std::reference_wrapper<int> r1 = n1;
	std::reference_wrapper<int> r2 = n2;

	r1 = r2;		// 참조의 이동? 값의 이동

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
	std::cout << r1 << std::endl;
	std::cout << r1 << std::endl;
}