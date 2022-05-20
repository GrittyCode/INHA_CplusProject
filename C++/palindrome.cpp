
#include "2022-05-19.h"
#include "Chapter5.h"
using namespace std;


bool Chapter5::FindWordCorrect(string str)
{
	//회문을 찾자
	//회문인 경우는 leel level경우를 말한다.
	//인덱스 맨 앞과 맨뒤가 모두 같을 경우만 회문, 홀수의 경우에는 무시하고 가면됨
	for (int i = 0; i < str.size() / 2; i++)
	{
		if (str[i] != str[str.size() - (i + 1)])
		{
			return false;
		}
	}
	return true;

}
int main()
{
	string str;
	
	while (1)
	{
		cout << "단어를 입력하시오(종료를 원하면 exit입력) : ";
		cin >> str;
		if (str == "exit") break;
		int flag = Chapter5::FindWordCorrect(str);
		if (flag == true)
		{
			cout << str << "은 회문입니다. \n";
		}
		else
		{
			cout << str << "은 회문이 아닙니다. \n";
		}
	}
	

	return 0;
}