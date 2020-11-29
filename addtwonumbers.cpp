* 2. Add Two Numbers Leetcode



/**

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.




 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    
    pair<int,int> add(int a,int b){
        if(a+b < 9) return make_pair(a+b,-1);
        return make_pair((a+b)%10,(a+b)/10);
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1,*t2=l2, *ans,*head;
        ans = new ListNode(-1);
        head = ans;
        int c=-1;
        bool flag=false;
        
        while(t1!=nullptr || t2!=nullptr ){
            pair<int,int> p;
            
            if(t1==nullptr && t2!=nullptr){
                
                if(flag) p=add(0 ,t2->val+c);
                else p=add(0,t2->val);
                
                if(p.second==-1){
                    flag=false;
                    ans->next = new ListNode(p.first);
                    ans = ans->next;
                }else {
                    flag=true;
                    ans->next =new  ListNode(p.first);
                    ans = ans->next;
                    c=p.second;
                }
                t2=t2->next;
                
                
            }else if(t2==nullptr && t1!=nullptr){
                
                if(flag)  p=add(t1->val ,0+c);
                else  p=add(t1->val,0);
                
                if(p.second==-1){
                    flag=false;
                    ans->next = new ListNode(p.first);
                    ans = ans->next;
                }else {
                    flag=true;
                    ans->next =new ListNode(p.first);
                    ans = ans->next;
                    c=p.second;
                }
                t1=t1->next;
                
            }else{
                if(flag) p=add(t1->val,t2->val+c);
                else p=add(t1->val,t2->val);
                
                if(p.second==-1){
                    flag=false;
                    ans->next =new ListNode(p.first);
                    ans = ans->next;
                }else {
                    flag=true;
                    ans->next =new ListNode(p.first);
                    ans = ans->next;
                    c=p.second;
                }
                
                    t1=t1->next;
                    t2=t2->next;
                
            }
        
         
        }
        if(flag && c!=0) ans->next = new ListNode(c);
        
         return head->next;
        
        
    }
};
        
