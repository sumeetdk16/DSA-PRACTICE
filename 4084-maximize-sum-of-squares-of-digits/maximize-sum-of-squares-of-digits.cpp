class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if (sum > 9 * num)
            return "";

        int no_of_nines = sum / 9;
        int rem = sum % 9;

        string ans(no_of_nines, '9');
        if (rem > 0)
            ans.push_back(rem + '0');
        ans.append(num - ans.length(), '0');

        return ans;
    }
};