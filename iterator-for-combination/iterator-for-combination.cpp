class CombinationIterator {
private:
    vector<string> combination;
    int idx;
    string input;
public:
    
    
    CombinationIterator(string characters, int combinationLength) {
        combination.clear();
        idx = 0;
        input = characters;
        string str = "";
        for(int i = 0; i < combinationLength; i++)
            str.push_back('0');
        while(str.size() < characters.size())
            str.push_back('1');
        
        do combination.push_back(str);
        while(next_permutation(str.begin(), str.end()));
    }
    
    string next() {
        string str = combination[idx];
        idx++;
        string result = "";
        for(int i = 0; i < str.size(); i++)
            if(str[i] == '0') result.push_back(input[i]);
        return result;
    }
    
    bool hasNext() {
        return idx < (int)combination.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */