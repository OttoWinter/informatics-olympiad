//
//  cave.cpp
//  CAVE
//
//  Created by Otto Winter on 28/02/2017.
//  Copyright © 2017 Otto Winter. All rights reserved.
//

#include "cave.h"
#include <cstdio>
#include <iostream>

#define DEBUG if(false)

static const int MAX_N = 5005;

int N;
int S[MAX_N];
bool dont_touch[MAX_N];
int D[MAX_N];
int combinations_tried = 0;

void construct_s(int left, int right, int val) {
    DEBUG printf("construct_s(left=%d right=%d val=%d)\n", left, right, val);
    for (int i = left; i <= right; i++) {
        if (!dont_touch[i])
            S[i] = val;
    }
}

int try_combination(int *S) {
    if (combinations_tried == 70000) {
        printf("TOO MANY QUERIES!!1\n");
        exit(0);
    }
    DEBUG printf("Trying: ");
    DEBUG for (int i = 0; i < N; i++) {
        printf("%d ", S[i]);
    }
    int res = tryCombination(S);
    DEBUG printf(" ==> %d\n", res);
    combinations_tried++;
    return res;
}

bool is_open(int door) {
    int depth = try_combination(S);
    if (depth > door || depth == -1) {
        DEBUG printf("Door %d is open.\n", door);
        return true;
    }
    DEBUG printf("Door %d is closed.\n", door);
    return false;
}

bool all_dont_touch(int left, int right) {
    for (int i = left; i <= right; i++) {
        if (!dont_touch[i])
            return false;
    }
    return true;
}

int find_lever(int door) {
    DEBUG printf("find_lever(door=%d)\n", door);
    int left = 0;
    int right = N - 1;
    
    construct_s(left, right, false);
    bool open_state = !is_open(door);
    DEBUG printf("open_state=%d\n", open_state);
    construct_s(left, right, !open_state);
    bool open;
    while (left < right) {
        int mid = (left + right) / 2;
        
        construct_s(left, mid, open_state);
        open = is_open(door);
        if (!open) {
            DEBUG printf("Going right (left=%d right=%d mid=%d open=%d)\n", left, right, mid, open);
            left = mid + 1;
        } else {
            DEBUG printf("Going left (left=%d right=%d mid=%d open=%d)\n", left, right, mid, open);
            right = mid;
            construct_s(left, mid, !open_state);
        }
    }
    DEBUG printf("Found lever for door %d: %d\n", door, left);
    S[left] = open_state;
    dont_touch[left] = true;
    return left;
}

void exploreCave(int _N) {
    N = _N;
    for (int door = 0; door < N; door++) {
        D[find_lever(door)] = door;
        DEBUG printf("\n\n");
    }
    
    DEBUG printf("Combinations tried: %d\n", combinations_tried);
    
    answer(S, D);
}
