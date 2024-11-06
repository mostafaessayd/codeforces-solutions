/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/5/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
   vector<string> vec;
   int maxLength = 0;
   int sizeOfVector = 0;
   string s;
   while(getline(cin , s)) {
    maxLength = max(maxLength , (int)s.size());
    sizeOfVector++;
    vec.push_back(s);
   }
   
   for(int i = 0 ; i < maxLength + 2 ; i++) {
    cout << '*';
   }
   cout << '\n';
   int c = 0;
   for(int i = 0 ; i < sizeOfVector ; i++) {
    cout << '*';
    int rest = maxLength - vec[i].size();
    for(int j = 0 ; j < rest / 2 + (rest % 2) * c ; j++) cout << ' ';
    cout << vec[i];
    for(int j = 0 ; j < rest / 2 ; j++) cout << ' ';
    if(c == 0 && rest & 1) cout << ' ';
    cout << "*\n";
    if(rest & 1)
    c ^= 1;
   }
   for(int i = 0 ; i < maxLength + 2 ; i++) {
    cout << '*';
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
   // cin >> t;
    while(t--) {
        answer();
    }

    return 0;
}