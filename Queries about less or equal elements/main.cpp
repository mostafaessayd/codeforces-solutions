/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/600/problem/B
rating : 1300
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n , m;
  cin >> n >> m;
  vector<int> a(n);
  for(int i = 0 ; i < n ; i++) {
    cin >> a[i];
  }
  
  map<int , vector<int>> allIndexe;
  map<int , int> allValues;

  vector<int> b(m);
  for(int i = 0 ; i < m ; i++) {
    cin >> b[i];
    allIndexe[b[i]].push_back(i);
  }

  sort(a.rbegin() , a.rend());
  sort(b.rbegin() , b.rend());

  int lastIndexe = 0;
  int stop = -1;

  for(int i = 0 ; i < m ; i++) {
    while(a[lastIndexe] > b[i] && lastIndexe < n) {
      lastIndexe++;
    }

    if(lastIndexe == n) {
      stop = b[i];
      break;
    }else {
     allValues[b[i]] = n - lastIndexe;
    }
  }

  if(~stop) {
   for(int i = 0 ; i < m ; i++) {
    if(b[i] <= stop) {
      allValues[b[i]] = 0;
    }
   }
  }

  vector<int> answers(m , 0);
  for(int i = 0 ; i < m ; i++) {
    answers[allIndexe[b[i]][0]] = allValues[b[i]];
    allIndexe[b[i]].erase(allIndexe[b[i]].begin());
  }

  for(int i = 0 ; i < m ; i++) {
    cout << answers[i] << ' ';
  }
}

int main()
{
  ios::sync_with_stdio(false);
	cin.tie(0);
  cout.tie(0);

  int t = 1;
 // cin >> t;

  while (t--)
  {
    answer();
  }

  return 0;
}