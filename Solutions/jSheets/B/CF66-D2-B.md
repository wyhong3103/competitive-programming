```cpp

#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()

using namespace std;
using vi = vector<int>;
using ll = long long;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


int rained(vector<int>& a, int i){
    int ans = 0;
    //left
    int index = i-1;
    int prev = i;
    while (index >= 0){
        if (a[index] <= a[prev]){
            ans++;
            index--;
            prev--;
        }else{
            break;
        }
    }
    //right
    index = i+1;
    prev = i;
    while (index < sz(a)){
        if (a[index] <= a[prev]){
            ans++;
            index++;
            prev++;
        }else{
            break;
        }
    }
    return ans+1;
}


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i : a) cin >> i;
    
    int ans = 0;
    for(int i{}; i < n; i++){
        ans = max(ans, rained(a, i));
    }
    cout << ans;

}

int main(){
    //setIO("t");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```