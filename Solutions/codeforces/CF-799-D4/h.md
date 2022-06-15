Kadane algorithm on every number.
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
 
        vector<ll> a(n);
        for(auto& i : a) cin >> i;
        
        // number : [cur, l, r]
        map<ll,vi> mp;
 
        // number, best sum, l, r
        vector<ll> res(4);
        res[0] = -1;
        res[1] = -1;
 
        for(int i{}; i < n; i++){
            if (!mp.count(a[i])){
                mp[a[i]].resize(3);
                mp[a[i]][0] = 1;
                mp[a[i]][1] = i;
                mp[a[i]][2] = i;

                if (mp[a[i]][0] > res[1]){
                    res[0] = a[i];
                    res[1] = mp[a[i]][0];
                    res[2] = mp[a[i]][1];
                    res[3] = mp[a[i]][2];
                }
           
                //new number skip the below
                continue;
 
            }
            
            if (mp[a[i]][0] - (i-mp[a[i]][2]-1) <= 0){
                mp[a[i]][0] = 1;
                mp[a[i]][1] = i;
                mp[a[i]][2] = i;
            }else{
            	//deduct the interval
                mp[a[i]][0] -= max(0, i-mp[a[i]][2]-1);
                mp[a[i]][0]++;
                mp[a[i]][2] = i;
            }
 
            if (mp[a[i]][0] > res[1]){
                res[0] = a[i];
                res[1] = mp[a[i]][0];
                res[2] = mp[a[i]][1];
                res[3] = mp[a[i]][2];
            }
        }
 
        cout << res[0] << ' ' << res[2]+1 << ' ' << res[3]+1 << '\n'; 
    }     
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```