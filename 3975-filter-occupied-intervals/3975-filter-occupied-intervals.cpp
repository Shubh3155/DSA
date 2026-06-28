class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>> merged;

        for(const auto& interval : occupiedIntervals){
            if(merged.empty()){
                merged.push_back(interval);
            }
            else {
                if(interval[0] <= merged.back()[1] + 1) {
                    merged.back()[1] = max(merged.back()[1], interval[1]);
                }
                else {
                    merged.push_back(interval);
                }
            }
        }
        vector<vector<int>> result;

        for(const auto& interval : merged){
            int start = interval[0];
            int end = interval[1];

            if(end < freeStart){
                result.push_back(interval);
            }
            else if(start > freeEnd){
                result.push_back(interval);
            }
            else {
                if(start < freeStart){
                    result.push_back({start,freeStart - 1});
                }
                if(end > freeEnd){
                    result.push_back({freeEnd+1, end});
                }
            }
        }
        return result;
    }
};