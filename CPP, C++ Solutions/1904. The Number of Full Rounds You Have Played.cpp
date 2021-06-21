// TC - O(1)
// SC - O(1)
class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int startMinute = stoi(startTime.substr(0, 2))*60 + stoi(startTime.substr(3, 2));
        int endMinute = stoi(finishTime.substr(0, 2))*60 + stoi(finishTime.substr(3, 2));
        int count = 0;
        if(startMinute > endMinute) endMinute += 1440;
        
        if(startMinute%15)
            startMinute += (15 - startMinute%15);
        if(endMinute%15)
            endMinute -= endMinute%15;
        if(startMinute < endMinute) return (endMinute-startMinute)/15;
        
        return 0;
    }
};