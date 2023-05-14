```

kay basically, for an array, the answer is the sum of the length of each shortest disjoint segments s.t there are no inversion pairs between different segments

so if u understood this, we can move on to dp on range, where 

dp[i][j] = minimal cost needed to sort the subarray [i,j]

for each dp transition at dp[i][j], we only have to know about the leftmost element of the disjoint segment that consist of element j, let it be l so dp[i][j] = dp[i][l-1] + (j-l), s.t l >= j

the challenging part is to figure out how to precompute the leftmost element of the disjoint segment that consists of element i for every subarray s.t endpoint = i

To precompute the above, we run the following algorithm

for(int i{}; i < n; i++){
    int mn = a[i];
    int cur = a[i];
    for(int j{i-1}; j >= 0; j--){
        if (cur < a[j]){
            cur = mn;
            e[i][j] = j;
        }else{
            e[i][j] = (j == i-1 ? i : e[i][j+1]);
            mn = min(mn, a[j]);
        }
    }
}

We let current = a[i], and from j-1 to 0, we set the lefmost index of the segment that consists of element i when lefmost element is j, e[i][j] according to following cases

If a[j] > current, that means min needs to be here, so e[i][j] = j and let current = min

else we just let e[i][j] = e[i][j+1] since if a[j] < current, we dont need to move current to here, so answer would be the same

The reason we let current = min, is cus of the following case

4 2 5 3

a[i] = 3, at a[i-1] = 5, it is an inversion so we need to let e[i][i-1] = i-1, 

and at a[i-2] = 2, we dont have to do anything! 

BUT, at a[i-3] = 4, we have to switch sort 3 into here, but 2 is smaller and it also needs be taken into account, so 2 become the our current element, since it is part of the inversion segment! we need to get the smallest segment to the leftmost!

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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i;
 
    vector<vi> e(n, vi(n));
 
    for(int i{}; i < n; i++){
        int mn = a[i];
        int cur = a[i];
        for(int j{i-1}; j >= 0; j--){
            if (cur < a[j]){
                cur = mn;
                e[i][j] = j;
            }else{
                e[i][j] = (j == i-1 ? i : e[i][j+1]);
                mn = min(mn, a[j]);
            }
        }
    }
 
    vector<vi> dp(n, vi(n));
 
    for(int i{2}; i <= n; i++){
        for(int j{}; j <= n-i; j++){
            dp[j][j+i-1] = i-1;
            dp[j][j+i-1] = min(dp[j][j+i-1], dp[j][max(0,e[j+i-1][j]-1)] + (j+i-1 - e[j+i-1][j]));
        }
    }
 
    ll total = 0;
    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++) total += dp[i][j];
    }
    cout << total << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```