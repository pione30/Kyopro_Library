#include <vector>
typedef vector<int> vi;

const int N = 262144; //218
vi segtree(2 * N - 1);

void st_add(int x){
	int n = N - 1 + x;
	while (n > 0){
		++segtree[n];
		n = (n - 1) / 2;
	}
}

int st_eject(int x){
	int n = 0;
	while (2 * n + 1 < 2 * N - 1){
		if (segtree[2 * n + 1] < x){
			x -= segtree[2 * n + 1];
			n = 2 * n + 2;
		}
		else{
			n = 2 * n + 1;
		}
		--segtree[n];
	}
	return n - (N - 1);
}
