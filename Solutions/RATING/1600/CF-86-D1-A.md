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
const double EPS = (1e-7);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}


void solve(){
    string s;
    getline(cin >> ws, s);
    
    vector<string> words;
    string cur = "";
    for(int i{}; i < sz(s); i++){
        if (s[i] == ' '){
            words.pb(cur);
            cur = "";
            continue;
        }
        cur += s[i];
    }
    words.pb(cur);
    
    map<string,pi> mp;
    mp["lios"] = {0,0};
    mp["etr"] = {0,1};
    mp["initis"] = {0,2};
    mp["liala"] = {1,0};
    mp["etra"] = {1,1};
    mp["inites"] = {1,2};

    auto identify = [&](string temp){
        pi res = {-1,-1};
        for(auto& i : mp){
            if (sz(i.fir) > sz(temp)) continue;
            if (temp.substr(sz(temp)-sz(i.fir),sz(i.fir)) == i.fir) return i.sec;
        }
        return res;
    };

    bool ok = 1;
    if (sz(words) == 1){
        ok = (identify(words[0]).fir != -1);
    }else{
        bool gender = (identify(words[0]).fir);
        int at = 0;
        //adj
        for(int i{at}; i < sz(words); i++){
            pi identity = identify(words[i]);
            if (identity.fir != gender) ok = 0;
            if (identity.sec != 0) break;
            at++;
        }

        //noun
        int cnt = 0;             
        for(int i{at}; i < sz(words); i++){
            pi identity = identify(words[i]);
            if (identity.fir != gender) ok = 0;
            if (identity.sec != 1) break;
            else cnt++;
            at++;
        }
        if (cnt != 1) ok = 0;

        //verb
        for(int i{at}; i < sz(words); i++){
            pi identity = identify(words[i]);
            if (identity.fir != gender) ok = 0;
            if (identity.sec != 2){
                ok = 0;
                break;
            }
        }
    }

    cout << (ok ? "YES" : "NO");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```