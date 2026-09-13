class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> result(num1.size() + num2.size(), 0);

        for(int i = 0; i < num1.size(); i++) {
            for(int j = 0; j < num2.size(); j++) {
                result[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        // Handle carry
        for(int i = 0; i < result.size() - 1; i++) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }

        string ans = "";

        for(int i = result.size() - 1; i >= 0; i--) {
            if(ans.empty() && result[i] == 0)
                continue;

            ans += (result[i] + '0');
        }

        return ans;
    }
};