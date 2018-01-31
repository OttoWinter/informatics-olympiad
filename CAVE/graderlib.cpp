//
//  graderlib.cpp
//  CAVE
//
//  Created by Otto Winter on 28/02/2017.
//  Copyright © 2017 Otto Winter. All rights reserved.
//

#include "graderlib.h"

void answer(int S[], int D[]) {
    int i;
    int correct = 1;
    for (i = 0; i < N; ++i)
        if (S[i] != realS[i] || D[i] != realD[i]) {
            correct = 0;
            break;
        }
    
    if (correct)
        printf("CORRECT\n");
    else
        printf("INCORRECT\n");
    
    for (i = 0; i < N; ++i) {
        if (i > 0)
            printf(" ");
        printf("%d", S[i]);
    }
    printf("\n");
    
    for (i = 0; i < N; ++i) {
        if (i > 0)
            printf(" ");
        printf("%d", D[i]);
    }
    printf("\n");
    
    exit(0);
}

int tryCombination(int S[]) {
    int i;
    
    if (num_calls >= MAX_CALLS) {
        printf("INCORRECT\nToo many calls to tryCombination().\n");
        exit(0);
    }
    ++num_calls;
    
    for (i = 0; i < N; ++i)
        if (S[inv[i]] != realS[inv[i]])
            return i;
    return -1;
}

int init() {
    int i, res;
    
    scanf("%d", &N);
    
    for (i = 0; i < N; ++i) {
        scanf("%d", &realS[i]);
    }
    for (i = 0; i < N; ++i) {
        scanf("%d", &realD[i]);
        inv[realD[i]] = i;
    }
    
    num_calls = 0;
    return N;
}
