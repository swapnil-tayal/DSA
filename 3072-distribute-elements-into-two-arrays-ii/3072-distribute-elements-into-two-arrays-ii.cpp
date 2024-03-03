// tree ordered_set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using ordered_set = tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>;


class Solution {
public:
    vector<int> resultArray(vector<int>& nums){

        ordered_set st1;
        ordered_set st2;
        vector<int> arr1, arr2;
        
        st1.insert(nums[0]);
        st2.insert(nums[1]);
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        
        for(int i=2; i<nums.size(); i++){
            
            int x1 = st1.size() - st1.order_of_key(nums[i]+1);
            int x2 = st2.size() - st2.order_of_key(nums[i]+1);
            
            if(x1 > x2){
                st1.insert(nums[i]);
                arr1.push_back(nums[i]);
            }
            else if(x2 > x1){
                st2.insert(nums[i]);
                arr2.push_back(nums[i]);
            }
            else{
                if(st2.size() < st1.size()){
                    arr2.push_back(nums[i]);
                    st2.insert(nums[i]);
                }
                else{
                    arr1.push_back(nums[i]);
                    st1.insert(nums[i]);
                }
            }
        }
        vector<int> ans;
        for(auto i: arr1) ans.push_back(i);
        for(auto i: arr2) ans.push_back(i);
        return ans;
    }
};