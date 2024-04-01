vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int>ans;
    TreeNode *current, *pre;//predecesor

	if (root == NULL)
		return ans;

	current = root;
	while (current != NULL) {

		if (current->left == NULL) {
			ans.push_back(current->data);
			current = current->right;
		}
		else {

			/* Find the inorder predecessor of current */
			pre = current->left;
			while (pre->right != NULL
				&& pre->right != current)
				pre = pre->right;

			/* Make current as the right child of its
			inorder predecessor */
			if (pre->right == current) {
                pre->right = NULL;
				current = current->right;
				
			}

			/* Revert the changes made in the 'if' part to
			restore the original tree i.e., fix the right
			child of predecessor */
			else {
				ans.push_back(current->data);
                pre->right = current;
				current = current->left;
			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */

    return ans;
}

// 1...If left child is null, print the current node data. Move to right child. 
// ….Else, Make the right child of the inorder predecessor point to the current node. Two cases arise: 
// ………a) The right child of the inorder predecessor already points to the current node. Set right child to NULL. Move to right child of current node. 
// ………b) The right child is NULL. Set it to the current node. Print the current node’s data and move to left child of current node. 
// 2...Iterate until the current node is not NULL.