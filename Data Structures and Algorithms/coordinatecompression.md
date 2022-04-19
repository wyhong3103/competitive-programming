Check out the problem : https://usaco.guide/silver/sorting-custom?lang=cpp for a better understanding on this technique.
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}



const int MAX = 1e5+5;

vi indices; //array that stores the real index (instead of 1 to N)
pair<pi, int> updates[MAX]; //array that is used to store update queries
ll diff[MAX]; //difference array
ll prf[MAX]; //prefix sum array


int getCompressedIndex(int a){
    return lower_bound(all(indices),a) - indices.begin();
}

void solve(){
    int n;
    cin >> n;

    for(int i{}; i < n; i++){
        int l, r ,v;
        cin >> l >> r >> v;
        indices.pb(l);
        indices.pb(r+1);
        updates[i].fir = {l,r+1};
        updates[i].sec = v;
    }

    sort(all(indices));
    indices.erase(unique(all(indices)), indices.end());
    //Remove duplicates

    for(int i{}; i < n; i++){
        auto a = updates[i];
        diff[getCompressedIndex(a.fir.fir)] += a.second; 
        diff[getCompressedIndex(a.fir.sec)] -= a.second; 
    }

    // If problem involve queries that has indices that is not in the updates, we can add the indices into the difference array as well, that means get every interval we need and put it into the difference array

}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```