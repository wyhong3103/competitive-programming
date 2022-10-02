```

a feature for three cards is good if all three cards has the same i-th feature, or distinct i-th feature. is a set, if all features are good

f1 f2 f3
0  2  2
0  1  2 
0  2  0

feature 2, 3 aren't good features

meta-set = 5 cards, that has more than 1 set

We can find every set in N^2. Every 2 card needs a unique card to make it distinct, we can use a binary search tree to know its whereabout/ existence.

First, find a center card, and then find all the set it could be, and then add to its count.

Finally, for all i, let it be the center card, and do nC2.

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

ll nc2(ll n){
    ll nom = n * (n-1);
    return nom / 2;
}

char findDistinct(char a, char b){
    if (a > b){
        char temp = a;
        a = b;
        b = temp;
    }
    if (a == '1' && b == '2') return '0';
    else if (a == '0' && b == '1') return '2';
    else if (a == '0' && b == '2') return '1';
}

void solve(){
    int n, k;
    cin >> n >> k;

    map<string, int> mp;
    vector<string> a(n);
    for(int i{}; i < n; i++){
        string s;
        for(int j{}; j < k; j++){
            int x;
            cin >> x;
            s += (x+'0');
        }
        mp[s] = i;
        a[i] = s;
    }

    vll cnt(n);

    ll total = 0;
    set<vi> used;
    for(int i{}; i < n; i++){
        for(int j{i+1}; j < n; j++){
            vi temp;
            temp.pb(i);
            temp.pb(j);

            string needed;
            for(int l{}; l < k; l++){
                needed += (a[i][l] == a[j][l] ? a[i][l] : findDistinct(a[i][l], a[j][l]));
            }

            if (mp.count(needed)){
                temp.pb(mp[needed]);        
                sort(all(temp));
                if (!used.count(temp)){
                    for(auto& i : temp) cnt[i]++;
                    used.insert(temp);
                }
            }
        }
    } 

    for(auto& i : cnt){
        if (i >= 2) total += nc2(i);
    }

    cout << total;
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