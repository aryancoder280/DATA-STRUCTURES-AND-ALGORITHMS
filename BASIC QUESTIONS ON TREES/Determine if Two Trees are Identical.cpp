//DEFINATION OF IDENTCAL TREES=Two trees are identical when they have same data and arrangement of data is also same.
//------------------solution--------------------------------
// ASSUME ROOTS OF BOTH TREES ARE PASSED IN THE FUNCTION GIVEN BELOW.
bool isIdentical(Node *r1, Node *r2)
{
    if((r1==NULL||r2==NULL)&&r1==r2)
       return true;
    else if((r1==NULL||r2==NULL)&&r1!=r2)
    return false;
    else
    {
        if(r1->data==r2->data)
        {
            queue<Node*>q1,q2;
          q1.push(r1);
          q2.push(r2);
          Node *root1;
          Node *root2;
          while(!q1.empty()||!q2.empty())
          {
            root1=q1.front();
            q1.pop();
            root2=q2.front();
            q2.pop();

            if(root1->left!=NULL&&root2->left!=NULL)
            {
                if(root1->left->data==root2->left->data)
                {
                    q1.push(root1->left);
                    q2.push(root2->left);
                }
                else
                return false;
            }
         else if((root1->left==NULL&&root2->left!=NULL)||(root1->left!=NULL&&root2->left==NULL))
           return false;

        if(root1->right!=NULL&&root2->right!=NULL)
            {
                if(root1->right->data==root2->right->data)
                {
                    q1.push(root1->right);
                    q2.push(root2->right);
                }
                else
                return false;
            }
         else if((root1->right==NULL&&root2->right!=NULL)||(root1->right!=NULL&&root2->right==NULL))
           return false;
        }


     }
     else
      return false;

      return true;

  }
}
