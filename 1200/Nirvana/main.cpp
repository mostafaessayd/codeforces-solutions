/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1143/problem/B
rating : 1200
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;
using ll = long long;
int N = 2e5 + 1;

void answer()
{
	int n;
	cin >> n;
	
	auto get = [&](auto self , int x)->int {
		if(x < 10) return max(1 , x);
		int a = self(self , x / 10) * (x % 10);
		int b = self(self , (x / 10) - 1) * 9;
		return max(a , b);
	};
	cout << get(get , n);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  //cin >> t;

  while (t--)
  {
    answer();
  }

  return 0;
}