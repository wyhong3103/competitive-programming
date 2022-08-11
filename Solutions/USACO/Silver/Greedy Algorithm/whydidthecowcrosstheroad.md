This code passess all the test except for test 8, it failed for some reasons, i will leave it for now,	since i ain't got a clue about it. Anyways, it's pretty fast! Coordinate compressed, prefix sum, sorted set etc, etc.
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
    int c, n;
    cin >> c >> n;

    map<int,pi> chicks;
    vector<pair<pi,int>> cows;
    
    vi chicks_v;
    for(int i{}; i < c; i++){
        int t;
        cin >> t;
        if (!chicks.count(t)){
            chicks_v.pb(t);
        }
        chicks[t].fir++;
    }

    sort(all(chicks_v));

    for(int i{}; i < sz(chicks_v); i++){
        chicks[chicks_v[i]].sec = i;
        if (i == 0){
            chicks_v[i] = chicks[chicks_v[i]].fir;
        }else{
            chicks_v[i] = chicks[chicks_v[i]].fir + chicks_v[i-1];
        }
    }

    for(int i{}; i < n; i++){
        int f, t;
        cin >> f >> t;
        cows.pb({{f,t}, {}});
    }

    for(auto& i : cows){
        int f = i.fir.fir , t = i.fir.sec;
        auto end = chicks.upper_bound(t);
        auto start = chicks.lower_bound(f);
        if (start == chicks.end()){
            i.sec = 0;
        }else{
            i.sec = chicks_v[(--end)->sec.sec] - (start == chicks.begin() ? 0 : chicks_v[(--start)->sec.sec]);
        }
    } 

    sort(all(cows), [](auto& a, auto& b){
        return a.sec < b.sec;
    });

    ll total = 0;
    for(auto& i : cows){
        if (i.sec){
            auto it = chicks.lower_bound(i.fir.fir);
            if (it == chicks.end()){
                continue;
            }else{
                if (it->fir >= i.fir.fir && it->fir <= i.fir.sec){
                    total++;
                    chicks[it->fir].fir--;
                    if (chicks[it->fir].fir == 0){
                        chicks.erase(it->fir);
                    }
                }
            }
        }
    }

    cout << total;
}
 
int main(){
    setio("helpcross");
 	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```