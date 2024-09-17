/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1846/problem/E1
 rating : 1300
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 2e5 + 1;

map<int , int> cnt;

void answer()
{
	int n;
	cin >> n;
	cout << (cnt[n] && n > 6 ? "YES" : "NO") << '\n';
}

int main()
{
  ios_base::sync_with_stdio(0);
  
  for(int i = 2 ; i < 1e4; i++) {
  	cnt[i + 1]--;
  	int cur = 1;
  	int sum = 1;
  	while(sum < 1e6) {
  		cur *= i;
  		sum += cur;
  		cnt[sum]++;
  	}
  }
  
  int t = 1;
  cin >> t;
  while (t--)
  {
    answer();
  }
  
  return 0;
}