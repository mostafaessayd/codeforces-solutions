/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1381/problem/A1
 rating : 1300
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;
using ll = long long;

void answer() {
    int n;
    string a , b;
    cin >> n >> a >> b;
    int k = 0;
    vector<int> pos;
    for(int i = 0 ; i < n ; i++) {
    	if(a[i] != b[i]) {
    		k += 3;
    		pos.push_back(i + 1);
    		pos.push_back(1);
    		pos.push_back(1 + i);
    	}
    }
    
    cout << k << ' ';
    for(int ind : pos) {
    	cout << ind << ' ';
    }
    cout << '\n';
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