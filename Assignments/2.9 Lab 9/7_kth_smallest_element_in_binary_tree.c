/*
Given a [info message="<ul>Binary search tree is a node-based binary tree data structure which has the following properties: <li>The left subtree of a node contains only nodes with keys less than the node’s key.</li> <li>The right subtree of a node contains only nodes with keys greater than the node’s key. </li><li>The left and right subtree each must also be a binary search tree.</li></ul>"]Binary search tree[/info] and an integer value K, find a Kth smallest element.
The binary search tree is composed of structure [info message="struct node {<br>     int key; <br>     struct node *left, *right;<br>};" ]'struct node'[/info]. 
Write a function: 
        int solution(struct node *R, int K)
that accept a root node of binary search tree R of type “struct node” and an integer value K. The function should return Kth smallest element in Binary Search Tree.
Input
    7
    10 6 13 4 8 12 15
    3
    Where, 
First line represents a number of nodes N in a tree. 
Second line represents elements of a tree. 
Third line of input represents K.
Output
    8
Given array can be represented in tree format as
                10             
              /      \ 
            6        13
          /   \       /   \ 
        4     8   12   15
Here 3rd smallest element is 8.
Assume that, 
No duplicate key values allowed in the binary tree.
K within the range from [1 to N] (where N is number of nodes)
N is the number within the range [1 to 10000]
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

void solution(struct node *R, int K)      // Inorder search and display smallest
{
    static int count = 0;
    if(R==NULL)
        return;
    solution(R->left,K);                // Traverse through left subtree
    count = count + 1;
    if(count == K)                     // finding the kth smallest element
    {
        printf("%d ",R->key);         // printing kth smallest element
    }
    solution(R->right,K);            // Traversing through rightsubtree
}

struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node *root, int key)
{
    if (root == NULL)
        return newNode(key);
    if (key < root->key)
        root->left  = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}
int main(int argc, char **argv)
{
    int *A;
    int i,N,K;
    struct node * R =NULL;
    scanf("%d",&N);
    A = (int *) malloc(N*sizeof(int));
    for(i=0; i<N; i++)
    {
        scanf("%d",&A[i]);
        if(i==0)
        {
            R = insert(R,A[i]);
        }
        else
        {
            insert(R,A[i]);
        }
    }
    scanf("%d",&K);
    solution(R,K);
}