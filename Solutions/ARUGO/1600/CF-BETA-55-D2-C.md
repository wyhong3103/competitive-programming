Implementation heavy problem.
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


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool ok = 1;
    //cnt = number of pairs of '?'
    int cnt = 0;
    for(int i{}; i < sz(s)/2; i++){
        if ((s[i] != '?' && s[sz(s)-i-1] != '?') && (s[i] != s[sz(s)-i-1])) ok = 0;
        else if (s[i] == '?' && s[i] == s[sz(s)-i-1]) cnt++;
    }

    if (sz(s) % 2 != 0 && s[sz(s)/2] == '?') cnt++; 

    set<char> need;
    for(int i{}; i < n; i++){
       need.insert('a'+i);
    }


    for(auto& i : s){
        if (need.count(i)){
            need.erase(i);
        }
    }

    //cnt is currently equal to the number of time we can place 'a' on double '?'
    cnt =  cnt - sz(need);

    for(int i{}; i < sz(s)/2; i++){
        if (s[i] == '?' && s[sz(s)-i-1] == '?'){
            char cur = (sz(need) && cnt <= 0  ? *(need.begin()) : 'a');
            if (cnt <= 0) need.erase(cur);
            s[i] = cur;
            s[sz(s)-i-1] = cur;
            cnt--;
        }else{
            if (s[sz(s)-i-1] == '?'){
               swap(s[sz(s)-i-1], s[i]); 
            }
            s[i] = s[sz(s)-i-1];
        }
    }

    //Handle middle element
    if (s[sz(s)/2] == '?'){
        char cur = (sz(need) ? *(need.begin()): 'a');
        s[sz(s)/2] = cur;
        need.erase(cur);
    }

    if (!ok || sz(need)){
        cout << "IMPOSSIBLE";
        return;
    }
    cout << s;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}


```