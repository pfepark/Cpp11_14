int main()
{
	int n = 10;
	int* p = &n;
					// 1) int		2) int&
	decltype(p) d1;		//int*
	decltype(*p) d2;	//int&	*p = 2			=��ȣ�� ���ʿ� �� �� ������ ����Ÿ��

	int x[3] = { 1,2,3 };

	decltype(x[0]) d3;	//int&

	decltype(n + n) d4;	//int

	decltype(++n) d6; //int&	++������ ������ ���ϵȴ�.
	decltype(n++) d5;	//int
	
	decltype(n = 20) d7;	//int&
}