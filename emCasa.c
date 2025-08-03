/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void armazena( struct TreeNode* root, int *vetor, int *i);

struct TreeNode* balanceBST( struct TreeNode* root ) {
    int vetor[10000];
    int i = 0;
    armazena( root, vetor, &i );

    return criaArvore( vetor, 0, i-1 );
}



void armazena( struct TreeNode* root, int *vetor, int *i){
    if ( root == NULL )
        return;
    armazena( root->left, vetor, i );
    vetor[*i] = root->val;
    (*i)++;
    armazena( root->right, vetor, i );
    return;
}

struct TreeNode* criaArvore( int *vetor, int inicio, int fim ) {
    if ( inicio > fim )
        return NULL;
    
    int meio = ( inicio + fim ) / 2;

    struct TreeNode *novo = ( struct TreeNode* )malloc( sizeof ( struct TreeNode ) );
    novo->val = vetor[meio];
    novo->left = criaArvore( vetor, inicio, meio - 1 );
    novo->right = criaArvore ( vetor, meio + 1, fim );
    return novo;
}