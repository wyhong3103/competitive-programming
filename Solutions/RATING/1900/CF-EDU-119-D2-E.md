```

The idea is we can merge two color together if needed!

And if it's a color that is not in use, we can just create a new identifier for that color etc.

DSU basically, since it's just all about merging !

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


const int MX = 5e5+5;
int ranking[MX];
int parent[MX];
int color[MX];
int to[MX];

struct DSU{
    int get(int a){
        return parent[a] = (parent[a] == a ? parent[a] : get(parent[a]));
    }

    bool merge(int a, int b, int prev, int c){
        a = get(a);
        b = get(b);
        
        if (a == b) return false;

        if (ranking[a] == ranking[b]) ranking[a]++;

        if (ranking[a] > ranking[b]){
            color[a] = c;
            parent[b] = a;
            to[c] = a;
            to[prev] = 0;
        }else{
            color[b] = c;
            parent[a] = b;
            to[c] = b;
            to[prev] = 0;
        }
        return true;
    }
};

void solve(){
    int n;
    cin >> n;

    DSU dsu;

    vi arr;
    int cur = 1;
    while(n--){
        int t;
        cin >> t;
        if (t == 1){
            int x;
            cin >> x;
            if (to[x] == 0){
                color[cur] = x;
                to[x] = cur;
                parent[cur] = cur;
                arr.pb(cur);
                cur++;
            }else{
                arr.pb(to[x]);
            }
        }else{
            int x, y;
            cin >> x >> y;
            if (to[x] != 0 && to[y] == 0){
                color[to[x]] = y;
                to[y] = to[x];
                to[x] = 0;
            }
            else if (to[x] != 0){
                dsu.merge(to[x], to[y],x, y);
            }
        }
    }

    for(auto& i : arr){
        cout << color[dsu.get(i)] << ' ';
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