class Solution {
public:
long long solve(int n)
{
  return 1LL * n * (n - 1) / 2;

}
  long long distributeCandies(int n, int l) {
    
    if (n > 3 * l) {
      return 0;
    }

    long long total = solve(n + 2);
    
    if (n > l) {
      total -= 3 * solve(n - l + 1);
    }

  if (n >= 2 * l) {
      total += 3 * solve(n - 2 * l);
    }
    

    return total;
  }
};
