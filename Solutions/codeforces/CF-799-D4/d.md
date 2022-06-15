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
    int t;
    cin >> t;
    while(t--){
        string time;
        cin >> time;
 
        int minutes;
        cin >> minutes;
 
        int hours = minutes/60;
        minutes = minutes - ((minutes/60)*60);
 
        int res = 0;
        string temp = time;
 
        do{
            int h = ((temp[0]-'0')*10) + temp[1]-'0';
            int m = ((temp[3]-'0')*10) + temp[4]-'0';
 
            h = (h + hours) % 24;
            if (m + minutes >= 60) h++;
            //If h++ turned to 24, we need to set it to 00
            h %= 24;
            m = (m + minutes) % 60;
            
            //Reconstruct the string
            temp = "";
            //if h is 1, we will have to add a 0 before it
            if (!(h/10)) temp += '0';
            temp += to_string(h);
            temp += ':';
            if (!(m/10)) temp += '0';
            temp += to_string(m);
 
            if (temp[0] == temp[4] && temp[1] == temp[3]){
                res++;
            }
        }while(temp != time);
 
        cout << res << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```