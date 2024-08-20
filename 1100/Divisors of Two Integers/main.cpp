/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1108/problem/B
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
   vector<int> vec(n);
   for(int& val : vec) {
    cin >> val;
   }

   int first = *max_element(vec.begin() , vec.end());
   vector<int> rep(1e4 + 1 , 0);
   for(int i = 0 ; i < n ; i++) {
    if(first % vec[i] == 0) {
      if(rep[vec[i]] == 0) {
        rep[vec[i]] = 1;
        vec[i] = -1;
      }
    }
   }

   cout << first << ' ' << *max_element(vec.begin() , vec.end());
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