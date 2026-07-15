class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char , int > mp;

        int left =0;
        int right =0;
        int count = t.size();
        int len = INT_MAX;
        int start = 0;

        for(char ch : t)
        mp[ch]++;

        while(right < s.size()){
            if(mp[s[right]]>0)
                count--;

                mp[s[right]]--;

                while(count==0){
                    if(right-left+1 < len){
                        len = right-left+1;
                        start=left;
                    }
                    mp[s[left]]++;

                    if(mp[s[left]]>0)
                        count++;

                     left++;
                   
                }
                 right++;
                
                }
                if(len==INT_MAX)
                    return"";

                return s.substr(start, len);
    

    }
};