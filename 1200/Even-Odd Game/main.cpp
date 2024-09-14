/**
created by : cidi mohamed mostepha
link :https://codeforces.com/contest/1472/problem/D
rating : 1200
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void answer()
{
  int n;
  cin >> n;
  vector<ll> vec(n);
  for(int i = 0 ; i < n ; i++) {
  	cin >> vec[i];
  }
  
  sort(vec.rbegin() , vec.rend());
  
  ll a = 0 , b = 0;
  for(int i = 0 ; i < n ; i++) {
  	if((vec[i] + i) & 1) {
  		continue;
  	}
  	a += (i % 2 == 0 ? vec[i] : 0);
  	b += (i % 2 == 1 ? vec[i] : 0);
  }
  
  if(a == b) {
  	cout << "Tie\n";
  } else {
  	if(a > b) {
  		cout << "Alice\n";
  	} else {
  		cout << "Bob\n";
  	}
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