// Time Complexity - O(N)
// Auxiliary Space Complexity - O(1)

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        int curr = first;
        for(int i = 0; i < n; i++)
            curr = (encoded[i] = curr^encoded[i]);
        
        reverse(encoded.begin(), encoded.end());
        encoded.push_back(first);
        reverse(encoded.begin(), encoded.end());
        return encoded;
    }
};