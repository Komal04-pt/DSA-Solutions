class Solution {
public:

    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {

        int n = s.size();
        int ans = 0;
        int start = 0;

        while (start < n) {

            bool found = false;

            for (int end = start + k - 1; end < n; end++) {
                for (int l = start; l <= end - k + 1; l++) {

                    if (isPalindrome(s, l, end)) {

                        ans++;
                        start = end + 1;

                        found = true;
                        break;
                    }
                }

                if (found)
                    break;
            }

            if (!found)
                break;
        }

        return ans;
    }
};