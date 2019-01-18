//--------------------ASKED IN MICROSOFT AND AMAMZON----------------
Given a Binary Tree, your task is to print its level order traversal where each level is separated by $ 

For the below tree the output will be 1 $ 2 3 $ 4 5 6 7 $ 8 $

          1
       /     \
     2        3
   /    \     /   \
  4     5   6    7
    \
     8

            

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print the level order traversal of the tree as specified in the problem statement .

Constraints:
1 <=T<= 20
1 <= Number of edges<= 1000
1 <= Data of a node<= 100

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 $ 3 2  $
10 $ 20 30 $ 40 60 $
  
  NOTE = TREE CAN BE SKEW!!!!!

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.   Second test case represents a tree with 4 edges and 5 nodes.


//----------SOLUTION----------

//-----TREE CONSTRUCTION----------U CAN SKIP TO THE LEVELORDER FUNCTION----
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void levelOrder(struct Node* node);
/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node* node)
{
  if (node == NULL)
    return;
  inOrder(node->left);
  printf("%d ", node->data);
  inOrder(node->right);
}
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     levelOrder(root);
     cout << endl;
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
//You are required to complete this method

//-----------------LEVEL ORDER FUNCTION----------------------
void levelOrder(Node* root)
{
   queue<Node*>q;
  q.push(root);
  int level,count=1;
  while(!q.empty())
  {
      level=count;
      count=0;
      Node*t;
   for(int i=1;i<=level;i++)
   {
       t=q.front();
        q.pop();
           if(t->left)
           {
               count++;
               q.push(t->left);
           }
           if(t->right)
           {
               count++;
               q.push(t->right);
           }
           cout<<t->data<<" ";
   }
   cout<<"$ ";
}
}
