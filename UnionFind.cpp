vi par(N);

//木の根を求める
int find(int x){
  if (par[x] == x) return x;
  else return par[x] = find(par[x]); //経路圧縮
}

// xとyが同じグループに属するか否か
bool same(int x, int y){
  return find(x) == find(y);
}

// xとyの属するグループを併合
void merge(int x, int y){
  int px = find(x);
  int py = find(y);
  if (px == py) return;

  par[px] = py;
}
