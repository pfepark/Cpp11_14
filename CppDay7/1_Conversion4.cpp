// Safe Bool 이라는 개념 - Boost에 있는 개념
class File
{
public:
	File(const char* s) {}

	//operator bool() { return true; }	// 성공/실패 여부를 조사해서 리턴
	//operator void*() { return this; }	// 실패시 0 리턴

	void true_function() {}	// 주소만 사용하기 위해 만든 함수
	typedef void(File::*PF)();
	operator PF() { return &File::true_function; }		// 맴버 함수 포인터로의 변환. 맴버 함수는 delete되지 않는다.
};

int main()
{
	File f("a.txt");

	// 파일 Open이 성공했는지 알고 싶다.
	if (f) {}	// 객체를 if()로 test => scalar test

	//int a = f + 1;	//f는 bool로 변환되어 +이 된다. 이렇게 하면 안됨. 그래서 operator void*()

	//delete f; // 하면 어떻게 하나...void*로 변환되어 컴파일이 잘됨.

}