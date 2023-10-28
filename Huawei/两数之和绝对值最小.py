#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> vec;
	vector<int> ans(2);

	//读取一行数组
	int a;
	do
	{
		cin >> a;
		vec.push_back(a);
	} while (getchar() != '\n');
	int total = INT_MAX;
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i + 1; j < vec.size(); j++)
		{
			if(abs(vec[i] + vec[j]) < total)
			{
				total = abs(vec[i] + vec[j]);
				ans[0] = vec[i];
				ans[1] = vec[j];
			}
		}
	}
	cout << ans[0]<< ' ' << ans[1] << ' '<< total << endl;
	cout<<total<<endl;
	system("pause");
	return 0;
}


