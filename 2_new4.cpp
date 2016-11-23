#include <iostream>
#include <vector>

std::vector<int> a;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// 힙에 Point 한개를 만들어 보세요
	Point* p1 = new Point(0, 0);

	// 힙에 Point 10개를 만들어 보세요
	//Point* p2 = new Point[10];

	// 메모리 할당과 생성자 호출을 분리하자.
	Point* p2 = static_cast<Point*>(operator new (sizeof(Point) * 10));

	// 이미 존재하는 메모리에 객체를 생성한다.
	for (int i = 0; i < 10; i++)
	{
		new (&p2[i]) Point(0, 0);	// placement new
	}

	// ------
	// 이제 p2 사용
	// STL의 vector가 내부적으로 버퍼를 만들때 위처럼
	// 메모리 할당과 생성자 호출을 분리하고 있다.
}