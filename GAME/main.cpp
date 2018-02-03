//
// Created by Otto Winter on 20/04/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

#define fail(s, x...) do { \
        fprintf(stderr, s "\n", ## x); \
        exit(1); \
    } while(0)

#define MAX_SIZE 1000000000
#define MAX_N 100000

int main() {
  int R, C, N;
  int P, Q, U, V;
  long long K;
  int i, type;
  int res;

  scanf("%d", &R);
  if (R < 1 || R > MAX_SIZE)
    fail("R is out of bounds.");

  scanf("%d", &C);
  if (C < 1 || C > MAX_SIZE)
    fail("C is out of bounds.");

  scanf("%d", &N);

  init(R, C);

  for (i = 0; i < N; i++) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d%d%lld", &P, &Q, &K);
      update(P, Q, K);
    } else if (type == 2) {
      scanf("%d%d%d%d", &P, &Q, &U, &V);
      printf("%lld\n", calculate(P, Q, U, V));
    } else
      fail("Invalid action type in input file.");
  }

  return 0;
}
