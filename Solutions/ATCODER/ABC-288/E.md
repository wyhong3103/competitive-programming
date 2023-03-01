```

we have N items,

we need to buy all the N items, 

to buy an item , we follow the following way,

let k be the unsold items now, choose an integer j <= r, buy the item with the j-th smallest id among the unsold item, for its regular price + cj

This can be solved greedily

Note that we will have to pay for sum(price[i]) regardless

greedy : find the smallest c_j buy every item after c_j, bc its guarantee that if we dont buy item after j with c_j it would cost higher, until we clear all the items


But how do we solve it when it involves choosing a subset of the item? (The original problem)

One main observation is that the extra cost of the i-th item would only be affected by its previous element! As we take an item with greater ID, it would only affect the order of the later items but not the earlier ones.

We could solve this by using knapsack DP, and then we'll discuss how the above observation helps to solve this problem in the transition.

DP state

dp[i][j] = minimal cost after processing first i items s.t current knapsack has j items

if i is a must take item

dp[i][j] = dp[i-1][j-1] + minimal cost from c[i-j] to c[i] + price[i]

Why we can do the above?

let's not care about the order, one thing we know is that, taking the later element wouldn't affect us at all. we could just buy the i-th item when first x (0 <= x <= j) is being sold, it wouldn't affect the price at all! In plain words, in a subset of j items that we're going to buy, we can buy the i-th item in any order, and if we decide to buy it after x items, then it is guaranteed that the cost for item j is going to be c[i-x] this is because x items before i is being sold! And by doing this it wouldn't affect any other items that we haven't bought! 

else

dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + minimal cost from c[i-j] to c[i] + price[i])

We have to make sure that we have taken all the must take item in the knapsack!

Check the imeplementation!


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


// Segment tree for min
struct SegTree{
    ll size;
    vll val;
    
    ll NEUTRAL_ELEMENT = LONG_LONG_MAX;

    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.assign(2*size, 0LL);
    }
 
    ll merge(ll a, ll b){
        return min(a, b);
    }

    void buildHelper(vll& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)){
                val[x] = a[lx];
            }
            return;
        }
 
        int m = (lx+rx)/2;
        buildHelper(a, (x*2)+1, lx, m);
        buildHelper(a, (x*2)+2, m, rx);
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void build(vll& a){
        buildHelper(a, 0, 0, size);
    }

    // Make sure it runs in O(log N), eliminate the segment that is impossible, return the segment that is fully covered
    ll queryHelper(int l, int r, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r){
            return val[x];
        }
        int m = (lx + rx) / 2;
        return merge(queryHelper(l, r, (x*2)+1, lx, m), queryHelper(l, r, (x*2)+2, m, rx));
    }
 
    ll query(int l, int r){
        return queryHelper(l, r, 0, 0, size);
    }
};

void solve(){
    int n, m;
    cin >> n >> m;

    vll a(n);
    for(auto& i : a) cin >> i;

    vll c(n);
    for(auto& i : c) cin >> i;

    vi must(n);
    for(int i{}; i < m; i++){
        int x;
        cin >> x;
        x--;
        must[x] = 1;
    }

    vector<vll> dp(n+5, vll (n+5, LONG_LONG_MAX));

    dp[0][0] = 0;

    SegTree st;
    st.init(n+5);
    st.build(c);

    int cnt = 0;
    ll res = LONG_LONG_MAX;
    for(int i{1}; i <= n; i++){
        dp[i][0] = 0;
        for(int j{1}; j <= n; j++){
            if (dp[i-1][j-1] == LONG_LONG_MAX) break;
            if (j < cnt+1){
                dp[i][j] = dp[i-1][j];
            }
            else{
                if (must[i-1]){
                    dp[i][j] = dp[i-1][j-1] + st.query(i-j,i) + a[i-1];
                    // If last item
                    if (cnt + 1 == m) res = min(res, dp[i][j]);
                }else{
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + st.query(i-j,i) + a[i-1]);
                }
            }
        }
        cnt += must[i-1];
    }

    cout << res;
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