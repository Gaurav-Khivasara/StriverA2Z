#include <iostream>
using namespace std;

int jump(int idx, int h[], int k, int dp[]) {
  if (idx == 0) {
    return 0;
  }

  int tj = INT_MAX;
  if (dp[idx] == 0) {
    for (int i = 1; i <= k; i++) {
      if (idx >= i) {
        tj = min(jump(idx - i, h, k, dp) + abs(h[idx] - h[idx - i]), tj);
        dp[idx] = tj;
      }
    }
  }

  return dp[idx];
}

int jumpTabulation(int h[], int k, int dp[], int n) {
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    int tj = INT_MAX;
    for (int j = 1; j <= k; j++) {
      if (i >= j) {
        tj = min(dp[i - j] + abs(h[i] - h[i - j]), tj);
        dp[i] = tj;
      }
    }
  }

  return dp[n];
}

int main() {
  int n;
  cin >> n;

  int h[n];
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  int k;
  cin >> k;

  int dp[n] = {0};

  // cout << "jump: " << jump(n - 1, h, k, dp) << endl;
  cout << "jumpTabulation: " << jumpTabulation(h, k, dp, n - 1) << endl;

  for (int x: dp) {
    cout << x << " ";
  }

  return 0;
}
