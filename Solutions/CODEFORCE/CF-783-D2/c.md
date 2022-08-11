This is pretty straightfoward as well, but I somehow messed it up. Could've solve it 1 hour earlier, I used a while loop to gather the sum initially, which is the bottleneck of my original code, I didn't realise that until the last 10 minutes. I was literally heavily doubting myself because how could a code that does n^2, that has a worst case of 5000^2 got TLE, and it's the while loop which caused it! Anyways, the idea is to try every position as the position we use as 0, because the array will always be in an increasing order, we jsut have to decide which is the one we're going to use as 0. Bruteforcing will solve this problem.
```cpp
#include <bits/stdc++.h>
#include <limits>
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
    int n;
    cin >> n;
    
    vi a(n);
    for(auto& i : a) cin >> i;
    vector<ll> b(n);
 
    ll ans = numeric_limits<ll>::max();
    for(int i{}; i < n; i++){
        ll total = 0;
        //processing foward
        for(int j{i+1}; j < n; j++){
            b[j] = ceil(b[j-1]/a[j]) * a[j];
            total += ceil(b[j-1]/a[j]);
            if (b[j] <= b[j-1]){
                b[j] += a[j];
                total++;
            }
        }
        //processing backward
        for(int j{i-1}; j >= 0; j--){
            b[j] = ceil(b[j+1]/a[j]) * a[j];
            total += abs(ceil(b[j+1]/a[j]));
            if (b[j] >= b[j+1]){
                b[j] -= a[j];
                total++;
            }
        }
        vector<ll> temp(n);
        swap(temp, b);
        ans = min(ans, total);
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