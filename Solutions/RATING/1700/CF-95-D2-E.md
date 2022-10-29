There has been a lot of similar queen questions in old CF problemsets, and it's just way too easy for today's 1700.
```

Anways my idea is (not optimized obviously.)

Store the ys on the same x axis, and do the same for xs on the same y axis.

This way, to know whether we can attack a queen that is on the same row/col. We simply need to binary search the x axis to see if we're the last queen/first queen. If we're not the last, there must be one in front for us to attack, if we're not the first, there must be one behind for us to attack.

As for diagonal, it's a bit tricker.

Anways, we could store the same thing, but on the (0,y) it points to diagonally. And there's diagonally upward, and diagonally downward. 

4 3

it's pointing to (4+3) upward, and (4-3) downward. Simple math.

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

    map<int,set<int>> row;
    map<int,set<int>> col;
    map<int,set<int>> du;
    map<int,set<int>> dd;
    
    vector<pi> loc(m);
    for(int i{}; i < m; i++){
        pi at;
        cin >> at.fir >> at.sec;
        loc[i] = at;
        row[at.fir].insert(at.sec);
        col[at.sec].insert(at.fir);
        du[at.sec+at.fir].insert(at.fir);
        dd[at.sec-at.fir].insert(at.fir);
    }

    vi res(9);
    vector<int> cnt(m);
    for(int i{}; i < m; i++){
        pi at = loc[i];
        auto r = row[at.fir].lower_bound(at.sec);
        if (r != (--row[at.fir].end())) cnt[i]++;
        if (at.sec != *(row[at.fir].begin())) cnt[i]++;

        auto c = col[at.sec].lower_bound(at.fir);
        if (c != (--col[at.sec].end())) cnt[i]++;
        if (at.fir != *(col[at.sec].begin())) cnt[i]++;

        auto d_u = du[at.fir+at.sec].lower_bound(at.fir);
        if (d_u != (--du[at.fir+at.sec].end())) cnt[i]++;
        if (at.fir != *(du[at.fir+at.sec].begin())) cnt[i]++;

        auto d_d = dd[at.sec-at.fir].lower_bound(at.fir);
        if (d_d != (--dd[at.sec-at.fir].end())) cnt[i]++;
        if (at.fir != *(dd[at.sec-at.fir].begin())) cnt[i]++;
        res[cnt[i]]++;
    }
    for(auto& i : res) cout << i << ' ';
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