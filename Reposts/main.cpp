/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/522/problem/A
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
 int n;
 cin >> n;
 
 map<string , vector<string>> adj;
 map<string , int> vis;

 for(int i = 0 ; i < n ; i++) {
    string x , y , z;
    cin >> x >> z >> y;
    for(int k = 0 ; k < x.size() ; k++) {
      x[k] = tolower(x[k]);
    }
    for(int k = 0 ; k < y.size() ; k++) {
      y[k] = tolower(y[k]);
    }
    adj[y].push_back(x);
 }

 auto dfs = [&](auto self , string u)->int {
  vis[u]++;
  if(adj[u].size() == 0) {
    return 1;
  }else {
    int ans = 0;
    for(string v : adj[u]) {
      if(vis[v] == 0){
        ans = max(ans , self(self , v) + 1);
      }
    }

    return ans;
  }
 };

 cout << dfs(dfs , "polycarp") << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
	cin.tie(0);
  cout.tie(0);
  
  int t = 1;
 // cin >> t;

  while (t--)
  {
    answer();
  }

  return 0;
}