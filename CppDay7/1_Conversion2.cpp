class Vector
{
public:
	// explicit 생성자 : 인자 하나짜리 생성자가 암시적 변환을 일으키는 것을 막는다.
	explicit Vector(int sz) {}
};

void foo(const Vector& v) {}

int main()
{
	Vector v(10);
	foo(v);		// ok

	foo(10);	// ?? 인자를 잘못보냈다. 그런데..
				// 10(int) => Vector로 암시적 변환되면 된다.
}