// 완벽한 전달자의 장점
#include <vector>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b)
	{
		std::cout << "Point()" << std::endl;
	}

	~Point()
	{
		std::cout << "~Point()" << std::endl;
	}
};

int main()
{
	std::vector<Point> v;

	// vector에 요소넣기
	//Point p(1, 2);
	//v.push_back(p);

	// 2. 임시객체로 넣기. 임시객체 소멸, 복사된 객체 소멸. 2번 소멸자 호출. 생성자는 생성자 한번, 복사생성자 한번.
	//v.push_back(Point(1, 2));

	// 3. Point를 만들기 위한 인자만 보내서 vector가 Point를 만들게 하자.
	v.emplace_back(1, 2);	// 단, 인자는 Point 생성자로 완벽하게 전달되어야 한다.
}