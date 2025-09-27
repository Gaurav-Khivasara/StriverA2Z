#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

void minMaxFreqElements(int arr[], int n) {
  unordered_map<int, int> map;
  for (int i = 0; i < n; i++) {
    map[arr[i]]++;
  }
  
  int minFreq = n + 1;
  int maxFreq = 0;
  
  int min = arr[0];
  int max = arr[0];
  
  for (int i = 0; i < n; i++) {
    if (map[arr[i]] < minFreq) {
      minFreq = map[arr[i]];
      min = arr[i];
    } else if (map[arr[i]] > maxFreq) {
      maxFreq = map[arr[i]];
      max = arr[i];
    }
  }

  // for (auto entry : map) {
  //   cout << entry.first << " => " << entry.second << endl;
  // }
  // cout << endl;

  // for (int i = 0; i < n; i++) {
  //   cout << arr[i] << " => " << map[arr[i]] << endl;
  // }
  // cout << endl;
  
  cout << "Min freq ele: " << min << endl;
  cout << "Max freq ele: " << max << endl;
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    minMaxFreqElements(arr, n);
  }

  return 0;
}
