
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a,b,c;

  if (cin >> a >> b >> c) {
    int target_point = ((a+b+c)/7)*4;

    if (a == target_point || b == target_point || c == target_point) {
      cout << "YA\n";
    } else {
      cout << "TIDAK\n";
    }
  } 
  return 0;
}