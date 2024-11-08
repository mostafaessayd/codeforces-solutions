/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/102/problem/A
rating : 1200
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;
using ll = long long;
int N = 2e5 + 1;

void answer()
{
	int n , m;
	cin >> n >> m;
	vector<int> prix(n);
	for(int& val : prix) cin >> val;
	int edge[100][100] = {0};
	for(int i = 0 ; i < m ; i++) {
		int u , v;
		cin >> u >> v;
		u--;
		v--;
		edge[u][v] = edge[v][u] = 1;
	}
	
	int ans = 1e9;
	for(int i = 0 ; i < n - 2 ; i++) {
		for(int j = i + 1 ; j < n - 1 ; j++) {
			for(int k = j + 1 ; k < n ; k++) {
				if(edge[i][j] && edge[i][k] && edge[k][j]) {
					ans = min(ans , prix[i] + prix[j] + prix[k]);
				  }
			}
		}
	}
	
	cout << (ans == 1e9 ? -1 : ans);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  //cin >> t;

  while (t--)
  {
    answer();
  }

  return 0;
}