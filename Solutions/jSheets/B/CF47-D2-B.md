My solution
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

void solve(){
    map<char,pair<int,int>> m;
    for(int i{}; i < 3; i++){
        char c1, op, c2;
        cin >> c1 >> op >> c2;
        if (op == '>'){
            m[c1].fir++;
            m[c2].sec++;
        }else{
            m[c2].fir++;
            m[c1].sec++;
        }
    }
    pair<int,int> count;
    char low, up;
    set<char> abc = {'A','B','C'};
    for(auto& i : m){
        if (!i.sec.sec){
            count.sec ++;
            up = i.fir;
            abc.erase(i.fir);
        }
        if (!i.sec.fir){
            count.fir ++;
            low = i.fir;
            abc.erase(i.fir);
        }
    }
    if (count.sec == 1 && count.fir == 1){
        cout << low << *abc.begin() << up;

    }
    else{
        cout << "Impossible";
    }
}

int main(){
    //setIO("t");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```

Another way to solve this is using topological sort, and print impossible if there is a cycle found in the graph, because topological sort can only be performed on a DAG, (Directed Acyclic Graph).

