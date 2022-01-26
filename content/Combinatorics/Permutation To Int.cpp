/**
 * Description: Permutation -> integer conversion. (Not order preserving.)
 * Integer -> permutation can use a lookup table.
 * Time: O(n)
 **/

int permToInt(vector<int>& v) {
	int use = 0, i = 0, r = 0;
	for(int x : v) r = r * ++i + __builtin_popcount(use & -(1<<x)),
		use |= 1 << x;                     // (note: minus, not ~!)
	return r;
}