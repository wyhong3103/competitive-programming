Solving it using lcm (to get the number that is divisible by A or B), this code is slow! Because of the map operations and gcd/lcm I believe. This problem is pretty straightfoward. [Save The Nature](https://codeforces.com/contest/1223/problem/C)
<br>
Key takeaway:
- Number that is divisible by A and B doesn't mean the divisor is A * B, it literally means number that is divisible by A or B
- Should prioritize using array over hash map
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
 

ll gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(int a, int b){
    return a/gcd(a,b) * b;
}


bool valid(map<ll,int> mp, pi a, pi b, int mid, ll k){
    ll total = 0;
    if (a.fir < b.fir) swap(a,b);

    vector<pair<ll,int>> tickets(3);
     
    tickets[0].fir = mid/lcm(a.sec,b.sec);
    tickets[1].fir = mid/a.sec - tickets[0].fir;
    tickets[2].fir = mid/b.sec - tickets[0].fir;
    tickets[0].sec = a.fir + b.fir;
    tickets[1].sec = a.fir;
    tickets[2].sec = b.fir;
    
    for(auto& i : tickets){
        while (i.fir){
            auto it = --mp.end();
            total += ((ll)(it->fir) * i.sec)/100;
            it->sec--;
            if (it->sec == 0){
                mp.erase(it->fir);
            }
            i.fir--;
        }
    }

    return total >= k;
}


void solve(){
    int t;
    cin >> t;
    while(t--){
        //number of tickets
        int n;
        cin >> n;

        map<ll,int> mp;
        for(int i{}; i < n; i++){
            ll x;
            cin >> x;
            if (!mp.count(x)) mp[x] = 0;
            mp[x]++;
        }

        pi a;
        cin >> a.fir >> a.sec;

        pi b;
        cin >> b.fir >> b.sec;

        ll k;
        cin >> k;

        int lo = 1, hi = n;
        while (hi > lo){
            int mid = lo + (hi-lo)/2;
            if (valid(mp, a, b, mid, k)){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        
        cout << (valid(mp,a,b,lo,k) ? lo : -1) << '\n';
    }
}

 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```

Alternative way to solve it (faster)

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n; vector<ll> p;

ll x, a, y, b, k;

bool works(int sellTickets){
	vector<ll> percentages(sellTickets);
	
	// Add x% to every a-th ticket.
	for(int i = a - 1; i < sellTickets; i += a){
		percentages[i] += x;
	}
	
	// Add y% to every b-th ticket
	for(int i = b - 1; i < sellTickets; i += b){
		percentages[i] += y;
	}
	
	sort(percentages.begin(), percentages.end(), greater<ll>());
	
	ll cur = 0;
	for(int i = 0; i < sellTickets; i++){
		cur += percentages[i] * p[i] / 100;
	}
	
	return cur >= k;
}

void solve(){
	cin >> n;
	p.resize(n);
	
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	
	sort(p.begin(), p.end(), greater<ll>());
	
	cin >> x >> a >> y >> b >> k;
	
	int l = 0, r = n, ans = -1;
	
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(works(mid)){
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	
	cout << ans << endl;
}

int main(){
	int q; cin >> q;
	for(int i = 1; i <= q; i++){
		solve();
	}
}

```