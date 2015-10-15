/* FIXME: Implementf treenode! */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct treenode{
    int data;
    struct treenode *left;
    struct treenode *right;

}TreeNode; 

    /*	Tree
	    1
	   / \
	  2   5
	 / \   \
	3   4   6
    */
TreeNode *CreateTree(){
    TreeNode *node1 = (TreeNode *)malloc(sizeof(TreeNode));
    node1->data = 1;
    node1->left = (TreeNode *)malloc(sizeof(TreeNode));
    node1->right = (TreeNode *)malloc(sizeof(TreeNode));

    TreeNode *node2 = node1->left;
    node2->data = 2;
    node2->left = (TreeNode *)malloc(sizeof(TreeNode));
    node2->right = (TreeNode *)malloc(sizeof(TreeNode));

    TreeNode *node3 = node2->left;
    node3->data = 3;
    node3->left = NULL;
    node3->right = NULL;

    TreeNode *node4 = node2->right;
    node4->data = 4;
    node4->left = NULL;
    node4->right = NULL;

    TreeNode *node5 = node1->right;
    node5->data = 5;
    node5->left = NULL;
    node5->right = (TreeNode *)malloc(sizeof(TreeNode));

    TreeNode *node6 = node5->right;
    node6->data = 6;
    node6->left = NULL;
    node6->right = NULL;
    return node1;
}
TreeNode *flatten(TreeNode *root){
    if(root == NULL){
	return NULL;
    }
    if(root->right){
	root->right = flatten(root->right);
    } 
    if(root->left){
	TreeNode *tmp = root->right;
	root->right = flatten(root->left);
	TreeNode *tmp2 = root->right;
	while(tmp2->right){
	    tmp2 = tmp2->right;
	}
	tmp2->right = tmp;
	root->left = NULL;
    }
    return root;
}

int main()
{
    
    TreeNode *head = CreateTree();
    assert(head!=NULL&& "create failed!");
    flatten(head);
    printf("%d->%d->%d->%d->%d->%d\n",head->data,
				    head->right->data,
				    head->right->right->data,
				    head->right->right->right->data,
				    head->right->right->right->right->data,
				    head->right->right->right->right->right->data);
    return 0;
}
