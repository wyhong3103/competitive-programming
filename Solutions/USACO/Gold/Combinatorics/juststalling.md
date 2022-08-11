```
We could sort the height of the cows and stalls

And use 2 pointers to determine how much stalls a cow can fit into, one notably thing in here is that, smaller cow can always fit into stalls that bigger cows can fit into.

The combinatorics behind this is simply the product rule

Say we got 4 cows with height 1, 2, 3, 4

Cows with height 1 and 2, can fit into 4 stalls
Cows with height 3 can fit into 3 stalls
Cows with height 4 can fit into 2 stalls

The idea of solving this problem is to start multiplying from the tallest cow, and subtract 1 on used stalls as we multiply from taller cow to shorter cow, this is because stalls that a bigger cow can fit into also means a smaller cow can fit into, so each time we do subtract 1 on use stalls, that means smaller cows have 1 less stall to fit , because it's already chosen.

So the solution to this problem is , 2 * (3-1) * (4-2) * (4-3), which gives 8

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

void solve(){
    int n;
    cin >> n;

    vi a(n);
    vi b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    sort(all(a));
    sort(all(b));

    vi loc(n);
    int p1 = 0, p2 = 0;
    int sm = 0;
    while (p1 < n && p2 < n){
        if (a[p1] > b[p2]){
            p2++;
            sm++;
        }else{
            loc[p1] = n-sm;
            p1++;
        }
    }

    if (p1 != n){
        cout << 0;
        return;
    }

    ll res = 1;
    int used = 0;
    for(int i{n-1}; i >= 0; i--){
        res *= loc[i]-(used++);
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