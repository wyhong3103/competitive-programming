```

Implementation problem

We try to map a picture to its previous one (i.e the one with the least changes!)

Because the answer is guaranteed to exist so above would work.

A picture is a possible candidate for previous iff every different cell of it compared to current picture, let it be r, c, at curent picture [x,y] it must be flipped! (i.e formed a cross of same color with 4 adjcent cell of its)

So we can sort of use a linked list to deal with it.

Do a bfs at the end, to simulate the process.

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
 
vi dr = {1, -1, 0, 0} ;
vi dc = {0, 0, 1, -1} ; 
 
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
 
    k++;
 
    vector<vector<string>> a(k);
    for(auto& i : a){
        i.resize(n);
        for(auto& j : i) cin >> j;
    }
 
    vector<vector<pi>> op(k);
    vector<vi> next(k);
    vi prev(k, -1);
 
    for(int i{}; i < k; i++){
 
        //{changes, index}
        pi least{INT_MAX, -1};
        for(int j{}; j < k; j++){
            if (i == j) continue;
 
            bool ok = 1;
            vector<pi> diff;
            for(int r{1}; r < n-1; r++){
                for(int c{1}; c < m-1; c++){
                    if (a[i][r][c] != a[j][r][c]) diff.pb({r,c});
                }
            }
 
            if (!sz(diff)) continue;
 
            for(auto& t : diff){
                for(int d{}; d < 4; d++){
                    ok &= a[i][t.fir+dr[d]][t.sec+dc[d]] == a[i][t.fir][t.sec];
                }
            }
 
            if (ok && sz(diff) < least.fir){
                least = {sz(diff),j};
            }
        }
        
        if (least.fir != INT_MAX){
            next[least.sec].pb(i);
            prev[i] = least.sec;
 
            for(int r{1}; r < n-1; r++){
                for(int c{1}; c < m-1; c++){
                    if (a[i][r][c] != a[least.sec][r][c]) op[least.sec].pb({r,c});
                }
            }
        }
    }
 
    vi starts;
    for(int i{}; i < k; i++){
        if (prev[i] == -1){
            starts.pb(i);
        }
    }
    
 
    vector<pi> res;
 
    if (sz(starts) > 1){
        for(int i{1}; i < sz(starts); i++) res.pb({starts[i], -1});
    }
 
    queue<int> q;
    q.push(starts[0]);
 
    set<pi> used;
    while (!q.empty()){
        int cur = q.front(); q.pop();
 
        for(auto& i : op[cur]){
            if (!used.count(i)) res.pb(i);
            used.insert(i);
        }
 
        for(auto& i : next[cur]){
            res.pb({i, -1});
            q.push(i);
        }
    }
 
    cout << starts[0]+1 << '\n';
    cout << sz(res) << '\n';
    for(auto& i : res){
        if (i.sec == -1){
            cout << 2 << ' ' << i.fir+1 << '\n';
        }else{
            cout << 1 << ' ' << i.fir+1 << ' ' << i.sec+1 << '\n';
        }
    }
    
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