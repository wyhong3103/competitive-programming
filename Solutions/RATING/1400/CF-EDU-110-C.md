The idea basically is, if part of the string is unstable, all of it's substring are unstable, so we simply do (length)\*(length+1)/2, to get the number of substring in that part of the string. Solved this problem using two pointers, the tricky part is how do we move p1, 
```
0??0

first part of string is from 0 to 2, because at 3 , our string would not be unstable, then we move our first pointer, continue seeking for new string, and second part of the string is from 1 to 3. Notice that the only valid way to move the first pointer, is to move it to the first ? of the consecutive ? before ending of the previous string.


```
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
    string s;
    cin >> s;

    ll res = 0;

    ll p1 = 0, p2 = 1;
    int cur = (s[0] == '?' ? -1 : s[0]);
    int prev = (s[0] == '?' ? 0 : -1);
    while (p2 < sz(s)){
        if (cur == -1 && s[p2] == '?'){
            p2++;
            continue;
        }

        if (prev == -1 && s[p2-1] == '?'){
            prev = p2-1;
        }else if (prev != -1 && s[p2-1] != '?'){
            prev = -1;
        }

        if (cur != -1){
            if (cur == s[p2]){
                res += (p2-p1)*(p2-p1+1)/2;
                if (prev != -1){
                    res -= ((p2-prev)*(p2-prev+1))/2;
                    p1 = prev;
                    cur = -1;
                }else{
                    p1 = p2;
                    cur = s[p2];
                    p2++;
                }
                continue;
            }
        }
        cur = (s[p2] == '?' ? (cur == '1' ? '0' : '1'): s[p2]);
        p2++;
        
    }
    res += ((p2-p1)*(p2-p1+1))/2;

    cout << res << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}
```