My first DSU problem, ever.
```

The idea is pretty simple.

Let's start with the first observation, notice that we have E powerlines, and we remove them one by one in accordance to the order of q, by reversing the process, this entire task just seems so much simpler than how it seemed to be. Essentially, we have E powerlines, we start adding edges (reversed order of q) and then prints out the total number of cities that are electrified.

But now here comes the problem, how can we efficiently add edges between potentially big components and merge them together as one even bigger component? DSU comes to the rescue.

Basically, we could DSU to union the disjoints set in an almost constant time complexity. More on DSU, you can look up on CF EDU section which provides a really great lecture on DSU.

Instead of just using ranking & parents array, we also need the number of cities for each component with leader of the component = i, and an array to keep track of the state of the component with leader = i. (whether it's electrified or not)

The two operation (adding cities of two component & electrify one another) are an associative & commutative operation. Therefore, it can be performed on dsu union as well.

Each time we add an edge, we remove the cities on initial components that are electrified from the result, and then add the one after union, to avoid double counting.
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

const int MX = 200005;
int cities[MX];
int ranking[MX];
bool isElectrified[MX];
int parent[MX];
    
int dsu_get(int a){
    return parent[a] = (parent[a] == a ? parent[a] : dsu_get(parent[a]));
}

void dsu_union(int a, int b){
    a = dsu_get(a);
    b = dsu_get(b);
    
    if (a == b) return;
    if (ranking[a] == ranking[b]) ranking[a]++;

    if (ranking[a] > ranking[b]){
        parent[b] = a;
        cities[a] += cities[b];
        isElectrified[a] |= isElectrified[b];
    }else{
        parent[a] = b;
        cities[b] += cities[a];
        isElectrified[b] |= isElectrified[a];
    }
}

void solve(){
    int n, m, e;
    cin >> n >> m >> e;

    for(int i{}; i < n+m; i++){
        if (i < n) cities[i] = 1;
        else isElectrified[i] = 1;
        parent[i] = i;
    }


    vector<pi> lines;
    for(int i{}; i < e; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        lines.pb({u,v});
    }

    int q;
    cin >> q;
    vector<bool> initial(e, 1);
    vi events;
    for(int i{}; i < q; i++){
        int x;
        cin >> x;
        x--;
        initial[x] = 0;
        events.pb(x);
    }

    int cur = 0;
    for(int i{}; i < e; i++){
        if (initial[i]){
            set<int> temp_parents;
            temp_parents.insert(dsu_get(lines[i].fir));
            temp_parents.insert(dsu_get(lines[i].sec));
            for(auto& j : temp_parents){
                if (isElectrified[j]){
                    cur -= cities[j];
                }
            }
            dsu_union(lines[i].fir, lines[i].sec);
            if (isElectrified[dsu_get(lines[i].fir)]) cur += cities[dsu_get(lines[i].fir)];
        }
    }

    vi res(q);

    for(int i{q-1}; i >= 0; i--){
        res[i] = cur;
        int event = events[i];
        set<int> temp_parents;
        temp_parents.insert(dsu_get(lines[event].fir));
        temp_parents.insert(dsu_get(lines[event].sec));
        for(auto& j : temp_parents){
            if (isElectrified[j]){
                cur -= cities[j];
            }
        }
        dsu_union(lines[event].fir, lines[event].sec);
        if (isElectrified[dsu_get(lines[event].fir)]) cur += cities[dsu_get(lines[event].fir)];
    }
    for(auto& i : res) cout << i << '\n';
    
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