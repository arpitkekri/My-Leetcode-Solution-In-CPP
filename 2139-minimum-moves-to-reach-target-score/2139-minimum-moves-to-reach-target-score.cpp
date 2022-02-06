class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        
        int count=0;
        while(target>1)
        {
            if(target%2)
            {
                count++;
                target--;
            }
            else
            {
                if(maxDoubles>0)
                {
                    target/=2;
                    count++;
                    maxDoubles--;
                }
                else
                    return count+target-1;
            }
            
        }
        return count;
        
    }
};