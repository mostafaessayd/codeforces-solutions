/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1954/problem/C
rating : 1200
*/

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 1;

void answer()
{
	string a , b;
	cin >> a >> b;
	
	bool found = false;
	for(int i = 0 ; i < a.size() ; i++) {
		if(a[i] == b[i]) {
			continue;
		}
		if(!found) {
			if(a[i] < b[i]) {
				swap(a[i] , b[i]);
			}
		} else {
			if(a[i] > b[i]) {
				swap(a[i] , b[i]);
			}
		}
        found = true;
	}

	cout << a << '\n' << b << '\n';
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