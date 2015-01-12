class Solution {
    bool isInterleaveRecusion(string s1, string s2, string s3, int p1, int p2, int p3){
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if(p3 == len3){
            if(p1 == len1 && p2 == len2){
                return true;
            }
            return false;
        }
        bool r1 = false;
        if(p1 < len1 && s3[p3] == s1[p1]){
            r1 = isInterleaveRecusion(s1, s2, s3, p1 + 1, p2, p3 + 1);
        }
        if(r1){
            return true;
        }
        bool r2 = false;
        if(p2 < len2 && s3[p3] == s2[p2]){
            r2 = isInterleaveRecusion(s1, s2, s3, p1, p2 + 1, p3 + 1);
        }
        return r2;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        return isInterleaveRecusion(s1, s2, s3, 0, 0, 0);
    }
};
