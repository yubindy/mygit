#include "leection.h"
#include <cstddef>
class Solution {
public:
    bool rul;
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return isture(A,B);
    }
    bool isture(TreeNode* A, TreeNode* B) {
        if(A==nullptr||B==nullptr&&A!=B){
            return false;
        }
        bool p=false;;
        if(A->val==B->val){
            printf("panduan %d",A->val);
            p=issub(A,B);
            if(p==true){
                return p;
            }else{
                printf("rul %d",p);
            }
        }
        p=isture(A->left,B);
        if(p==true){
                return p;
        }
        p=isture(A->right,B);
        return p;
    }
    bool issub(TreeNode* a, TreeNode* b){
        if(a==nullptr&&b!=nullptr){
            return false;
        }else if(a!=nullptr&&b==nullptr||a==nullptr&&b==nullptr){
            return true;
        }
        printf(" %d ",a->val);
        if(a->val!=b->val){
            return false;
        }
        bool rul=true;
        if(a->left||b->left){
            rul=issub(a->left,b->left);
            if(rul==false) {
            return rul;
            }
        }
        if(a->right||b->right){
            rul=issub(a->right,b->right);
        }
        return rul;

    }
};