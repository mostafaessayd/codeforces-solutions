/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1385/problem/C
rating : 1200
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void answer()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> vec[i];
	}
	
	int i = n - 1;
	while(i > 0 && vec[i - 1] >= vec[i]) i--;
	while(i > 0 && vec[i - 1] <= vec[i]) i--;
	
	cout << i << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--)
  {
    answer();
  }

  return 0;
}