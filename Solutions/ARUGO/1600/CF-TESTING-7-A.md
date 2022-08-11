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
using vdb = vector<double>;
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
    int n;
    cin >> n;
    if (n%2){
        cout << -1;
    }else{
        vector<vi> a(n);
        for(auto& i : a) i.resize(n);
        
        int cnt = 0;
        bool cur = 0;
        for(int i{}; i < n; i++){
            if ((n/2) % 2 == 0) cur = !cur;
            for(int j{}; j < n; j++){
                a[i][j] = cur;
                cnt++;
                if (cnt == 2){
                    cur = !cur;
                    cnt = 0;
                }
            }
        }

        cnt = 0;
        bool inverse = 0;
        for(int i{}; i < n; i++){
            for(auto& j : a){
                for(auto& k : j) cout << ((inverse ? !k : k) ? 'b' : 'w');
                cout << '\n';
            }
            cnt++;
            if (cnt == 2){
                inverse = !inverse;
                cnt = 0;
            }
            cout << '\n';
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