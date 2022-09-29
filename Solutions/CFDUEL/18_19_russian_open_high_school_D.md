```

We basically need to find a pair of element that is not adjacent (do not have a direct edge to each other). And we can make them the smallest, (in a, let i = 1, j = 2, in b, i = 1, j = 2) and then simply assign the number.

My initial approach was to assign a directed edge (bigger -> smaller) and then try to flip the edge manually. But that was unnecessary, we manually set the relation of all, and then trying to manually reset the solution. The above was the smarter approach where we start off with no relation and then set our desired pair to whatever we want and then only assign the relation.

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

ll nc2(ll n){
    ll nom = n * (n-1);
    return nom / 2;
}

const int MX = 1e5;
vi adj[MX];

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i{}; i < m; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    if (n == 1 || nc2(n) == m){
        cout << "NO" << '\n';
        return;
    }

    vi a(n);
    vi b(n);
    
    pi found {-1,-1};
    for(int i{}; i < n; i++){
        if (sz(adj[i]) != n-1){
            set<int> s;
            for(int j{}; j < n; j++){
                if (j == i) continue;
                s.insert(j);
            }
            for(auto& j : adj[i]){
                s.erase(j);
            }
            found = {i, *s.begin()};
            break;
        }
    } 

    a[found.fir] = 1;
    a[found.sec] = 2;
    b[found.fir] = 1;
    b[found.sec] = 1;
    
    int cur = 3;
    for(int i{}; i < n; i++){
        if (!a[i]){
            a[i] = cur;
            b[i] = cur;
            cur++;
        }
    }
    cout << "YES" << '\n';
    for(auto i : a) cout << i << ' ';
    cout << '\n';
    for(auto i : b) cout << i << ' ';

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