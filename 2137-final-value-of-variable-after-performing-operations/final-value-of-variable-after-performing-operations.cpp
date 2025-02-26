class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int counter = 0;
        for(int i = 0; i < operations.size(); i++)
        {
            if(operations[i].at(0) == '+' || operations[i].at(2) == '+')
                counter++;
            else 
                counter--;
        }
        return counter;
    }
};