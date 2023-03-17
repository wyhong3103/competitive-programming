```

Notice that if you decided to listen to an album, the total score is the number of different prefix maximums.

If we are to plot all the different albums on a number line, we can see that if we are to take i, i is from album x from it's the j-th prefix maximum of x, then we can take eveything before i, and it will not allow us to take anything from any other array until the last prefix maximum of album x. This gives us an idea to use DP, because we can get the optimal state before i, and then just connect them up together in state transitions.

The reason we're not allow to take anything from i to it's maximal in the album its from, is that, if i is being considered as one of the track that is bigger than any other track before, we will listen till the last song on the album, so by the time we finish the album, our current maximum would be album x's maximum.

DP state

dp[i] = longest prefix max that ends at i

DP transition

We can preprocess the array first, for every point i on the number line, we store an array of point informations, which is 
[maximum of the album the current point is involved in, total prefix maximum from i to the maximum]

At point i

dp[maximum of that album] = max(dp[max of that album], dp[j, j < i] + prefix maximum until the maximum of that album)

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

void solve(){
    int n;
    cin >> n;

    vector<vi> a(n);

    for(auto& i : a){
        int k;
        cin >> k;
        i.resize(k);
        for(auto& j : i) cin >> j;
    }
    
    //endp + count
    map<int,vector<vi>> p;

    for(int i{}; i < n; i++){
        int mx = 0;
        int cnt = 0;
        vi temp;
        for(auto& j : a[i]){
            if (j > mx){
                mx = j;
                cnt++;
                temp.pb(j);
            }
        }
        for(int j{}; j < sz(temp); j++){
            p[temp[j]].pb({mx, cnt-j});
        }
    }

    map<int,int> dp;
    
    dp[0] = 0;

    for(auto& i : p){
        dp[i.fir] = max(dp[i.fir], (--dp.lower_bound(i.fir))->sec);
        for(auto& j : i.sec){
            auto it = --dp.lower_bound(i.fir);
            dp[j[0]] = max(dp[j[0]], it->sec + j[1]);
        }    
    }

    cout << dp.rbegin()->sec << '\n';

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