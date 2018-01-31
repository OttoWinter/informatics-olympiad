//
// Created by Otto Winter on 20/04/2017.
//

#include <cstdio>
#include <algorithm>
#include <utility>
#include <type_traits>

#define INF 300070
#define DEBUG if(false)

using index_t = int;
using query_t = int;
using val_t = int;

static const index_t MAX_N = 50005;

struct Segment {
  val_t best_prefix;
  val_t best_suffix;
  val_t best;
  val_t sum;

  Segment *left_child;
  Segment *right_child;
};

template<typename T>
T &&vmin(T &&val) { return std::forward<T>(val); }

template<typename T0, typename T1, typename... Ts>
typename std::common_type<T0, T1, Ts...>::type vmin(T0 &&val1, T1 &&val2, Ts &&... vs) {
  if (val2 < val1)
    return vmin(val2, std::forward<Ts>(vs)...);
  else
    return vmin(val1, std::forward<Ts>(vs)...);
}

template<typename T>
T &&vmax(T &&val) { return std::forward<T>(val); }

template<typename T0, typename T1, typename... Ts>
typename std::common_type<T0, T1, Ts...>::type vmax(T0 &&val1, T1 &&val2, Ts &&... vs) {
  if (val2 > val1)
    return vmax(val2, std::forward<Ts>(vs)...);
  else
    return vmax(val1, std::forward<Ts>(vs)...);
}

index_t N;
query_t Q;
val_t arr[MAX_N];
Segment *root;

void build_tree(Segment *seg, index_t seg_from, index_t seg_to) {
  if (seg_from == seg_to) {
    seg->best_prefix = seg->best_suffix = seg->best = seg->sum = arr[seg_from];
    return;
  }
  index_t seg_mid = (seg_from + seg_to) / 2;
  auto *left_child = new Segment();
  build_tree(left_child, seg_from, seg_mid);
  auto *right_child = new Segment();
  build_tree(right_child, seg_mid + 1, seg_to);
  seg->best_prefix = std::max(left_child->best_prefix, left_child->sum + right_child->best_prefix);
  seg->best_suffix = std::max(right_child->best_suffix, right_child->sum + left_child->best_suffix);
  seg->best = vmax(seg->best_prefix,
                   seg->best_suffix,
                   left_child->best,
                   right_child->best,
                   left_child->best_suffix + right_child->best_prefix);
  seg->sum = left_child->sum + right_child->sum;
  seg->left_child = left_child;
  seg->right_child = right_child;
}

Segment query(Segment *seg, index_t seg_from, index_t seg_to, index_t want_from, index_t want_to) {
  if (want_from <= seg_from && seg_to <= want_to)
    return *seg;
  Segment ans_seg{};
  if (seg_from > want_to || seg_to < want_from) {
    ans_seg.best = ans_seg.best_prefix = ans_seg.best_suffix = ans_seg.sum = -1 * INF;
    return ans_seg;
  }

  index_t seg_mid = (seg_from + seg_to) / 2;
  Segment left_query = query(seg->left_child, seg_from, seg_mid, want_from, want_to);
  Segment right_query = query(seg->right_child, seg_mid + 1, seg_to, want_from, want_to);
  ans_seg.best_prefix = std::max(left_query.best_prefix, left_query.sum + right_query.best_prefix);
  ans_seg.best_suffix = std::max(right_query.best_suffix, right_query.sum + left_query.best_suffix);
  ans_seg.best = vmax(ans_seg.best_prefix,
                      ans_seg.best_suffix,
                      left_query.best,
                      right_query.best,
                      left_query.best_suffix + right_query.best_prefix);
  ans_seg.sum = left_query.sum + right_query.sum;

  return ans_seg;
}

void print_tree(Segment *seg, index_t seg_from, index_t seg_to) {
  if (seg == nullptr) {
    printf("NULL");
    return;
  }
  printf("{[%d;%d](best_prefix=%d,best_suffix=%d,best=%d,sum=%d) ",
         seg_from,
         seg_to,
         seg->best_prefix,
         seg->best_suffix,
         seg->best,
         seg->sum);

  index_t seg_mid = (seg_from + seg_to) / 2;
  printf("left=");
  print_tree(seg->left_child, seg_from, seg_mid);
  printf(", right=");
  print_tree(seg->right_child, seg_mid + 1, seg_to);
  printf("}");
}

int main() {
  scanf("%d", &N);
  for (index_t i = 1; i <= N; i++)
    scanf("%d", arr + i);
  root = new Segment();
  build_tree(root, 1, N);
  DEBUG print_tree(root, 1, N);
  DEBUG printf("\n");
  scanf("%d", &Q);
  for (query_t q = 0; q < Q; q++) {
    index_t a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", query(root, 1, N, a, b).best);
  }
  return 0;
}
