


#include<iostream>
#include<string>
using namespace std;

string Avail(string a, string b)
{
	char s[100];
	for (int p = 0; p < 100; p++)
		s[p] = '0';
 
	for (int i = 0;i < a.length(); i++)
	{
		int m = a[a.length() - 1 - i] - '0', Mod = 0, k = i;
		for (int j = 0; j < b.length(); j++)
		{
			int n = b[b.length() - 1 - j] - '0';
			int t = (m*n + Mod + (s[k + j] - '0')) / 10;
			s[k + j] = (m*n + Mod + (s[k + j] - '0')) % 10 + '0';
			Mod = t;
		}
		if (Mod)s[k + b.length()] = Mod + '0';
	}
 
	string u;
	for (int q = 0; q < a.length() + b.length(); q++)
		u = s[q] + u;
 
	while (u[0] == '0')
		u = u.substr(1, u.length() - 1);
 
	return u;
}
bool Compare(string a, string b)
{
	if (a.length() == b.length())
	{
		for (int k = 0; k < a.length(); k++)
		{
			if (a[k] > b[k])
				return true;
			if (a[k] < b[k])
				return false;
		}
		return true;
	}
	else return a.length() > b.length();
}
string FindMax(string str,int N,int K)
{
	if (!K)return str;
 
	string max = "0";
	for (int i = 1; i < N - K + 1; i++)
	{
		string a = str.substr(0, i);
		string b = str.substr(i, str.length() - i);
 
		max = Compare(max, Avail(a, FindMax(b, N - i, K - 1))) ? max : Avail(a, FindMax(b, N - i, K - 1));
	}
	return max;
}
int main()
{
	int N, K;
	string S;
	cin >> N >> K >> S;
 
	cout << FindMax(S, N, K) << endl;
 
	return 0;
}
 