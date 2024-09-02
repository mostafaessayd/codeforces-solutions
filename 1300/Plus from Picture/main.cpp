/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1182/problem/B
 rating : 1300
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n, m;
  cin >> n >> m;
  vector<string> vec(n);
  for (int i = 0; i < n; i++)
  {
    cin >> vec[i];
  }

  int ans = 0;
  for (int i = 1; i < n - 1; i++)
  {
    for (int j = 1; j < m - 1; j++)
    {
      if (vec[i][j] == '*' && vec[i + 1][j] == '*' && vec[i - 1][j] == '*' && vec[i][j + 1] == '*' && vec[i][j - 1] == '*' && vec[i + 1][j + 1] == '.' && vec[i - 1][j - 1] == '.' && vec[i - 1][j + 1] == '.' && vec[i + 1][j - 1] == '.')
      {
        bool okey = true;
        int k = i + 1;
        while (k < n)
        {
          if (vec[k][j + 1] == '*' || vec[k][j - 1] == '*')
          {
            okey = false;
          }
          k++;
        }
        k = i - 1;
        while (k > -1 && okey)
        {
          if (vec[k][j + 1] == '*' || vec[k][j - 1] == '*')
          {
            okey = false;
          }
          k--;
        }
        k = j - 1;
        while (k > -1 && okey)
        {
          if (vec[i + 1][k] == '*' || vec[i - 1][k] == '*')
          {
            okey = false;
          }
          k--;
        }
        k = j + 1;
        while (k < m && okey)
        {
          if (vec[i + 1][k] == '*' || vec[i - 1][k] == '*')
          {
            okey = false;
          }
          k++;
        }

        if (okey)
        {
          ans++;
        }
        else
        {
          cout << "NO";
          return;
        }
      }
      if (ans > 1)
      {
        cout << "NO";
        return;
      }
    }
  }

  vector<vector<int>> vis(n, vector<int>(m));
  auto dfs = [&](auto self, int x, int y) -> void
  {
    if (vis[x][y] == 1 || vec[x][y] == '.')
    {
      return;
    }
    vis[x][y] = 1;
    vector<pair<int, int>> next_cell;
    next_cell.push_back({x, y + 1});
    next_cell.push_back({x, y - 1});
    next_cell.push_back({x + 1, y + 1});
    next_cell.push_back({x - 1, y - 1});
    next_cell.push_back({x - 1, y});
    next_cell.push_back({x + 1, y});
    next_cell.push_back({x - 1, y + 1});
    next_cell.push_back({x + 1, y - 1});
    for (auto cell : next_cell)
    {
      if (cell.first >= 0 && cell.first < n && cell.second >= 0 && cell.second < m)
      {
        self(self, cell.first, cell.second);
      }
    }
  };

  int rep = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (vis[i][j] || vec[i][j] == '.')
      {
        continue;
      }
      rep++;
      if (rep > 1)
      {
        cout << "NO";
        return;
      }
      dfs(dfs, i, j);
    }
  }

  cout << (ans == 1 ? "YES" : "NO");
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}