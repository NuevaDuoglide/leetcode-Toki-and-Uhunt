#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    int parity = 0;
    int a;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        parity = (parity + (a % 2)) % 2;
    }

    // biar data gak rusak aja sih

    int b;
    for (int i = 0; i < n; ++i) {
        cin >> b;
    }
    cout << parity << "\n";
    return 0;
}