This solution literally came out of nowhere, nothing special about it, just by counting 0s and 1s to determine how many I need.

```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;
 
void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}
 
 
 
 
void solve(){
    int t;
    cin >>t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        
        int count0 = 0;
        int count1 = 0;
        int ans{};
 
        for(int i{}; i < n; i++){
            if (s[i] == '1'){
                count0 = 0;
                if (i != 0)
                count1++;
            }else if(s[i] == '0'){
                if (count1 == 1 && s[i-2] != '1'){
                    ans+=1; 
                }
                count1 = 0;
                count0++;
            }
            if (count0 == 2){
                ans += 2;           
                count0 = 1;
            }
        }
        cout << ans << '\n'; 
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```