#include <vector>

const int MAX_N = 262144; //2^18
vector<int> segtree(2 * MAX_N - 1);

void st_add(int x){
	int n = MAX_N - 1 + x;
	while (n > 0){
		++segtree[n];
		n = (n - 1) / 2;
	}
}

int st_eject(int x){
	int n = 0;
	while (2 * n + 1 < 2 * MAX_N - 1){
		if (segtree[2 * n + 1] < x){
			x -= segtree[2 * n + 1];
			n = 2 * n + 2;
		}
		else{
			n = 2 * n + 1;
		}
		--segtree[n];
	}
	return n - (MAX_N - 1);
}
