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
 
const int MAX = 1e5 +5;
int a[MAX];
int fenwick_tree[MAX];

//Sum of [1,k]
int sum(int k){
    int s = 0;
    while (k >= 1){
        s += fenwick_tree[k];
        k -= k&-k;
    }
    return s;
}

//Update
void upd(int k, int x){
    while (k <= n){
        fenwick_tree[k] += x;
        k += k&-k;
    }
}

void construct(){
    for(int i{1}; i <= n; i++){
        int k = i + (i&-i);
        if (k < n){
            fenwick_tree += a[i];
        }
    }
}

void solve(){
   //code  
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```