// #include<iostream>
// using std::cout; using std::cin; using std::endl;

// struct ListNode
// {
//     int val;
//     ListNode* next;
//     ListNode(int val) : val(val), next(nullptr){};
//     ListNode(int val, ListNode* next) : val(val), next(next){};
// };

// ListNode* removeElements(ListNode* head, int val) {
//     //虚拟头结点：
//     //ListNode* preHead = new ListNode(0,head);
//     ListNode* p = head;
//     while(p->next != nullptr){
//         if(p->next->val == val){
//             ListNode* tmp = p->next;
//             p->next = p->next->next;
//             delete tmp;
//         }   
//         else {
//             p = p->next;
//         }      
//     }
//     //head = preHead->next;//重新设置头结点
//     //delete preHead;//把new的虚拟头结点delete
//     return head;
// }
// void addAtHead(ListNode* head, int val) {
//     //ListNode* preHead = new ListNode(0,head);
//     ListNode* newNode = new ListNode(val);
//     newNode->next = head->next;
//     head->next = newNode; 
//     //head = newNode;
// }

// void addAtTail(ListNode* head, int val) {
//     //ListNode* preHead = new ListNode(0,head);
//     ListNode* newNode = new ListNode(val);
//     ListNode* tail;
//     tail = head;
//     while(tail->next != NULL){
//         tail = tail->next;
//     }
//     newNode->next = NULL;
//     tail->next = newNode;
//     tail = newNode;
// }
// void showLinkList(ListNode* head){
//     //ListNode* preHead = new ListNode(0,head);
//     ListNode* p = head;
//     while(p->next != nullptr){
//         cout << p->next->val << " -> ";
//         p = p->next;
//     }
//     cout << "NULL." << endl;
// }

// int main(){
//     //创建虚拟头结点：
//     ListNode* preHead = new ListNode(0,nullptr);
//     addAtHead(preHead,16);
//     addAtHead(preHead,16);
//     addAtHead(preHead,18);
//     addAtTail(preHead,22);
//     addAtTail(preHead,22);
//     addAtTail(preHead,23);
//     showLinkList(preHead);

//     ListNode* preHead2 = removeElements(preHead,0);//22
//     showLinkList(preHead2);
//     showLinkList(preHead);

//     return 0;
// }

#include<iostream>
using std::cout; using std::cin; using std::endl;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr){};
    ListNode(int val, ListNode* next) : val(val), next(next){};
};
//void
ListNode* removeElements(ListNode*& head, int val) {//
    //虚拟头结点：
    ListNode* preHead = new ListNode(0,head);
    ListNode* p = preHead;
    while(p->next != nullptr){
        if(p->next->val == val){
            ListNode* tmp = p->next;
            p->next = p->next->next;
            delete tmp;
        }   
        else {
            p = p->next;
        }      
    }
    head = preHead->next;//重新设置头结点
    delete preHead;//把new的虚拟头结点delete
    return head;
}
void addAtHead(ListNode*& head, int val) {//
    ListNode* preHead = new ListNode(0,head);
    ListNode* newNode = new ListNode(val);
    //cout << "形参head的地址：" << head << " ； head的数据域： " << head->val << " ； head的指针域： " << head->next << endl;
    //cout << "形参newNode的地址：" << newNode << " ； newNode的数据域： " << newNode->val << " ； newNode " << newNode->next << endl;
    newNode->next = preHead->next;//head;
    preHead->next = newNode; 
    head = preHead->next;
    //head = newNode;
    //cout << "形参head的地址：" << head << " ； head的数据域： " << head->val << " ； head的指针域： " << head->next << endl;
    //cout << "形参newNode的地址：" << newNode << " ； newNode的数据域： " << newNode->val << " ； newNode " << newNode->next << endl;
    delete preHead;
    //return head;

    // ListNode* newNode = new ListNode(val);
    // newNode->next = preHead->next;
    // preHead->next = newNode;
}

void addAtTail(ListNode* head, int val) {//&
    ListNode* preHead = new ListNode(0,head);
    ListNode* newNode = new ListNode(val);
    ListNode* tail;
    tail = preHead;
    while(tail->next != NULL){
        tail = tail->next;
    }
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
    delete preHead;
}
void showLinkList(ListNode* head){//&
    ListNode* preHead = new ListNode(0,head);
    ListNode* p = preHead;
    while(p->next != nullptr){
        cout << p->next->val << " -> ";
        p = p->next;
    }
    cout << "NULL." << endl;
    delete preHead;
}

int main(){
    //创建虚拟头结点：
    ListNode* head = new ListNode(0,nullptr);
    //cout << "main函数中head的地址：" << head << " ； head的数据域： " << head->val << " ； head的指针域： " << head->next << endl;
    addAtTail(head,22);showLinkList(head);
    addAtTail(head,22);showLinkList(head);
    addAtTail(head,23);showLinkList(head);

    //cout << "main函数中head的地址：" << head << " ； head的数据域： " << head->val << " ； head的指针域： " << head->next << endl;
    addAtHead(head,16);
    //cout << "main函数中head的地址：" << head << " ； head的数据域： " << head->val << " ； head的指针域： " << head->next << endl;
    showLinkList(head);
    addAtHead(head,16);showLinkList(head);
    addAtHead(head,18);showLinkList(head);
    //showLinkList(head);

    //cout << "main函数中head的地址：" << head << " ； head的数据域： " << head->val << " ； head的指针域： " << head->next << endl;
    ListNode* head2 = removeElements(head,18);//18 0 16 22 这个删0可以，因为head2把子函数中返回的head给带出来了
    //cout << "main函数中head2的地址：" << head2 << " ； head2的数据域： " << head2->val << " ； head2的指针域： " << head2->next << endl;
    //cout << "main函数中head的地址：" << head << " ； head的数据域： " << head->val << " ； head的指针域： " << head->next << endl;
    showLinkList(head2);
    removeElements(head,16);//16 0 22 这个删0会报错，因为head没动，但其他内容被修改了，直接报错
    showLinkList(head);

    return 0;
}