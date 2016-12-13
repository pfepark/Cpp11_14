class Test
{
	int value;
public:
	explicit Test(int n) : value(n) {}
};

int main()
{
	// 아래 2줄의 차이점은?
	Test t1(5);		// 1. 인자 한개짜리 생성자 호출
	Test t2 = 5;	// 2. a. 5를 변환생성자를 사용해서 Test 임시객체 생성
					//	  b. 임시객체를 복사 생성자를 사용해서 t2에 복사 (대표적 shared_ptr.. 은 이렇게 안됨)
}