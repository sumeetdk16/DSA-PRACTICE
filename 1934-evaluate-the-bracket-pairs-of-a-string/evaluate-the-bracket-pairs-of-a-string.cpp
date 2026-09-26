class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        int n = s.size(), i = 0;

        unordered_map<string, string> mpp;
        for (auto &it : knowledge) {

            mpp[it[0]] = it[1];
        }

        string tmp = "", ans = "";

        bool flag = 0;

        while (i < n) {
            if (s[i] == '(') // open bracket case
                flag = 1;

            else if (s[i] == ')') // close bracket case
            {
                flag = 0;

                if(mpp.count(tmp)) ans+=mpp[tmp];//find the value of key 
                else ans+='?';//if not found add ?

                tmp = "";
            } else if (flag == 0) // normal words
                ans += s[i];
            else // tmp string
            {
                tmp += s[i];
            }

            i++;//inc i always 
        }

        return ans;
    }
};