```cpp
#include <bits/stdc++.h>
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
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    string s, t;
    cin >> s >> t;
 
    vector<pair<char, int>> a;
    
    pair<char,int> cur = {'0',-1};
    for(auto& i :s){
        if (cur.fir == '0'){
            cur.fir = i;
            cur.sec = 1;
        }else if (i == cur.fir){
            cur.sec++; 
        }else{
            a.pb(cur);
            cur.fir = i;
            cur.sec = 1;
        }
    }
    a.pb(cur);
 
    vector<pair<char, int>> b;
    cur = {'0', -1};
    for(auto& i :t){
        if (cur.fir == '0'){
            cur.fir = i;
            cur.sec = 1;
        }else if (i == cur.fir){
            cur.sec++; 
        }else{
            b.pb(cur);
            cur.fir = i;
            cur.sec = 1;
        }
    }
    b.pb(cur);
 
    
    if (sz(a) != sz(b)) cout << "No";
    else{
        bool ok = 1;
        for(int i{}; i < sz(a); i++){
            if (b[i].fir != a[i].fir) ok = 0;
            else if (b[i].sec < a[i].sec || b[i].sec > a[i].sec && a[i].sec < 2) ok = 0;
        }
 
        cout << (ok ? "Yes" : "No");
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