You might be tempted to think this problem as an LCS problem, but it's really not. If we were to do it in LCS fashion, it will took O(N^2). But because of the fact that these two sequences are permutation, we could do things like LIS.
```
For example, say we have the sequence below

5
3 2 1 4 5
1 2 3 4 5

We could see this question in this way, in order for i to pair up with j they have to form a line

3 2 1 4 5
 \    | |
  \   | |
   \  | | 
1 2 3 4 5

And this is exactly the thing, there will be line between i in b and j in b such that (a[i] == b[j])

And our job is to find the longest pairs such that none of the segments intersect, and we could do this with LIS.
```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

 
void solve(){
    int n;
    cin >> n;
    
    vi perm(n);
    for(int i{}; i < n; i++){
        int p;
        cin >> p;
        p--;
        perm[p] = i;
    }
    vi a(n);
    for(int i{}; i < n; i++){
        int p;
        cin >> p;
        p--;
        a[i] = perm[p];
    }

    vi dp(n+1);
    fill(all(dp), INT_MAX);
    dp[0] = -dp[0];
    
    for(int i{}; i < n; i++){
        int at = upper_bound(all(dp), a[i]) - dp.begin();
        dp[at] = a[i];
    }
    int mx = 0;
    for(int i{}; i <= n; i++){
        if (dp[i] != INT_MAX) mx = max(mx, i);
    }

    cout << mx;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}


```