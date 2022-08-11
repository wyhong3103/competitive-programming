This could've been much faster if I precompute the dictionary instead of reconstruct it everytime.
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
 
        bool ok =false;
        int count = 0;
        for(int i{}; i < 26; i++){
            string temp =""; 
            temp += 'a'+i;
            for(int j{}; j < 26; j++){
                if (i != j){ 
                    temp += 'a'+j;
                    count++;
                    if (temp == s){
                        ok = true;
                        break;
                    }
                    temp.pop_back();
                }
            }
            temp.pop_back();
            if (ok) break;
        }
        cout << count << '\n';
    }
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```