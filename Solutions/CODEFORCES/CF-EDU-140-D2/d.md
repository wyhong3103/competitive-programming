```

We can construct the solution from the top (winner).

Just look at the code, it's pretty self explanatory, at the end, (the leaf level), we will get some number of 0, 1, 2 ,3.

0 = winner, 1 = > x, 2 = < x, 3 = anything.

For skill integer x to win, there has to be at least the number of 2s smaller than x, number of 1s bigger than x.

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


const int MX = (1 << 19);
//0 = x, 1 = > x , 2 = < x, 3 = anything
vi res;

void recur(int cur, int level, string& s){
    if (level == sz(s)){
        res.pb(cur);
        return;
    }

    if (s[level] == '0'){
        //winner
        recur(cur, level+1, s);
        //loser
        int loser = -1;
        if (cur == 3) loser = 3;
        else if (cur == 0) loser = 1;
        else if (cur == 1) loser = 1;
        else if (cur == 2) loser = 3;
        recur(loser, level+1, s);
    }else{
        //winner
        recur(cur, level+1, s);
        //loser
        int loser = -1;
        if (cur == 3) loser = 3;
        else if (cur == 0) loser = 2;
        else if (cur == 1) loser = 3;
        else if (cur == 2) loser = 2;
        recur(loser, level+1, s);
    }
}

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    recur(0, 0, s);

    pi cnt;
    for(auto& i : res){
        if (i == 2) cnt.fir++;
        else if (i == 1) cnt.sec++;
    }

    for(int i{cnt.fir+1}; i <= (1 << n)-cnt.sec; i++){
        cout << i << ' '; 
    }
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