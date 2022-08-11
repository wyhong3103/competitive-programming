Algorithm used : GCD, LCD, Inclusive-Exclusive Principle

```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;

void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

ll gcd(ll a,ll b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}


ll lcm(ll a,ll b){
    return a / gcd(a,b) * b;
}



void solve(){
    int t;
    cin >> t;
    while(t--){
        ll n,m,a,d;
        cin >> n >> m >> a >> d;

        ll sum{};
        for(int i{}; i < pow(2,5); i++){

            ll div{1}, sign{}, elementcnt{};

            if (i & 1) div = lcm(a,div), elementcnt++;
            if (i >> 1 & 1) div = lcm(div,(a+d)), elementcnt++;
            if (i >> 2 & 1) div = lcm(div,(a + (2 * d))) , elementcnt++;
            if (i >> 3 & 1) div = lcm(div,(a + (3 * d))), elementcnt++;
            if (i >> 4 & 1) div = lcm(div,(a + (4 * d))), elementcnt++ ;

            if (!elementcnt) continue;

            sign = elementcnt % 2 == 1 ? 1 : -1;

            sum += sign * (((m)/div) - ((n-1)/div));
        }
        cout << (m+1)-n-sum << '\n';
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
}


```