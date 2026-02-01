#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool possible(const vector<int>& A, int M, int X) {
    int segments = 1;
    int curOR = 0;

    for (int val : A) {
        // If single element OR itself exceeds X => impossible
        if (val > X) return false;

        int newOR = curOR | val;

        if (newOR <= X) {
            curOR = newOR;
        } else {
            segments++;
            curOR = val;
            if (segments > M) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int low = 0, high = 0;
    for (int x : A) high |= x; // maximum possible OR

    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (possible(A, M, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
