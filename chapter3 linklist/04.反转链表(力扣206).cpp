struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    //头插法倒置  
    ListNode* reverseList(ListNode* head) {
        ListNode *Vhead = new ListNode();
        ListNode *cur,*aft;
        cur = head;
        while(cur){
            aft = cur->next;
            cur->next = Vhead->next;
            Vhead->next = cur;
            cur = aft;
        }
        head = Vhead->next;
        delete Vhead;
        return head;
    }
    //双指针法倒置
    ListNode* reverseList2(ListNode* head) {
        ListNode* pre,*aft,*temp;
        pre = nullptr;
        aft = head;
        while(aft){
            temp = aft->next;
            aft->next = pre;
            pre = aft;
            aft = temp;
        }
        return pre;
    }
    //递归法倒置
    ListNode* reverseList3(ListNode* head) {
        return reverse(nullptr,head);
    }
    ListNode* reverse(ListNode* pre, ListNode* aft){
        if(!aft) return pre;
        ListNode* temp = aft->next;
        aft->next = pre;
        return reverse(aft,temp);
    }
};