Implementation heavy problem, stack is the perfect candidate for the soluion. Basically store every level deepest item in the stack.
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
        int n;
        cin >> n;

        vi a(n);
        for(auto& i : a) cin >> i;

        stack<string> level;
        for(auto& i : a){
            if (i == 1){
                if (level.empty()) level.push("1");
                else{
                    level.push(level.top() + ".1");
                }
            }else{
                while (!level.empty()){
                    string temp = level.top();
                    level.pop();
                    string cur = "";
                    for(int i{}; i < sz(temp); i++){
                        if (temp[i] == '.') cur = "";
                        else cur += temp[i];
                    }
                    int val = stoi(cur);
                    if (val+1 == i){
                        level.push(temp.substr(0, sz(temp)-sz(cur)) + to_string(val+1));
                        break;
                    }
                }
            }
            cout << level.top() << '\n';
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```