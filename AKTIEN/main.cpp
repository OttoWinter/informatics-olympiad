#include <stdio.h>
#include <algorithm>
#include <limits>

using namespace std;

using index_t = int;
using stock_t = int;

static const stock_t MAX_N = 1000005;

index_t N;
stock_t stock[MAX_N];
stock_t lowest[MAX_N];

int main() {
    scanf("%d", &N);
    for(index_t i = 1; i <= N; i++)
        scanf("%d", &stock[i]);

    lowest[0] = std::numeric_limits<stock_t>::max();
    for(index_t i = 1; i <= N; i++)
        lowest[i] = min(lowest[i-1], stock[i]);

    stock_t max_diff = std::numeric_limits<stock_t>::min();
    for(index_t i = 2; i <= N; i++)
        max_diff = max(max_diff, stock[i] - lowest[i-1]);

    printf("%d", max_diff);
    return 0;
}
