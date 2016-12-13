#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class String
{
	char* buffer;

public:
	String(const char* s)
	{
		buffer = new char[strlen(s) + 1];
		strcpy(buffer, s);
	}

	~String()
	{
		delete[] buffer;
	}
	// char를 대신할 proxy 클래스를 만들자.
	// "Temporary Proxy" 라는 기술.. www.google.com "C++ idioms" 검색.

	// http://cafe.naver.com/cppmaster
	class Proxy
	{
		String& str;
		int idx;

	public:
		Proxy(String& s, int n) : str(s), idx(n)
		{

		}

		operator char()
		{
			std::cout << "[]를 오른쪽에서 사용할때" << std::endl;
			return str.buffer[idx];
		}

		Proxy& operator=(const char c)
		{
			std::cout << "[]를 왼쪽에서 사용할때" << std::endl;
			str.buffer[idx] = c;
			return *this;
		}
	};

	//char& operator[](int idx)	// []연산은 오른쪽과 왼쪽에 있을때 다르게 동작하고 싶을때가 있다. (예, 멀티스레드 지원..)
	Proxy operator[](int idx)
	{
		std::cout << "[]" << std::endl;
		return Proxy(*this, idx);
	}
};

int main()
{
	String s = "hello";

	char c = s[0];
	s[0] = 'a';
}