```


It is pretty obvious that we need to binary search L. but how do we find validate L?

Well, there's a way to find the largest square in the 2D grid.

This is sort of like DP.

To constuct a square that is size of x at [i,j], largest square at [i-1,j-1] must be x-1, and the number of consecutive cells in the row[i] and col[j] until current cell must be >= x as well! (including [i,j])

But this is not always the case, number of consecutive cells in row and col will not always >= x, when that's the case, largest square at [i,j] is simply min(row[i], col[i])+1.

Else, size at [i,j] is simply 1.

Repeat the above recurrence formula, we're going to get the largest square!

And then just verify it.

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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<vi> a(n, vi(m));
 
    for(auto& i : a){
        for(auto& j : i) cin  >> j;
    }
 
    int lo = 1, hi = 1e6;
    while (hi > lo){
        int mid = lo + (hi-lo+1)/2;
 
        vector<vi> temp(n, vi(m));
        vector<vi> row(n, vi(m));
        vector<vi> col(n, vi(m));
        vector<vi> si(n, vi(m));
        bool found = 0;
        for(int i{}; i < n; i++){
            for(int j{}; j < m; j++){
                if (a[i][j] >= mid){
                    temp[i][j] = 1;
                    row[i][j] = (!i ? 0 : row[i-1][j]) + 1;
                    col[i][j] = (!j ? 0 : col[i][j-1]) + 1;
 
                    si[i][j] = 1;
                    if (i && j && temp[i-1][j-1] && temp[i-1][j] && temp[i][j-1]){
                        if (row[i-1][j] >= si[i-1][j-1] && col[i][j-1] >= si[i-1][j-1]) si[i][j] = si[i-1][j-1] + 1;
                        else{
                            si[i][j] = min(row[i-1][j], col[i][j-1]) + 1;
                        }
                    }
                    
 
                    found |= si[i][j] == mid;
                }
            }
        }
 
        if (found) lo = mid;
        else hi = mid-1;
    }
    cout << lo << '\n';
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