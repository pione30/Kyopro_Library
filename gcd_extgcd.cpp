typedef long long int lli;

lli gcd(lli a, lli b){
	if (b < 0) return -1;
	if (b == 0) return a;
	return gcd(b, a % b);
}

lli extgcd(lli a, lli b, lli& x lli& y){
	lli d = a;
	if (b != 0){
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else{
		x = 1; y = 0;
	}
	return d;
}