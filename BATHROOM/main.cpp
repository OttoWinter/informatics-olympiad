//
//  main.cpp
//  BATHROOM
//
//  Created by Otto Winter on 19/04/2017.
//  Copyright © 2017 Otto Winter. All rights reserved.
//

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

#define DEBUG if(false)

using ll = long long;

std::map<ll, ll> spaces;

inline ll compute_left(ll i) { return (i  - 1) / 2; }
inline ll compute_right(ll i) { return i / 2; }

int main(int argc, const char * argv[]) {
    ll T, N, K;
    scanf("%lld", &T);
    
    for (int i = 1; i <= T; i++) {
        scanf("%lld %lld", &N, &K);
        spaces.clear();
        spaces[N]++;

        ll l = -1, r = -1, k = K;
        while (k > 0) {
            auto it = --spaces.end();
            ll size = it->first;
            ll count = it->second;
            spaces.erase(it);

            l = compute_left(size);
            r = compute_right(size);
            spaces[l] += count;
            spaces[r] += count;
            k -= count;
        }
        printf("Case #%d: %lld %lld\n", i, std::max(l, r), std::min(l, r));
    }
    
    return 0;
}
