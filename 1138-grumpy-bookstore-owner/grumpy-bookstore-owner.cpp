class Solution {
public:
   
    
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int n = customers.size();
    int total_satisfied = 0;

    // 1. Count customers already satisfied
    for (int i = 0; i < n; ++i) {
        if (grumpy[i] == 0)
            total_satisfied += customers[i];
    }

    // 2. Sliding window to find max additional satisfied customers
    int extra_satisfied = 0, max_extra = 0;

    for (int i = 0; i < X; ++i) {
        if (grumpy[i] == 1)
            extra_satisfied += customers[i];
    }
    max_extra = extra_satisfied;

    for (int i = X; i < n; ++i) {
        if (grumpy[i] == 1)
            extra_satisfied += customers[i];
        if (grumpy[i - X] == 1)
            extra_satisfied -= customers[i - X];
        max_extra = max(max_extra, extra_satisfied);
    }

    return total_satisfied + max_extra;
}

};
