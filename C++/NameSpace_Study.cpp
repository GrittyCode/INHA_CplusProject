#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

const int BUF = 512;
const int N = 5;
char buffer[BUF];

using namespace std;

namespace t1
{
	int TT;
	void Print(int i)
	{
		cout << "t1 : " << i << endl;
	}
}

namespace t2
{
	int TT;
	void Print(int i)
	{
		cout << "t2 : " << i * i << endl;
	}
}


int main()
{
	t1::TT = 40;
	t1::Print(t1::TT);

	t2::TT = 50;
	t2::Print(t2::TT);


	//default namespace is t1이라는 뜻
	using namespace t1;

	Print(50);

	t2::Print(50);

	return 0;
}

