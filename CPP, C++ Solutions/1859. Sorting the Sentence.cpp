// TC - O(N)
// SC - O(N)
class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string item;
        vector<string> v(10, "");
        
        while(ss >> item)
            v[item[item.size()-1]-'0'] = item.substr(0, item.size()-1);
        
        item = "";
        for(int i = 1; i < 10; i++) {
            if(v[i] == "")
                break;
            
            item += v[i] + " ";
        }
        
        return item.substr(0, item.size()-1);
    }
};