#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minTimeToCross(vector<int>& times) {
    sort(times.begin(), times.end());
    int n = times.size();
    if (n <= 2) return times.back();

    int total_time = 0;
    while (n > 3) {
        // Two strategies: sending the two slowest together or one at a time
        int time1 = times[0] + 2 * times[1] + times[n - 1];
        int time2 = 2 * times[0] + times[n - 2] + times[n - 1];
        total_time += min(time1, time2);

        // Remove the two slowest who have crossed
        n -= 2;
    }
    // Handle the last three people
    if (n == 3) total_time += times[0] + times[1] + times[2];
    else total_time += times[1];

    return total_time;
}

int main() {
    int n;
    cin >> n;
    vector<int> times(n);
    for (int i = 0; i < n; ++i) cin >> times[i];

    cout << minTimeToCross(times) << endl;

    return 0;
}