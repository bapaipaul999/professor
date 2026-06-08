class MyLinkedList {
public:

    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int x) {
            val = x;
            next = NULL;
        }
    };

    ListNode* head;
    ListNode* tail;

    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    int get(int index) {
        ListNode* temp = head;

        while (temp && index--) {
            temp = temp->next;
        }

        return temp ? temp->val : -1;
    }

    void addAtHead(int val) {
        ListNode* node = new ListNode(val);

        if (head == NULL) {
            head = tail = node;
        } else {
            node->next = head;
            head = node;
        }
    }

    void addAtTail(int val) {
        ListNode* node = new ListNode(val);

        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void addAtIndex(int index, int val) {

        if (index == 0) {
            addAtHead(val);
            return;
        }

        ListNode* temp = head;

        for (int i = 0; temp && i < index - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL) return;

        ListNode* node = new ListNode(val);

        node->next = temp->next;
        temp->next = node;

        if (node->next == NULL) {
            tail = node;
        }
    }

    void deleteAtIndex(int index) {

        if (head == NULL) return;

        if (index == 0) {
            ListNode* del = head;
            head = head->next;

            if (head == NULL) {
                tail = NULL;
            }

            delete del;
            return;
        }

        ListNode* temp = head;

        for (int i = 0; temp && i < index - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            return;
        }

        ListNode* del = temp->next;

        temp->next = del->next;

        if (del == tail) {
            tail = temp;
        }

        delete del;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */