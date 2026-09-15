class Solution {
public:
    bool rotateString(string s, string goal) {
        string doubled = s + s;
        if(s.length()!=goal.length()) return false;
         return doubled.find(goal)!=string::npos;

    }
};