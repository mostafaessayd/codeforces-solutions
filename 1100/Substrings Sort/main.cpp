/**
created by : cidi mohamed mostepha
link :https://codeforces.com/contest/988/problem/B
rating : 1100
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
 int n;
 cin >> n;
 vector<string> vec(n);
 for(int i = 0 ; i < n ; i++) {
  cin >> vec[i];
 }
 
 sort(vec.begin() , vec.end() , [&](string x , string y)->bool{
  return x.size() < y.size();
 });

 auto isSubstring = [&](string a , string b)->bool {
  for(int i = 0 ; i < a.size() ; i++) {
    if(a[i] == b[0]) {
      int j = i;
      int cur = 0;
      while(j < a.size() && cur < b.size()) {
        if(a[j] != b[cur]) {
          break;
        }
        j++;
        cur++;
      }
      if(cur == b.size()) {
        return true;
      }
    }
  }

  return false;
 };

 for(int i = 1 ; i < n ; i++) {
  if(!isSubstring(vec[i] , vec[i - 1])) {
    cout << "NO\n";
    return;
  }
 }

 cout << "YES\n";
 for(int i = 0 ; i < n ; i++) {
  cout << vec[i] << '\n';
 }
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