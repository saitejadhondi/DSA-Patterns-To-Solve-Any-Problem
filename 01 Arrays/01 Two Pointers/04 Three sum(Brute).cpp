/*
Time Complexity:
With set: O(n³ log n)
If we used unordered_set (with a custom hash for vectors):
Average case: O(n³)
Worst case: O(n^6) (bad hashing collisions)
Space Complexity:
O(n³) (to store all unique triplets)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find triplets having sum equals to 0
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> tripletSet;
        int n = nums.size();

        // Check all possible triplets
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end()); // sort to ensure uniqueness
                        tripletSet.insert(temp);
                    }
                }
            }
        }

        // Convert set to vector
        return vector<vector<int>>(tripletSet.begin(), tripletSet.end());
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);

    cout << "Unique triplets with sum 0 are:\n";
    for (auto& triplet : ans) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << " ";
        }
        cout << "]\n";
    }

    return 0;
}