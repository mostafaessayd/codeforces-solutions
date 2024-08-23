/**
 * created by : cidi mohamed mostepha
 * link : https://codeforces.com/contest/1626/problem/B
 * rating : 1100
 */

#include<bits/stdc++.h>

using namespace std;

void answer() {
  string s;
  cin >> s;
  bool okey = false;
  int last_two = -1;
  for(int i = 0 ; i < s.size() - 1; i++) {
    int rem = (s[i] - '0') * 10 + (s[i + 1] - '0');
    int cur = (s[i] - '0') + (s[i + 1] - '0');
    if(cur > 9) {
      last_two = i;
    }
    if(cur > rem && cur > 9) {
      okey = true;
      s[i] = (cur / 10) + '0';
      s[i + 1] = (cur % 10) + '0';
      break;
    }
  }
  
  if(!okey) {
    if(last_two != -1) {
      int rem = (s[last_two] - '0') * 10 + (s[last_two + 1] - '0');
      int cur = (s[last_two] - '0') + (s[last_two + 1] - '0');
      s[last_two] = (cur / 10) + '0';
      s[last_two + 1] = (cur % 10) + '0';
    } else {
    int n = s.size();
    int cur = (s[0] - '0') + (s[1] - '0');
    s[0] = '0';
    s[1] = cur + '0';
    if(s[0] == '0') {
      s.erase(s.begin());
    }
    }
  }

  cout << s << '\n';
}

int main() {
  int t = 1;
  cin >> t;
  while(t--) {
    answer();
  }
  return 0;
}

/**
 *  
 */
