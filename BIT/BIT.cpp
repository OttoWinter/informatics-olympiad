//
//  BIT.cpp
//  BIT
//
//  Created by Otto Winter on 18/04/2017.
//  Copyright © 2017 Otto Winter. All rights reserved.
//

#include "BIT.h"

using index_t = int;
using value_t = long long;

static const index_t MAX_N = 100005;

index_t N;
value_t bit[MAX_N];

inline index_t lsb(index_t i) { return i & (-i); }

void init(index_t n) {
  N = n;
}

void update(index_t i, int v) {
  for (; i <= N; i += lsb(i))
    bit[i] += v;
}

value_t query(index_t i) {
  value_t total = 0;
  for (; i > 0; i -= lsb(i))
    total += bit[i];
  return total;
}

value_t query(index_t a, index_t b) {
  return query(b) - query(a - 1);
}
