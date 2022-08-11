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
 
 
const int MAX = 2e5 +5;
int fenwick_tree[MAX];
int n;
 
//Sum of [1,k]
int sum(int k){
    int s = 0;
    while (k >= 1){
        s += fenwick_tree[k];
        k -= k&-k;
    }
    return s;
}
 
//Update
void upd(int k, int x){
    while (k <= n+1){
        fenwick_tree[k] += x;
        k += k&-k;
    }
}
 
void solve(){
    cin >> n;
    
    vi a(n);
    for(auto& i : a){
        cin >> i;
    }
 
    for(int i{}; i < n; i++){
        if (i+1 > a[i]){
            upd(a[i]+1,1);
        }
    }
 
    ll res = 0;
    
    for(int i{}; i < n; i++){
        if (i+1 > a[i]){
            res += sum(n+1)-sum(i+2);
            upd(a[i]+1,-1);
        }
    }
 
    cout << res << '\n';
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