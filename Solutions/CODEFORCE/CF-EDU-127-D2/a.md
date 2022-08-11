Basically making sure every segment of a and b is > 2, if there's any smaller than that, then we print NO.
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
        string s;
        cin >> s;
 
        string temp = "";
        temp += s[0];
        bool ok = true;
        for(int i{1}; i < s.length(); i++){
            if (s[i] == temp[0]){
                temp += s[i];
            }else{
                if (temp.length() < 2){
                    ok = false;
                    break;
                }else{
                    temp = s[i];
                }
            }
        }
        if (temp.length() < 2) ok = false;
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