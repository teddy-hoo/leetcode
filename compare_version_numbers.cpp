class Solution {
private:
    vector<string> split(string s, char divider){
        vector<string> parts;
        int len = s.size();
        int start = 0;
        int i = 0;
        for(; i < len; i++){
            if(s[i] == divider){
                string sub = trim(s.substr(start, i - start));
                parts.push_back(sub);
                start = i + 1;
            }
        }
        if(start < i){
            string sub = trim(s.substr(start, i - start));
            parts.push_back(sub);
        }
        return parts;
    }    
    int compareDigits(string s1, string s2){
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 != len2){
            return len1 > len2 ? 1 : -1;
        }
        int begin1 = 0;
        int begin2 = 0;
        while(begin1 < len1 && begin2 < len2){
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
    string trim(string s){
        int begin = 0;
        int end = s.size();
        while(begin < end && s[begin] == '0'){
            begin++;
        }
        if(begin == end){
            return "";
        }
        return s.substr(begin, end);
    }
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1 = split(version1, '.');
        vector<string> v2 = split(version2, '.');
        int i = 0;
        for(; i < v1.size() && i < v2.size(); i++){
            int versionCompare = compareDigits(v1[i], v2[i]);
            if(versionCompare != 0){
                return versionCompare;
            }
        }
        if(i != v1.size() && v1[i].size() > 0){
            return 1;
        }
        else if(i != v2.size() && v2[i].size() > 0){
            return -1;
        }
        else{
            return 0;
        }
    }
};
