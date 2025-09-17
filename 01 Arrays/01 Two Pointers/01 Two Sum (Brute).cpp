#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find two indices in the array `nums` such that their elements sum up to `target`.
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        // Return {-1, -1} if no such pair is found
        return {-1, -1};
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);

    cout << "This is the answer: [" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}