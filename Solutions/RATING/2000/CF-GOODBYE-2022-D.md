```

Abridged Statement : 

In array a, array b, and array c, For each multiset of {ai, bi, ci}, koxia can remove one of the element from the multiset, and the opponent is going to choose one of the two element left from the multiset. Let it be xi, if all the xi forms a permutation at the end, koxia wins.

We are to find the total number of array c s.t koxia will always win if they both played optimally.

Observation :

Koxia can only win if all the multiset with one element removed is the same element, and all the multiset are distinct elements.

The idea is, if we have {ai, bi} left in the multiset and ai != bi, and because we need the opponent to select a permutation to win, which implied there will be another ai and bi in other multiset, this is because, if we are to choose ai from this multiset, which mean we need bi in the other. So to avoid choosing a permutation, opponnet can just choose two bi or two ai, to have a non permutation xi selected.

So from this observation, it's obvious that we always need to let the two element remaining in a multiset to be the same.

If ai != bi, we can use ci to be ai and to remove bi from the multiset, so that we have 2 ai, and opponent is forced to choose ai, or the other way round. 

If ai == bi, ci can be anything, since the only possible two same elements are just ai, so we can have any ci and remove it. (not hard to see why is this)

So, in order to win, we need to have all the number that remained in the multiset to be distinct.

And here's how we check it.

Have a graph with nodes 1 to n, and with edges (ai,bi) for every i.

This edge i is directed, and it represents which element we choose to use for (ai,bi).

The idea is to have every node in this graph with only 1 indegree.

In order to have every node to have only 1 indegree, for every connected component that is size n, there must be n edges, if more than that, we will have more than 1 indegree for some nodes.

A connected component that has n edges and n nodes, is basically a graph with only one cycle, the idea is when we only have n-1 edges we have a tree, we add more more edge, we form a cycle.

How many total ways to assign direction in such a graph? well just 2.

Proof : 

The only variation in the directions we can have in this graph is basically the cycle, we can do clockwise and anticlockwise direction. The nodes that arent in a cycle, stay the same direction. You can kind of visualize it like the below

				  o --> o
				  ^	
				  |	
o <-- o <-- o <-- o --> o --> o
				  ^		      |
				  |		      |
				  |	 	      v
				  o	<-- o <-- o


The head of the cycle, the one node that is basically connected to the tails, let the edges it has be y, y-2 edges should always point out, another 2 is the one where it involves in a cycle.

As you can see we can only change clockwise and anticlockwise, if we changed more than that, some node will not be pointed and this node wil be pointed more than once.

Special case : 

A connected component with self loop, (ai == bi), we can't really do clockwise and anticlockwise in this situation, but what we can do is, use any number, ci because we would still have ai chosen for the i-th multiset.

We can easily find the number of components that has no self loop and number of component that has.

Answer is just 2^(number of component with no self loop) * n^(number of components with self loop)

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
 
const int MOD = 998244353;
 
int get(int a, vi& parent){
    return parent[a] = (parent[a] == a ? a : get(parent[a], parent));
}
 
void merge(int a, int b, vi& parent, vi& edges, vi& siz, vi& one){
    a = get(a,parent);
    b = get(b,parent);
 
    if (a == b){
        edges[a]++;
        return;
    }
 
    if (siz[a] > siz[b]){
        siz[a] += siz[b];
        edges[a]++;
        edges[a] += edges[b];
        parent[b] = a;
        one[a] |= one[b];
    }else{
        siz[b] += siz[a];
        edges[b]++;
        edges[b] += edges[a];
        parent[a] = b;
        one[b] |= one[a];
    }
}
 
 
ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p / 2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? sq * n : sq) % MOD;
}
 
void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    vi siz(n);
    vi parent(n);
    vi edges(n);
    vi one(n);
 
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
    
    
    for(int i{}; i < n; i++){
        a[i]--;
        b[i]--;
        if (a[i] == b[i]) one[a[i]] = 1;
        parent[i] = i;
        siz[i] = 1;
        edges[i] = 0;
    }
 
    for(int i{}; i < n; i++){
        merge(a[i], b[i], parent, edges, siz, one);
    }
 
    set<int> cc;
    set<int> sc;
    for(int i{}; i < n; i++){
        int p = get(i, parent);
        if (siz[p] != edges[p]){
            cout << 0 << '\n';
            return;
        }
        if (one[p]) sc.insert(p);
        else cc.insert(p);
    }
 
    cout << (modpow(2,(ll)sz(cc)) * modpow(n, (ll)sz(sc))) % MOD << '\n';
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