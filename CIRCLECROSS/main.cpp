//
//  main.cpp
//  CIRCLECROSS
//
//  Created by Otto Winter on 05.02.18.
//  Copyright © 2018 Otto Winter. All rights reserved.
//

#include <cstdio>

#define DEBUG if(false)

int N;
int a[50005];
int lazy[4 * 100005];

inline int left(int i) { return i * 2; }
inline int right(int i) { return left(i) + 1; }
inline int parent(int i) { return i / 2; }

void add(int i, int l, int r, int sl, int sr, int num) {
  if (l > sr || r < sl)
    return;
  if (l == r || (l >= sl && r <= sr)) {
    lazy[i] += num;
    return;
  }

  add(left(i), l, (l + r) / 2, sl, sr, num);
  add(right(i), (l + r) / 2 + 1, r, sl, sr, num);
}

int query(int i, int l, int r, int want) {
  if (l == want && r == want)
    return lazy[i];
  if (l > want || r < want)
    return 0;

  lazy[left(i)] += lazy[i];
  lazy[right(i)] += lazy[i];
  lazy[i] = 0;
  return query(left(i), l, (l + r) / 2, want)
      + query(right(i), (l + r) / 2 + 1, r, want);
}

int main(int argc, const char *argv[]) {
  scanf("%d", &N);
  DEBUG printf("N=%d\n", N);

  unsigned long long res = 0;
  for (int i = 1; i <= 2 * N; i++) {
    int k;
    scanf("%d", &k);
    DEBUG printf("i=%d k=%d\n", i, k);

    if (a[k]) {
      int q = query(1, 1, 2 * N, a[k]);
      res += i - a[k] - q - 1;
      DEBUG printf("res += %d - %d - %d - 1\n", i, a[k], q);

      add(1, 1, 2 * N, 1, i, 1);
      add(1, 1, 2 * N, 1, a[k], 1);

      DEBUG printf("Segment Tree: ");
      DEBUG for (int j = 1; j <= 15; j++) {
          printf("(%d) ", lazy[i]);
          printf("%d ", query(1, 1, 2 * N, j));
        }
      DEBUG printf("\n");
    }
    a[k] = i;
  }
  printf("%llu\n", res);
  return 0;
}
