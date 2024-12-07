#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
   string s;
   int n;
   cin >> n >> s;
   vector<int> cnt(26 , 0);
   for(char ch : s) {
    cnt[ch - 'a']++;
   }
   sort(s.begin() , s.end());

   int k = s.size();
   while(k) {
    for(int i = 0 ; i < 26 ; i++) {
        if(cnt[i]) {
            cnt[i]--;
            k--;
            cout << (char)(i + 'a');
        }
    }
   }
   cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        answer();
    }

    return 0;
}