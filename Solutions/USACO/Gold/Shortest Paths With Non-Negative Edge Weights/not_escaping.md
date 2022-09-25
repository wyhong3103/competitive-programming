```

My very first attempt on this problem was about using dijkstra's, and came with a little trick to handle negative weight which turned out to be false.

My second attmept has the right approach, in fact, it is the same approach that I had with the AC solution, only difference is the way I store the ladders/dist of each coordinates.

First, let's talk about the approach then later talk about the way I stored relevant informations.

First off, obiviously, it is impossible to do dijkstra's because of the negative weigted edge, and I learned the hard way on my first attempt.

Then, come to think about it, the way this graph formed, is like a directed acyclic graph, and basically DP on DAG, we could process the graph level by level (floor by floor), it's like topological sorted order and do the DP, but there's no need to do top sort, as it's already top sorted in the beginning (floor to floor).

Now we figured out how to do DP on the graph. My initial approach is to naively do DP on each ladder and then whenever we reach the new endpoint, also try to DP on all the accesible rooms on the new floor (which is ladder's endpoint).

But that would obviously give k^2.

So I figured out a better way to handle the shortest distance on the same floor. (which is not dijkstra's, although i could've use dijkstra's)

Basically, we only process the shortest distance on the same floor when we reach that floor (after processing DP on all the floors before).

And the idea is pretty simple,

Let's look at one example


2x x A x 2x 3x 4x

Say we're at A, and as you can see the adjacent cells are distanced by x, 2x, 3x.

In this case, we can easily use segtree to get the minimal element in the current array.

As we move on to the next one, it became,

3x 2x x A x 2x 3x

Notice that, every element on the left +x, and every on the right -x.

Now the alternative : using orderd set to get the minimal element after adding x to their corresponding distance, although we couldn't do range query adding and subtracting, but we didn't need that, as adding and subtracting doesn't change their relative order, we could still get the minimal element, but only we need to keep track of the how much we need to +, or -.

We could use two set, {after} and {before}.

{after} store the elements after the current element. 

{before} store the elements before the current element.

Every value of the element in after is dist[i][j] + (x[i] * j)

Every value of the element in before is dist[i][j] + (x[i] * (m-1-j))

To retrieve the real value we need at k, it's simply, dist[i][j] - x[i] * (k or m-1-k depends on whether it's after or before).

And this is it, it's not so simple compared to dijkstra's though. I think it's better if we used dijkstra's.

And that would solve the problem.

But the weird thing is using hash map/ ordered_map to store the coordinate and their corresponding value will get TLE. Lesson learned I guess, when dealing with coordinated compressed item, avoid using the coordinate as a key, try to reduce one of the dimension to array.
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

struct Ladder{
    pi f,t;
    ll w;
};

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vi> adj_f(n);
    vector<vector<Ladder>> ladders(n);
    vector<map<int,ll>> dist(n);

    vll x(n);
    for(auto& i : x) cin >> i;

    for(int i{}; i < k; i++){
        pi f, t;
        ll w;
        cin >> f.fir >> f.sec >> t.fir >> t.sec >> w;
        f.fir--;
        f.sec--;
        t.fir--;
        t.sec--;

        adj_f[f.fir].pb(f.sec);
        adj_f[t.fir].pb(t.sec);
        ladders[f.fir].pb({f, t, w});
        dist[f.fir][f.sec] = LONG_LONG_MAX;
        dist[t.fir][t.sec] = LONG_LONG_MAX;
    }

    dist[n-1][m-1] = LONG_LONG_MAX;
    dist[0][0] = 0;
    adj_f[n-1].pb(m-1);
    adj_f[0].pb(0);


    for(int i{}; i < n; i++){
        if (!sz(adj_f[i])) continue;

        set<pll> after;
        set<pll> before;
        
        sort(all(adj_f[i]));
        for(auto& j : adj_f[i]){
            if (dist[i][j] == LONG_LONG_MAX) continue;
            after.insert({{dist[i][j]+(j*x[i])}, j});
        }

        for(int j{}; j < sz(adj_f[i]); j++){
            ll after_sm = adj_f[i][j] * x[i];
            ll before_sm = ((m-1)-adj_f[i][j]) * x[i];
            pi at = {i, adj_f[i][j]};
            if (dist[at.fir][at.sec] != LONG_LONG_MAX) after.erase({dist[at.fir][at.sec]+after_sm, adj_f[i][j]});
            if (sz(after))
                dist[at.fir][at.sec] = min(dist[at.fir][at.sec], (*after.begin()).fir-after_sm);
            if (sz(before))
                dist[at.fir][at.sec] = min(dist[at.fir][at.sec], (*before.begin()).fir-before_sm);
            if (dist[at.fir][at.sec] != LONG_LONG_MAX) before.insert({dist[at.fir][at.sec]+before_sm, adj_f[i][j]});
        }

        for(auto& j : ladders[i]){
            if (dist[i][j.f.sec] == LONG_LONG_MAX) continue;
            dist[j.t.fir][j.t.sec] = min(dist[j.t.fir][j.t.sec], dist[i][j.f.sec] - j.w);
        }
    }

    if (dist[n-1][m-1] == LONG_LONG_MAX ){
        cout << "NO ESCAPE" << '\n';
    }else{
        cout << dist[n-1][m-1] << '\n';
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