/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1669/problem/E
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ll dp[26][26] = {0LL};
		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			for (int i = 0; i < 26; i++)
			{
				for (int j = 0; j < 26; j++)
				{
					if ((s[0] == i + 'a' && s[1] != j + 'a') || (s[0] != i + 'a' && s[1] == j + 'a'))
					{
						ans += dp[i][j];
					}
				}
			}

			dp[s[0] - 'a'][s[1] - 'a']++;
		}

		cout << ans << '\n';
	}

	return 0;
}