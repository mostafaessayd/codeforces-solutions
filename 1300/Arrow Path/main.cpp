/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1948/problem/C
 rating : 1300
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
	int n;
	cin >> n;
	vector<string> vec(2);
	cin >> vec[0] >> vec[1];
	vector<vector<int>> vis(2 , vector<int>(n));

	auto dfs = [&](auto self , int x , int y)->void {
		if(vis[x][y] == 1) {
			return;
		} else {
			vis[x][y] = 1;
			for(auto ind : {make_pair(x , y + 1) , make_pair(x , y - 1) , make_pair(x ^ 1 , y)}) {
				if(ind.second > -1 && ind.second < n) {
					if(vec[ind.first][ind.second] == '>') {
						ind.second++;
					} else {
						ind.second--;
					}
					self(self , ind.first , ind.second);
				}
			}
		}
	};

	dfs(dfs , 0 , 0);

	cout << (vis[1][n - 1] ? "YES\n" : "NO\n");
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}