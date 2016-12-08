// 1_맴버함수 템플릿, 81page

// 1. 아래 Complex를 템플릿으로 하는 이유... double로 해도 되지만 성능저하
// 2. T a = T() : zero initialize
//				T 가 primitive 또는 포인터이면 0,
//				사용자 타입이면 디폴트 생성자로 초기화
template<typename T> class Complex
{
	T re, im;
public:
	Complex(T a = T(), T b = T()) : re(a), im(b)
	{

	}

	// 복사 생성자 generic 복사생성자..
	// "U가 T로 복사(대입)될 수 있다면, Complex<U>는 Complex<T>로 복사(대입)될 수 있어야 한다."
	template<typename U> Complex(const Complex<U>& c);

	// 모든 종류의 Complex는 친구이다.
	template<typename U> friend class Complex;
};

// template 클래스의 맴버 함수 템플릿의 외부 구현
template<typename T> template<typename U>
Complex<T>::Complex(const Complex<U>& c) : re(c.re), im(c.im)
{}

int main()
{
	Complex<int> c1(1, 2);

	Complex<int> c2 = c1;		// 복사 생성자. 컴파일러 제공버전이면 ok.

	Complex<double> c3 = c1;	// c1, c3는 서로 다른 타입. private에 접근이 안되므로 friend 선언으로 처리.


	// 스마트 포인터를 생각해봅시다.
	std::shared_ptr<Dog> p1(new Dog);
	std::shared_ptr<Animal> p2 = p1;

	// 복사 가능한 스마트 포인터는 기본적으로
	// 복사 생성자, 대입연산자, ==, != 의 template 버전이 제공되어야 한다.
}