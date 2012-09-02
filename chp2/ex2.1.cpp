int gcd(int a, int b)
{
  int c = a % b;
  while(c != 0)
  {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

struct Rational {
	Rational(int n_, int d_) : n(n_), d(d_) {
		int g = gcd(n, d);
		n /= g;
		d /= g;
		
		if(d < 0) {
			n = -n;
			d = -d;
		}
	}

	int n, d;
};

int main() {
	Rational r(2, 3);
	return 0;
}
