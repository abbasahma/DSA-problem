// C++ implementation to print elements of
// the Array which can be expressed as
// power of some integer to given exponent K

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Method returns Nth power of A
double nthRoot(ll A, ll N)
{

	double xPre = 7;

	// Smaller eps, denotes more accuracy
	double eps = 1e-3;

	// Initializing difference between two
	// roots by INT_MAX
	double delX = INT_MAX;

	// x^K denotes current value of x
	double xK;

	// loop until we reach desired accuracy
	while (delX > eps) {

		// calculating current value from previous
		// value by newton's method
		xK = ((N - 1.0) * xPre
			+ (double)A / pow(xPre, N - 1))
			/ (double)N;

		delX = abs(xK - xPre);
		xPre = xK;
	}

	return xK;
}

// Function to check
// whether its k root
// is an integer or not
bool check(ll no, int k)
{
	double kth_root = nthRoot(no, k);
	ll num = kth_root;

	if (abs(num - kth_root) < 1e-4)
		return true;

	return false;
}

// Function to find the numbers
void printExpo(ll arr[], int n, int k)
{
	for (int i = 0; i < n; i++) {
		if (check(arr[i], k))
			cout << arr[i] << " ";
	}
}

// Driver code
int main()
{

	int K = 6;

	ll arr[] = { 46656, 64, 256,
				729, 16, 1000 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printExpo(arr, n, K);

	return 0;
}

