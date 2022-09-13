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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
 
void solve(){
    ll m, n;
    cin >> m >> n;

    vector<vll> a(n, vll(3));

    for(int i{}; i < n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    auto good = [&](ll mid){
        ll cnt = 0;
        for(auto& i : a){
            ll groups =  mid/((i[1]*i[0])+i[2]);
            cnt += groups * i[1];
            cnt += min((mid - (groups * ((i[1]*i[0])+i[2])))/i[0], i[1]);
        } 
        return cnt >= m;
    };

    ll lo = 0, hi = 1e9;
    while (hi > lo){
        ll mid = lo + (hi-lo)/2;
        if (good(mid)){
            hi = mid;
        }else lo = mid+1;
    }

    ll sm = 0;
    vll res(n);
    for(int i{}; i < n; i++){
        ll cnt = 0;

        ll groups =  lo/((a[i][1]*a[i][0])+a[i][2]);
        cnt += groups * a[i][1];
        cnt += min((lo - (groups * ((a[i][1]*a[i][0])+a[i][2])))/a[i][0], a[i][1]);

        res[i] = cnt;
        sm += cnt;
    }

    cout << lo << '\n';
    for(auto& i : res){
        if (sm > m){
            ll sub = min(i, sm-m);
            i -= sub;
            sm -= sub;
        }
        cout << i << ' ';
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