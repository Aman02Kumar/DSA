class Solution {
public:
	int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
	int n = startTime.size();
	int previousEndTime = 0;
	int gap;
    int maxi1 = 0, maxi2 = 0, maxi3 = 0;

	for (int i = 0; i < n; i++) {
		gap = startTime[i] - previousEndTime;
        previousEndTime = endTime[i];

		if(gap > maxi1){
            maxi3 = maxi2;
            maxi2 = maxi1;
            maxi1 = gap;
        }
        else if(gap > maxi2){
            maxi3 = maxi2;
            maxi2 = gap;
        }
        else if(gap > maxi3){
            maxi3 = gap;
        }
	}

	gap = eventTime - endTime.back();

    if(gap > maxi1){
        maxi3 = maxi2;
        maxi2 = maxi1;
        maxi1 = gap;
    }
    else if(gap > maxi2){
        maxi3 = maxi2;
        maxi2 = gap;
    }
    else if(gap > maxi3){
        maxi3 = gap;
    }

    // cout << maxi1 << " " << maxi2 << " " << maxi3 << endl;

	int maxFreeSpace = 0;
	int left, right;

	for (int i = 0; i < n; i++) {
		if (i > 0) {
			left = startTime[i] - endTime[i - 1];
		}
		else {
			left = startTime[i];
		}

		if (i < n - 1) {
			right = startTime[i + 1] - endTime[i];
		}
		else {
			right = eventTime - endTime[i];
		}

		int gap = endTime[i] - startTime[i];
		int greaterGaps = 0;

        if(maxi3 >= gap) greaterGaps = 3;
        else if(maxi2 >= gap) greaterGaps = 2;
        else if(maxi1 >= gap) greaterGaps = 1;
		
		if (left >= gap) greaterGaps--;
		if (right >= gap) greaterGaps--;

		if (greaterGaps > 0) {
			maxFreeSpace = max(maxFreeSpace, left + right + gap);
		}
		else {
			maxFreeSpace = max(maxFreeSpace, left + right);
		}

		// cout << left << " " << right << " " << greaterGaps << " " << gap << endl;
	}

	return maxFreeSpace;
}
};