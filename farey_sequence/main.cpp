#include <iostream>
#include <vector>
using namespace std;

vector<int64_t> farey(double n, int iter) {
	bool is_positive = 1;
	if (n < 0) {
		is_positive = 0;
	}

	int64_t before_decimal = (int64_t)n;
	double after_decimal = abs(n - before_decimal);
	before_decimal = abs(before_decimal);

	int64_t a = 0; // 
	int64_t b = 1; // representing fraction: 0/1

	int64_t c = 1; // 
	int64_t d = 1;  // representing fraction: 1/1

	int64_t pivot_a = a + c;
	int64_t pivot_b = b + d;

	for (int i = 0; i < iter; i++) {
		pivot_a = a + c;
		pivot_b = b + d;
		double pivot = (double)pivot_a / pivot_b;
		if (after_decimal > pivot) {
			a = pivot_a;
			b = pivot_b;
		}
		else if (after_decimal < pivot) {
			c = pivot_a;
			d = pivot_b;
		}
	}

	if (is_positive) {
		return {pivot_a + before_decimal * pivot_b,pivot_b};
	}
	else {
		return { -1 * (pivot_a + before_decimal * pivot_b),pivot_b };
	}
	
}

int main() {
	vector<int64_t> f = farey(-206500.153123138979,1000);
	cout << f[0] << "/" << f[1];
}