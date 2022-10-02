/*
Given a [info message="A binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child. "]binary tree[/info], print a pre-order array representation of it.
Reference: https://en.wikipedia.org/wiki/Tree_traversal
The binary tree is created using structure [info message="struct node <br>{ <br>    int key; <br>    struct node *left, *right; <br>}; "]'struct node'[/info].
Write a function: 
        void solution(struct node * R) 
that accept root node of binary tree R of type 'struct node' and a number of nodes in the tree as N. The function should return pre-order array representation of the binary tree.
Input
    3
    2 3 1
    2 1 3
    Where, 
First line of input represents the size of an array N. 
Second line contains post-order array representation.
Third line contains in-order array representation.
Output
    1 2 3 
Here the output is the pre-order representation of the constructed tree.
Assume that, 
N is an integer within the range [0 to 10000]. 
Array elements are integers within the range [-2147483648 to 2147483647].
No duplicate key values allowed in the binary tree.
Structure “struct node” is already defined. 
*/
#include<stdio.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int key)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key  = key;
    temp->left  = temp->right = NULL;
    return (temp);
}

struct Node *createTree(int in[], int post[], int n)
{
    if(n <= 0)
    {
        return NULL;
    }
    if(n == 1)
    {
        return newNode(in[0]);
    }
    int rootNode = post[n-1];
    
    struct Node *root = newNode(rootNode);
    int i;
    for(i = 0; i < n; i++)
    {
        if(in[i] == rootNode)
        {
            break;
        }
    }
    int leftlen = i, rightlen = n-i-1;
    int leftin[leftlen];
    int rightin[rightlen];
    memcpy(leftin,&in[0],leftlen*sizeof(int));
    memcpy(rightin,&in[leftlen+1],rightlen*sizeof(int));
    
    int leftpost[leftlen];
    int rightpost[rightlen];
    memcpy(leftpost,&post[0],leftlen*sizeof(int));
    memcpy(rightpost,&post[leftlen],rightlen*sizeof(int));
    
    root -> left = createTree(leftin,leftpost,leftlen);
    root -> right = createTree(rightin,rightpost,rightlen);
    return root;
}

void solution(struct Node *root)
{
    if(root == NULL) 
        return; 
    else
    {
        printf("%d ",root->key);                 // Printing the root node first
        solution(root->left);                    // Traversing left subtree
        solution(root->right);                   // Traversing right subtree
    }
}


int main()
{
    int n;
    scanf("%d",&n);
    int in[n],post[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&post[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&in[i]);
    }
    struct Node *root = createTree(in,post,n);
    solution(root);
    return 0;
}