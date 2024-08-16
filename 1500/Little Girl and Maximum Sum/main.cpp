/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/276/problem/C
rating : 1500
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n , q;
    cin >> n >> q;
    vector<long long> vec(n);
    for(long long& val : vec){
    	cin >> val;
    }
    
    vector<long long> dp(n + 1);
    while(q--)
    {
    	int l , r;
    	cin >> l >> r;
    	l--;
    	r--;
    	dp[l]++;
    	dp[r + 1]--;
    }
    
    for(int i = 1 ; i < n ; i++){
    	dp[i] += dp[i - 1];
    }
    
    sort(vec.rbegin() , vec.rend());
    sort(dp.rbegin() , dp.rend());
    
    long long ans = 0;
    for(int i = 0 ; i < n ; i++){
    	ans += vec[i] * dp[i];
    }
    
    cout << ans;
    return 0;
}
