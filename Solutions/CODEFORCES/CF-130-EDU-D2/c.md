My implementaiton on this problem might be a little OD.
```
The idea of solving this problem is pretty simple

First off we know that, ab can be ba, bc and be cb

One observation is that

long as the first character is a, and there is no other character other than a before first b after that , we can definitely bring b toward

aaaaaaab
can be
baaaaaaa

Same goes to bc, as long as the first character is b, and there isn't any an a before the first c, we can bring it to the first letter

So the idea is to reconstruct the string using queue to store the closest index of each character

if the i-th character is 'a', then the first 'a' must be the closest, bc there isn't any character that can swap 'a'

if the i-th character is 'b', either 'b' be the closest or 'a' comes before 'b' and 'c' be the last

if the i-th character is 'c', either 'c' be the closest or 'b' comes before 'c' and 'a' be the last

Things to beware of - empty queue
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
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
 
        string s, t;
        cin >> s >> t;
 
        vector<queue<int>> que(3);
 
        for(int i{}; i < n; i++){
            switch(s[i]){
                case 'a':
                    que[0].push(i);
                    break;
                case 'b':
                    que[1].push(i);
                    break;
                case 'c':
                    que[2].push(i);
                    break;
            }
        }
 
        bool ok = 1;
        for(int i{}; i < n; i++){
            map<char,int> mp;
            for(int i{}; i < 3; i++){
                mp['a'+i] = (que[i].empty() ? -1 : que[i].front());
            }
 
            //try the first character
            pi index{-1,-1};
            for(auto& j : mp){
                if (j.sec == -1) continue;
 
                if (index.sec == -1) index.sec = INT_MAX;
 
                if (j.fir == t[i]){
                    index.fir = j.sec; 
                }
                index.sec = min(index.sec , j.sec);
            }
 
            if (index.fir != -1 && index.fir == index.sec){
                que[t[i]-'a'].pop();                
                continue;
            }
            if (que[t[i]-'a'].empty()){
                ok = 0;
                continue;
            }
 
            if (t[i] == 'b' && mp['a'] != -1 && mp['a'] < mp['b'] && mp['a'] < (mp['c'] == -1 ? INT_MAX : mp['c']) && mp['b'] < (mp['c'] == -1 ? INT_MAX : mp['c'])){
                que[1].pop();
            }else if (t[i] == 'c' && mp['b'] != -1 && mp['b'] < (mp['a'] == -1 ? INT_MAX : mp['a']) && mp['b'] < mp['c'] && mp['c'] < (mp['a'] == -1 ? INT_MAX : mp['a'])){
                que[2].pop();
            }else{
                ok = 0;
            } 
        }
 
        cout << (ok ? "YES" : "NO") << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```