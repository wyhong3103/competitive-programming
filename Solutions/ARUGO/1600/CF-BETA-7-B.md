Input is small, we can literally brute force it.
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

void solve(){
    int t, m;
    cin >> t >> m;

    int cur = 1;
    //start, {id, end}
    map<int,pi> mp;

    while(t--){ 
        string s;
        cin >> s;
        if (s == "alloc"){
            int n;
            cin >> n;

            int at = 1;
            for(auto& i : mp){
                if (i.fir - at >= n){
                    break;
                }else{
                    at = i.fir+i.sec.sec;
                }
            }
            if (((mp.upper_bound(at) != mp.end() ? mp.upper_bound(at)->fir : m+1)) - at >= n){
                mp[at] = {cur, n};
                cout << cur++ << '\n';
            }else{
                cout << "NULL" << '\n';
            }
        }else if (s == "erase"){
            int n;
            cin >> n;

            int found = -1;
            for(auto& i : mp){
                if (i.sec.fir == n){
                    found = i.fir;
                    break;
                }
            }
            if (found != -1){
                mp.erase(found);    
            }else{
                cout << "ILLEGAL_ERASE_ARGUMENT" << '\n';
            }
        }else{
            int at = 1;
            map<int,pi> temp;
            for(auto& i : mp){
                temp[at] = i.sec;
                at += i.sec.sec;
            }
            mp = temp;
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