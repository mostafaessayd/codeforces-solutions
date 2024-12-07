#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int n , m;
    cin >> n >> m;
    vector<vector<int>> stage(n , vector<int>(m , 0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> stage[i][j];
        }
    }  

    vector<int> col_sum(m , 0) , row_sum(n , 0);
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            row_sum[i] += stage[i][j];
            col_sum[j] += stage[i][j];
        }
    }

    int ans = 0;
    for(int i = 0 ; i < n ; i++) {
        int left = 0;
        int right = row_sum[i];
        for(int j = 0 ; j < m ; j++) {
            if(stage[i][j] == 0) {
                ans += (right > 0);
                ans += (left > 0);
            } else {
                left++;
                right--;
            }
        }
    }

    for(int i = 0 ; i < m ; i++) {
        int up = 0;
        int down = col_sum[i];
        for(int j = 0 ; j < n ; j++) {
            if(stage[j][i] == 0) {
                ans += (up > 0);
                ans += (down > 0);
            } else {
                up++;
                down--;
            }
        }
    }

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        answer();
    }

    return 0;
}