#include <vector>
#include <iostream>
#include <climits>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void selectionSort(int arr[], int n) {
  // min is sent at first of sorted
  // select minimum from i + 1 => n and swap(arr[i], min), i = 0 -> n - 1

  for (int i = 0; i < n - 1; i++) {
    // cout << "Pass " << i + 1 << endl;
    int min = i;
    // int cmp = 1;
    for (int j = i + 1; j < n; j++) {
      // cout << "Comparison " << cmp << endl;
      // cmp++;
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    // cout << endl;
    
    swap(arr[i], arr[min]);
  }
}

void bubbleSort(int arr[], int n) {
  // max is sent at last of unsorted, just like bubbles come to the surface
  // swap adjacent from 0 to n - i, i = 1 -> n - 1
  
  for (int i = 1; i < n; i++) {
    // cout << "Pass " << i << endl;
    // int cmp = 1;
    bool swapped = false;
    for (int j = 0; j < n - i; j++) {
      // cout << "Comparison " << cmp << endl;
      // cmp++;
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    // cout << endl;

    if (!swapped) {
      break;
    }
  }
}

void insertionSort(int arr[], int n) {
  // each element is placed (inserted) in its correct position (sorted)
  // swap from i to 0, i = 0 -> n - 1

  for (int i = 1; i < n; i++) {
    int j = i;
    // cout << "Pass " << i + 1 << endl;
    // int cmp = 1;
    while (j > 0 && arr[j - 1] > arr[j]) {
      // cout << "Comparison " << cmp << endl;
      // cmp++;
      swap(arr[j - 1], arr[j]);
      j--;
    }
    // cout << endl;
  }
}

void selectionSortRecursive(int arr[], int n, int i) {
  if (i < n - 1) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }

    swap(arr[i], arr[min]);

    selectionSortRecursive(arr, n, i + 1);
  }
}

void bubbleSortRecursive(int arr[], int n, int i) {
  if (i < n) {
    bool swapped = false;
    for (int j = 0; j < n - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    
    if (!swapped) {
      return;
    }

    bubbleSortRecursive(arr, n, i + 1);
  }
}

void insertionSortRecursive(int arr[], int n, int i) {
  if (i < n) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      swap(arr[j - 1], arr[j]);
      j--;
    }

    insertionSortRecursive(arr, n, i + 1);
  }
}

void merge(int arr[], int left, int mid, int right) {
  int merged[right - left + 1];

  int i = left;
  int j = mid + 1;
  int k = 0;

  while (i <= mid && j <= right) {
    if (arr[i] < arr[j]) {
      merged[k++] = arr[i++];
    } else {
      merged[k++] = arr[j++];
    }
  }
  
  while (i <= mid) {
    merged[k++] = arr[i++];
  }
  
  while (j <= right) {
    merged[k++] = arr[j++];
  }
  
  for (i = left; i <= right; i++) {
    arr[i] = merged[i - left];
  }
}

void mergeSort(int arr[], int left, int right) {
  // Divide and merge while maintaing sorting order
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

int partition(int arr[], int left, int right) {
  int i = left;
  int j = right;
  while (i < j) {
    while (i < right && arr[i] <= arr[left]) {
      i++;
    }
    
    while (j > left && arr[j] > arr[left]) {
      j--;
    }

    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[left], arr[j]);

  return j;
}

void quickSort(int arr[], int left, int right) {
  // Pick the first and place it in its correct position

  if (left < right) {
    int partitionIdx = partition(arr, left, right);
    quickSort(arr, left, partitionIdx - 1);
    quickSort(arr, partitionIdx + 1, right);
  }
}

void selection_sort(vector<int> &a, int n) {
  for (int i = 0; i < n - 1; i++) {
    int mn = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[mn]) {
        mn = j;
      }
    }

    swap(a[i], a[mn]);
  }
}

void bubble_sort(vector<int> &a, int n) {
  for (int i = n - 1; i > 0; i--) {
    bool flag = false;
    for (int j = 0; j < i; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        flag = true;
      }
    }

    if (!flag) {
      break;
    }
  }
}

void insertion_sort(vector<int> &a, int n) {
  for (int i = 1; i < n; i++) {
    int j = i;
    while (j > 0 && a[j - 1] > a[j]) {
      swap(a[j - 1], a[j]);
      j--;
    }
  }
}

void merge_(vector<int> &a, int left, int mid, int right) {
  vector<int> merged;
  
  int i = left;
  int j = mid + 1;

  while (i <= mid && j <= right) {
    if (a[i] < a[j]) {
      merged.push_back(a[i++]);
    } else {
      merged.push_back(a[j++]);
    }
  }
  
  while (i <= mid) {
    merged.push_back(a[i++]);
  }
  
  while (j <= right) {
    merged.push_back(a[j++]);
  }

  for (int i = left; i <= right; i++) {
    a[i] = merged[i - left];
  }
}

void merge_sort(vector<int> &a, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge_(a, left, mid, right);
  }
}

void selection_sort_rec(vector<int> &a, int n, int i) {
  if (i < n) {
    int mni = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[mni]) {
        mni = j;
      }
    }
    
    swap(a[mni], a[i]);
    
    selection_sort_rec(a, n, i + 1);
  }
}

void bubble_sort_rec(vector<int> &a, int n, int i) {
  if (i >= 0) {
    bool flag = false;
    for (int j = 0; j < i; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        flag = true;
      }
    }

    if (flag) {
      bubble_sort_rec(a, n, i - 1);
    }
  }
}

void insertion_sort_rec(vector<int> &a, int n, int i) {
  if (i < n) {
    int j = i;
    while (j > 0 && a[j] < a[j - 1]) {
      swap(a[j], a[j - 1]);
      j--;
    }

    insertion_sort_rec(a, n, i + 1);
  }
}

int partition_(vector<int> &a, int left, int right) {
  int i = left;
  int j = right;
  while (i < j) {
    while (i < right && a[i] <= a[left]) {
      i++;
    }

    while (j > left && a[j] > a[left]) {
      j--;
    }

    if (i < j) {
      swap(a[i], a[j]);
    }
  }

  swap(a[left], a[j]);

  return j;
}

void quick_sort(vector<int> &a, int left, int right) {
  if (left < right) {
    int idx = partition_(a, left, right);
    quick_sort(a, left, idx - 1);
    quick_sort(a, idx + 1, right);
  }
}

int main() {
  // int n;
  // cin >> n;
  // int arr[n];
  // for (int i = 0; i < n; i++) {
  //   cin >> arr[i];
  // }

  // selectionSort(arr, n);
  // bubbleSort(arr, n);
  // insertionSort(arr, n);
  
  // selectionSortRecursive(arr, n, 0);
  // bubbleSortRecursive(arr, n, 1);
  // insertionSortRecursive(arr, n, 1);

  // mergeSort(arr, 0, n - 1);
  // quickSort(arr, 0, n - 1);


  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  quick_sort(a, 0, n - 1);

  for (int x: a) {
    cout << x << " ";
  }

  return 0;
}