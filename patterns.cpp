#include <iostream>
using namespace std;

void print18(int n) {
  for (int i = 1; i <= n; i++) {
    for (char j = 'A' + n - i; j < n + 'A'; j++) {
      cout << j << " ";
    }
    cout << endl;
  }
}

void print19(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      cout << "*";
    }
    for (int j = 0; j < 2 * i; j++) {
      cout << " ";
    }
    for (int j = i; j < n; j++) {
      cout << "*";
    }
    cout << endl;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      cout << "*";
    }
    for (int j = 0; j < 2 * (n - i); j++) {
      cout << " ";
    }
    for (int j = 0; j < i; j++) {
      cout << "*";
    }
    cout << endl;
  }
}

void print22(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = n; j > n - i; j--) {
      cout << j << " ";
    }
    for (int j = 0; j < 2 * (n - i); j++) {
      cout << n - i + 1 << " ";
    }
    for (int j = n - i + 2; j <= n; j++) {
      cout << j << " ";
    }
    cout << endl;
  }
  for (int i = n - 1; i > 0; i--) {
    for (int j = n; j > n - i; j--) {
      cout << j << " ";
    }
    for (int j = 0; j < 2 * (n - i); j ++) {
      cout << n - i + 1 << " ";
    }
    for (int j = n - i + 2; j <= n; j++) {
      cout << j << " ";
    }
    cout << endl;
  }
}

void _print22(int n) {
  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      int top = i - 0;
      int bottom = 2 * (n - 1) - i;
      int left = j - 0;
      int right = 2 * (n - 1) - j;

      cout << n - min(min(top, bottom), min(left, right));
    }
    cout << endl;
  }
}

void print(int n) {
  for (int i = n; i > 0; i--) {
    for (int j = n; j > 0; j--) {
      cout << (i <= j ? j : i) << " ";
    }
    
    for (int j = 2; j <= n; j++) {
      cout << (i <= j ? j : i) << " ";
    }

    cout << endl;
  }
  
  for (int i = 2; i <= n; i++) {
    for (int j = n; j > 0; j--) {
      cout << (i <= j ? j : i) << " ";
    }
    
    for (int j = 2; j <= n; j++) {
      cout << (i <= j ? j : i) << " ";
    }
    
    cout << endl;
  }
}

int main() {
  int n;
  cin >> n;

  print(n);

  return 0;
}
