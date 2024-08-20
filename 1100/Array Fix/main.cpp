/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1948/problem/B
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
   vector<int> integer_values(n + 1);
   for(int i = 0 ; i < n ; i++) {
    cin >> integer_values[i];
    vec[i] = to_string(integer_values[i]);
   }
   
   vector<char> src;
   vector<int> final_array;
   integer_values[n] = INT_MAX;
   bool okey = true;
   for(int i = n - 1 ; i > -1 ; i--) {
    if(integer_values[i] > integer_values[i + 1]) {
      okey = false;
    }
    for(int j = vec[i].size() - 1 ; j > -1 ; j--) {
      src.push_back(vec[i][j]);
      if(!okey) {
        final_array.push_back(vec[i][j] - '0');
      }
    }
    if(okey) {
      final_array.push_back(integer_values[i]);
    }
   }

   reverse(final_array.begin() , final_array.end());
   reverse(src.begin() , src.end());
   okey = is_sorted(src.begin() , src.end()) || is_sorted(final_array.begin() , final_array.end());
   cout << (okey ? "YES" : "NO") << '\n';
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