class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int longest=0;
        unordered_set<int>s(nums.begin(),nums.end());;
        for(auto& num:s){
            if(s.contains(num-1))
            continue;

            int n=num;
            int cur=1;

            while(s.contains(n+1)){
                cur++;n++;
            }
            longest=max(longest,cur);
        }
        return longest;

        
    }
};