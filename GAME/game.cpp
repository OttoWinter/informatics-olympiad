//
// Created by Otto Winter on 20/04/2017.
//

#include "game.h"

using val_t = long long;
using index_t = int;

struct Segment {
  val_t gcd;

  Segment *left;
  Segment *right;
};

Segment *root;
index_t R, C;

val_t gcd(val_t X, val_t Y) {
  long long tmp;
  while (X != Y && Y != 0) {
    tmp = X;
    X = Y;
    Y = tmp % Y;
  }
  return X;
}

val_t update(Segment *seg,
             index_t seg_x_from, index_t seg_x_to, index_t seg_y_from, index_t seg_y_to,
             index_t want_x, index_t want_y, val_t value) {
  if (seg_x_from > want_x || seg_x_to < want_x)
    return seg->gcd;
  if (seg_x_from == seg_x_to) {
    if (seg_y_from > want_y || seg_y_to < want_y)
      return seg->gcd;
    if (seg_y_from == seg_y_to)
      return seg->gcd = value;
    index_t seg_y_mid = (seg_y_from + seg_y_to) / 2;
    if (seg->left == nullptr)
      seg->left = new Segment();
    val_t left = update(seg->left,
                        seg_x_from, seg_x_to, seg_y_from, seg_y_mid,
                        want_x, want_y, value);
    if (seg->right == nullptr)
      seg->right = new Segment();
    val_t right = update(seg->right,
                         seg_x_from, seg_x_to, seg_y_mid + 1, seg_y_to,
                         want_x, want_y, value);
    return seg->gcd = gcd(left, right);
  } else {
    index_t seg_x_mid = (seg_x_from + seg_x_to) / 2;
    if (seg->left == nullptr)
      seg->left = new Segment();
    val_t left = update(seg->left,
                        seg_x_from, seg_x_mid, seg_y_from, seg_y_to,
                        want_x, want_y, value);
    if (seg->right == nullptr)
      seg->right = new Segment();
    val_t right = update(seg->right,
                         seg_x_mid + 1, seg_x_to, seg_y_from, seg_y_to,
                         want_x, want_y, value);
    return seg->gcd = gcd(left, right);
  }
}

val_t query(Segment *seg,
            index_t seg_x_from, index_t seg_x_to, index_t seg_y_from, index_t seg_y_to,
            index_t want_x_from, index_t want_x_to, index_t want_y_from, index_t want_y_to) {
  if (seg == nullptr)
    return 0;
  if (want_x_from <= seg_x_from && seg_x_to <= want_x_to &&
      want_y_from <= seg_y_from && seg_y_to <= want_y_to)
    return seg->gcd;
  if (want_x_from > seg_x_to || want_x_to < seg_x_from ||
      want_y_from > seg_y_to || want_y_to < seg_y_from)
    return 0;
  if (seg_x_from == seg_x_to) {
    index_t seg_y_mid = (seg_y_from + seg_y_to) / 2;
    val_t left = query(seg->left,
                       seg_x_from, seg_x_to, seg_y_from, seg_y_mid,
                       want_x_from, want_x_to, want_y_from, want_y_to);
    val_t right = query(seg->right,
                        seg_x_from, seg_x_to, seg_y_mid + 1, seg_y_to,
                        want_x_from, want_x_to, want_y_from, want_y_to);
    return gcd(left, right);
  } else {
    index_t seg_x_mid = (seg_x_from + seg_x_to) / 2;
    val_t left = query(seg->left,
                       seg_x_from, seg_x_mid, seg_y_from, seg_y_to,
                       want_x_from, want_x_to, want_y_from, want_y_to);
    val_t right = query(seg->right,
                        seg_x_mid + 1, seg_x_to, seg_y_from, seg_y_to,
                        want_x_from, want_x_to, want_y_from, want_y_to);
    return gcd(left, right);
  }
}

void init(index_t r, index_t c) {
  R = r;
  C = c;
  root = new Segment();
}

void update(index_t P, index_t Q, val_t K) {
  update(root, 0, R, 0, C, P, Q, K);
}

val_t calculate(index_t P, index_t Q, index_t U, index_t V) {
  return query(root, 0, R, 0, C, P, U, Q, V);
}
