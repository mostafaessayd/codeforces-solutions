/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/429/problem/A
rating : 1300
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

 vector<vector<int>> adj;
 vector<int> vis;
 vector<int> values;
 vector<int> goals;
 vector<int> answers;

void dfs(int v , int d , int x , int y) {
 vis[v] = 1;

 if(d & 1) {
  if(x & 1) {
    int value = (values[v] ? 0 : 1);
    if(value != goals[v]) {
      answers.push_back(v);
      for(int u : adj[v]) {
        if(!vis[u]) {
          dfs(u , d + 1 , x + 1 , y);
        }
      }
    }else {
      for(int u : adj[v]) {
        if(!vis[u]) {
          dfs(u , d + 1 , x , y);
        }
      }
    }
  }else {
    if(values[v] != goals[v]) {
      answers.push_back(v);
      for(int u : adj[v]) {
        if(!vis[u]) {
          dfs(u , d + 1 , x + 1 , y);
        }
      }
    }else {
      for(int u : adj[v]) {
        if(!vis[u]) {
          dfs(u , d + 1 , x , y);
        }
      }
    }
  }
 }else {
  if(y & 1) {
    int value = (values[v] ? 0 : 1);
    if(value != goals[v]) {
      answers.push_back(v);
      for(int u : adj[v]) {
        if(!vis[u]) {
          dfs(u , d + 1 , x , y + 1);
        }
      }
    }else {
      for(int u : adj[v]) {
        if(!vis[u]) {
          dfs(u , d + 1 , x , y);
        }
      }
    }
  }else {
    if(values[v] != goals[v]) {
      answers.push_back(v);
      for(int u : adj[v]) {
        if(!vis[u]) {
          dfs(u , d + 1 , x , y + 1);
        }
      }
    }else {
      for(int u : adj[v]) {
        if(!vis[u]) {
          dfs(u , d + 1 , x , y);
        }
      }
    }
  }
 }
}

void answer()
{
 int n;
 cin >> n;
 
 adj.resize(n);
 vis.resize(n , 0);
 values.resize(n);
 goals.resize(n);

 for(int i = 0 ; i < n - 1 ; i++) {
  int x , y;
  cin >> x >> y;
  x--;
  y--;
  adj[x].push_back(y);
  adj[y].push_back(x);
 }

 for(int i = 0 ; i < n ; i++) {
  cin >> values[i];
 }

 for(int i = 0 ; i < n ; i++) {
  cin >> goals[i];
 }
 
 dfs(0 , 0 , 0 , 0);

 cout << answers.size() << '\n';
 for(int v : answers) {
  cout << v + 1 << '\n';
 }
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