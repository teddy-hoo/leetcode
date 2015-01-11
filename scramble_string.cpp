class Solution {
private:
    bool determineScrambleOrNot(string s1, string s2, int begin1, int end1, int &begin2, int &end2){
        if(begin1 == end1){
            begin2 = s2.find(s1[begin1]);
            if(begin2 < 0){
                return false;
            }
            end2 = begin2;
            return true;
        }
        int middle = (begin1 + end1 + 1) / 2;
        int cbegin1 = -1;
        int cend1 = -1;
        int cbegin2 = -1;
        int cend2 = -1;
        
        if(!determineScrambleOrNot(s1, s2, begin1, middle - 1, cbegin1, cend1)){
            return false;
        }
        if(!determineScrambleOrNot(s1, s2, middle, end1, cbegin2, cend2)){
            return false;
        }
        
        if(cend1 + 1 == cbegin2){
            begin2 = cbegin1;
            end2 = cend2;
            return true;
        }
        else if(cend2 + 1 == cbegin1){
            begin2 = cbegin2;
            end2 = cend1;
            return true;
        }
        
        return false;
        
    }
public:
    bool isScramble(string s1, string s2) {
        
        int len1 = s1.size();
        int len2 = s2.size();
        
        if(len1 != len2){
            return false;
        }
        
        int begin = -1;
        int end = -1;
        determineScrambleOrNot(s1, s2, 0, len1 - 1, begin, end);
        if(begin == 0 && end == len1 - 1){
            return true;
        }
        return false;
    }
};