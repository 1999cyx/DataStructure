/*
        @作者:        cloudYun
        @文件:        LinkStack
        @时间:        2020/3/9 9:46
*/

#ifndef MY_DS_LINKSTACK_H
#define MY_DS_LINKSTACK_H

#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class LinkStack;

template<class T>
class LinkNode {
    friend class LinkStack<T>;

private:
    T data;
    LinkNode<T> *next;

public:
    LinkNode() {
        next = NULL;
    }

    explicit LinkNode(T p) {
        data = p;
        next = NULL;
    }

    LinkNode<T> &operator=(const LinkNode<T> *p) {
        data = p->data;
        next = p->next;
        return *this;
    }
};

template<class T>
class LinkStack {
private:
    LinkNode<T> *head;

public:
    LinkStack();                              //构造函数
    ~LinkStack();                             //析构函数
    void push(T p);                           //进栈
    void pop();                               //出栈
    bool top(T &p);                           //取栈顶
    bool isEmpty();                           //判断栈是否为空
    int size();                               //返回栈的大小
    void print();                             //打印
    void clear();                             //清空
};

//初始化单链表
template<class T>
inline LinkStack<T>::LinkStack() {
    head = new LinkNode<T>();
}

//析构函数
template<class T>
inline LinkStack<T>::~LinkStack() {
    clear();
}

//进栈
template<class T>
void LinkStack<T>::push(T p) {
    //创建结点
    LinkNode<T> *temp;
    temp = new LinkNode<T>(p);

    //插入结点
    temp->next = head->next;
    head->next = temp;
}

//出栈
template<class T>
void LinkStack<T>::pop() {
    LinkNode<T> *temp = NULL;    //存储删除的结点
    if (head->next != NULL) {
        //将删除的结点与前驱节点和后继节点断开
        temp = head->next;
        head->next = head->next->next;
    }
    delete temp;     //释放空间
}

//取栈顶
template<class T>
bool LinkStack<T>::top(T &p) {
    if(isEmpty())
        return false;
    p = head->next->data;
    return true;
}

//判断栈是否为空
template<class T>
bool LinkStack<T>::isEmpty() {
    return head->next == NULL;
}

//返回栈的大小
template<class T>
int LinkStack<T>::size() {
    int len = 0;   //存储单链表的长度

    LinkNode<T> *q = head;
    while (q->next != NULL) {
        len++;
        q = q->next;
    }

    return len;
}

//打印栈
template<class T>
void LinkStack<T>::print() {
    LinkNode<T> *p = head->next;
    if (p == NULL)
        return;
    while (p->next != NULL) {
        cout <<"|"<<setw(6)<< p->data << "|"<<endl<<"┼──────┼"<<endl;
        p = p->next;
    }
    cout <<"|"<<setw(6)<< p->data << "|"<<endl<<"┼──────┼"<<endl;
}

//清空
template<class T>
void LinkStack<T>::clear() {
    LinkNode<T> *temp;

    while(head->next != NULL) {
        temp = head->next;
        head->next = temp->next;
        delete temp;
    }
}

#endif //MY_DS_LINKSTACK_H