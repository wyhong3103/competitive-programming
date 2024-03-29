Extremely high-quality and fast hash map. Taken from [Blowing up unordered_map, and how to stop getting hacked on it](https://codeforces.com/blog/entry/62393)
```cpp
struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// Now we can simply define our unordered_map or our gp_hash_table as follows:

unordered_map<long long, int, chash> safe_map;
gp_hash_table<long long, int, chash> safe_hash_table;
```