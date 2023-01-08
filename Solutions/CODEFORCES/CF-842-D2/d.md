```

What does it mean to have one exactly inversion?

Basically a sorted array but two adjacent elmeent is flipped.

We should basically ask ourself what is the min swap to sort an array

It's not hard to see that if a[i] and a[j] is in each other position, we just need one swap.

Let's generalize this,

If we are to model this as a graph problem, there will be cycles. And for each cycle to be sorted we need size[cycle]-1 swaps.

We can do DSU to find all connected components.

Because moves needed for each component we do size[cycle]-1, total moves needed is simply n-number of cycles.

Lastly, check the total moves neeeded for each i, i+1, 1 < i < k.

Claim : if i and i+1 is in the same cycle, answer = n-number of cycles-1

Proof : If they're at the same cycle, we can sort every other element first, and at last, they're the last two remain unsorted (i.e inversed)

Claim : if i and i+1 is not in the same cycle, answer = n-number of cycles+1

Proof : If they're not in the same cycle, we can sort every other element first, and then finally swap them. OR, because they're not in the same cycle, we know that if they're going to take each other position, they're gonnna connect in some way, so we just merge the two component, which gives us one less number of cycles.

Couldn't generalize the above claims during contest, was so close. Missed expert by an inch.

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
 
 
const int MX = 2e5 + 5;
 
struct DSU{
    int size[MX];
    int parent[MX];
    int total;
        
    int get(int a){
        return parent[a] = (parent[a] == a ? parent[a] : get(parent[a]));
    }
 
    bool merge(int a, int b){
        a = get(a);
        b = get(b);
        
        if (a == b) return false;
 
        if (size[a] > size[b]){
            parent[b] = a;
            size[a] += size[b];
        }else{
            parent[a] = b;
            size[b] += size[a];
        }
        total--;
        return true;
    }
};
 
void solve(){
    int n;
    cin >> n;
 
    vi a(n);
    for(auto& i : a) cin >> i;
 
    vi at(n);
 
    DSU dsu;
    dsu.total = n; 
    for(int i{}; i < n; i++){
        dsu.parent[i] = i;
        dsu.size[i] = 1;
        at[a[i]-1] = i;
    }
 
    //move needed = n - total
    for(int i{}; i < n; i++){
        dsu.merge(a[i]-1, i);
    }
 
    int mn = INT_MAX;
    for(int i{}; i < n-1; i++){
        int cur = n-dsu.total;
 
        if (dsu.get(at[i]) == dsu.get(at[i+1])) cur--;
        else cur++;
 
        mn = min(mn, cur);
    }
    cout << mn << '\n';
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