The idea of this problem is pretty simple, you can think of array b as another version of a (in order for a to become b). Think of it as prime factorization, we can decompose them to their most simplest form, if they matched up that means it's possible for one to become another. Operation 2 is actually the opposite of operation 1, that's why it's possible.
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
 
//Totally unnecessary
ll binpow(ll b, ll p) {
	if(p == 0)	return 1;
	ll sq = binpow(b, p/2);
	sq = sq*sq;
 
	if(p%2 == 1)
		sq = sq*b;
 
	return sq;
}
 
void solve(){
    ll n, m;
    cin >> n >> m;
 
    vector<ll> a(n);
    for(auto& i : a) cin >> i;
 
    ll k;
    cin >> k;
    vector<ll> b(k);
    for(auto& i : b) cin >> i;
 
    //decomposing to the same value
    vector<pair<ll,ll>> cnt1;
    for(auto& i : a){
        if (i % m == 0){
            ll cnt = 0;
            while (i % m == 0){
                i /= m;
                cnt++;
            }
            cnt1.pb({i, binpow(m, cnt)});
        }else{
            cnt1.pb({i, 1});
        }
    }
 
    vector<pair<ll,ll>> temp1;
    pair<ll,ll> cur{cnt1[0].fir,0};
    for(auto& i : cnt1){
        if (i.fir == cur.fir){
            cur.sec += i.sec;
        }else{
            temp1.pb(cur);
            cur.fir = i.fir;
            cur.sec = i.sec;
        }
    }
    temp1.pb(cur);
 
    vector<pair<ll,ll>> cnt2;
    for(auto& i : b){
        if (i % m == 0){
            ll cnt = 0;
            while (i % m == 0){
                i /= m;
                cnt++;
            }
            cnt2.pb({i, binpow(m, cnt)});
        }else{
            cnt2.pb({i, 1});
        }
    }
 
    vector<pair<ll,ll>> temp2;
    cur = {cnt2[0].fir,0};
    for(auto& i : cnt2){
        if (i.fir == cur.fir){
            cur.sec += i.sec;
        }else{
            temp2.pb(cur);
            cur.fir = i.fir;
            cur.sec = i.sec;
        }
    }
    temp2.pb(cur);
 
    bool ok = 1;
    if (sz(temp1) != sz(temp2)) ok = 0;
    else{
        for(int i{}; i < sz(temp1); i++){
            if (!(temp1[i].fir == temp2[i].fir && temp1[i].sec == temp2[i].sec)) ok = 0;
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