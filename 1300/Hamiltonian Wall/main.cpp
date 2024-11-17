/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1766/problem/C
rating : 1300
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;
const int MOD = 1e9 + 7;

void answer() {
   int n;
   cin >> n;
   vector<string> vec(2);
   cin >> vec[0] >> vec[1];
   for(int t = 0 ; t < 2 ; t++) {
      if(vec[t][0] == 'W') continue;
      vector<vector<int>> vis(2 , vector<int>(n , 0));
      int lastX = -1 , lastY = -1;
      int i = t;
      int j = 0;
      while(j < n - 1) {
         if(i == 0) {
            bool found = false;
            if(vec[1][j] == 'B' && !(lastX == 1 && j == lastY) && vis[1][j] == 0) {
               vis[1][j]++;
               lastX = i;
               lastY = j;
               i++;
               found = true;
            }
            if(vec[0][j + 1] == 'B' && !(lastX == 0 && j == lastY - 1) && vis[0][j + 1] == 0 && !found) {
               vis[0][j + 1]++;
               lastX = i;
               lastY = j;
               j++;
               found = true;
            }
            if(!found) break;
         } else {
            bool found = false;
            if(vec[0][j] == 'B' && !(lastX == 0 && j == lastY) && vis[0][j] == 0) {
               vis[0][j]++;
               lastX = i;
               lastY = j;
               i--;
               found = true;
            }
            if(vec[1][j + 1] == 'B' && !(lastX == 1 && j == lastY - 1) && vis[1][j + 1] == 0 && !found) {
               vis[1][j + 1]++;
               lastX = i;
               lastY = j;
               j++;
               found = true;
            }
            if(!found) break;
         }
      }

      if(j == n - 1) {
         cout << "YES\n";
         return;
      }
   }

   cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--) {
        answer();
    }

    return 0;
}