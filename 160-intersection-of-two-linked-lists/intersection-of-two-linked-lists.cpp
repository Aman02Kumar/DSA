/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode * ss(ListNode * s, ListNode *b,int x){

            while(x && b!=NULL){
                x--;
                b=b->next;
            }

            while (s != NULL && b != NULL && s != b) {
            s = s->next;
            b = b->next;
        }
            return s;
    }
    ListNode *getIntersectionNode(ListNode * a, ListNode *b) {
        
        int n = 0,m=0;
        ListNode * x = a;
        ListNode * y = b;


        while(a!=NULL){
            n++;
            a= a->next;
        }
        while(b!=NULL){
            m++;
            b= b->next;
        }

        if(n>m) return ss(y,x,n-m);
        else return  ss(x,y,m-n);
        // return NULL;
}
};