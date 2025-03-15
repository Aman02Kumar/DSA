class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (citations[mid] >= (n - mid)) {
                right = mid - 1;  // Try to find a higher h-index
            } else {
                left = mid + 1;   // Increase the range
            }
        }

        return n - left;
    }
};
