It's basically about removing the biggest g as we could with the biggest b, to minimize the cost.
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
    int n, m;
    cin >> n >> m;
 
    vi b(n);
    for(auto& i : b) cin >> i;
 
    map<int,int> g;
    for(int i{}; i < m; i++){
        int x;
        cin >> x;
        if (!g.count(x)) g[x] = 0;
        g[x]++;
    }
    
    sort(b.rbegin(), b.rend());
 
    ll total = 0;
    bool found = false;
 
    if (b[0] > (g.begin())->fir) cout << -1;
    else{ 
        for(auto& i : b){
            int temp = m-1;
            //Temp = m-1, because we need to make sure that we give i candy at least once, or else we're just going to keep giving the big candy
            if (found){
                total += (ll)i * m;
            }else{
            	//MORE POINTER ARITHMETIC, BRUHH
                auto it = --(g.end());
                while (temp--){
                    if (!found && it->fir >= i){
                        total += it->fir;
                        g[it->fir]--;
                        if (g[it->fir] == 0){
                            if (it != g.begin()){
                                int val = it->fir;
                                it--;
                                g.erase(val);
                            }
                            else found = true;
                        }
                    }else{
                        total += i;
                    }
                }
                //The 1 time that we give i candies
                total += i;
                if (g.count(i)){
                    g[i]--;
                    if (g[i] == 0) g.erase(i);
                    if (sz(g) == 0) found = true;
                }
            }
        }
        cout << total;
    }
 
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```