/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1227/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e3 + 1;

int buildMinSegment(vector<int> &segment, vector<int> &src, int l, int r, int pos)
{
	if (l > r)
	{
		return 1e9;
	}
 
	if (l == r)
	{
		segment[pos] = src[l];
		return src[l];
	}
 
	int newR = (l + r) / 2;
	int newL = (l + r) / 2 + 1;
	int p1 = buildMinSegment(segment, src, l, newR, pos * 2 + 1);
	int p2 = buildMinSegment(segment, src, newL, r, pos * 2 + 2);
	return segment[pos] = min(p1, p2);
}
 
void update(int l, int r, int x, ll y, int pos, vector<int> &seg, vector<int> &data)
{
	if (l == r)
	{
		data[x] = y;
		seg[pos] = y;
	}
	else
	{
		int mid = (l + r) / 2;
		if (x <= mid)
		{
			update(l, mid, x, y, pos * 2 + 1, seg, data);
		}
		else
		{
			update(mid + 1, r, x, y, pos * 2 + 2, seg, data);
		}
		seg[pos] = max(seg[pos * 2 + 1], seg[pos * 2 + 2]);
	}
}
 
int getMin(vector<int> &segment, int l, int r, int a, int b, int pos)
{
	if (a > r || l > b)
	{
		return 1e9;
	}
 
	if (l >= a && b >= r)
	{
		return segment[pos];
	}
 
	int newR = (l + r) / 2;
	int newL = (l + r) / 2 + 1;
	int p1 = getMin(segment, l, newR, a, b, pos * 2 + 1);
	int p2 = getMin(segment, newL, r, a, b, pos * 2 + 2);
	return min(p1, p2);
}
 
int buildMaxSegment(vector<int> &segment, vector<int> &src, int l, int r, int pos)
{
	if (l > r)
	{
		return -1e9;
	}
 
	if (l == r)
	{
		segment[pos] = src[l];
		return src[l];
	}
 
	int newR = (l + r) / 2;
	int newL = (l + r) / 2 + 1;
	int p1 = buildMaxSegment(segment, src, l, newR, pos * 2 + 1);
	int p2 = buildMaxSegment(segment, src, newL, r, pos * 2 + 2);
	return segment[pos] = max(p1, p2);
}
 
int getMax(vector<int> &segment, int l, int r, int a, int b, int pos)
{
	if (a > r || l > b)
	{
		return -1e9;
	}
 
	if (l >= a && b >= r)
	{
		return segment[pos];
	}
 
	int newR = (l + r) / 2;
	int newL = (l + r) / 2 + 1;
	int p1 = getMax(segment, l, newR, a, b, pos * 2 + 1);
	int p2 = getMax(segment, newL, r, a, b, pos * 2 + 2);
	return max(p1, p2);
}

void answer()
{
  int n;
  cin >> n;
  vector<int> vec(n);
  vector<int> src(n);
  vector<int> vis(n + 1 , 0);
  for(int i = 0 ; i < n ; i++) {
    cin >> vec[i];
    src[i] = i + 1;
  }
  
  vector<int> maxSegment(4 * n);
  buildMaxSegment(maxSegment , src , 0 , n - 1 , 0);
  vector<int> ans;
  for(int i = 0 ; i < n ; i++) {
    if(vis[vec[i]] == 0) {
      ans.push_back(vec[i]);
      vis[vec[i]]++;
      update(0 , n - 1 , vec[i] - 1 , -1 , 0 , maxSegment , src);
    } else {
      int target = getMax(maxSegment , 0 , n - 1 , 0 , vec[i] - 1 , 0);
      if(target == -1) {
        cout << "-1\n";
        return;
      }
      vis[target]++;
      update(0 , n - 1 , target - 1 , -1 , 0 , maxSegment , src);
      ans.push_back(target);
    }
  }
  
  for(int ind : ans) {
    cout << ind << ' ';
  }
  cout << "\n";
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