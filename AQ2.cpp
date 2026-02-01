#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);

    unordered_map<int, int> freq;
    int mn = INT_MAX, mx = INT_MIN;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        freq[A[i]]++;
        mn = min(mn, A[i]);
        mx = max(mx, A[i]);
    }

    int ans = 0;
    for (int start = mn; start <= mx; start++) {
        int total = 0;
        for (int x = start; x <= start + 10; x++) {
            if (freq.count(x)) total += freq[x];
        }
        ans = max(ans, total);
    }

    cout << ans << "\n";
    return 0;
}
