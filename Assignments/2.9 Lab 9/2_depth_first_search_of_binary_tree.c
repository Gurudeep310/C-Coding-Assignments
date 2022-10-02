/*
Depth first search for binary tree - clone
Data StructuresBinary TreeSearching
Close
Given a binary tree and a value, search the value in the given binary tree using [info message="Depth First Search (DFS) is an algorithm for traversing or searching tree or graph data structures. One starts at the root (selecting some arbitrary node as the root in the case of a graph) and explores as far as possible along each branch before backtracking."]Depth First Search[/info] (use in-order of the tree for depth-first search).
Reference: https://en.wikipedia.org/wiki/Depth-first_search 
e.g. for the given tree
               1
             /    \ 
          2        3
         /  \      /  \
       4   5   6    7
Depth-first traversal of given tree using in-order of tree is 
    4 2 5 1 6 3 7
The binary tree is created using structure [info message="struct node <br>{<br>     int key;<br>     struct node *left, *right; <br>};"]'struct node'[/info]. 
Write a function: 
    int solution(struct node *R, int V)
that accept root node of binary tree R of type 'struct node' and a value to search V. A function search the given value in the binary tree using depth first search. If value found then return a number of nodes visited to reach that node, return -1 if value not found.
Input
    7
    4 5 2 6 7 3 1
    4 2 5 1 6 3 7
    6
    Where, 
First line of input represents the size of an array N. 
Second line contains post-order array representation. 
Third line contains in-order array representation.
Forth line represents value to search V.
Output
    4
Assume that, 
N is a number within the range [1 to 10000]. 
Array elements are integers within the range [-2147483648 to 2147483647]. 
No duplicate key values allowed in the binary tree. 
Structure “struct node” is already defined. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

int search;

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

void solution(struct Node* root,int element)
{
    static int count = -1;
    if(root == NULL)                          // If root is null just return
    {
        return; 
    }
    else
    {
        solution(root->left,element);      // Traverse to the last leave in the left subtree
        count = count + 1;                 
        if(root->key == element)          // print the leaf of left parent then the root
        {
            printf("%d",count);          // if search element found then print number of nodes travesered
        }
        solution(root->right,element);  // the to the same thing for the right subtree
    }
}


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
    scanf("%d",&search);
    int flag = 0;
    for(int i = 0; i<n; i++)
    {
        if(search == in[i])               // check if requested element is present in the binary tree first
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1) 
        solution(root,search);       
    else 
        printf("-1");                // if element not present then print -1
    return 0;
}