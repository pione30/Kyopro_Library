const int INF = 0x7fffffff;
const int MAX_N = 1 << 17;

vi dat(2 * MAX_N - 1, INF);
int n;

void init(int n_){
  // 簡単のため、要素数を2のべき乗に
  n = 1;
  while(n < n_) n *= 2;
}

// k番目の値(0-indexed)をaに変更
void update(int k, int a){
  k += n - 1;
  dat[k] = a;
  while(k > 0){
    k = (k - 1) / 2;
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
}

// [a, b)の最小値を求める
// 後ろのほうの引数は、計算の簡単のための引数。
// kは節点の番号、l, rはその節点が[l, r)に対応づいていることを表す。
// したがって、外からはquery(a, b, 0, 0, n)として呼ぶ。
int query(int a, int b, int k, int l, int r){
  // [a, b)と[l, r]が交差しなければ、INF
  if(r <= a || b <= l) return INF;

  // [a, b)が[l, r]を完全に含んでいれば、この節点の値
  if(a <= l && r <= b) return dat[k];
  else {
    // そうでなければ、2つの子の最小値
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
}
