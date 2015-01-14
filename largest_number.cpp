class Solution {
private:
    vector<string> convertToString(vector<int> num){
        vector<string> strNum;
        for(int i = 0; i < num.size(); i++){
            stringstream ss;
            ss << num[i];
            string str = ss.str();
            strNum.push_back(str);
        }
        return strNum;
    }
    bool compare(string s1, string s2){
    
        int len1 = s1.size();
        int len2 = s2.size();
        
        int p1 = 0;
        int p2 = 0;
        while(p1 < len1 && p2 < len2){
            if(s1[p1] > s2[p2]){
                return true;
            }
            else if(s1[p1] < s2[p2]){
                return false;
            }
            p1++;
            p2++;
        }
        
        int offset = 0;
        while(p1 < len1){
            if(s1[p1] > s1[offset]){
                return true;
            }
            else if(s1[p1] < s1[offset]){
                return false;
            }
            else {
                if(s1.size() > offset + 1 && s1[offset + 1] > s1[offset]){
                    return false;
                }
                else if(p1 + 1 == len1){
                    return true;
                }
            }
            p1++;
            offset++;
        }
        
        offset = 0;
        while(p2 < len2){
            if(s2[p2] > s2[offset]){
                return false;
            }
            else if(s2[p2] < s2[offset]){
                return true;
            }
            else {
                if(s2.size() > offset + 1 && s2[offset + 1] > s2[offset]){
                    return true;
                }
                else if(p2 + 1 == len2){
                    return false;
                }
            }
            p2++;
            offset++;
        }
    
        return true;
    }
    int partition(vector<string> &s, int begin, int end){
    
        string pivot = s[begin];
        
        while(begin < end){
            while(begin < end && compare(pivot, s[end])) end--;
            s[begin] = s[end];
            while(begin < end && !compare(pivot, s[begin])) begin++;
            s[end] = s[begin];
        }
        
        s[end] = pivot;
        return end;
    }
    void sortNum(vector<string> &s, int begin, int end){
        if(begin >= end){
            return;
        }
        
        int pivot = partition(s, begin, end);
        
        sortNum(s, begin, pivot - 1);
        sortNum(s, pivot + 1, end);
    }
    string genRes(vector<string> strNum){
        string result;
        for(int i = 0; i < strNum.size(); i++){
            if(result == "0" && strNum[i] == "0"){
                continue;
            }
            result += strNum[i];
        }
        return result;
    }
public:
    string largestNumber(vector<int> &num) {
        
        string result;
        if(num.size() == 0){
            return result;
        }
        
        vector<string> strNum = convertToString(num);
        sortNum(strNum, 0, strNum.size() - 1);
        
        result = genRes(strNum);
        
        return result;
    }
};