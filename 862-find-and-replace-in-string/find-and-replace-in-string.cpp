class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        
        int currOffset = 0;
        unordered_set<int> seen;
        vector<tuple<int, string, string>> arr;

        for (int i = 0; i < indices.size(); i++) {
            if(s.substr(indices[i], sources[i].size()) != sources[i]) continue;
            if (seen.count(indices[i])) {
                continue;
            }
            seen.insert(indices[i]);
            arr.push_back({indices[i], sources[i], targets[i]});
        }
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            tie(indices[i], sources[i], targets[i]) = arr[i];
        }

        int k = indices.size();
        for(int i=0; i<arr.size(); i++){

            int ind = indices[i] + currOffset;
            int orgSize = sources[i].size();
            if(s.substr(ind, orgSize) == sources[i]){
                currOffset += - sources[i].size() + targets[i].size();
                s.replace(ind, orgSize, targets[i]);
            }
        }
        return s;
    }
};