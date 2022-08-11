Could have solve this question a lot faster, but being stupid for a long while.
```
Basically, in order for a picture to be beautiful, the picture can only be such patterns


X X O O
X X O O
X X O O
X X O O

Or

X X X X
X X X x
O O O O
O O O O

Basically, for each color there has got to be at least 2 row/col according to your setting, if your setting is column, the pattern must be in column, otherwise row. Just greedy over the colors really, start with the one with the greatest number of pigment. But we have to be careful while doing greedy on it, we will sometimes overtake it (taking too much). So the idea is, to take just the amount we need for 2 row/col from each color that can be taken, from greatest to lowest. And store the color we took, and then we can simply grabbing as much as possible from those color we selected.

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
    ll n, m, k;
    cin >> n >> m >> k;

    vll a(k);
    for(auto& i : a) cin >> i;

    sort(all(a), greater<ll>());

    bool ok = 0;
    if (n % 2 || m % 2){
        //this is actually useless
        for(auto& i : a){
            if (i >= (n*m)) ok = 1;
        }
    }

    {
        //row
        {
            //get all even row first
            vll tmp = a;
            vi used;
            ll tmpn = n; 
            for(int i{}; i < k; i++){
                if (tmp[i] >= m*2){
                    tmp[i] -= m*2;
                    if (tmpn > 1){
                        tmpn-=2;
                        used.pb(i);
                    }
                }
            }
            //start filling
            for(auto& i : used){
                tmpn -= min(tmp[i]/m, tmpn);
            }
            ok |= tmpn == 0;
        }

        //col
        {
            vll tmp = a;
            vi used;
            ll tmpm = m; 
            for(int i{}; i < k; i++){
                if (tmp[i] >= n*2){
                    tmp[i] -= n*2;
                    if (tmpm > 1){
                        tmpm-=2;
                        used.pb(i);
                    }
                }
            }
            for(auto& i : used){
                tmpm -= min(tmp[i]/n, tmpm);
            }
            ok |= tmpm == 0;
        }
    }

    cout << (ok ? "Yes" : "No") << '\n';
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