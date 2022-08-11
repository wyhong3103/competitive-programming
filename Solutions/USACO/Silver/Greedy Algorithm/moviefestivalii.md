The idea is about watching the optimal scheduled movies. The tricky part of this problem is that, you need to find the optimal movie to swap. It's still about sorting it with it's ending time, but this time , you can watch k movies at parallel, and to watch more movies, you have to swap it optimally. I made a critical mistake while first attempting this problem, I used a queue, and made some bad assumptions like, only the first element will be pop (because it ends the earliest). While this sounds convincing, but it's actually false! The most optimal solution is to use a sorted set, and swap the movie optimally, using upper_bound to get the one movie that we can swap. If there's no movie we can swap, then we will check if there's any remaining spaces, assuming that we haven't got k parallel movies.
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
    int n, k;
    cin >> n >> k;
    
    vector<pi> movies(n);
 
    for(auto& i : movies) cin >> i.sec >> i.fir;
 
    sort(all(movies));
 
    ll total = 0;
    int count = 0;
    map<int,int> mp;
    
    
    for(auto& i : movies){
        if (mp.empty()){
            mp[i.fir] = 1;
            total++;
            count++;
        }else{
            auto it = mp.upper_bound(i.sec);
            if (it == mp.begin() && count >= k){
                continue;
            }
            else if (it == mp.begin() && count < k){
                if (!mp.count(i.fir)) mp[i.fir] = 0;
                mp[i.fir]++;
                total++;
                count++;
            }
            else{
                //get the element before it
                it--;
                int time = it->fir;
                mp[time]--;
                if (mp[time] == 0) mp.erase(time);
                if (!mp.count(i.fir)) mp[i.fir] = 0;
                mp[i.fir]++;
                total++;
            }
        }
    }
    cout << total;

}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```