class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        // double slope = (double)(coordinates[0][0]-coordinates[1][0])/(double)(coordinates[0][1]-coordinates[1][1]);

        // cout<< slope<<endl;
        for(int i = 2; i < n; ++i) {
            // double temp_slope = (double)(coordinates[0][0]-coordinates[i][0])/(double)(coordinates[0][1]-coordinates[i][1]);
            // cout<< temp_slope<<endl;
            if((coordinates[0][0]-coordinates[i][0]) * (coordinates[0][1]-coordinates[1][1]) != (coordinates[0][1]-coordinates[i][1]) * (coordinates[0][0]-coordinates[1][0])) {
                return false;
            }
        }
        return true;
    }
};