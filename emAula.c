/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void procurar (struct TreeNode* root, int depth);

int depthE = 0, depthD = 2;

struct TreeNode* balanceBST(struct TreeNode* root) {
    if (root == NULL) {
        return root;
    }

     
    balanceBST(root->left);
    balanceBST(root->right);

    /*
    if (root->left != NULL)
        procurar(root->left,depthE);
    if (root->right != NULL)
        procurar(root->right,depthD);*/

    int fb = depthE - depthD;

    struct TreeNode* p = root;
    if ( fb > 1 ) {
        p = root->left;
        p->right = root;
    } else if ( fb < -1 ) {
        p = root->right;
        p->left = root;
    }
   
    return p;
}

void procurar (struct TreeNode* root, int depth) {
    if (root == NULL) {
        return;
    }

    if (root->left != NULL)
        procurar(root->left,depth);
    if (root->right != NULL)
        procurar(root->right,depth);
    depth++;
    return;
}