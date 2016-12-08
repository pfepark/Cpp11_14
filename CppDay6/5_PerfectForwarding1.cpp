int hoo(int a) { return -a; }

void goo(int a, int b) {}

template<typename ... Types>
void foo(Types... args)
{
	//goo(args);	// error args를 다른 곳에 보낼 때는 pack을 풀러서 보내야 한다.

	goo(args...);	// ok

	hoo(arsgs...);	// error. hoo는 인자가 1개이다.

	goo(hoo(args)...);	// ok		...의 위치를 주의깊에 보자.
	//	goo( hoo(args의 첫번째), hoo(args의 두번째))
	goo(hoo(args...));	// error	...의 위치를 주의깊에 보자.
}

int main()
{
	foo(2, 3);
}