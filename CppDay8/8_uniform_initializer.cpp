// 8_uniform_initializer

struct Point { int x, y; };

class Complex
{
	int re, im;
public:
	Complex(int a, int b) : re(a), im(b) {}
};

int main()
{
	/*
	int n1 = 0;
	int n2(0);
	int x[3] = { 1,2,3 };
	Point p = { 1, 2 };
	Complex c( 1,2 );
	*/

	// 모든 종류의 객체를 동일한 방법으로 초기화 하자. - uniform initializer (일관된 초기화)
	int n1{ 0 };
	int n2{ 0 };
	int x[3]{ 1,2,3 };
	Point p{ 1, 2 };
	Complex c{ 1, 2 };

	int _n1 = { 0 };
	int _n2 = { 0 };
	int _x[3] = { 1,2,3 };
	Point _p = { 1, 2 };
	Complex _c = { 1, 2 };

	int n3{ 3.4 };	// error
	char ch{ 300 };	// error
}