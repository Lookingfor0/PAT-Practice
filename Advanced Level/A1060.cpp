#include <iostream>
#include <string>

using namespace std;


int n;  // 有效位数

string deal(string s, int& e)
{
	while (s.length() > 0 && s[0] == '0')
	{
		s.erase(s.begin());
	}
	if (s[0] == '.')
	{
		s.erase(s.begin());
		while (s.length() > 0 && s[0] == '0')
		{
			s.erase(s.begin());
			e--;
		}
	}
	else
	{
		int k = 0;
		while (k < s.length() && s[k] != '.')
		{
			k++;
			e++;
		}
		if (k < s.length())
		{
			s.erase(s.begin() + k);  // 删除小数点
		}
	}
	if (s.length() == 0)
	{
		e = 0;
	}
	int num = 0;
	string res;
	while (num < n)
	{
		if (num < s.length())
			res += s[num];
		else
			res += '0';
		num++;
	}
	return res;
}

int main()
{
	string s1, s2, sn1, sn2;
	cin >> n >> s1 >> s2;
	int e1 = 0, e2 = 0;
	sn1 = deal(s1, e1);
	sn2 = deal(s2, e2);
	if (sn1 == sn2)
	{
		cout << "YES 0." << sn1 << "*10^" << e1 << endl;
	}
	else
	{
		cout << "NO 0." << sn1 << "*10^" << e1 << " 0." << sn2 << "*10^" << e2 << endl;
	}
	return 0;
}