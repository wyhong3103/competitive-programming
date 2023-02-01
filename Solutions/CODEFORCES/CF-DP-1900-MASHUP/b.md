```

DP state

dp[s] = probabilities that we will reach this state s

Every set bit i in bitmask s, represent that i is dead/eaten

DP transition

dp[s] += dp[s ^ (1<<i)] * p[j][i] * (1/(n-popcount)) * (1/(n-popcount+1)) * 2

for every i that is set in bitmask s, and every j that is not set in bitmask s

We not only have to consider the probabibility that i get destroyed by j, but also, the probability of them meeting, from choosing the first fish to selecting the second fish. 

multiply by 2, because we could also be selecting the second fish first before the first fish, but at the end, fish i should get eaten.

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


const int MXN = 19;
double dp[1 << MXN];
double p[MXN][MXN];


void solve(){
    int n;
    cin >> n;

    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            cin >> p[i][j];
        }
    } 

    dp[0] = 1;

    for(int b{1}; b < (1 << n)-1; b++){
        double pselecti = 1/(double)(n-__builtin_popcount(b)+1);
        double pmeetj = 1/(double)(n-__builtin_popcount(b));
        for(int i{}; i < n; i++){
            if (b & (1 << i)){
                for(int j{}; j < n; j++){
                    if (!(b & (1 << j))){
                    	//select i first then meet with j
                        dp[b] += dp[b ^ (1<<i)] * p[j][i] * pselecti * pmeetj;
                        //select j first then meet with i
                        dp[b] += dp[b ^ (1<<i)] * p[j][i] * pselecti * pmeetj;
                    }
                }
            }
        }
    }

    cout << setprecision(6) << fixed;
    for(int i{}; i < n; i++){
        cout << dp[((1<<n)-1) ^ (1<<i)] << ' ';
    }
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