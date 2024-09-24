/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1791/problem/F
rating : 1500
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node {
    ll value_of_addition;
};

struct UpdateRangeSegmentTree {
    vector<Node> segment;
    int n;
    UpdateRangeSegmentTree(vector<ll>& data) {
        this->n = data.size();
        this->segment.resize(4 * n);
    }

    void build(int l , int r , int pos , vector<ll>& data) {
        if(l == r) {
            segment[pos].value_of_addition = 0;
        } else {
            int mid = (l + r) / 2;
            build(l , mid , pos * 2 , data);
            build(mid + 1 , r , pos * 2 + 1 , data);
            segment[pos].value_of_addition = 0;
        }
    }

    void updateRange(int l , int r , int a , int b , ll v , int pos) {
        if(l > b || a > r) {
            return;
        }
        if(l >= a && r <= b) {
            segment[pos].value_of_addition += v;
            return;
        }
        int mid = (l + r) / 2;
        updateRange(l , mid , a , b , v , pos * 2);
        updateRange(mid + 1 , r , a , b , v , pos * 2 + 1);
    }

    ll getValueInPosition(int l , int r , int idx , ll v , int pos) {
        if(l == r) {
            return segment[pos].value_of_addition + v;
        } else {
            int mid = (l + r) / 2;
            if(mid < idx) {
                return getValueInPosition(mid + 1 , r , idx , v + segment[pos].value_of_addition , pos * 2 + 1);
            } else {
                return getValueInPosition(l , mid , idx , v + segment[pos].value_of_addition , pos * 2);
            }
        }
    }
};

void answer() {
    int n , q;
    cin >> n >> q;
    vector<ll> vec(n);
    for(ll& val : vec) {
        cin >> val;
    }
    
    UpdateRangeSegmentTree seg = UpdateRangeSegmentTree(vec);
    
    auto update = [&](auto self , int value , int rep)->int {
        if(value < 10 || rep == 0) {
            return value;
        } else {
            int x = value;
            int sum = 0;
            while(x) {
                sum += x % 10;
                x /= 10;
            }

            return self(self , sum , rep - 1);
        }
    };

    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int l , r;
            cin >> l >> r;
            seg.updateRange(0 , n - 1 , l - 1 , r - 1 , 1 , 1);
        } else {
            int i;
            cin >> i;
            cout << update(update , vec[i - 1] , seg.getValueInPosition(0 , n - 1 , i - 1 , 0 , 1)) << '\n';
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        answer();
       // cout << "\n\n\n";
    }

    return 0;
}