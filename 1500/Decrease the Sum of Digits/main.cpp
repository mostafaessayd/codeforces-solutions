/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1409/problem/D
rating : 1500
*/

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 1;

void answer()
{
	ll n , s;
	cin >> n >> s;
	
	auto getSum = [&](auto self , ll x)-> ll {
		return (x == 0 ? 0 : self(self , x / 10) + x % 10);
	};

	ll need = 0;
	ll pos = 1;
	while(getSum(getSum , n) > s) {
		need += (10 - ((n / pos) % 10)) * pos;
		n += (10 - ((n / pos) % 10)) * pos;
		pos *= 10;
	}

	cout << need << '\n';
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