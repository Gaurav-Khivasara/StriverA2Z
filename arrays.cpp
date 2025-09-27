#include <string>
#include <unordered_map>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <iostream>
using namespace std;

void reverseArr(int arr[], int left, int right) {
  int mid = left + (right - left + 1) / 2;
  for (int i = left; i < mid; i++) {
    int temp = arr[i];
    arr[i] = arr[right + left - i];
    arr[right + left - i] = temp;
  }
}

void rotateLeft(int arr[], int n, int k) {
  k %= n;
  reverseArr(arr, 0, k - 1);
  reverseArr(arr, k, n - 1);
  reverseArr(arr, 0, n - 1);
}

void rotateRight(int arr[], int n, int k) {
  k %= n;
  rotateLeft(arr, n, n - k);
}

vector<int> arrIntersection(int arr1[], int m, int arr2[], int n) {
  vector<int> intersection;

  int i = 0;
  int j = 0;
  while (i < m && j < n) {
    if (arr1[i] == arr2[j]) {
      intersection.push_back(arr1[i]);
      i++;
      j++;
    }
    else if (arr1[i] < arr2[j]) {
      i++;
    }
    else {
      j++;
    }
  }

  return intersection;
}

vector<int> arrIntersectionUnique(int arr1[], int m, int arr2[], int n) {
  vector<int> intersection;

  int i = 0;
  int j = 0;
  while (i < m && j < n) {
    if (arr1[i] == arr2[j]) {
      if (intersection.empty() || intersection.back() != arr1[i]) {
        intersection.push_back(arr1[i]);
      }
      i++;
      j++;
    }
    else if (arr1[i] < arr2[j]) {
      i++;
    }
    else {
      j++;
    }
  }

  return intersection;
}

int maxSubarraySumK(int arr[], int n, int k) {
  int maxLen = 0;
  int sum = 0;
  int left = 0;
  int right = 0;
  while (right < n) {
    sum += arr[right];

    if (sum > k) {
      sum -= arr[left++];
    }

    if (sum == k) {
      maxLen = max(right - left + 1, maxLen);
    }

    right++;
  }

  return maxLen;
}

void printSubarrayWithMaxSum(int arr[], int n) {
  int mx = INT_MIN;
  int start = -1;
  int end = -1;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (sum == 0) {
      start = i;
    }

    sum += arr[i];

    if (sum > mx) {
      mx = sum;
      end = i;
    }

    if (sum < 0) {
      sum = 0;
    }
  }

  for (int i = start; i <= end; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void spiralMatrix(int **mat, int n, int m) {
  int r = m - 1;
  int b = n - 1;
  int l = 0;
  int t = 0;
  int k = 0;
  while (k < m * n) {
    int j = l;
    while (j <= r && k < m * n) {
      cout << mat[t][j] << " ";
      j++;
      k++;
    }
    t++;
    int i = t;
    while (i <= b && k < m * n) {
      cout << mat[i][r] << " ";
      i++;
      k++;
    }
    r--;
    j = r;
    while (j >= l && k < m * n) {
      cout << mat[b][j] << " ";
      j--;
      k++;
    }
    b--;
    i = b;
    while (i >= t && k < m * n) {
      cout << mat[i][l] << " ";
      i--;
      k++;
    }
    l++;
  }
  cout << endl;
  // int r = m - 1;
  // int b = n - 1;
  // int l = 0;
  // int t = 0;
  // int k = 0;
  // while (k < m * n) {
  //   for (int j = l; j <= r; j++) {
  //     cout << mat[t][j] << " ";
  //     k++;
  //   }
  //   t++;
  //   for (int i = t; i <= b; i++) {
  //     cout << mat[i][r] << " ";
  //     k++;
  //   }
  //   r--;
  //   for (int j = r; j >= l && k < m * n; j--) {
  //     cout << mat[b][j] << " ";
  //     k++;
  //   }
  //   b--;
  //   for (int i = b; i >= t && k < m * n; i--) {
  //     cout << mat[i][l] << " ";
  //     k++;
  //   }
  //   l++;
  // }
  // cout << endl;
}

int nCr(int n, int r) {
  int c = 1;
  for (int i = 0; i < n - r; i++) {
    c = (c * (n - i)) / (i + 1);
  }
  return c;
}

int pascalsTriangleEle(int r, int c) {
  return nCr(r - 1, c - 1);
}

vector<int> pascalsTriangleRow(int r) {
  vector<int> row;
  int c = 1;
  for (int i = 0; i < r; i++) {
    row.push_back(c);
    c = (c * (r - i - 1)) / (i + 1);
  }
  
  return row;
}

vector<vector<int>> pascalsTriangle(int n) {
  vector<vector<int>> triangle;
  for (int i = 1; i <= n; i++) {
    triangle.push_back(pascalsTriangleRow(i));
  }
  return triangle;
}

vector<int> largestSubarrayWithSum0(int arr[], int n) {
  int l;
  int r;
  int sum = 0;
  unordered_map<int, int> map;
  for (int i = 0; i < n; i++) {
    sum += arr[i];

    if (sum == 0) {
      l = 0;
      r = i;
    }

    int rem = sum;
    
    if (map.find(rem) == map.end() && i - map[rem] > r - l) {
      l = map[rem];
      r = i;
    }

    if (map.find(sum) != map.end()) {
      map[sum] = i;
    }
  }

  vector<int> lsw(r - l + 1);
  for (int i = l; i <= r; i++) {
    lsw.push_back(arr[i]);
  }
  return lsw;
}

int largest_ele(vector<int> a) {
  int max = a[0];
  for (int i = 1; i < a.size(); i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }

  return max;
}

vector<int> second_largest(vector<int> a) {
  int n = a.size();
  
  if (n <= 1) {
    return {};
  }

  int min = INT_MAX;
  int mn;
  int max = INT_MIN;
  int mx;
  mn = mx = a[0];

  for (int i = 0; i < n; i++) {
    if (a[i] > mx) {
      max = mx;
      mx = a[i];
    } else if (a[i] > max && a[i] != mx) {
      max = a[i];
    }
    
    if (a[i] < mn) {
      min = mn;
      mn = a[i];
    } else if (a[i] < min && a[i] != mn) {
      min = a[i];
    }
  }

  return {min, max};
}

string is_arr_sorted_and_rotated(vector<int> a) {
  int count = 0;
  for (int i = 1; i < a.size(); i++) {
    if (a[i] < a[i - 1]) {
      count++;
    }
  }

  return !count || count == 1 && a[a.size() - 1] <= a[0] ? "true" : "false";
}

int remove_duplicates(vector<int> &a) {
  int idx = 0;
  for (int i = 1; i < a.size(); i++) {
    if (a[idx] != a[i]) {
      idx++;
      swap(a[idx], a[i]);
    }
  }

  return idx;
}

void reverse_arr(vector<int> &a, int left, int right) {
  for (int i = left; i <= (right + left) / 2; i++) {
    swap(a[i], a[right + left - i]);
  }
}

void rotate_left(vector<int> &a, int k) {
  k %= a.size();
  reverse_arr(a, 0, k - 1);
  reverse_arr(a, k, a.size() - 1);
  reverse_arr(a, 0, a.size() - 1);
}

void rotate_right(vector<int> &a, int k) {
  k %= a.size();
  rotate_left(a, a.size() - k);
}

int linear_search(vector<int> &a, int tgt) {
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == tgt) {
      return i;
    }
  }

  return -1;
}

