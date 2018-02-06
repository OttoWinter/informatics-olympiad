//
//  dna.cpp
//  DNA
//
//  Created by Otto Winter on 28/02/2017.
//  Copyright © 2017 Otto Winter. All rights reserved.
//

#include "dna.h"

#include <cstdio>
#include <vector>
#include <bitset>
#include <iostream>

#define DEBUG if(false)

#define N_MAX 1005

int N, T;
int zeros;

template<typename Iter>
std::string construct_string_(size_t size, Iter begin, Iter end) {
  std::string z(size, ' ');
  std::transform(begin, end, z.begin(), [](bool v) { return v ? '1' : '0'; });
  return z;
}

inline std::string construct_string(const std::vector<bool> &v) {
  return construct_string_(v.size(), v.begin(), v.end());
}
inline std::string construct_string_reverse(const std::vector<bool> &v) {
  return construct_string_(v.size(), v.rbegin(), v.rend());
}
inline std::string construct_string(int size, bool value) {
  return construct_string(std::vector<bool>(size, value));
}

bool _make_test(const std::string &s) {
  bool res = make_test(s);
  DEBUG std::cout << "Testing '" << s << "' -> " << res << std::endl;
  return res;
}

std::string analyse(int _N, int _T) {
  N = _N;
  T = _T;

  DEBUG printf("Phase 1: Looking for max number of zeros.\n");
  int left = 0;
  int right = N + 1;
  while (left != right) {
    int mid = (left + right) / 2;

    std::string z = construct_string(mid, false);
    if (_make_test(z))
      left = mid + 1;
    else
      right = mid;
  }
  zeros = left - 1;
  DEBUG printf("Phase 1: Found %d zeros.\n", zeros);
  if (zeros == 0)
    return construct_string(N, true);
  else if (zeros == N)
    return construct_string(N, false);

  DEBUG printf("\nPhase 2: Finding out chars on right.\n");
  std::vector<bool> base = std::vector<bool>(zeros, false);
  std::vector<bool> experimental = std::vector<bool>(zeros, false);
  int now_zeros = 0;
  for (int i = 1; i <= N - zeros; i++) {
    base.push_back(true);
    experimental.push_back(true);
    DEBUG std::cout << "i=" << i << " base='" << construct_string(base) << "' experimental='"
                    << construct_string(experimental) << "'" << std::endl;
    if (!_make_test(construct_string(experimental))) {
      base.pop_back();
      experimental.pop_back();
      experimental.push_back(false);
      now_zeros++;
      if (now_zeros > zeros)
        break;
    } else {
      base.pop_back();
      base.insert(base.end(), now_zeros, false);
      base.push_back(true);
      now_zeros = 0;
    }
  }
  DEBUG std::cout << "Phase 2: Found string '" << construct_string(base) << "'" << std::endl;

  DEBUG printf("\nPhase 3: Finding out remaining 0 chars at right.\n");
  left = 1;
  right = now_zeros + 1;
  while (left != right) {
    int mid = (left + right) / 2;
    std::vector<bool> t(base);
    t.insert(t.end(), mid, false);

    if (_make_test(construct_string(t))) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  base.insert(base.end(), left - 1, false);
  DEBUG printf("Phase 3: Found %d '0' chars on right.\n", left - 1);

  DEBUG printf("\nPhase 4: Finding out chars on left.\n");
  std::vector<bool> rev(base.rbegin(), base.rend());
  auto right_size = int(base.size());
  for (int i = 0; i < N - right_size; i++) {
    rev.push_back(false);
    if (!_make_test(construct_string_reverse(rev))) {
      rev.pop_back();
      rev.push_back(true);
    }
  }
  DEBUG std::cout << "Phase 4: Finished: result:  '" << construct_string_reverse(rev) << "'." << std::endl;

  return construct_string_reverse(rev);
}
