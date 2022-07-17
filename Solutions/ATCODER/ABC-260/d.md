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
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
 
void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(auto& i : a) cin >> i;
 
    vi res(n);
    fill(all(res),-1);
    
    vi id(n);
    fill(all(id),-1);
 
    int cur = 0;
    //{top {number, id}};
    map<int,pi> stcktop;
    for(int i{}; i < n; i++){
        auto it = stcktop.lower_bound(a[i]);
        if (it == stcktop.end()){
            res[a[i]-1] = cur;
            if (k == 1){
                id[cur++] = i;
            }else{
                stcktop[a[i]]={1, cur++};
            }
        }else{
            pi temp = it->sec;
            res[a[i]-1] = temp.sec;
            temp.fir++;
            if (temp.fir == k){
                id[temp.sec] = i;
            }else{
                stcktop[a[i]] = temp;
            }
            stcktop.erase(it->fir);
        }
    }
 
    for(int i{}; i < n; i++){
        if (res[i] == -1 || id[res[i]] == -1) cout << -1 << '\n';
        else cout << id[res[i]]+1 << '\n';
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