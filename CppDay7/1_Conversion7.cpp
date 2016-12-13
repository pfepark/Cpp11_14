#include <iostream>

void foo(int n) { std::cout << "int" << std::endl; }
void foo(void* n) { std::cout << "void*" << std::endl; }
void goo(char* n) { std::cout << "void*" << std::endl; }

// ������ 0�� ������.
struct xnullptr_t
{
	// void*���� ����ȯ �ʿ�
	template <typename T>
	operator T*() { return (T*)0; }
	explicit operator bool() { return false; }
};

xnullptr_t xnullptr;

int main()
{
	foo(0);	// 0�� �����ͷ� ��ȯ�Ǳ⵵ ������ ��Ȯ���� int�̴�.
	foo(xnullptr);	// void* ���� ȣ��
	goo(xnullptr);
}