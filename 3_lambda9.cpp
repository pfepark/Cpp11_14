int main()
{
	int v1, v2;

	auto f1 = [=](int a) { return a + v1 + v2; };
	auto f2 = [&](int a) { return a + v1 + v2; };

	auto f3 = [v1](int a) { return a + v1 + v2; };	// v1만 캡쳐(값)
	auto f4 = [&v1](int a) { return a + v1 + v2; };	// v1만 캡쳐(참조)

	// 모든 지역변수는 값, v1만 참조
	auto f5 = [=, &v1](int a) { return a + v1 + v2; };

	// 모든 지역변수는 참조, v1만 값
	auto f6 = [&, v1](int a) { return a + v1 + v2; };

	//auto f6 = [&, &v1](int a) { return a + v1 + v2; };	// error 앞에 디폴트 캡쳐를 사용하고 다음도 같다면 컴파일 에러
}