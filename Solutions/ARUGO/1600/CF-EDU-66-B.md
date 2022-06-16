The idea of solving this problem is actually pretty simple, it's just about using a stack(as a callstack), to keep track of things, but the tricky part is the part where we need to detect overflows. We cannot simply just multiply the number of loops, (bc eventually the variable that is used to store the current complexity will overflow). So the idea is to only multiply/divide when we're in the appopriate range. If we ever add in the overflow range, we're going to have a boolean variable call pre_overflow, if pre_overflow is true, then the variable is going to overflow.
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
    int n;
    cin >> n;
    

    ll cur = 0;
    ll cur_complexity = 1;
    //number , isOverflow
    stack<pair<int,bool>> stck;
    

    bool pre_overflow = 0;
    bool ok = 1;
    for(int i{}; i < n; i++){
        string s;
        cin >> s;

        if (!ok) continue;
        if (s == "for"){
            int t;
            cin >> t;
            stck.push({t, false});
            if (cur_complexity > (((ll)1 << 32) - 1)){
                pre_overflow = 1;
                stck.top().sec = 1;    
            }else{
                cur_complexity *= t;
            }
        }
        else if (s == "add"){
            if (pre_overflow){
                ok = 0;
            }
            cur += cur_complexity;
            if (cur > (((ll)1 << 32) - 1)){
                ok = 0;
            }
        }else{
            if (!stck.top().sec) cur_complexity /= stck.top().fir;
            if (cur_complexity <= (((ll)1 << 32) - 1)){
                pre_overflow = 0;
            }
            stck.pop();
        }
    }

    if (ok) cout << cur;
    else cout << "OVERFLOW!!!";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```