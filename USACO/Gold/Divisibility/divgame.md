Prime factorization, but we have to partition it optimally, for example if power = 4,the best way we could partition it is x^1 , x^3, to know how many times can we partition, it's pretty simple, we can take advantage of the summation formula. n(n+1)/2 = x, since we know that the summation formula always goes 1+2+3 .... when power = 4, we want to find the best n it could be. The maximum number we can reach is until 2, since 1+2+3 goes over 4, we simply don't have enough to reach 1+2+3. That's the idea.
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

void solve(){
    ll n;
    cin >> n;
    ll ans = 0;
    //Have to look out for integer overflow
    for(ll i{2}; i * i <= n; i++){
        int div = 0;
        while (n % i == 0){
            div++;
            n /= i;
        }
        if (div){
            int part = 0;
            while (part * (part + 1) <= div * 2){
                part++;
            }
            ans += part-1;
        }
    }
    if (n > 1){
        ans++;
    }
    cout << ans;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```