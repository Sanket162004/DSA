class Solution {
public:
    inline void traverseOptionalPoint(string s, int &i) {
        if (i < s.size() && s[i] == '.') i++;
    }

    inline void traverseOptionalSign(string s, int &i) {
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            i++;
        }
    }
    
    inline bool isIntegerStart(string s, int &i) {
        int cnt = 0;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') cnt++, i++;
        return cnt > 0;
    }

    inline bool isDecimalContinuation(string s, int &i) {
        traverseOptionalPoint(s, i);
        return isIntegerStart(s, i);
    }

    inline bool isOptionalExponent(string s, int &i) {
        if (i < s.size() && s[i] == 'e' || s[i] == 'E') {
            i++;
            traverseOptionalSign(s, i);
            if (!isIntegerStart(s, i)) return false;
        }
        return true;
    }

    bool isNumber(string s) {
        int i = 0, n = s.size();

        traverseOptionalSign(s, i);
        
        bool isInteger = isIntegerStart(s, i);
        bool isDecimal = isDecimalContinuation(s, i);
        if (!isInteger && !isDecimal) return false;

        bool isValidExponent = isOptionalExponent(s, i);
        if (!isValidExponent) return false;

        return i == n;
    }
};