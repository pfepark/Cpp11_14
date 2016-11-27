int main()
{
	// 람다와 리턴 타입 - 33page

	// 1. 정확한 모양
	auto f1 = [](int a, int b) -> int { return a + b; };

	// 2. 리턴문장이 하나라면 생략 가능.
	auto f2 = [](int a, int b) { return a + b; };

	// 3. 리턴 문장이 2개이상인 경우
	auto f3 = [](int a, int b) { if (a == 1) return a; else return a + b; };

	// 4. 다른 타입일 경우 - 반드시 리턴 타입을 명시해야 한다.
	auto f4 = [](int a, double b) -> double { if (a == 1) return a; else return b; };
}