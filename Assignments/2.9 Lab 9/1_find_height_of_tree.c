/*
Find height of tree - clone
Given a [info message="A binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child."]binary tree[/info], find the height of given tree.
The height of a binary tree is the length of the path from the root to the deepest node in the tree. The binary tree with only one node has a depth value zero.
e.g. for this binary tree
                 2
                /  \ 
              4    5 
             /  \ 
           1    3
                /
              9
Here height of the tree is 3.
The binary tree is created using structure [info message="struct node <br>{<br>     int key;<br>     struct node *left, *right; <br>};"]'struct node'[/info]. 
Write a function: 
       int solution(struct node * R) 
that accept root node of binary tree R of type 'struct node'. The function should return the height of a tree.
Input
    6
    1 9 3 4 5 2
    1 4 9 3 2 5
    Where, 
First line of input represents the size of an array N. 
Second line contains post-order array representation. 
Third line contains in-order array representation.
Output
    3
Assume that, 
N is an integer within the range [0 to 10000]. 
Array elements are integers within the range [-2147483648 to 2147483647]. 
No duplicate key values allowed in the binary tree. 
Structure “struct node” is already defined.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int max_height(struct Node *root)
{
    if(root == NULL)                                       // If not tree then print -1
        return -1; 
    else{
        int left_height = max_height(root->left);         // Calcuate height of left tree using recurssion
        int right_height = max_height(root->right);      // Calcuate height of right tree using recurssion
        if(left_height > right_height)                  // Print max height of the binary tree
            return left_height + 1;                     
        else
            return right_height + 1;
    }
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

//Write your code here


//Your program will be evaluated by this main method and several test cases.
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
    int ans = max_height(root);
    printf("%d",ans);
    return 0;
}