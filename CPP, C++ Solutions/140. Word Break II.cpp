/************* Method-1 (BackTracking Solution, TC-O(N*..), SC-O(M)) **************
// M = max(1000 wordDict.length, res.length) 
class Solution {
public:
    void wordBreakHelper(string &s, unordered_set<string> &dict, int start, string &contri, vector<string> &res) {
        // Positive base case
        int n = s.size();
        if(start == n) {
            contri = contri.substr(0, (int)contri.size()-1);
            res.push_back(contri);
            return;
        }
        
        string temp = "";
        string prev_contri;
        for(int i = start; i < n; i++) {
            temp += s[i];
            
            if(dict.find(temp) == dict.end()) 
                continue;
            prev_contri = contri;
            contri = contri + temp + " ";
            wordBreakHelper(s, dict, i+1, contri, res);
            // Undo
            contri = prev_contri;
        }    
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        string contri;
        vector<string> res;
        wordBreakHelper(s, dict, 0, contri, res);
        return res;
    }
};
******************************************************************************/


/***************** Method-2 (DP Optimization, pruning, TC-O(M^(N/Ek)), SC-(M)-linear) *********************/
class Solution {
public:
    void wordBreakHelper(string &s, unordered_set<string> &dict, int start, string &contri, vector<string> &res, vector<bool> &dp) {
        // Positive base case
        int n = s.size();
        if(start == n) {
            contri = contri.substr(0, (int)contri.size()-1);
            res.push_back(contri);
            return;
        }
        
        // Pruning step
        if(!dp[start]) 
            return;
        
        string temp = "";
        string prev_contri;
        for(int i = start; i < n; i++) {
            temp += s[i];
            
            if(dict.find(temp) == dict.end()) 
                continue;
            prev_contri = contri;
            contri = contri + temp + " ";
            wordBreakHelper(s, dict, i+1, contri, res, dp);
            // Undo
            contri = prev_contri;
        }    
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        
        string temp;
        for(int i = n-1; i >= 0; i--) {
            // Compute dp[i];
            temp = "";
            for(int j = i; j < n; j++) {
                temp += s[j];
                
                if(dict.find(temp) == dict.end()) 
                    continue;
                
                dp[i] = dp[i] || dp[j+1];
                if(dp[i] == true)
                    break;
            }
        }
        string contri;
        vector<string> res;
        wordBreakHelper(s, dict, 0, contri, res, dp);
        return res;
    }
};