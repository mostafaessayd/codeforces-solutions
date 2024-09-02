/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/946/problem/C
 rating : 1300
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  string s;
  cin >> s;
  int n = s.size();
  vector<int> rep(26 , 0);
  vector<char> next(26 , 'z');
  string target = "abcdefghijklmnopqrstuvwxyz";
  
  for(int i = 0 ; i < 25 ; i++) {
    next[i] = i + 'a' + 1; 
  }
  
  int i = 0;
  int j = 0;
  string ans = "";
  while(i < n && j < target.size()) {
    if(s[i] == target[j]) {
      ans += s[i];
      j++;
      rep[target[j - 1] - 'a']++;
    } else {
      if(rep[s[i] - 'a']) {
        if(target[j] > s[i]) {
          s[i] = target[j];
          rep[s[i] - 'a']++;
          j++;
        }
      }
    }
    i++;
  }

  if(j == target.size()) {
    cout << s << '\n';
  } else {
    cout << "-1\n";
  }
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