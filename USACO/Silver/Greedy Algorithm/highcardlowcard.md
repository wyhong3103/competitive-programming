Basically split the game into two set, since the winner of the first half is the one with the higher card, so we can simply just make the set sort in a non-increasing order, and we can simply pull out our biggest card everytime. And for the second half, we use our smallest card.
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
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){ 
    int n;
    cin >> n;
    
    set<int> a;
    set<int, greater<int>> f;
    set<int> s;
    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        if (i < n/2){
            f.insert(x);
        }else{
            s.insert(x);
        }
    }

    for(int i{1}; i <= 2*n; i++){
        if (!s.count(i) && !f.count(i)) a.insert(i); 
    }

    int count = 0;
    
    //first half
    for(auto& i : f){
        auto it = --(a.end());
        if (*(it) > i) {
            count++;
            a.erase(*(it));
        }
    }

    //second half
    for(auto& i : s){
        auto it = a.begin();
        if (*(it) < i) {
            count++;
            a.erase(*(it));
        }
    }

    cout << count;
}
 
int main(){
    setio("cardgame");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```