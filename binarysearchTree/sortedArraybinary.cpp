lass Solution {
public:
    TreeNode* helper(vector<int>& nums,int st,int end){
        if(st > end){
            return NULL;
        }

        int mid = st + (end - st) / 2;
        TreeNode* currNode = new TreeNode(nums[mid]);
        currNode->left = helper(nums, st, mid-1);
        currNode->right = helper(nums, mid+1, end);

        return currNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};