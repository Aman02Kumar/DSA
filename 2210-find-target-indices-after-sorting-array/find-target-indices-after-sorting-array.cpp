class Solution {
public:
    // Function to find the first occurrence of target (lower bound)
    int lb(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] >= target) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    // Function to find the last occurrence of target (upper bound)
    int ub(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] > target) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l - 1;
    }

    vector<int> targetIndices(vector<int>& nums, int target) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Find the first and last occurrence of target
        int first = lb(nums, target);
        int last = ub(nums, target);

        // Step 3: If target is not found, return empty vector
        if (first >= nums.size() || nums[first] != target) {
            return {};
        }

        // Step 4: Store all indices from first to last
        vector<int> result;
        for (int i = first; i <= last; i++) {
            result.push_back(i);
        }

        return result;
    }
};
