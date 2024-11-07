/**
created by : cidi mohamed mostepha
link :https://codeforces.com/contest/879/problem/B
rating : 1200
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <deque>

using namespace std;
using ll = long long;

void answer()
{
	int n;
	ll k;
	cin >> n >> k;
	deque<int> vec;
	for(int i = 0 ; i < n ; i++) {
		int val;
		cin >> val;
		vec.push_back(val);
	}
	
	int rep = 0;
	for(int i = 0 ; i < n ; i++) {
		while(rep < n && vec[0] > vec[1]) {
			rep++;
			vec.push_back(vec[1]);
			int t = vec[0];
			vec.erase(vec.begin());
			vec.erase(vec.begin());
			vec.push_front(t);
		}
		
		if(rep == n || rep >= k) {
			cout << vec[0];
			return;
		}
		vec.push_back(vec[0]);
		vec.erase(vec.begin());
		rep = 1;
	}
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