vector<int> arr_union(vector<int> &a, int n, vector<int> &b, int m) {
  int i = 0;
  int j = 0;
  vector<int> u;
  while (i < n && j < m) {
    if (a[i] <= b[j]) {
      if (u.empty() || u.back() != a[i]) {
        u.push_back(a[i]);
      }
      i++;
      if (a[i] == b[j]) {
        j++;
      }
    } else {
      if (u.empty() || u.back() != b[j]) {
        u.push_back(b[j]);
      }
      j++;
    }
  }
  
  while (i < n) {
    if (u.empty() || u.back() != a[i]) {
      u.push_back(a[i]);
    }
    i++;
  }
  
  while (j < m) {
    if (u.empty() || u.back() != b[j]) {
      u.push_back(b[j]);
    }
    j++;
  }

  return u;
}

int missing_no(vector<int> a) {
  int xor1 = 0;
  int xor2 = 0;
  for (int i = 0; i < a.size(); i++) {
    xor1 ^= (i + 1);
    xor2 ^= a[i];
  }

  return xor1 ^ xor2;
}

int max_cons_ones(vector<int> a) {
  int mx = 0;
  int ones = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 1) {
      ones++;
    } else {
      mx = max(ones, mx);
      ones = 0;
    }
  }

  return max(ones, mx);
}

int single_no(vector<int> a) {
  int x = a[0];
  for (int i = 1; i < a.size(); i++) {
    x ^= a[i];
  }

  return x;
}

int longest_subarray_sum_pos(vector<int> a, int tgt) {
  int len = 0;
  for (int right = 0, left = 0, sum = 0;
     right < a.size();
     right++) {
    sum += a[right];

    if (sum > tgt) {
      sum -= a[left++];
    }

    if (sum == tgt) {
      len = max(right - left + 1, len);
    }
  }

  return len;
}

int longest_subarray_sum(vector<int> a, int tgt) {
  int len = 0;
  unordered_map<long, int> map;
  long sum = 0;
  for (int i = 0; i < a.size(); i++) {
    sum += a[i];

    if (sum == tgt) {
      len = max(i + 1, len);
    }

    if (map.find(sum - tgt) != map.end()) {
      len = max(i - map[sum - tgt] + 1, len);
    }

    if (map.find(sum) == map.end()) {
      map[sum] = i;
    }
  }

  return len;
}

