#include <vector>

const int MAX_N = 262144; //2^18
vector<int> bit(2 * MAX_N - 1);
int n;

int bit_sum(int i){
	int s = 0;
	while (i > 0){
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void bit_add(int i, int x){
	while (i <= n){
		bit[i] += x;
		i += i & -i;
	}
}