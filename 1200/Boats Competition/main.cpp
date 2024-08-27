/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1399/problem/C
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  int n;
  cin >> n;
  vector<int> vec(n);
  vector<int> indices(50000 , 0);
  for (int i = 0; i < n; i++)
  {
    cin >> vec[i];
    indices[vec[i]]++;
  }

  set<int> poss_sum;
  for (int i = 0; i < n ; i++)
  {
    for (int j = 0 ; j < n; j++)
    {
      poss_sum.insert(vec[i] + vec[j]);
    }
  }

  auto getMaxNumberOfTeams = [&](int target) -> int
  {
    vector<int> src(50000 , 0);
    for (int i = 0; i < n; i++)
    {
      src[vec[i]] = indices[vec[i]];
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
      if(src[vec[i]] == 0) {
        continue;
      }
      if(target - vec[i] <= 0) {
        continue;
      }

      if(vec[i] * 2 == target) {
        res += src[vec[i]] / 2;
        src[vec[i]] %= 2;
      } else {
        while(src[vec[i]] * src[target - vec[i]] > 0) {
          res++;
          src[vec[i]]--;
          src[target - vec[i]]--;
        }
      }
    }
    return res;
  };

  int ans = 0;
  for (int ind : poss_sum)
  {
    ans = max(ans, getMaxNumberOfTeams(ind));
  }

  cout << ans << "\n";
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