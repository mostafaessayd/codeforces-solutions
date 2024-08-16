/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1927/problem/D
rating : 1300
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Node {
    int max_value;
    int min_value;
    int max_index;
    int min_index;
};

void build_segment_tree(vector<int>& array, vector<Node>& segment_tree, int low, int high, int pos) {
    if (low == high) {
        segment_tree[pos].max_value = array[low];
        segment_tree[pos].min_value = array[low];
        segment_tree[pos].max_index = low;
        segment_tree[pos].min_index = low;
        return;
    }
    
    int mid = (low + high) / 2;
    build_segment_tree(array, segment_tree, low, mid, 2 * pos + 1);
    build_segment_tree(array, segment_tree, mid + 1, high, 2 * pos + 2);
    
    segment_tree[pos].max_value = max(segment_tree[2 * pos + 1].max_value, segment_tree[2 * pos + 2].max_value);
    if (segment_tree[pos].max_value == segment_tree[2 * pos + 1].max_value) {
        segment_tree[pos].max_index = segment_tree[2 * pos + 1].max_index;
    } else {
        segment_tree[pos].max_index = segment_tree[2 * pos + 2].max_index;
    }
    
    segment_tree[pos].min_value = min(segment_tree[2 * pos + 1].min_value, segment_tree[2 * pos + 2].min_value);
    if (segment_tree[pos].min_value == segment_tree[2 * pos + 1].min_value) {
        segment_tree[pos].min_index = segment_tree[2 * pos + 1].min_index;
    } else {
        segment_tree[pos].min_index = segment_tree[2 * pos + 2].min_index;
    }
}

Node range_query(vector<Node>& segment_tree, int qlow, int qhigh, int low, int high, int pos) {
    if (qlow <= low && qhigh >= high) {
        return segment_tree[pos];
    }
    if (qlow > high || qhigh < low) {
        Node null_node;
        null_node.max_value = numeric_limits<int>::min();
        null_node.min_value = numeric_limits<int>::max();
        null_node.max_index = -1;
        null_node.min_index = -1;
        return null_node;
    }
    
    int mid = (low + high) / 2;
    Node left_child = range_query(segment_tree, qlow, qhigh, low, mid, 2 * pos + 1);
    Node right_child = range_query(segment_tree, qlow, qhigh, mid + 1, high, 2 * pos + 2);
    
    Node result;
    result.max_value = max(left_child.max_value, right_child.max_value);
    if (result.max_value == left_child.max_value) {
        result.max_index = left_child.max_index;
    } else {
        result.max_index = right_child.max_index;
    }
    
    result.min_value = min(left_child.min_value, right_child.min_value);
    if (result.min_value == left_child.min_value) {
        result.min_index = left_child.min_index;
    } else {
        result.min_index = right_child.min_index;
    }
    
    return result;
}

void handle_queries(vector<int>& array, vector<pair<int, int>>& queries) {
    int n = array.size();
    vector<Node> segment_tree(4 * n);
    
    build_segment_tree(array, segment_tree, 0, n - 1, 0);
    
    for (auto& query : queries) {
        int l = query.first;
        int r = query.second;
        
        Node result = range_query(segment_tree, l, r, 0, n - 1, 0);
        
        if(result.max_value == result.min_value) {
            cout << "-1 -1\n";
        }else {
           cout << result.min_index + 1 << " " << result.max_index + 1 << endl; 
        }
    }
}

void answer() {
    int n;
    cin >> n;
    vector<int> vec(n);

    for(int i = 0 ; i < n ; i++) {
        cin >> vec[i];
    }
    
    vector<pair<int, int>> queries;
    int q;
    cin >> q;
    while(q--) {
    int x , y;
    cin >> x >> y;
    x--;
    y--;
    queries.push_back({x , y});
    }
    
    handle_queries(vec, queries);

    cout << '\n';
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        answer();
    }
    return 0;
}
