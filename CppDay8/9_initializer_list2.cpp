// 9_initializer_list

#include <iostream>
#include <initializer_list>

class Point
{
public:
	explicit Point(int a, int b) { std::cout << "int, int" << std::endl; }								// 1
	//Point(std::initializer_list<int> ini) { std::cout << "initializer_list" << std::endl; }		// 2
};
int main()
{
	// 아래 코드가 각각 어떤 생성자를 호출할지 생각해보세요.
//	Point p1(1, 2);			// 1, 없다면 error
//	Point p2{ 3, 4 };		// 2, 없다면 1번
//	Point p3 = { 5, 6 };	// 2, 없다면 1번

//	Point p4(1,2,3);		// error
//	Point p5{ 1, 2, 3 };	// ok.
//	Point p6 = { 1, 2, 3 };	// ok.	vector<int> v = { 1, 2, 3, 5, 6 };
	Point p7({ 5, 6 });		// 2, 없으면.. 
							// {5, 6} => Point 객체로 암시적 형변환 발생해서 임시객체생성, 복사 생성자로 p7에 복사
							// 암시적 형변환을 막으려면 explicit를 붙이면 된다.

	// C++11/14
	// * 람다, 완벽한 전달자, move, 가변인자 템플릿..
}