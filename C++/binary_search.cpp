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
		cout << "��";

		for (int i = start; i < end; ++i)
		{
			if (i == mid) cout << "+";
			else cout << "  ";
		}
		cout << "��\n";

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
			cout <<  key << "�� arr[" << mid << "]" << "���ֽ��ϴ�." << cnt << "������" << " ã�ҽ��ϴ�\n";
			return;
		}
	}

	cout << "================================================\n";
	cout << key << "���� �������� �ʽ��ϴ�. ���α׷��� �����մϴ�..";
	return;
}

int main()
{
	cout << "���ϴ� �迭�� ũ�⸦ �Է��ϼ��� : ";
	int iter;
	cin >> iter;

	vector<int> num;
	for (int i = 0; i < iter; ++i)
	{
		cout << "�迭 [" << i << "]�� ���� ���� �Է��ϼ��� : ";
		int temp;
		cin >> temp;
		num.push_back(temp);
	}

	cout << "=======�ý��� ������========\n";
	sort(num.begin(), num.end());
	cout << "=======�ý��� ���ĿϷ�========\n";


	cout << "ã�� ���� ���� �Է��ϼ��� : ";
	int key;
	cin >> key;

	search_idx(num,key);

	return 0;
}

