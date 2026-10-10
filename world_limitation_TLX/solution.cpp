#include <iostream>

using namespace std;

int main() {
  int A, X;
  cin >> A >> X;
  int N = X / A;
  int M = X % A;

  cout << N << " " << M << "\n";

  return 0;
}

// jadi deklarasi variabel dulu, terus  masukkan nilai dari A dan X
// lalu hitung N dan M dengan rumus N = X / A dan M = X % A