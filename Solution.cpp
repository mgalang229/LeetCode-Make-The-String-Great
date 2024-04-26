class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (char& c : s) {
            if (!st.empty()) {
                char top = tolower(st.top());
                char cur = tolower(c);
                if (top == cur && ((islower(st.top()) && isupper(c)) || (islower(c) && isupper(st.top())))) {
                    st.pop();
                    continue;
                }
            }
            st.push(c);
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
