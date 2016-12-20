#include <iostream>
#include <memory>

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	static void* operator new(size_t sz)
	{
		return malloc(sz);
	}

	static void operator delete(void* p)
	{
		free(p);
	}
};

void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

int main()
{
	// 아래 코드는 메모리를 몇번 할당할까요?
	//std::shared_ptr<Point> p1(new Point(1, 2));

	// sizeof(Point) + sizeof(관리객체) 를 한번에 메모리 할당하는 함수
	std::shared_ptr<Point> p1 = std::make_shared<Point>(1, 2);	// Point(1,2)로 객체를 만들어달라.
	//std::shared_ptr<Point> p2 = p1;
}

/*
// make_shared의 원리
template<typename T, typename ..Types>
shared_ptr<T> Make_shared(Types&&... args)
{
	// 1. 메모리 할당
	void* p = operator new(sizeof(T) + sizeof(관리객체));

	// 2. 할당한 메모리 앞부분은 객체이다. 생성자를 호출해야 한다.
	new (p) T(args...);

	// 3. 관리 객체도 초기화하고

	// 4. shared_ptr을 만들어서 리턴한다.
	shared_ptr<T> sp;
	sp._set(p, (char*)p + sizeof(T));

	// 3. 
}
*/