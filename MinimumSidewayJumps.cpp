https://leetcode.com/problems/minimum-sideway-jumps/

class Solution {
public:
    int theOther(int lane1 , int lane2) {
        return (6 - (lane1+lane2));
    }
    
    int bestNextLane(int current_lane , int index , vector<int>& obstacles){
        
        for (int i=index+1; i<obstacles.size(); i++){
            if (obstacles[i] != 0 && obstacles[i] != current_lane) return       theOther(current_lane, obstacles[i]);
        }
        return -1;
    }
     
    int minSideJumps(vector<int>& obstacles) {
        int current_lane = 2;
        int side_jumps = 0;
        for (int i=0; i<obstacles.size()-1; i++){
           if (obstacles[i+1] == current_lane) {
               side_jumps += 1;
               int optimistic = bestNextLane(current_lane, i+1, obstacles );
               if (obstacles[i] == optimistic)
                   current_lane = theOther(optimistic,current_lane); 
               else 
                   current_lane = optimistic;
               if (current_lane == -1) return side_jumps;
           }
        }
        return side_jumps;
    }
};
