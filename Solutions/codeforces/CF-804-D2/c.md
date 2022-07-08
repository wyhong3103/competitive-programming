No comment, I failed the combinatorics part.
```
First let's identify some observations I made.

First off, you can imagine having 2 pointer around the i-th element, where the 2 pointers are pointing at the 2 outermost element on both left and right , and that is smaller than the i-th element. The reason we're doing is that,

Say we have

0 x x x x 2 x x x x 1

Notice that, we can move 2 in between 0 and 1, because the MEX is still going to be the same, nothing is going to change. But if we moved it out of the boundaries, the MEX between will become 2, so it became impossible to do.

If the i-th element itself is one of the pointer

Say i-th is 1 in this case

0 x x x x 1

We couldn't move it as well, if we move it to the left the mex of left will increase, if we move it to the right, the mex from 0 to i itself, will become 1.

That's the idea, we only need to maintain this 2 pointers so that we don't get out of the boundary.

Now the combinatorics part.

Say we got the i-th element, and the free spaces is 4, so we multiply our result by 4, after doing this , we must marked this place as taken, then when it comes to next element, the free spaces is 3 , we multiply by 3, do it over and over again until it ends.

The reason why this work, is because of product rule

Say we got 5 element, 2 element can only access 4 positions, and the rest can access all

Now let's consider the first 2 element that can only access the 4 position

First element , 4 position
Second element, 4 position

this would turned out as 4x3, this is because if we've already considered the first element, when we consider the second element, we can see it as 1 position have been taken out, because one of those 4 position have already been considered by the first element. So it's simply product rule.

So it's just multiplication of i-th free spaces

```

```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;
int n;
int fenwick_tree[MAX];

//Sum of [1,k]
int sum(int k){
    int s = 0;
    while (k >= 1){
        s += fenwick_tree[k];
        k -= k&-k;
    }
    return s;
}

//Update
void upd(int k, int x){
    while (k <= n){
        fenwick_tree[k] += x;
        k += k&-k;
    }
}

void solve(){
    cin >> n;

    vi a(n+1);
    for(int i{1}; i <= n; i++) cin >> a[i];


    vi loc(n+1);
    for(int i{1}; i <= n; i++){
        loc[a[i]+1] = i;
        upd(i, 1);
    }

    ll res = 1;
    pi range(INT_MAX, 0);
    for(int i{1}; i <= n; i++){
        range.fir = min(range.fir, loc[i]);
        range.sec = max(range.sec, loc[i]);

        if (loc[i] == range.fir || loc[i] == range.sec){
            upd(loc[i], -1);
        }else{
            int pos = sum(range.sec) - sum(range.fir);
            res = (res * pos) % MOD;
            upd(loc[i], -1);
        }
    }

    
    cout << res << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        memset(fenwick_tree, 0, sizeof(fenwick_tree));
    }
	return 0;
}

```