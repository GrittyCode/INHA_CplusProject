#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

void search_idx(const vector<int> num, int key)
{
	cout << "   |";
	for (int i = 0; i < num.size(); ++i)
	{
		cout << i << " ";
	}
	cout << "\n";
	cout << "---+------------------------------\n";
	
	int start = 0;
	int end = num.size() - 1;
	int cnt = 0;
	while (start <= end)
	{
		cout << "   |";
		cnt++;
		int mid = (start + end) / 2;
		for (int i = 0; i < start; ++i)
		{
			cout << "  ";
		}
		cout << "←";

		for (int i = start; i < end; ++i)
		{
			if (i == mid) cout << "+";
			else cout << "  ";
		}
		cout << "→\n";

		cout << mid << "  |";
		for (int i = 0; i < num.size(); ++i)
		{
			cout << i << " ";
		}
		cout << "\n";



		if (num[mid] > key)
		{
			end = mid - 1;
		}
		else if (num[mid] < key)
		{
			start = mid + 1;
		}
		else if (num[mid] == key)
		{
			cout << "\n";
			cout <<  key << "는 arr[" << mid << "]" << "에있습니다." << cnt << "번만에" << " 찾았습니다\n";
			return;
		}
	}

	cout << "================================================\n";
	cout << key << "값은 존재하지 않습니다. 프로그램을 종료합니다..";
	return;
}

int main()
{
	cout << "원하는 배열의 크기를 입력하세요 : ";
	int iter;
	cin >> iter;

	vector<int> num;
	for (int i = 0; i < iter; ++i)
	{
		cout << "배열 [" << i << "]에 넣을 값을 입력하세요 : ";
		int temp;
		cin >> temp;
		num.push_back(temp);
	}

	cout << "=======시스템 정렬중========\n";
	sort(num.begin(), num.end());
	cout << "=======시스템 정렬완료========\n";


	cout << "찾고 싶은 수를 입력하세요 : ";
	int key;
	cin >> key;

	search_idx(num,key);

	return 0;
}

