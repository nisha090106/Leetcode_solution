class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> cpy = heights;
        sort(cpy.begin(),cpy.end());
        int count = 0;
        for(int i = 0 ; i<heights.size();i++){
            if(heights[i]!=cpy[i]){
                count++;
            }
        }
        return count;
    }
};