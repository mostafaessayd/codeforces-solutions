/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/122/problem/B
 rating : 1000
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  string s;
  cin >> s;
  map<string , int> dp;
  vector<string> vec;
  for(int i = 0 ; i < s.size() ; i++) {
    string temp = "";
    bool isLuky = true;
    for(int j = i ; j < s.size() ; j++) {
      if(s[j] != '7' && s[j] != '4') {
        isLuky = false;
      }
      if(isLuky == false) {
        break;
      } 
      temp += s[j];
      dp[temp]++;
      vec.push_back(temp);
    }
  }
  
  if(vec.empty()) {
    cout << "-1";
    return;
  }

  auto cmp = [&](string& a , string& b)->bool {
    int n = min((int)a.size() , (int)b.size());
    for(int i = 0 ; i < n ; i++) {
      if(a[i] > b[i]) {
        return false;
      } else if(a[i] < b[i]) {
        return true;
      }
    }

    return true;
  };
  
  for(int i = 0 ; i < vec.size() - 1 ; i++) {
    for(int j = i + 1 ; j < vec.size() ; j++) {
      if(dp[vec[i]] == dp[vec[j]]) {
      if(!cmp(vec[i] , vec[j])) {
        swap(vec[i] , vec[j]);
      }
    } else {
      if(dp[vec[i]] < dp[vec[j]]) {
        swap(vec[i] , vec[j]);
      }
    }
    }
  }
  cout << vec[0];
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
 // cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}