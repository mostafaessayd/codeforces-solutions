/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/754/problem/A
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
	cin >> n;
	vector<int> vec(n);
	int good = 0;
	for(int& val : vec) {
	 cin >> val;
	 good += (val != 0);
	}
	
	if(good == 1) {
		cout << "YES\n1\n1 " << n;
		return;
	}
	if(!good) {
		cout << "NO";
	} else {
		cout << "YES\n";
		vector<pair<int , int>> ans;
		for(int i = 0 ; i < n ; ) {
			int x = i + 1;
			while(i < n && vec[i] == 0) {
				i++;
			}
			i++;
			while(i < n && vec[i] == 0) {
				i++;
			}
			ans.push_back({x , i});
		}
		
		cout << ans.size() << '\n';
		for(auto ind : ans) {
			cout << ind.first << ' ' << ind.second << '\n';
		}
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