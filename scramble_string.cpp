/**
 * backtracking algorithm
 * date:   28-01-2015
 * author: Teddy
 */
 
/**
 *    "great"
 *     great
 *     /   \
 *    gr   eat
 *   / \   / \
 * "great" & "rgtae"
 * sort(gr) == sort(rg)
 * sort(eat) == sort(tae)
 * 01, 24   compare with 01, 24 02, 34
 * 02, 34   compare with 02, 34 01, 24
 */

/**
 * Time: T(n) = 2T(n/2) + O(nlogn); O(nlognlogn)
 * Space: o(n)
 */
 
class Solution {
private:
    string str1;
    string str2;
private:
    bool compareSubstr(int b1, int e1, int b2, int e2, int half, int len){
        string sub11 = str1.substr(b1, half);
        string sub12 = str1.substr(e1, len - half);
        string sub21 = str2.substr(b2, half);
        string sub22 = str2.substr(e2, len - half);
        sort(sub11.begin(), sub11.end());
        sort(sub12.begin(), sub12.end());
        sort(sub21.begin(), sub21.end());
        sort(sub22.begin(), sub22.end());
        if(sub11 == sub21 && sub12 == sub22){
            return true;
        }
        return false;
    }
    bool compare( int b1, int b2, int len){
        
        if(len == 1){
            return str1[b1] == str2[b2] ? true : false;
        }

        bool result = false;
        
        for(int half = 1; half < len; half++){
            
            if(compareSubstr(b1, b1 + half, b2, b2 + half, half, len)){
                result = compare(b1, b2, half) &&
                         compare(b1 + half, b2 + half, len - half);
            }

            if(result){
                return true;
            }
            
            if(compareSubstr(b1, b1 + half, b2 + len - half, b2, half, len)){
                result = compare(b1, b2 + len - half, half) &&
                         compare(b1 + half, b2, len - half);
            }

            if(result){
                return true;
            }

        }
        
        return false;
    }
public:
    bool isScramble(string s1, string s2) {
        int len = s1.size();
        
        if(len <= 0){
            return true;
        }
        
        str1 = s1;
        str2 = s2;
        
        return compare(0, 0, len);
    }
};