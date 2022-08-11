The idea is simple, first we do knapsack on t, after that, if dp[i] is reachable, we set it's halved value as reachable as well(drinking water). Then we do knapsack all over again.
```
	dp[0] = 1;
    for(int i{1}; i <= t; i++){
        if (i-a >= 0 && dp[i-a]){
            dp[i] = 1;
        }
        if (i-b >= 0 && dp[i-b]){
            dp[i] = 1;
        }
        if (dp[i]) dp[i/2] = 1;
    }

Here's what i did initially which is wrong, this is because, some value will get halved more than once. I have to seperate this two process.

For example

say dp[2] = 0, and dp[5] = 1, dp[5/2] = 1, will set dp[2] = 1, and say the next state is dependent on whether dp[2] is reachable, then dp[i] = 1, and because of the way we implemented it, we're going to set the halved value as 1 as well, which is wrong!
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
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

const int MXT = 5e6+1;
bool dp[MXT];


void solve(){
    int t, a, b;
    cin >> t >> a >> b;


    dp[0] = 1;
    for(int i{1}; i <= t; i++){
        if (i-a >= 0 && dp[i-a]){
            dp[i] = 1;
        }
        if (i-b >= 0 && dp[i-b]){
            dp[i] = 1;
        }
    }

    for(int i{1}; i <= t; i++){
        if (dp[i]) dp[i/2] = 1;
    }
    
    int mx = 0;
    for(int i{1}; i <= t; i++){
        if (i-a >= 0 && dp[i-a]){
            dp[i] = 1;
        }
        if (i-b >= 0 && dp[i-b]){
            dp[i] = 1;
        }

        if (dp[i]){
            mx = max(mx, i);
        }
    }

    cout << mx;
}

 
int main(){
    setio("feast");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}
```