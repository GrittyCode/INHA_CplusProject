#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i <= n; ++i)
	{
		//공백 출력
		for (int j = i; j <= n; ++j)
		{
			cout << "  ";
		}

		for (int j = 0; j < (2 * i) + 1; ++j)
		{
			
			if (j > i)
			{
				int sum = (2 * i) + 1;
				cout << pow(2,  sum - (j+ 1)) << " ";;
			}
			else
			{
				cout << pow(2, j) << " ";
			}
		}

		cout << "\n";
	}
	return 0;
}
