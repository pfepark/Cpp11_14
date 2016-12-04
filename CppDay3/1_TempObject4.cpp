// "3일차"
// 1_임시객체.cpp - 교재 1-6 rvalue.

#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b)
	{
		std::cout << "Point()" << std::endl;
	}

	~Point()
	{
		std::cout << "~Point()" << std::endl;
	}

	Point(const Point& p)
	{
		std::cout << "copy ctor" << std::endl;
	}
};

// 임시객체와 함수 리턴
Point foo()
{
	// NRVO ( Named RVO ) : 이름있는 객체도 컴파일러가 RVO해줄 수 있다는 의미
	Point p(1, 2);
	return p;		// 리턴용 임시객체가 생성된다.
					//return temp(p);	이후 p는 파괴되고 temp가 리턴. 복사생성자 호출.

	// 만들고 리턴하지 말고.. 만들면서 리턴하자.
	//return Point(1, 2);			// 임시객체를 사용한 리턴.
								// RVO (Return Value Optimization)이라는 기술.

	// 최근 컴파일러는 릴리즈에서 위,아래 차이 없이 최적화를 해준다.
}

int main()
{
	Point p1(0, 0);

	p1 = foo();		// foo에서 만들어진 임시객체는 여기서 ;를 만나 파괴된다.

	std::cout << "----------" << std::endl;
}
