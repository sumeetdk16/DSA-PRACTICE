class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        // optimal
        vector<int> depth(seq.size(),0);
        int cnt=0;
        for(int i=0;i<seq.size();i++)
        {
            if(seq[i]=='(') //opening case
            {
                cnt++;
                depth[i]= (cnt%2)==0? 0:1; //even / odd
            }
            else//closing case 
            {
                depth[i]= (cnt%2)==0 ? 0:1; //even /odd
                cnt--;
            }
        }
        return depth;
        
    }
};