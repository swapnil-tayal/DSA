// tree ordered_set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using ordered_set = tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>;


class Solution {
public:
    vector<int> resultArray(vector<int>& nums){

        vector<int> arr1, arr2, num1, num2;
        
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        num1.push_back(nums[0]);
        num2.push_back(nums[1]);
        
        
        for(int i=2; i<nums.size(); i++){
            
            int ind1 = (upper_bound(arr1.begin(), arr1.end(), nums[i]) - arr1.begin());
            int ind2 = (upper_bound(arr2.begin(), arr2.end(), nums[i]) - arr2.begin());
        
            if(arr1.size() - ind1 > arr2.size() - ind2){
                arr1.insert(arr1.begin() + ind1, nums[i]);
                num1.push_back(nums[i]);
                
            }else if(arr1.size() - ind1 < arr2.size() - ind2){
                arr2.insert(arr2.begin() + ind2, nums[i]);
                num2.push_back(nums[i]);
                
            }else{
                if(arr2.size() < arr1.size()){
                    arr2.insert(arr2.begin() + ind2, nums[i]);
                    num2.push_back(nums[i]);
                }
                else{
                    arr1.insert(arr1.begin() + ind1, nums[i]);
                    num1.push_back(nums[i]);
                }
            }
        }
        vector<int> ans;
        for(auto i: num1) ans.push_back(i);
        for(auto i: num2) ans.push_back(i);
        return ans;
    }
};