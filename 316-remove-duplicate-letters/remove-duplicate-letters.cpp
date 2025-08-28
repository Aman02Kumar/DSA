class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(256, -1);
        vector<bool> inStack(256, false);
        stack<char> st;

        // Step 1: Store last index of each char
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;
        }

        // Step 2: Traverse string
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // If already in stack, skip
            if (inStack[c])
                continue;

            // Step 3: Maintain monotonic stack
            while (!st.empty() && st.top() > c && lastIndex[st.top()] > i) {
                inStack[st.top()] = false; // mark removed
                st.pop();
            }

            st.push(c);
            inStack[c] = true;
        }

        // Step 4: Build answer
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};