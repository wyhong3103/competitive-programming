```
u can always do it with at most 2 color, find the longest subsequence that is rbs, and then the rest must be in the form of )))))(((((, so u just need another 1 for that 

edge case, reverse is rbs, answer is 1 

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
 
/*
 
 
beautiful if is RBS or reversed is RBS
 
given a bracket seq
 
find min number of comp to split s.t the above is fulfilled
 
if rbs = 1 color
 
else
 
how to get a beautiful or RBS, number of ( = number of )
 
if that is fulfilled, can we always get components of RBS
 
//cancel all the (),
//at the end we would get
 
)))(((
 
yes possible
 
we only need two component
 
*/
 
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    pi cnt;
    for(auto& i :s){
        cnt.fir += i == '(';
        cnt.sec += i == ')';
    }
    if (cnt.fir != cnt.sec){
        cout << -1 << '\n';
        return;
    }
 
    string temp = s;
    reverse(all(temp));
 
 
    int sm = 0;
    bool ok = 1;
    for(int i{}; i < n; i++){
        sm += temp[i] == '(' ? 1 : -1;
        ok &= sm >= 0;
    }
 
    if (sm == 0 && ok){
        cout << 1 << '\n';
        for(int i{}; i < n; i++) cout << 1 << ' ';
        cout << '\n';
        return;
    }
    
 
 
    vi color(n);
    stack<int> st;
    bool found1 = 0;
    bool found2 = 0;
    for(int i{}; i < n; i++){
        if (st.empty() && s[i] == ')'){
            color[i] = 1;
            found1 = 1;
        }else if (s[i] == ')'){
            st.pop();
            found2 = 1;
        }else{
            st.push(i);
        }
    }
    while (!st.empty()){
        color[st.top()] = 1;
        st.pop();
        found1 = 1;
    }
 
    cout << found1+found2 << '\n';
    if (found1 && found2) for(auto& i :color)cout<<i+1<< ' ';
    else{
        for(auto& i :color)cout<<i+found2<< ' ';
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