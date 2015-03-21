typedef vector<int> vi;

vi par;
vi rank_of_tree;

void init(int N){
	par.resize(N);
	rank_of_tree.resize(N);
	for (int i = 0; i < N; ++i) par[i] = i;
}

//木の根を求める
int find(int x){
	if (par[x] == x){
		return x;
	}
	else {
		return par[x] = find(par[x]); //経路圧縮
	}
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

	if (rank_of_tree[px] < rank_of_tree[py]){
		par[px] = py;
	}
	else {
		par[py] = px;
		if (rank_of_tree[px] == rank_of_tree[py]) ++rank_of_tree[px];
	}
}
