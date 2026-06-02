class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int m = landStartTime.size();
        int n = waterStartTime.size();
        
        int result = INT_MAX;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                int land = landStartTime[i] + landDuration[i];
                int land_water = max(land, waterStartTime[j]) + waterDuration[j];
                result = min(result, land_water);

                int water = waterStartTime[j] + waterDuration[j];
                int water_land = max(water, landStartTime[i]) + landDuration[i];
                result = min(result, water_land);
            }
        }
        return result;
    }
};