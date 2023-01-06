#include <iostream>
#include <vector>
using namespace std;

vector<int> farey(double n, int iter) {
	bool is_positive = 1;
	if (n < 0) {
		is_positive = 0;
	}

	long long int before_decimal = (int)n;
	double after_decimal = abs(n - before_decimal);
	
	int a = 0; // 
	int b = 1; // representing fraction: 0/1

	int c = 1; // 
	int d = 1;  // representing fraction: 1/1

	int pivot_a = a + c;
	int pivot_b = b + d;

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
		return { -1 * (pivot_a + (-1 * before_decimal * pivot_b)),pivot_b };
	}
	
}

int main() {
	vector<int> f = farey(-138.53321312,100);
	cout << f[0] << "/" << f[1];
}