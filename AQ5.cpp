#include <iostream>
using namespace std;


bool canFit(long long S, long long N, long long H, long long W) {
    return (S / W) * (S / H) >= N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long N, H, W;
        cin >> N >> H >> W;

        long long low = 0, high = 1;
        while (!canFit(high, N, H, W)) high *= 2;

        while (low + 1 < high) {
            long long mid = low + (high - low) / 2;
            if (canFit(mid, N, H, W)) high = mid;
            else low = mid;
        }

        cout << high << "\n";
    }
    return 0;
}
