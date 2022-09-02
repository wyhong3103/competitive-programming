```cpp

#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}


    
int dsu_get(int a, vi& parent){
    return parent[a] = (parent[a] == a ? parent[a] : dsu_get(parent[a], parent));
}

void dsu_union(int a, int b, vi& comp_sz, vi& parent, int& total){
    a = dsu_get(a, parent);
    b = dsu_get(b, parent);
    
    if (a == b) return;

    if (comp_sz[a] > comp_sz[b]){
        parent[b] = a;
        comp_sz[a] += comp_sz[b];
    }else{
        parent[a] = b;
        comp_sz[b] += comp_sz[a];
    }
    total--;
}

int distance(pi a, pi b){
    return (abs(a.fir-b.fir) * abs(a.fir-b.fir)) + (abs(a.sec-b.sec) * abs(a.sec-b.sec));
}

void solve(){
    int n;
    cin >> n;

    vector<pi> cows(n);
    for(auto& i : cows) cin >> i.fir >> i.sec;


    int lo = 0, hi = (25000*25000) + 5;
    while (hi > lo){
        int mid = lo + (hi-lo)/2;
        vi parent(n);
        vi comp_sz(n);
        for(int i{}; i < n; i++){
            parent[i] = i;
            comp_sz[i] = 1;
        }

        set<int> exist;
        int total = 0;
        for(int i{}; i < n; i++){
            if (!exist.count(i)){
                total++;
                exist.insert(i);
            }
            for(int j{i+1}; j < n; j++){
                if (distance(cows[i], cows[j]) <= mid){
                    if (!exist.count(j)){
                        total++;
                        exist.insert(j);
                    }
                    dsu_union(i, j, comp_sz, parent, total);
                }
            }
        }

        if (total == 1){
            hi = mid;
        }else lo = mid+1;
    }

    cout << lo;
}
int main(){
    setio("moocast");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```