/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/4/C
rating : 1300
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void answer()
{
	int n;
	cin >> n;
	vector<string> vec(n);
	map<string , int>dp;
	for(int i = 0 ; i < n ; i++){
		cin >> vec[i];
		if(dp[vec[i]] == 0)
		{
			cout << "OK\n";
		}else{
			cout << vec[i] << dp[vec[i]] << '\n';
		}
		dp[vec[i]]++;
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    //cin >> T;

    while (T--)
    {
        answer();
    }

    return 0;
}