int hoo(int a) { return -a; }

void goo(int a, int b) {}

template<typename ... Types>
void foo(Types... args)
{
	//goo(args);	// error args�� �ٸ� ���� ���� ���� pack�� Ǯ���� ������ �Ѵ�.

	goo(args...);	// ok

	hoo(arsgs...);	// error. hoo�� ���ڰ� 1���̴�.

	goo(hoo(args)...);	// ok		...�� ��ġ�� ���Ǳ� ����.
	//	goo( hoo(args�� ù��°), hoo(args�� �ι�°))
	goo(hoo(args...));	// error	...�� ��ġ�� ���Ǳ� ����.
}

int main()
{
	foo(2, 3);
}