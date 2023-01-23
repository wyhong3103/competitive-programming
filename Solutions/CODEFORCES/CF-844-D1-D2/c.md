```
If we only want x characters to stay (and be balanced). x has to divide n.

Claim : If we want x characters to stay, the top x characters with most frequency is going to be the x characters that stays.

Proof : Let's say top x characters, each has frequency less than n/x, it is easy to tell that we need to convert the least in order for them to each have a frequency of n/i. If some has more than n/x, it would still be optimal, because no matter what we choose, we have to remove the one that has more than n/x, so it wouldn't really affect anything.

Just bruteforce it. Greedily fill the top x characters, and find the one with min removal/insertion.

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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n;
    cin >> n;
 
    string s;
    cin >> s;
    
    vector<pi> freq(26);
    for(int i{}; i < 26; i++) freq[i].sec = i;
 
    for(int i{}; i < n; i++) freq[s[i]-'a'].fir++;
 
    sort(all(freq), greater<pi>());
 
    pi mn = {INT_MAX, 1};
    for(int i{1}; i <= 26; i++){
        if (n % i == 0){
            int cnt = 0;
            vector<pi> temp = freq;
            for(int j{}; j < 26; j++){
                for(int k{}; k < i; k++){
                    if (j >= i){ 
                        while (temp[j].fir && temp[k].fir < n/i){
                            temp[k].fir++;
                            temp[j].fir--;
                            cnt++;
                        }
                    }else{
                        while (j != k && temp[j].fir > n/i && temp[k].fir < n/i){
                            temp[k].fir++;
                            temp[j].fir--;
                            cnt++;
                        }
                    }
                }      
            } 
            mn = min(mn, {cnt, i});
        }
    }
 
    map<int,queue<int>> mp;
 
    for(int j{}; j < 26; j++){
        for(int k{}; k < mn.sec; k++){
            if (j >= mn.sec){ 
                while (freq[j].fir && freq[k].fir < n/mn.sec){
                    freq[k].fir++;
                    freq[j].fir--;
                    mp[freq[j].sec].push(freq[k].sec);
                }
            }else{
                while (j != k && freq[j].fir > n/mn.sec && freq[k].fir < n/mn.sec){
                    freq[k].fir++;
                    freq[j].fir--;
                    mp[freq[j].sec].push(freq[k].sec);
                }
            }      
        } 
    }
 
    cout << mn.fir << '\n';
    for(auto& i : s){
        if (sz(mp[i-'a'])){
            cout << (char)('a'+mp[i-'a'].front()); mp[i-'a'].pop();   
        }else cout << i;
    }
    cout << '\n';
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