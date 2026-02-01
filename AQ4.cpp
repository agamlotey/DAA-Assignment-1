#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        bool special = false;

        for (int l = 0; l <= i; l++) {
            int cnt = 0;
            for (int r = i; r < n; r++) {
                if (A[r] > A[i]) cnt++;

                if (cnt == k) special = true;
                if (cnt > k) break;
            }
            if (special) break;
        }

        if (special) ans += A[i];
    }

    cout << ans << "\n";
    return 0;
}
