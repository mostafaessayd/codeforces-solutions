/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1419/problem/D1
rating : 1000
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
   int n;
   cin >> n;
   vector<int> vec(n);
   for(int& val : vec) {
    cin >> val;
   }

   cout << n / 2 - ((n % 2) ^ 1) << '\n';
   sort(vec.rbegin() , vec.rend());
   for(int i = 0 ; i < n / 2 ; i++) {
    cout << vec[i] << ' ' << vec[n - i - 1] << ' '; 
   }
   if(n & 1) {
    cout << vec[n / 2];
   }
}

int main()
{
    int t = 1;
  //  cin >> t;
    while (t--)
    {
        answer();
    }

    return 0;
}