//
//  graderlib.h
//  CAVE
//
//  Created by Otto Winter on 28/02/2017.
//  Copyright © 2017 Otto Winter. All rights reserved.
//

#ifndef graderlib_h
#define graderlib_h

#include <stdio.h>
#include <stdlib.h>
#include "cave.h"

#define MAX_N 5000
#define MAX_CALLS 70000

#define fail(s, x...) do { \
fprintf(stderr, s "\n", ## x); \
exit(1); \
} while(0)

/* Symbol obfuscation */
#define N koala
#define realS kangaroo
#define realD possum
#define inv platypus
#define num_calls echidna

static int N;
static int realS[MAX_N];
static int realD[MAX_N];
static int inv[MAX_N];
static int num_calls;

void answer(int S[], int D[]);
int tryCombination(int S[]);
int init();


#endif /* graderlib_h */
