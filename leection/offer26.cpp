#include "leection.h"
#include <cstddef>
class Solution {
public:
    bool rul;
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==nullptr||B==nullptr&&A!=B){
            return false;
        }
        if(!A){
            return false;
        }
        bool p=false;;
        if(A->val==B->val){
            p=issub(A,B);
            if(p==true){
                return p;
            }
        }
        if(A->left){
            isSubStructure(A->left,B->left);
        }
        if(A->right){
            isSubStructure(B->right,B->right);
        }
        return p;
    }
    bool issub(TreeNode* a, TreeNode* b){
        if(a==nullptr||b==nullptr&&a!=b){
            return false;
        }
        if(a->val!=b->val){
            return false;
        }else{
            return true;
        }
        bool rul;
        if(a->left||b->left){
            rul=issub(a->left,b->left);
        }
        if(rul==false){
            return rul;
        }
        if(a->right||b->right){
            rul=issub(a->right,b->right);
        }
        return rul;

    }
};