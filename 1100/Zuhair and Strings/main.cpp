/**
created by : cidi mohamed mostepha
link :https://codeforces.com/contest/1105/problem/B
rating : 1100
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
   int n , k;
   string s;
   cin >> n >> k >> s;
   vector<int> rep(26 , 0);
   for(int i = 0 ; i < n ; ) {
    int j = i;
    int cur = 0;
    while(j < n) {
      if(s[i] != s[j]) {
        break;
      }
      j++;
      cur++;
    }
    rep[s[i] - 'a'] += cur / k;
    i = j;
   }

   cout << *max_element(rep.begin() , rep.end());
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