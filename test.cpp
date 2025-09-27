// #include <iostream>
// using namespace std;

// void printFileName() {
//   cout << "test.cpp" << endl;
// }

// void readArr(int arr[], int n) {
//   for (int i = 0; i < n; i++) {
//     cin >> arr[i];
//   }
// }

// int sumArr(int arr[], int n) {
//   for (int i = 0; i < n; i++) {
//     arr[0] += arr[i];
//   }

//   return arr[0];
// }

// double pi2() {
//   return 3.14;
// }

// void swap(int &a, int &b) {
//   int temp = a;
//   a = b;
//   b = temp;
// }

// int fib(int n) {
//   int a = 0;
//   int b = 1;
//   for (int i = 0; i < n - 1; i++) {
//     int temp = b;
//     b += a;
//     a = temp;
//   }

//   return b;
// }

// int main() {
//   int arr[5];
//   readArr(arr, 5);
  
//   printFileName();

//   cout << "arr: [";
//   for (int i = 0; i < 5; i++) {
//     cout << arr[i] << (i != 4 ? ", " : "]");
//   }
//   cout << endl;
  
//   cout << "Sum: " << sumArr(arr, 5) << endl;

//   int a;
//   int b;
  
//   cin >> a >> b;

//   cout << endl << "Before swap: a = " << a << ", b = " << b << endl;
//   swap(a, b);
//   cout << "After swap: a = " << a << ", b = " << b << endl;

//   int n;
//   cin >> n;
//   cout << "\nFibonacci " << n << ": " << fib(n) << endl;

//   return 0;
// }


#include <string>
#include <iostream>
using namespace std;

struct Book {
  string name;
  double price;
};

class BookInfo {
  public:
    Book book;
    void setBook(const string& n, double p) {
      book.name = n;
      book.price = p;
    }

    string getBookName() {
      return book.name;
    }

    double getBookPrice() {
      return book.price;
    }
};

int main() {
  BookInfo bi;

  bi.setBook("TGG", 10.99);
  cout << bi.getBookName() << endl;
  cout << bi.getBookPrice() << endl;
}
