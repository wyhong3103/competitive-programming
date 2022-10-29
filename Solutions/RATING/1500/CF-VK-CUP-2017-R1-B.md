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
    int n, k;
    cin >> n >> k;
    vector<string> a(n-k+1);
    for(auto& i : a) cin >> i;

    string cur = "Aa";
    
    vector<string> res;

    for(int i{}; i < n-k+1; i++){
        if (a[i] == "NO"){
            if (sz(res) <= i){
                res.pb(cur);
            }
            else{
                res.pb(res[i]);
            }
        }else{
            int len = sz(res);
            for(int j{}; j < k-max(len-(i+1)+1,0); j++){
                res.pb(cur);
                if (cur[0] < 'Z')cur[0]++;
                else cur[1]++;
            }
        }
    } 

    for(int i{}; i < n; i++){
        if (i < sz(res)) cout << res[i] << ' ';
        else {
            cout << cur << ' ';
            if (cur[0] < 'Z')cur[0]++;
            else cur[1]++;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}


```