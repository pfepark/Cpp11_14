#include <iostream>

void foo(int n) { std::cout << "int" << std::endl; }
void foo(void* n) { std::cout << "void*" << std::endl; }
void goo(char* n) { std::cout << "void*" << std::endl; }

int main()
{
	foo(0);	// 0�� �����ͷ� ��ȯ�Ǳ⵵ ������ ��Ȯ���� int�̴�.
	foo((void*)0);	// ������ ���� ȣ��

#define NULL (void*)0

	goo(NULL);
}