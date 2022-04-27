It's only possible to form a valid string, if every segment of RB has at least one R or one B (substring between W)
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
 
        bool ok = true;
 
        string temp = "";
        for(int i{}; i < n; i++){
            if (s[i] != 'W'){
                temp += s[i];
            }else{
                if (temp.length() > 0){
                    pi count {};
                    for(auto& i : temp){
                        if (i == 'R') count.fir++;
                        else count.sec++;
                    }
                    if (!count.fir || !count.sec){
                        ok = false;
                        break;
                    }
                }
                temp = "";
            }
        }
        if (temp.length() > 0){
            pi count {};
            for(auto& i : temp){
                if (i == 'R') count.fir++;
                else count.sec++;
            }
            if (!count.fir || !count.sec){
                ok = false;
            }
        }
        if (!ok) cout << "NO";
        else cout << "YES";
        cout << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```