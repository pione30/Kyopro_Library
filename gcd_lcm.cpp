typedef long long int lli;

lli gcd(lli a, lli b){
	if (a < b) swap(a, b);
	if (b <= 0) return -1;

	lli r = a % b;
	if (r == 0) return b;
	else return gcd(b, r);
}

lli lcm(lli a, lli b){
	return a * b / gcd(a, b);
}
