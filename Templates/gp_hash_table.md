```cpp

//A hash table that is faster than ordinary unordered_map
//More about it : https://codeforces.com/blog/entry/60737

//Your custom hashing function
struct chash{
    const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
}


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<int, int> table;

//Usage
gp_hash_table<key, int, chash> table;

```