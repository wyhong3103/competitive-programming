
Observations : 

1. If $n-1 \gt x$ , it is impossible to form such a tree, because even if we use all the edges only once, we would still have bigger sum.
2. From root, there will never need to be more than $1$ child, because let's say we have two linked list from root, the sum of distance from leaf to root would be the same as if we have one linked list with the length of both linked list.

Solution :

From the observations, we know that we only need one long linked list. So this gives us an idea to check every possible $m$ for the length of the linked list.

Linked list with length $m$ is possible if and only if $(n-(m+1)) * m \geq x - m$ and $(n-(m+1)) \leq x$, the reason is simple, if we have linked list of length $m$, the maximal possible sum with the rest of the nodes must be greater or equal to $x-m$ , otherwise it is impossible to form it. For the second condition, refer to the first observation.

How do we prove that if the current linked list of length $m$ fulfills the condition, one construction always exist?

Let's model the problem into an equation first,

$$ a_1 * 1 + a_2 * 2 + a_3 * 3 + ... + a_m * m = x - m $$

We basically need to fulfill the above equation such that $\sum_{i}^m a_i = n - (m + 1)$ .

We can greedily do this.

Let remaining score be $remain$, and remaining nodes be $node$

The idea is to start from $m$ to $1$, let current length be $i$, take as many $i$ as possible, as long as $node \leq remain$.  At the end, we'll get our desired construction.

Proof :

We're always making sure $node \leq remain$ hold, and $node * i \geq remain$, if any of this violates, we'll never able to get our desired score with the nodes. Notice that $remain$ always converges, and at each $i$, $remain$ will be reduced to the range of $[node, node + i]$, which implied at $i = 1$ , if $x \neq 0$,  then $x = node$. Notice that if $x = node + 1$ at $i = 1$, this would means at $i = 2$, we did not perform the necessary operation. 

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    ll n, x;
    cin >> n >> x;
 
    for(ll i{1}; i < n; i++){
        //max dist is i
        if ((n-(i+1)) * i >= x - i && n-(i+1) <= x - i){
            ll cur = x-i;
            ll remain = n-(i+1);
            vi res(i);
            for(int j{i}; j >= 1; j--){
                while (cur-j >= 0 && remain && cur - j >= remain - 1){
                    cur -= j;
                    remain--;
                    res[j-1]++;
                }
            }
 
            for(int j{1}; j <= i; j++){
                cout << j << ' ' << j+1 << '\n'; 
            }
            int node = i+2;
            for(int j{}; j < i; j++){
                for(int k{}; k < res[j]; k++){
                    cout << j+1 << ' ' << node << '\n';
                    node++;
                }
            }
            
 
            return;
        }
    }
    cout << -1 << '\n';
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