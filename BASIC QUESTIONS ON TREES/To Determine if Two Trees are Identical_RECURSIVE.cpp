/*ASSUME ROOT OF TWO TREES ARE PASSED AS  ARGUMENTS IN THE FUNCTION*/
bool check(node*r1 , node*r2)
{
    //base case
    if(r1==NULL&&r2==NULL)
    {
        return 1;
    }
    //RECURSIVE CASE
    else if(r1!=NULL&&r2!=NULL)
    {
        return (r1->data==r2->data&&check(r1->left,r2->left)&&check(r1->right,r2->right));
    }
    else 
        return 0;
}
