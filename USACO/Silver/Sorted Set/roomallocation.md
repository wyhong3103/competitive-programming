Damn , solving this is real luck! The main problem that concerned me in the very first place, is about the order of the customer information, I'm concerning whether it is sorted in the first place, or does it even matter if it's sorted or nah. My implementation failed in my first attempt, solely because of the fact that I didn't sort it by the departure time, and make a little mistake in the implementaiton. Anyways, I somehow got AC after sorting it, didn't really expct that, but it worked.
```
So the idea of solving this problem is that, as long as there are rooms where customer departure time that is earlier than the arrival time of a customer, then, we can use the room.

The implementation is a little tricky, took me quite a while to figure out what to do.

-----------------------------------------------

So first off, what we need to do is just sort the customer orders by the departure time, also we need to store the index, because we need to print it according to it's index.

After sorting it, we need a map that keep tracks of current hotel room, which store the depature time as the key, and a set of room numbers that is going to be available after that time as the value.

We're going to start with the first customer, which is the one with the earliest departure time.

What's going to happen is, we're going to search for the lower_bound of the arrival time of a customer, if the lower_bound is pointing at the beginning of the set, that means, there is no available room for that customer, so we need to get it a new room, also when the map is empty, these cases are the case where we need to add a new room, so just by doing this, we could keep track of the maximum number of rooms we need

else
We simply need to get a room number, from the one before the lower_bound (that means it has an earliear departure time than our arrival time), remove the room number from the set, and insert the room number to the set of the new departure time(it can already be existed, since there might be several customers that have the same depature time, all of the room numbers are going to be stored in a set), if the set has became empty, we need to get rid of the key and value from the map


```

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
 

struct Customer{
	// from, to, index
    int f , t, i;
};

bool cmp(Customer& a, Customer& b){
    return a.t > b.t;
}


void solve(){
    int n;
    cin >> n;

    vi a(n);

    map<int, set<int>> m;

    vector<Customer> v(n);
    for(int j{}; j < n; j++){
        cin >> v[j].f >> v[j].t;
        v[j].i = j;
    }
    sort(all(v), cmp);

    int mx = 0;
    for(int j{}; j < n; j++){
        if (m.empty()){
            m[v[j].t].insert(1);
            a[v[j].i] = 1;
            mx++;
        }else{
            auto it = m.lower_bound(v[j].f);
            if (it == m.begin()){
                mx++;
                m[v[j].t].insert(mx);
                a[v[j].i] = mx;
            }else{
            	//Grabbing the first element in the set with some pointer arithmetic
                a[v[j].i] = *(((--it)->sec).begin());
                //Erasing it from the set
                (it->sec).erase(a[v[j].i]);
                //If set has became empty we remove it from the map
                if (sz(it->sec) == 0) m.erase(it->fir);
                //Insert it into the set of new departure time
                m[v[j].t].insert(a[v[j].i]);
            }
        }
    }
    cout << mx << '\n';
    for(auto& i : a) cout << i << ' ';
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```