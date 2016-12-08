// typename

class AAA
{
public:
	//static int DWORD = 10;
	typedef int DWORD;
};

int p = 0;

// template 안에 typedef 된 타입을 꺼내 사용할때는 반드시 typename이 필요하다.

template<typename T> typename T::DWORD foo(T a)
{
	typename T::DWORD * p;	// 이 한줄을 해석하시오.
					// 1. DWORD는 static 맴버 data인데 , 곱하기 p하고 있다. (표준에서는 이것으로 본다.)
					// 2. DWORD는 typedef되어 있는데 포인터 변수 p를 선언하고 있다. (선언에서 typename을 붙여아한다)

	return 0;
}

int main()
{
	AAA aaa;
	foo(aaa);
}