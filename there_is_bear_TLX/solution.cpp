#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    if (!(cin >> n >> d)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // untuk two pointer maka:
    int count = 0;
    int left = 0, right = 0;

    while (right < n){
        int diff = a[right] - a[left];
        if (diff == d) {
            count++;
            left++;
            right++;
        } else if (diff < d) {
            right++;
        } else {
            left++;
        }
    }

    cout << count << "\n";
    return 0;





}