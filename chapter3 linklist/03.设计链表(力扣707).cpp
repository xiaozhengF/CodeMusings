
class MyLinkedList
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    MyLinkedList()
    {
        this->Vhead = new ListNode();
        this->size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        ListNode *cur = Vhead->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val, Vhead->next);
        Vhead->next = newNode;
        size++;
    }

    void addAtTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        ListNode *cur = Vhead;
        while (cur->next)
            cur = cur->next;
        cur->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size || index < 0)
            return;
        /* 这里要return，否则就是插入两回 */
        if (index == 0){
            this->addAtHead(val);
            return;
        }
        if (index == size){
            this->addAtTail(val);
            return;
        }
        ListNode *cur = Vhead;
        while (index--)
        {
            cur = cur->next;
        }
        ListNode *newNode = new ListNode(val);
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0)
            return;
        ListNode *cur = Vhead;
        while (index--)
        {
            cur = cur->next;
        }
        ListNode *temp = cur->next;
        cur->next = temp->next;
        delete temp;
        size--;
    }

private:
    ListNode *Vhead;
    int size;
};
int main(void){
    MyLinkedList* obj = new MyLinkedList();

}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */