Messed up the first implementation, although my answer is correct which is to construct the number of ways we can form the target sum using number from 1 to n, and then the final answer/2, because it's double counted, but the MOD will mess up the answer, in some occassion it would turn the even number into odd number(which is impossible, because every subset has to have another subset that contributes to the sum). So to resolve this, we can just assume the n element in another set, and don't count it.
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
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MAX = 2e5;
const int MOD = 1e9 + 7;
ll dp[MAX];
ll dp2[MAX];
 
void solve(){
    int n;
    cin >> n;
 
    if (((n*(n+1))/2) % 2 != 0){
        cout << 0;
        return;
    }
 
    int target = (n*(n+1))/4;
 
    dp[0] = 1;
    dp2[0] = 1;
    for(int c{1}; c < n; c++){
        for(int j{1}; j <= target; j++){
            if (j-c >= 0){
                dp[j] += dp2[j-c];      
                dp[j] %= MOD;
            }
        }
 
        for(int j{1}; j <= target; j++){
            dp2[j] = dp[j];
        }
    } 
 
    cout << dp[target];
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```