vector<int> two_sum(vector<int> a, int tgt) {
  sort(a.begin(), a.end());
  int left = 0;
  int right = a.size() - 1;
  while (left < right) {
    if (a[left] + a[right] == tgt) {
      return {left, right};
    } else if (a[left] + a[right] > tgt) {
      right--;
    } else {
      left++;
    }
  }

  return {-1, -1};
}

void swap(vector<int> &a, int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

void sort_colors(vector<int> &colors) {
  int left = 0;
  int right = colors.size() - 1;
  for (int i = left; i <= right; i++) {
    if (colors[i] == 0) {
      swap(colors[i], colors[left++]);
    } else if (colors[i] == 2) {
      swap(colors[i--], colors[right--]);
    }
  }
}

int majority_ele(vector<int> a) {
  int count = 1;
  int curr = a[0];
  for (int i = 1; i < a.size(); i++) {
    if (a[i] == curr) {
      count++;
    } else if (count == 0) {
      curr = a[i];
      count++;
    } else {
      count--;
    }
  }

  return curr;
}

long max_subarray_sum(vector<int> a) {
  long sum = 0;
  long max = 0;
  for (int i = 0; i < a.size(); i++) {
    sum += a[i];

    if (sum > max) {
      max = sum;
    }

    if (sum < 0) {
      sum = 0;
    }
  }

  return max;
}

long max_subarray_sum_print(vector<int> a) {
  long sum = 0;
  long max = 0;
  int start = -1;
  int end = -1;
  for (int i = 0; i < a.size(); i++) {
    if (start == -1) {
      start = i;
    }

    sum += a[i];

    if (sum > max) {
      max = sum;
      end = i;
    }

    if (sum < 0) {
      sum = 0;
      start = -1;
    }
  }

  for (int i = start; i <= end; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  return max;
}

long best_time_to_buy_sell_stock(vector<int> a) {
  int buy = a[0];
  int profit = 0;
  for (int i = 1; i < a.size(); i++) {
    if (a[i] < buy) {
      buy = a[i];
    }

    if (a[i] - buy > profit) {
      profit = a[i] - buy;
    }
  }

  return profit;
}

vector<int> rearrange_by_sign(vector<int> a) {
  int len = a.size();
  int p = 0;
  int n = 1;

  vector<int> sol(len, 0);
  for (int x: a) {
    if (x >= 0) {
      sol[p] = x;
      p += 2;
    } else {
      sol[n] = x;
      n += 2;
    }
  }

  return sol;
}

void next_permutation(vector<int> &a) {
  int n = a.size();
  int idx = -1;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1]) {
      idx = i;
      break;
    }
  }

  for (int i = n - 1; i > idx; i--) {
    if (a[i] > a[idx]) {
      swap(a[i], a[idx]);
      break;
    }
  }

  cout << idx << endl;
  // reverse_arr(a, idx + 1, n - 1);
  for (int i = idx + 1; i < (idx + 1 + n) / 2; i++) {
    cout << i << " " << n - 1 + idx << endl;
    // swap(a[i], a[(idx + 1 + n) / 2 - idx]);
  }
}

vector<int> leaders(vector<int> a) {
  vector<int> sol;
  int max = a[a.size() - 1];
  sol.push_back(max);
  for (int i = a.size() - 2; i >= 0; i--) {
    if (a[i] > max) {
      max = a[i];
      sol.push_back(max);
    }
  }

  return sol;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> vec) {
  os << "[";
  for (int i = 0; i < vec.size(); i++) {
    os << vec[i];
    if (i != vec.size() - 1) {
      os << ", ";
    }
  }
  os << "]";

  return os;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    // int **mat = new int *[n];
    // for (int i = 0; i < n; i++) {
    //   mat[i] = new int[m];
    //   for (int j = 0; j < m; j++) {
    //     cin >> mat[i][j];
    //   }
    // }

    // rotateLeft(arr, n, k);
    // rotateRight(arr, n, k);

    // for (int ele: arrIntersectionUnique(a, m, b, n)) {
    // for (int ele: arrIntersection(a, m, b, n)) {
    //   cout << ele << " ";
    // }

    // cout << maxSubarraySumK(a, n, k);
    // cout << endl;

    // printSubarrayWithMaxSum(a, n);

    // spiralMatrix(mat, n, m);

    // cout << pascalsTriangleEle(r, c) << endl;
    
    // for (auto ele: pascalsTriangleRow(r)) {
    //   cout << ele << " ";
    // }
    // cout << endl;
    
    // for (auto row: pascalsTriangle(n)) {
    //   for (auto ele: row) {
    //     cout << ele << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;

    // int arr[n];
    // for (int i = 0; i < n; i++) {
    //   cin >> arr[i];
    // }
    // for (auto x: largestSubarrayWithSum0(arr, n)) {
    //   cout << x << " ";
    // }
    // cout << endl;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    cout << leaders(a);

    cout << endl;
  }

  return 0;
}
