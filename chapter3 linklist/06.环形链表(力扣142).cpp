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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast,*slow;
        fast = slow = head;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                ListNode* index1,*index2;
                index1 = head;
                index2 = slow;
                while(index1!=index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};