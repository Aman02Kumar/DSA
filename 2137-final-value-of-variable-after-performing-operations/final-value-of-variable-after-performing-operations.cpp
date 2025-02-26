class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int counter = 0;
        for(int i = 0; i < operations.size(); i++)
        {
            if(operations[i][0] == '+' || operations[i][2] == '+')
                counter++;
            else 
                counter--;
        }
        return counter;
    }
};