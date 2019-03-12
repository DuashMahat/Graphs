


#include <iostream>
#include <iostream>
#include <iostream> 
#include <list> 
#include <queue>
#include <iterator> 
using namespace std;
/*
Given a sorted (increasing order) array with unique integer elements, write an algorithm
to create a binary search tree with minimal height.
*/
struct TreeNode {
  int val;
  TreeNode * leftTree;
  TreeNode * rightTree;
  TreeNode (int _val ) : leftTree(NULL) ,rightTree(NULL) {}
};

void inorderTraversal ( TreeNode * root ) {
    if (!root ) return;
    if (!(!root->leftTree)) inorderTraversal(root->leftTree );
    cout << root->val << "  ";
   if (!(!root->rightTree)) inorderTraversal(root->rightTree );
}

TreeNode * minimumBST ( vector<int> & vals )  {
       if (vals.size() == 0) return NULL;
       int mid = (vals.size())/2;
       TreeNode * root = new TreeNode (vals[mid]);
       vector <int> leftVector( vals.begin() , vals.begin() + mid);
       vector<int> rightVector ( vals.begin() + mid + 1 ,  vals.end());
       root->leftTree = minimumBST(leftVector);
       root->rightTree = minimumBST(rightVector);
       return root;
}
int main() {
   vector<int> sortedArray = { 1,2,3,4,5,6,7};
   TreeNode * test = minimumBST(sortedArray);
   inorderTraversal (test );
}
