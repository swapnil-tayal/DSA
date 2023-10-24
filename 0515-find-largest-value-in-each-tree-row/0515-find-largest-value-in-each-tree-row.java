/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> largestValues(TreeNode root) {
        
        if(root == null) return new ArrayList<Integer>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        List<Integer> ans = new ArrayList<>();
        
        while(!q.isEmpty()){
            
            int n = q.size();
            int maxi = Integer.MIN_VALUE;
            
            while(n > 0){
                
                TreeNode node = q.element();
                maxi = Math.max(maxi, node.val);
                
                q.poll();
                
                if(node.right != null) q.add(node.right);
                if(node.left != null) q.add(node.left);
                n--;
            }
            ans.add(maxi);
        }
        return ans;
    }
}