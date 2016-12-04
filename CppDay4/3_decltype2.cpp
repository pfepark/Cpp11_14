int main()
{
	int n = 10;
	int* p = &n;
					// 1) int		2) int&
	decltype(p) d1;		//int*
	decltype(*p) d2;	//int&	*p = 2			=등호의 왼쪽에 올 수 있으면 참조타입

	int x[3] = { 1,2,3 };

	decltype(x[0]) d3;	//int&

	decltype(n + n) d4;	//int

	decltype(++n) d6; //int&	++전위는 참조가 리턴된다.
	decltype(n++) d5;	//int
	
	decltype(n = 20) d7;	//int&
}