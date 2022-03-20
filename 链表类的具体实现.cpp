#include<iostream>
using std::cout; using std::cin; using std::endl;


class MyLinkedList {

    //创建表示结点的结构体：
    struct ListNode{
        int val;
        ListNode* next;
        //结构体ListNode的构造函数：
        ListNode(int val) : val(val), next(NULL){};
        //ListNode(int val, ListNode* next) : val(val), next(next){};
    };
    
    int size;//链表的结点个数
    ListNode* preHead;//虚头结点

public:
    
    //类MyLinkedList的构造函数：（可以设置初始值）
    MyLinkedList() {
        size = 0;//链表的结点个数初始化为0
        preHead = new ListNode(0);//虚头结点的值设为0，指向null
    }
    void showLinkList(){
        cout << "链表元素个数为 " << size << " ;分别为： ";
        ListNode* p = this->preHead;
        while(p->next != nullptr){
            cout << p->next->val << " -> ";
            p = p->next;
        }
        cout << "NULL." << endl;
    }
    int getIndex(int index) {
        if(index < 0 || index >= size)//索引值小于0或大于等于size，就返回-1，表示查找失败
            return -1;
        ListNode* p = preHead;
        for(int i = 0; i < index; i++){
            p = p->next;
        }
        return p->next->val;    
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = preHead->next;
        preHead->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* tail;
        tail = preHead;
        while(tail->next != NULL){
            tail = tail->next;
        }
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index == size)//index等于size时，直接调用尾插
            addAtTail(val);
        else if(index < 0)//index小于0时，直接调用头插  应该是小于等于0的时候？ 都可以，索引值为0的时候用下面的方式也相当于是用了头插法
            addAtHead(val);
        else if(index > size){//index大于size时，不做任何插入操作

        }else{
            ListNode* p = preHead;
            for(int i = 0; i < index; i++){
                p = p->next;
            }
            ListNode* newNode = new ListNode(val);
            newNode->next = p->next;
            p->next = newNode;
            size++;
        }
        
    }
    
    void deleteAtIndex(int index) {
        if(!(index < 0 || index >= size)){//index < 0 或者 index >= size 都不进行任何删除操作；
                                          //为什么是>=，因为当size为6时，元素下标是0-5，所以当index为6时也超界了
            ListNode* p = preHead;
            for(int i = 0; i < index; i++){
                p = p->next;
            }
            ListNode* tmp = p->next;
            p->next = p->next->next;
            delete tmp;
            size--;
        } 
        
    }
    //ListNode*
    void removeElements(int val) {//ListNode* head, 
        //虚拟头结点：
        //ListNode* preHead = new ListNode(0,head);
        ListNode* p = preHead;
        while(p->next != nullptr){
            if(p->next->val == val){
                ListNode* tmp = p->next;
                p->next = p->next->next;
                delete tmp;
                size--; 
            }   
            else {
                p = p->next;
            }   
              
        }
        //head = preHead->next;//重新设置头结点
        //delete preHead;//把new的虚拟头结点delete
        //return head;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * 
 * 
 * 
 * 
 * 
 * 
 */
int main(){

    MyLinkedList* obj = new MyLinkedList();
    
    //头插：
    obj->addAtHead(16);
    obj->addAtHead(15);
    obj->addAtHead(14);
    //尾插:
    obj->addAtTail(20);
    obj->addAtTail(21);
    obj->addAtTail(22);
    obj->showLinkList();//共6个元素 12 15 16 20 21 22
    //删除：
    //obj->deleteAtIndex(3);//-1 0 3 5 6 7 删除索引为index的某个元素
    //obj->removeElements(16);//删除值为val的所有元素
    //obj->showLinkList();
    //按下标插入元素：
    // obj->addAtIndex(0,26);//-1 0 3 6 7
    // obj->showLinkList();
    //获取第index个结点的值：
    // int res = obj->getIndex(7);//-1 0 3 6 7
    // if(res == -1)
    //     cout << "索引值无效！" << endl;
    // else
    //     cout << "第index个结点的值： " << res << endl;

    return 0;
}