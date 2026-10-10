#include <iostream>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int N;

   if(cin >> N){
      bool cek_nol = false;

      while (N > 0) {
         if (N % 10 == 0) {
            cek_nol = true;
            break;
         }
            N /= 10;
   }
      if (cek_nol) {
         cout << "YES\n";
      } else {
         cout << "NO\n";
      }
   }
   return 0;
}