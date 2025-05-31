class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // Pointer for children
        int j = 0; // Pointer for cookies

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++; // Child is content
            }
            j++; // Move to next cookie either way
        }

        return i; // Number of content children
    }
};
