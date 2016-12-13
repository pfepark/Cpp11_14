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
	// char�� ����� proxy Ŭ������ ������.
	// "Temporary Proxy" ��� ���.. www.google.com "C++ idioms" �˻�.

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
			std::cout << "[]�� �����ʿ��� ����Ҷ�" << std::endl;
			return str.buffer[idx];
		}

		Proxy& operator=(const char c)
		{
			std::cout << "[]�� ���ʿ��� ����Ҷ�" << std::endl;
			str.buffer[idx] = c;
			return *this;
		}
	};

	//char& operator[](int idx)	// []������ �����ʰ� ���ʿ� ������ �ٸ��� �����ϰ� �������� �ִ�. (��, ��Ƽ������ ����..)
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