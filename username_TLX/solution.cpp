#include <iostream>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int N;

   if (cin >> N) {
      char hrf_sblm = '\0';
      char hrf_skrg;

      for (int i = 0; i<N; i++){

        cin >> hrf_skrg;

        if (hrf_skrg != hrf_sblm) {
            cout << hrf_skrg;
            hrf_sblm = hrf_skrg;

        }
      }
      cout << "\n";
   }
   return 0;
}