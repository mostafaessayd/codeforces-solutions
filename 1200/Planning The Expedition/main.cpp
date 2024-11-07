/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1011/problem/B
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
	int n , m;
	cin >> n >> m;
	vector<int> vec(m);
	vector<int> freq(101 , 0);
	set<int> values;
	for(int& val : vec) {
		cin >> val;
		values.insert(val);
		freq[val]++;
	}
	
	for(int i = 100 ; i > 0 ; i--) {
		int k = 0;
		for(int ind : values) {
			k += freq[ind] / i;
		}
		if(k >= n) {
			cout << i;
			return;
		}
	}
	
	cout << "0";
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