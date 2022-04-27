This solution failed two cases. TLE
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

bool covered(vector<pi>& coords, int i, int j, char dir){
    if (coords[j].sec < coords[i].sec){
        int o = (coords[i].sec - coords[j].sec);
        if (dir == 'L' && coords[j].fir >= coords[i].fir-o){
            return true; 
        }
        if (dir == 'R' && coords[j].fir <= coords[i].fir+o){
            return true; 
        }
    }
    return false;
}

void solve(){
    int n;
    cin >> n;

    vector<pi> coords(n);
    set<pi> s;
    for(auto& i : coords){
        cin >> i.fir >> i.sec;
        s.insert({i.fir, i.sec});
    }

    sort(all(coords), [](pi a, pi b){
        if (a.fir == b.fir){
            return a.sec < b.sec;
        }
        return a.fir < b.fir;
    });

    int i = 0;
    while (i < n){
        if (!s.count(coords[i])){
            i++;
            continue;
        }
        if (i > 0){
            //procesing left
            int l = i-1;
            while (coords[l].fir >= coords[i].fir-coords[i].sec && l >= 0){
                if (s.count(coords[l]) && covered(coords, i, l, 'L')){
                    s.erase(coords[l]);
                }
                l--;
            }
        }
        if (i < n-1){
            //processing right
            int r = i+1;
            while (coords[r].fir <= coords[i].fir+coords[i].sec && r <= n-1){
                if (s.count(coords[r]) && covered(coords, i, r, 'R')){
                    s.erase(coords[r]);
                }
                r++;
            }
        }
        i++;
    }
    cout << sz(s);
}
 
int main(){
    //setio("mountains");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```