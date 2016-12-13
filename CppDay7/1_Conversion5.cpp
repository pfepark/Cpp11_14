// Safe Bool 이라는 개념 - Boost에 있는 개념
class File
{
public:
	File(const char* s) {}

	// C++ 11 : 변환 연산자 앞에도 explicit를 붙일 수 있습니다.
	//			명시적 변환만 허용하고 암시적 변환은 불가능
	// 단, if 문에 객체를 넣을 때는 암시적 변환 허용
	explicit operator bool() { return true; }
	
};

int main()
{
	File f("a.txt");

	bool b = f;						// error 암시적 변환은 허용되지 않음.
	bool b = static_cast<bool> (f);	// ok

	if (f) {}				// 암시적 변환은 안되지만 if에서는 예외적으로 암시적 변환 허용

}