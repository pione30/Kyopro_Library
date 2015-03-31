typedef long long int lli;

lli gcd(lli a, lli b){
	if (b < 0) return -1;
	if (b == 0) return a;
	return gcd(b, a % b);
}

lli lcm(lli a, lli b){
	return a * b / gcd(a, b);
}
