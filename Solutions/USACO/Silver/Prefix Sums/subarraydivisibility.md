We only need to keep tracks of the remainder in this problem, also we also have to keep an eye on the negative number, which would lead to a negative modulo, which is wrong.
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

    map<int, ll> mp;
    vector<ll> pref(n);
    pref[0] = a[0];
    
    for(int i{1}; i < n; i++){
        pref[i] = a[i] + pref[i-1];
    }

    ll count = 0;

    for(int i{}; i < n; i++){
        int remain = (((pref[i] % n) + n) % n);
        if (remain == 0){
            count++;
        }
        count += mp[remain];
        if (!mp.count(remain)) mp[remain] = 0;
        mp[remain]++;
    }
    cout << count;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```