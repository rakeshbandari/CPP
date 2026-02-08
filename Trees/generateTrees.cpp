#include "Tree.cpp"

vector<TreeNode*> recurs(int left_mark,int right_mark)
{
    TreeNode* node=NULL;
    vector<TreeNode*>left,right,res;
    
    if(left_mark<1||right_mark<1||left_mark>right_mark)
    {
        return res;
    }
    
    
    
    for(int j=left_mark;j<=right_mark;j++)
    {
        left=recurs(left_mark,j-1);
        right=recurs(j+1,right_mark);
        
       
        
        if(left.size()!=0&&right.size())
        {
              for(auto x:left)
            {
            
            for(auto y:right)
               {
                  node=new TreeNode();
                  node->val=j;
                  node->left=x;
                  node->right=y;
                  res.push_back(node);
               }
            }
        }
        else if(right.size()!=0)
        {
             for(auto y:right)
               {
                  node=new TreeNode();
                  node->val=j;
                  node->right=y;
                  res.push_back(node);
               }
        }
          else if(left.size()!=0)
        {
             for(auto y:left)
               {
                  node=new TreeNode();
                  node->val=j;
                  node->left=y;
                  res.push_back(node);
               }
        }
        else
        {
                  node=new TreeNode();
                  node->val=j;
                  res.push_back(node);
        }
      

    }
    return res;
}


vector<TreeNode*> catalan_number(int n) {
    return generateTrees(1,n);
}

int main()
{
  int n = 3;
  
  vector<TreeNode*> vec = catalan_number(n);    
  return 0;
}
