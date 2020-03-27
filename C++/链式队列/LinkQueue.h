/*
        @作者:        cloudYun
        @文件:        LinkQUeue
        @时间:        2020/3/27 20:37
        @编译器:      Clion
*/

#ifndef MY_DS_LINKQUEUE_H
#define MY_DS_LINKQUEUE_H

#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class LinkQueue;

template<class T>
class LinkNode {
    friend class LinkQueue<T>;

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
class LinkQueue {
private:
    LinkNode<T> *head;

public:
    LinkQueue();                              //构造函数
    ~LinkQueue();                             //析构函数
    void push(T p);                           //进队列
    void pop();                               //出队列
    bool front(T &p);                         //取队列顶
    bool isEmpty();                           //判断队列是否为空
    int size();                               //返回队列的大小
    void print();                             //打印
    void clear();                             //清空
};

//构造函数
template<class T>
inline LinkQueue<T>::LinkQueue() {
    head = new LinkNode<T>();
}

//析构函数
template<class T>
inline LinkQueue<T>::~LinkQueue() {
    clear();
}

//进队列
template<class T>
void LinkQueue<T>::push(T p) {
    //创建结点
    LinkNode<T> *temp;
    temp = new LinkNode<T>(p);

    //插入结点
    LinkNode<T> *q = head;
    while (q) {
        //当为找到最后一个结点时，后插结点
        if (q->next == NULL) {
            q->next = temp;
            temp->next = NULL;
            break;
        }
        q = q->next;
    }
}

//出队列
template<class T>
void LinkQueue<T>::pop() {
    LinkNode<T> *temp = NULL;    //存储删除的结点
    if (head->next != NULL) {
        //将删除的结点与前驱节点和后继节点断开
        temp = head->next;
        head->next = head->next->next;
    }
    delete temp;     //释放空间
}

//取队列顶
template<class T>
bool LinkQueue<T>::front(T &p) {
    if(isEmpty())
        return false;
    p = head->next->data;
    return true;
}

//判断队列是否为空
template<class T>
bool LinkQueue<T>::isEmpty() {
    return head->next == NULL;
}

//返回队列的大小
template<class T>
int LinkQueue<T>::size() {
    int len = 0;   //存储表的长度

    LinkNode<T> *q = head;
    while (q->next != NULL) {
        len++;
        q = q->next;
    }

    return len;
}

//打印队列
template<class T>
void LinkQueue<T>::print() {
    LinkNode<T> *p = head->next;
    if (p == NULL)      //空表
        return;
    cout << "顺序队列中的数据为： "<<endl;
    int len = size();
    for(int i=0;i<3;i++)
    {
        if(i==0||i==2)
        {
            cout<<"──────────┼";
            for(int j=0;j<len;j++)
                cout<<"──────┼";
            cout<<"──────────"<<endl;
            if(i==0)
                cout<<"顺序队列首 ";
        }
        else
        {
            cout<<"|";
            while(p!=NULL)
            {
                cout <<setw(6)<< p->data << "|";
                p=p->next;
            }
            cout<<"顺序队列尾 "<<endl;
        }
    }
}

//清空
template<class T>
void LinkQueue<T>::clear() {
    LinkNode<T> *temp;

    while(head->next != NULL) {
        temp = head->next;
        head->next = temp->next;
        delete temp;
    }
}

#endif //MY_DS_LINKQUEUE_H