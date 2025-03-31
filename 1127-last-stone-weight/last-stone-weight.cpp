class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;
        for(int s : stones){
            maxh.push(s);
        }

        while(maxh.size() > 1){
            int one = maxh.top();
            maxh.pop();

            int two = maxh.top();
            maxh.pop();
            
            maxh.push(abs(one-two));

        }

        return maxh.top();
    }
};