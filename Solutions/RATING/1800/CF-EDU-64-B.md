```

Sort all the distinct character in alphabetical order first.

One way to make sure none of the adjacent character be together is by doing the below

say we have abcdefg

We do two pointer like

ag

fagb

cfagbe

This way we can guarantee that no two adjacent character will coincide!

Proof (if it is even and possible)

When two of the pointers is right adjacent to each other, 

they will be placed at both end!

If it is odd, we can simply run a check on every adjacent character see where is the appopriate place to place the character!

Finally do a check again on every character! If not okay then no answer, else print the answer

```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    string s;
    cin >> s;
    
    vi cnt(26);
    string a;
    for(auto& i : s){
        if (!cnt[i-'a']) a.pb(i);
        cnt[i-'a']++;
    }
    sort(all(a));

    deque<char> q;
    int l = 0, r = sz(a)-1;
    while (r > l){
        if (l % 2 == 0){
            q.push_front(a[l]);
        }else{
            q.push_back(a[l]);
        }
        if (r % 2 == (sz(a)-1) % 2){
            q.push_back(a[r]);
        }else{
            q.push_front(a[r]);
        }
        r--;
        l++;
    }

    string res;

    if (sz(a) == 1) res += a[l];
    else if (sz(a) % 2 && sz(a) > 1){
        string temp;
        while (!q.empty()){
            temp += q.front();
            q.pop_front();
        }

        int ok = (abs(temp[0]-a[l]) == 1 ? ( abs(temp.back()-a[l]) == 1 ? -1 : sz(temp) ) : 0);
        for(int i{1}; i < sz(a); i++){
            if (ok != -1) break;
            if (abs(temp[i-1]-a[l]) != 1 && abs(temp[i]-a[l]) != 1) ok = i;
        }

        if (ok == 0) res += a[l];

        for(int i{}; i < sz(temp); i++){
            res += temp[i];
            if (i == ok-1){
                res += a[l];
            }
        }

        if (ok == -1) res += a[l];
    }else{
        while (!q.empty()){
            res += q.front();
            q.pop_front();
        }
    }

    bool ok = 1;
    for(int i{1}; i < sz(res); i++){
        if (abs(res[i]-res[i-1]) == 1) ok = 0;
    }

    if (!ok){
        cout << "No answer" << '\n'; 
    }else{
        for(auto& i : res){
            for(int j{}; j < cnt[i-'a']; j++) cout << i;
        }
        cout << '\n';
    }
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