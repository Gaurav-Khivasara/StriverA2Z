#include <iostream>
using namespace std;

int jump(int idx, int h[], int dp[]) {
  if (idx == 0) {
    return 0;
  }

  if (dp[idx] == 0) {
    int s = jump(idx - 1, h, dp) + abs(h[idx] - h[idx - 1]);

    int l = s;
    if (idx > 1) {
      l = jump(idx - 2, h, dp) + abs(h[idx] - h[idx - 2]);
    }

    dp[idx] = min(s, l);
  }

  return dp[idx];
}

int jumpTabulation(int h[], int dp[], int n) {
  dp[0] = 0;

  // dp[1] = abs(h[1] - h[0]);
  // for (int i = 2; i <= n; i++) {
  //   dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
  // }
  /* Looped from i = 1, because if n = 1 then, dp[1] would get garbage value
  Though the correct answer would have been returned
  Error in Java */
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
    if (i > 1) {
      dp[i] = min(dp[i - 2] + abs(h[i] - h[i - 2]), dp[i]);
    }
  }

  return dp[n];
}

int jumpOptimizedTabulation(int h[], int n) {
  int l = 0;
  int s = abs(h[1] - h[0]);
  for (int i = 2; i <= n; i++) {
    int temp = l;
    l = s;
    s = min(temp + abs(h[i] - h[i - 2]), s + abs(h[i] - h[i - 1]));
  }

  return s;
}

int main() {
  int n;
  cin >> n;

  int h[n];
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  int dp[n] = {0};

  // cout << "jump: " << jump(n - 1, h, dp) << endl;
  // cout << "jumpTabulation: " << jumpTabulation(h, dp, n - 1) << endl;
  cout << "jumpOptimzedTabulation: " << jumpOptimizedTabulation(h, n - 1) << endl;

  return 0;
}