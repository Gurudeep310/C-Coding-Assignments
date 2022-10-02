/*
Given a [info message="A binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child."]binary tree[/info] and key value, find the level of a node in a binary tree with the given key value.
e.g. for the following binary tree
                1                                            
               /  \                                   
            2      3                    
           / \      / \           
         4  5    6   7                               
For key = 1, the level of a node is 1.
For key = 5, the level of a node is 3.
The binary tree should be created using structure [info message="struct node{<br>   int key;<br>    struct node *left, *right;<br>}; "]struct node[/info].
Write a function: 
    int solution(struct node *R, int KEY)
that accept root node of binary tree R of type 'struct node' and a search value KEY of type integer. The function should find the level of a node in a binary tree with the given key value and returns the level of a node. If a node is not found with the given key then return 0.
Input
    7
    4 5 2 6 7 3 1
    4 2 5 1 6 3 7
    5
    Where, 
First line represents the size of an array N. 
Second line contains post-order array representation. 
Third line contains in-order array representation.
The fourth represents the key value KEY.
Output
    3
Assume that,
All the node values in a given tree are unique. 
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


/*
It returns level of the data if data is 
present in tree, otherwise returns 0.
*/
int solution(struct Node *root,int n,int level) 
{
    if(root == NULL) 
        return 0;
    if(root->key == n) 
        return level;
    int dl = solution(root->left,n, level + 1);
    if(dl!=0) 
        return dl;
    dl = solution(root->right, n, level + 1);
    return dl;
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
    int search;
    scanf("%d",&search);
    int flag = 0;
    for(int i = 0; i<n; i++)
    {
        if(search == post[i])                  
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        int ans = solution(root,search,1);
        printf("%d",ans);
    }
    else                                // If element not present in the binary tree then print 0
    {
        printf("0");
    }
    return 0;
}