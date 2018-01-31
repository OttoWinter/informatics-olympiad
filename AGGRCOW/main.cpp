//
// Created by Otto Winter on 20/04/2017.
//

#include <cstdio>
#include <limits>
#include <cstring>
#include <cstdint>
#include <algorithm>
#include <vector>

#define DEBUG if(false)

using test_t = int32_t;
using stall_t = int32_t;
using cow_t = int32_t;
using loc_t = int32_t;

static const stall_t MAX_N = 100005;
static const loc_t MAX_LOC = 1000000005;

test_t T;
stall_t N;

int main() {
    scanf("%d", &T);
    DEBUG printf("T=%d", T);
    for (test_t t = 0; t < T; t++) {
        stall_t N;
        cow_t C;
        scanf("%d %d", &N, &C);
        DEBUG printf("t=%d N=%d C=%d\n", t, N, C);
        
        std::vector<loc_t> locs;
        loc_t max_loc = 0;
        for (stall_t s = 0; s < N; s++) {
            loc_t loc;
            scanf("%d", &loc);
            locs.push_back(loc);
            max_loc = std::max(max_loc, loc);
        }
        std::sort(locs.begin(), locs.end());

        DEBUG printf("stalls: ");
        DEBUG for (stall_t s = 0; s < N; s++) {
            printf("%d ", locs[s]);
        }
        DEBUG printf("\n");

        loc_t lo = 2, hi = max_loc;
        while (lo != hi) {
            loc_t mid = (lo + hi) / 2;
            DEBUG printf("lo=%d mid=%d hi=%d \n", lo, mid, hi);
            cow_t cow = 0;
            loc_t last_loc = -1 * MAX_LOC;
            
            bool success = false;
            for (stall_t s = 0; s < N; s++) {
                if (locs[s] >= last_loc + mid) {
                    DEBUG printf("Putting cow %d at pos %d\n", cow, locs[s]);
                    last_loc = locs[s];
                    cow++;
                    if (cow >= C) {
                        success = true;
                        break;
                    }
                }
            }
            if (success) {
                DEBUG printf("Was successful\n");
                lo = mid + 1;
            } else {
                DEBUG printf("Was unsuccessful\n");
                hi = mid;
            }
            DEBUG printf("\n");
        }
        printf("%d\n", lo - 1);
    }
}
