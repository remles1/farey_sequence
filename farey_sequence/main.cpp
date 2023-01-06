#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int64_t> farey(double n, int iter) {
	int sign = 1;
	if (n < 0) {
		sign = -1;
	}

	string n_str = to_string(n);
	string before_decimal_str = "";
	string after_decimal_str = "0";
	bool passed_dot = 0;

	for (int i = 0; i < n_str.length(); i++) {
		if (n_str[i] == '.') {
			passed_dot = 1;
		};
		if (!passed_dot) {
			before_decimal_str.push_back(n_str[i]);
		}
		else {
			after_decimal_str.push_back(n_str[i]);
		}
	}

	int64_t before_decimal = stoll(before_decimal_str);
	double after_decimal = stod(after_decimal_str);
	if (after_decimal == 0) {
		return { (int64_t)n,1 };
	}
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

	return {sign*(pivot_a + before_decimal * pivot_b),pivot_b};
}

int main() {
	vector<int64_t> f = farey(-2.5, 1000);
	cout << f[0] << "/" << f[1];
}
