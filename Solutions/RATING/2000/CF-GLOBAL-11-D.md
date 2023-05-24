```

We can simulate the sorting process by making the optimal move.

We can only perform at most n moves, so we need to make sure that we can sort one adjacent pairs in each move.

How?


. . . . j . . . i . . . .

If the array is unsorted, it is guaranteed that we will have the siutaiton above where j is the next element of i in the sorted array!

Because our operation forces the element to reverse, which means two adjacent groups will still be adjcent to each other but reversed.

So the idea is to group them like below

. . . . [j . .] [. i]. . . .

. . . .  [. i] [j . .]. . . .

By doing the above we can sort them in N operations.

To make sure the process goes smoother, we can first merge every group that is the consecutive sorted segment. And then for any two groups, i and j, s.t i > j, if first element in j is the next element of last element of group i, then we perform the above. For any intermediate group between group i and j, we could just pretend as if it was part of group i.

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

bool ok(vi& a){
    int prev = -1;
    for(auto& i : a){
        if (i < prev) return false;
        prev = i;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;

    vi b = a;
    sort(all(b));
    
    map<int,int> nxt;

    for(int i{}; i < n-1; i++){
        nxt[b[i]] = b[i+1];
    }

    vector<vi> res;

    while(!ok(a)){
        vector<vi> g;
        vi temp = {a[0]};
        for(int i{1}; i < n; i++){
            if (a[i] == nxt[a[i-1]] || a[i] == a[i-1]) temp.pb(a[i]);
            else{
                g.pb(temp);
                temp = {a[i]};
            }
        }
        g.pb(temp);

        bool found = 0;
        int m = sz(g);
        for(int i{}; i < m; i++){
            for(int j{}; j < i; j++){
                if (g[i].back() == g[j][0] || nxt[g[i].back()] == g[j][0]){
                    vi moves;
                    for(int k{}; k <= j; k++) moves.pb(sz(g[k]));
                    int si = 0;
                    for(int k{j+1}; k <= i; k++) si += sz(g[k]);
                    moves.pb(si);
                    for(int k{i+1}; k < m; k++) moves.pb(sz(g[k]));

                    res.pb(moves);
                    
                    vi tempa;
                    int at = n-1;
                    for(int k{sz(moves)-1}; k >= 0; k--){
                        at -= moves[k];
                        for(int x{1}; x <= moves[k]; x++){
                            tempa.pb(a[at+x]);
                        }
                    }
                    a = tempa;
                    found = 1;
                }
                if (found) break;
            }
            if (found) break;
        }

    }

    cout << sz(res) << '\n';
    for(auto& i : res){
        cout << sz(i) << '\n';
        for(auto& j : i) cout << j << ' ';
        cout << '\n';
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