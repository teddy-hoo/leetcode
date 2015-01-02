class Solution {
private:
    int findDot(string s){
        int len = s.size();
        for(int i = 0; i < len; i++){
            if(s[i] == '.'){
                return i;
            }
        }
        return -1;
    }    
    int compareDigits(string s1, int begin1, int end1, string s2, int begin2, int end2){
        int len1 = end1 - begin1;
        int len2 = end2 - begin2;
        if(len1 != len2){
            return len1 > len2 ? 1 : -1;
        }
        while(begin1 < end1 && begin2 < end2){
            if(s1[begin1] > s2[begin2]){
                return 1;
            }
            else if(s1[begin1] < s2[begin2]){
                return -1;
            }
            begin1++;
            begin2++;
        }
        return 0;
    }
    void removeZero(string s, int &begin, int &end){
        while(begin <= end && s[begin] == '0'){
            begin++;
        }
//        while(end >= begin && s[end] == '0'){
//            end--;
//        }
    }
public:
    int compareVersion(string version1, string version2) {
        int begin1 = 0;
        int end1 = version1.size() - 1;
        int begin2 = 0;
        int end2 = version2.size() - 1;
        removeZero(version1, begin1, end1);
        removeZero(version2, begin2, end2);
        int dot1 = findDot(version1);
        int dot2 = findDot(version2);
        int mid1 = dot1 == -1 ? end1 + 1 : dot1;
        int mid2 = dot2 == -1 ? end2 + 1 : dot2;
        int versionCompare = compareDigits(version1, begin1, mid1, version2, begin2, mid2);
        if(versionCompare != 0){
            return versionCompare;
        }
        int subVersionCompare = compareDigits(version1, mid1 + 1, end1 + 1, version2, mid2 + 1, end2 + 1);
        return subVersionCompare;
    }
};
