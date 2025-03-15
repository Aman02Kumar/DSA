class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> sortedIntervals; // Stores {start, index}
        vector<int> result(n, -1); // Initialize with -1

        // Store start points with their original indices
        for (int i = 0; i < n; i++) {
            sortedIntervals.push_back({intervals[i][0], i});
        }

        // Sort intervals by start value
        sort(sortedIntervals.begin(), sortedIntervals.end());

        // Find the right interval using binary search
        for (int i = 0; i < n; i++) {
            int endValue = intervals[i][1];
            int left = 0, right = n - 1;
            int index = -1;

            // Binary search for the smallest start >= endValue
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (sortedIntervals[mid].first >= endValue) {
                    index = sortedIntervals[mid].second; // Store index
                    right = mid - 1; // Look for smaller start
                } else {
                    left = mid + 1;
                }
            }

            result[i] = index;
        }

        return result;
    }
};