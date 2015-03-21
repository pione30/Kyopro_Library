int par[N*N] = {0};

//�؂̍������߂�
int find(int x){
	if (par[x] == x){
		return x;
	}
	else {
		return par[x] = find(par[x]); //�o�H���k
	}
}

// x��y�������O���[�v�ɑ����邩�ۂ�
bool same(int x, int y){
	return find(x) == find(y);
}

// x��y�̑�����O���[�v�𕹍�
void merge(int x, int y){
	int px = find(x);
	int py = find(y);
	if (px == py) return;

	par[px] = py;
}