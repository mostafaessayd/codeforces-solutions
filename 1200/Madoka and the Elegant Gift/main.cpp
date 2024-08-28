/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1647/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 101;

int vis[N][N] = {0};
int n , m;
int height = INT_MAX;
int lower = 0;
void dfs(int x , int y , vector<string>& src , vector<priority_queue<int>>& temp) {
  if(vis[x][y] || src[x][y] == '0') {
    return;
  }

  vis[x][y] = 1;
  temp[x].push(y);
  height = min(height , x);
  lower = max(lower , x);
  if(x + 1 < n) {
    dfs(x + 1 , y , src , temp);
  }
  if(x - 1 > -1) {
    dfs(x - 1 , y , src , temp);
  }
  if(y + 1 < m) {
    dfs(x , y + 1 , src , temp);
  }
  if(y - 1 > -1) {
    dfs(x , y - 1 , src , temp);
  }
}

bool equal(priority_queue<int> a , priority_queue<int> b) {
  if(a.size() != b.size()) {
    return false;
  }

  while(!a.empty()) {
    if(a.top() != b.top()) {
      return false;
    }
    a.pop();
    b.pop();
  }

  return true;
}

void answer()
{
  cin >> n >> m;
  vector<string> vec(n);
  for(int i = 0 ; i < n ; i++) {
    cin >> vec[i];
  }
  
  for(int i = 0 ; i < N ; i++) {
    for(int j = 0 ; j < N ; j++) {
      vis[i][j] = 0;
    }
  }

  int ans = 0;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      if(vec[i][j] == '0' || vis[i][j]) {
        continue;
      }
      vector<priority_queue<int>> temp(n);
      height = INT_MAX;
      lower = 0;
      dfs(i , j , vec , temp);
      for(int k = height ; k < lower ; k++) {
        if(equal(temp[k] , temp[k + 1]) == false) {
          cout << "NO\n";
          return;
        }
      }
    }
  }

  cout << "YES" << '\n';
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