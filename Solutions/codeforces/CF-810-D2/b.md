```
We need to be greedy on this problem, we need to make sure the pairs that come to the party can only be even.

So the idea is to simply invite every friends, if the total number of groups is already an even number at the beginning simply return 0

Or else, we will have to remove at most 2 friends

for each pair of m, we get the minimum if we are to remove pair i, 

3 ways of removing pair

removing pairs that are both with even number of neighbours. The idea is if we are to remove one of them, the other would become odd, so, odd-even-odd = even, we get even at last.

remove the odd element in the pair, odd-odd = even

The answer is simply the minimum of them.
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
    int n, m;
    cin >> n >> m;

    vi a(n);
    for(auto& i : a) cin >> i;

    vector<set<int>> adj(n);
    vector<pi> con;
    for(int i{}; i < m; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        con.pb({f,t});
        adj[f].insert(t);
        adj[t].insert(f);
    }

    if (m % 2){
        int bst = INT_MAX;
        for(auto& i : con){
            if (sz(adj[i.fir]) % 2){
                bst = min(a[i.fir], bst);
            } 
            if (sz(adj[i.sec]) % 2){
                bst = min(a[i.sec], bst);
            }
            if (sz(adj[i.fir]) % 2 == 0 && sz(adj[i.sec]) % 2 == 0){
                bst = min(bst, a[i.sec]+a[i.fir]);
            }
        }
        cout << bst << '\n';
    }else{
        cout << 0 << '\n';
    }
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