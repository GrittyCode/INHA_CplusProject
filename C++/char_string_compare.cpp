
#include "2022-05-19.h"
#include "Chapter5.h"
using namespace std;

int main()
{
	char word[20] = "word";
	char* p_word = (char*)"word";

	//주소를 비교
	if (word == "word")
	{
		cout << "word 배열의 주소값이 word 상수 문자열과 주소가 다르다.\n";
	}

	//주소를 비교
	if (p_word == "word")
	{
		cout << "point char의 word가 word 상수 문자열의 주소가 같다.\n";
	}
	
	string str = "word";


	//주소에 있는 값을 비교
	if (str == "word")
	{
		cout << "string str의 word와 word 상수 문자열이 같다\n";
	}



	return 0;
}