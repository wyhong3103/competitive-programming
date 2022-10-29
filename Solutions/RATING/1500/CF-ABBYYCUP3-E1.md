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
 

const int MAX = 101;
const int MOD = 1e9;
ll fibo[MAX];
ll a[MAX];
int n, m;

ll fibo_gen(int i){
    if (i <= 1) return 1;
    if (fibo[i]) return fibo[i];
    ll& temp = fibo[i];
    return temp = (fibo_gen(i-1) + fibo_gen(i-2)) % MOD;
}

void solve(){
    fibo[0] = 1;
    fibo[1] = 1;
    fibo_gen(MAX-1);
    cin >> n >> m;


    for(int i{}; i < n; i++){
        cin >> a[i];
    }

    while(m--){
        int t;
        cin >> t;
        int x, y;
        cin >> x >> y;
        x--;
        if (t == 1){
            a[x] = y;
        }else{
            y--;
            ll total = 0;
            for(int i{x}; i <= y; i++){
                total = (total + ((fibo[i-x] * a[i]) % MOD)) % MOD;
            } 
            cout << total << '\n';
        }
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