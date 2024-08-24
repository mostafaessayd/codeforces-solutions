/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/196/problem/A
rating : 1100
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  string s;
  cin >> s;
  vector<int> rep(26);
  vector<pair<char , int>> src; 
  for(int i = 0 ; i < s.size() ; i++) {
    if(rep[s[i] - 'a']) {
      for(int j = 0 ; j < src.size() ; j++) {
        if(src[j].first == s[i]) {
          src[j].second++;
          break;
        }
      }
    } else {
      rep[s[i] - 'a']++;
      src.push_back({s[i] , 1});
    }
  }

  sort(src.rbegin() , src.rend());
  string ans = "";
  for(int i = 0 ; i < s.size() ; i++) {
    while(src.front().second == 0) {
      src.erase(src.begin());
    }

    if(s[i] == src[0].first) {
      ans += s[i];
    }
    for(int j = 0 ; j < src.size() ; j++) {
        if(src[j].first == s[i]) {
          src[j].second--;
          break;
        }
      }
  }

  cout << ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
  //cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}
