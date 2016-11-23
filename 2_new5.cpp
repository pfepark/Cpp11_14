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

	v.shrink_to_fit();	// capacity�� size�� �����.

	std::cout << v.size() << std::endl;		// 6
	std::cout << v.capacity() << std::endl;	// 6

	// DBConnnect class �� �����ڿ��� db�� �����Ѵٰ� ����.
	std::vector<DBConnect> v2(10);
	v2.resize(7);		// �پ�� 3���� ��ü�� �޸𸮿� ������.. �Ҹ��ڸ� ȣ���ؼ� db�� �ݾƾ� �Ѵ�.
						// �Ҹ����� ����� ȣ���� �ʿ��� ��Ȳ..

	v2.resize(8);		// �þ �ϳ��� ��ü�� ���� �޸𸮴� �̹� �����Ѵ�.
						// ������ �����ڸ� �ٽ� ȣ���ؼ� db�� �����ؾ� �ϹǷ� �������� ����� ȣ���� �ݵ�� �ʿ�.
}