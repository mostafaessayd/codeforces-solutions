/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1328/problem/C
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  string s;
  int n;
  cin >> n >> s;
  string a = "" , b = "";
  for(char ch : s) {
    if(ch == '2') {
      a += '1';
      b += '1';
    }
    if(ch == '1') {
      a += '1';
      b += '0';
    }
    if(ch == '0') {
      a += '0';
      b += '0';
    }
  }
  
  int i = 0;
  while(i < n) {
    if(a[i] != b[i]) {
      break;
    }
    i++;
  }

  if(i < n) {
    if(a[i] > b[i]) {
      swap(a[i] , b[i]);
      for(int j = i + 1 ; j < n ; j++) {
        if(b[j] == '0') {
          continue;
        }
        if(a[j] == b[j]) {
          b[j] = '0';
          a[j] = '2';
        } else {
          b[j] = '0';
          a[j] = '1';
        }
      }
    } else {
      swap(a[i] , b[i]);
      for(int j = i + 1 ; j < n ; j++) {
        if(a[j] == '0') {
          continue;
        }
        if(a[j] == b[j]) {
          a[j] = '0';
          b[j] = '2';
        } else {
          a[j] = '0';
          b[j] = '1';
        }
      }
    }
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