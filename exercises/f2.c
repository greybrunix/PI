

float
multInt1(int n, float m)
{	float res = m;
	while (n)
		res*=n--;
	return res;
}

float
multInt2(int n, float m)
{	float res = 0.f;
	while (n > 0)
	{ m+=m;
		n=n>>1;
		if (n%2) res+=m;
	}
	return res;
}

int
gdc1(int n, int m)
{	int menor;
	if (n > m) {n^=m;m=n^m;n^=m;}
	menor = n;
	while (menor && !(n%menor) && !(m%menor))
	  menor--;
	return menor;
}

int
gdc3(int m, int n)
{ int rem;
	if (n > m) {n^=m;m=n^m;n^=m;}
	rem = m % n;
	while (rem > 0)
	{ m = n;
		n = rem;
		rem = m%n;
	}
	return n;
}
