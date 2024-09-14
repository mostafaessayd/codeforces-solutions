/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1676/problem/F
 rating : 1300
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void answer()
{
  int n , k;
  cin >> n >> k;
  vector<int> vec(n);
  for(int i = 0 ; i < n ; i++) {
  	cin >> vec[i];
  }
  
  sort(vec.begin() , vec.end());
  
  vector<pair<int , int>> dp;
  for(int i = 0 ; i < n ;)
  {
  	dp.push_back({vec[i] , 0});
  	int j = i;
  	while(j < n && vec[j] == vec[i]) {
  		dp.back().second++;
  		j++;
  	}
  	
  	i = j;
  }
  
  int x = 0 , y = 0;
  int ans = -1;
  for(int i = 0 ; i < dp.size() ;) {
   if(dp[i].second < k) {
   	i++;
   	continue;
  	}
  	int tx = dp[i].first;
  	int j = i + 1;
  	while(j < dp.size() && dp[j].first - dp[j - 1].first == 1) {
  		if(dp[j].second < k) {
  			break;
  		}
  	 j++;
  	}
  	
  	if(dp[j - 1].first - dp[i].first > ans) {
  		x = dp[i].first;
  		y = dp[j - 1].first;
  		ans = dp[j - 1].first - dp[i].first;
  	}
  	
  	i = j;
  }
  
  if(ans == -1) {
  	cout << "-1\n";
  } else {
  	cout << x << ' ' << y << '\n';
  }
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