typedef int DWORD;
typedef void(*F)();

// C++11 using
using DWORD = int;
using F = void(*)();

int main()
{
	DWORD n;
	F p;
}