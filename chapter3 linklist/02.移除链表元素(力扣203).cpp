
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //解法1
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* Vhead = new ListNode(0,head);
        ListNode* pre = Vhead;
        ListNode* aft = Vhead->next;
        ListNode* temp;
        while(aft){
            if(aft->val == val) {
                temp = aft;
                aft = aft->next;
                delete temp;
            }
            else{
                pre->next = aft;
                pre = aft;
                aft = aft->next;
            }
        }
        pre->next = nullptr;
        head = Vhead->next;
        delete Vhead;
        return head;
    }
    //不带虚拟头节点
    ListNode* removeElements2(ListNode* head, int val) {
        ListNode* temp;
        while(head!=nullptr&&(head->val == val)) {
                temp = head;
                head = head->next;
                delete temp;
        }
        ListNode *cur = head;
        while(cur!=nullptr&&cur->next!=nullptr){
            if(cur->next->val == val){
                temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }
   //带虚拟头节点
    ListNode* removeElements3(ListNode* head, int val) {
        ListNode* temp;
        ListNode* Vhead = new ListNode(0,head);
        ListNode *cur = Vhead;
        while(cur->next!=nullptr){
            if(cur->next->val == val){
                temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }else{
                cur = cur->next;
            }
        }
        head = Vhead->next;
        delete Vhead;
        return head;
    }
};