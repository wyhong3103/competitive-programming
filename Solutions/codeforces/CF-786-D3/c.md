The idea of this problem is pretty straightfoward, if the second string consist of a letter 'a', and its length is more than 2, then it will be infinity. Because you can keep on replacing the a with the string, it just keep growing larger. For the other case, which is string that doesn't consist of 'a', it's just about the number of ways you could put an object that can be repeated into n(length of string a) different boxes. It's essentially the subset of it.
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
        string a, b;
        cin >> a >> b;
        
        int countb = 0;
        for(auto& i : b){
            if (i == 'a') countb++;
        }
 
        if (countb >= 1){
            cout << (countb == 1 && b.length() == 1 ? 1 : -1);
        }else{
            ll ans = 1;
            int len = a.length();
            while (len--){
                ans *= 2;
            }
            cout << ans;
        }
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