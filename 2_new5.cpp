#include "stdafx.h"
#include <iostream>
#include <vector>

class DBConnect
{

};

int main()
{
	std::vector<int> v(10);

	v.resize(5);

	std::cout << v.size() << std::endl;		// 5
	std::cout << v.capacity() << std::endl;	// 10

	v.push_back(1);

	std::cout << v.size() << std::endl;		// 6
	std::cout << v.capacity() << std::endl;	// 10

	v.shrink_to_fit();	// capacity와 size를 맞춰라.

	std::cout << v.size() << std::endl;		// 6
	std::cout << v.capacity() << std::endl;	// 6

	// DBConnnect class 는 생성자에서 db에 접속한다고 가정.
	std::vector<DBConnect> v2(10);
	v2.resize(7);		// 줄어든 3개의 객체는 메모리에 있지만.. 소멸자만 호출해서 db를 닫아야 한다.
						// 소멸자의 명시적 호출이 필요한 상황..

	v2.resize(8);		// 늘어난 하나의 객체를 위한 메모리는 이미 존재한다.
						// 하지만 생성자를 다시 호출해서 db에 접속해야 하므로 생성자의 명시적 호출이 반드시 필요.
}