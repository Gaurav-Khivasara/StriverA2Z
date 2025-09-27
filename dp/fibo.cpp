#include <iostream>
using namespace std;

int fibMemoization(int n, int dp[]) {
  if (n <= 1) {
    return n;
  }

  if (dp[n] == 0) {
    dp[n] = fibMemoization(n - 1, dp) + fibMemoization(n - 2, dp);
  }

  return dp[n];
}

int fibTabulation(int n, int dp[]) {
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

int fibOptimizedTabulation(int n) {
  int prev2 = 0;
  int prev = 1;
  for (int i = 2; i <= n; i++) {
    int temp = prev2;
    prev2 = prev;
    prev += temp;
  }

  return prev;
}

int main() {
  int n;
  cin >> n;

  int dp[n + 1] = {0};

  // cout << "fibMemoization: " << fibMemoization(n, dp) << endl;
  // cout << "fibTabulation: " << fibTabulation(n, dp) << endl;
  cout << "fibOptimizedTabulation: " << fibOptimizedTabulation(n);

  return 0;
}