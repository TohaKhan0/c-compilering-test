#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    vector<int> weights(n), values(n);
    cout << "Enter weights and values of items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> weights[i];
        cout << "Item " << i + 1 << " - Value: ";
        cin >> values[i];
    }

    int max_value = knapsack(W, weights, values, n);
    cout << "Maximum value that can be achieved: " << max_value << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

// Function to calculate the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    // DP table where dp[i][w] represents the maximum value for 'i' items and knapsack capacity 'w'
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    // Number of items
    int n = 10000;  // 10,000 items for a worst-case scenario
    // Knapsack capacity
    int W = 5000;

    // Generate random weights and values
    vector<int> weights(n);
    vector<int> values(n);
    srand(time(0));  // Seed for random number generation

    for (int i = 0; i < n; i++) {
        weights[i] = rand() % 100 + 1;  // Random weights between 1 and 100
        values[i] = rand() % 100 + 1;   // Random values between 1 and 100
    }

    // Measure start time
    auto start = chrono::high_resolution_clock::now();

    // Calculate the maximum value that can be obtained
    int max_value = knapsack(W, weights, values, n);

    // Measure end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate duration
    chrono::duration<double> duration = end - start;

    // Output the result and time taken
    cout << "Maximum value in knapsack: " << max_value << endl;
    cout << "Time taken: " << duration.count() << " seconds" << endl;

    return 0;
}
aita kiser?