Got a tons of WA from this problem, fuck, I started with 4 group, a tortoise and a hare, and one to find the spot, and last one to move the rest. This is just simply stupid, because there's no way you can do it, if t = 1, c = 999. The reason is that if they're going to meet after 1500 queries, you're going to spend extra 1000 to find the spot, and extra 1000 to get the rest to the spot. My initial idea is to search for a cycle point, if 0 is ever in the lead but not 1, then there's a cycle so we keep looking, but whatever, the order of the answer is randomized, it doesn't prints in an order of who's in the lead , who's next etc etc. So the solution is to find the cycle point, then move the rest to the spot, until they be in the same spot.
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
    //0 as a tortoise and 1 as a hare
    int cnt = 0;
    bool ok = false;
    do{
        if (cnt % 2 != 0){
            cout << "next " << 0 << ' ' << 1 << '\n';
        }else{
            cout << "next " << 1 << '\n';
        }
        int n;
        cin >> n;
        for(int i{}; i < n; i++){
            string s;
            cin >> s;
            if (s == "01" && cnt % 2 != 0){
                ok = true;
            }
        }
        cout.flush();
        cnt++;
    }while(!ok);

    //If they met each other, start finding the point, also keep tracks of the length   
    //we need to move 0 and 1 to the spot as well
    ok = false;
    do{
        cout << "next ";
        for(int i{}; i <= 9; i++) cout << i << ' ';
        cout << '\n';
        int n;
        cin >> n;
        for(int i{}; i < n; i++){
            string s;
            cin >> s;
            if (s == "0123456789") ok = true;
        }
        cout.flush();
    }while(!ok);
    cout << "done" << '\n';
}

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
    solve();
	return 0;
}
```