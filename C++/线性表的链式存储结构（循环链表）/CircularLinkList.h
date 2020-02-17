/*
        @作者:        CYX
        @文件:        CircularLinkList.h
        @时间:        2020/2/14 20:22
*/

#ifndef MY_DS_CIRCULARLINKLIST_H
#define MY_DS_CIRCULARLINKLIST_H


#include <iostream>

using namespace std;

template<class T>
class CircularLinkList;

template<class T>
class LinkNode {
    friend class CircularLinkList<T>;

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
class CircularLinkList {
private:
    LinkNode<T> *head;
    LinkNode<T> *rear;

public:
    CircularLinkList();                                //构造函数
    CircularLinkList(CircularLinkList<T> &list);       //拷贝构造函数
    ~CircularLinkList();                               //析构函数
    void append_first(T p);                            //头插法，在循环链表头插入数据
    void append_last(T p);                             //尾插法，在循环链表尾插入数据
    bool append_pos(int pos, T p);                     //在循环链表第pos个位置插入数据
    void pop_first();                                  //删除循环链表头数据
    void pop_last();                                   //删除循环链表尾数据
    bool pop_pos(int pos);                             //删除循环链表中第pos个数据
    void change_first(T p);                            //修改循环链表头数据
    void change_last(T p);                             //修改循环链表尾数据
    bool change_pos(int pos, T p);                     //修改循环链表中第pos个数据
    bool get_first_node(LinkNode<T> *&p);              //得到循环链表头结点
    bool get_last_node(LinkNode<T> *&p);               //得到循环链表尾结点
    bool get_pos_node(int pos, LinkNode<T> *&p);       //得到循环链表中第pos个结点
    bool get_first_data(T &p);                         //得到循环链表头数据
    bool get_last_data(T &p);                          //得到循环链表尾数据
    bool get_pos_data(int pos, T &p);                  //得到循环链表中第pos个数据
    int search(T p);                                   //返回循环链表中p相同的第一个元素的下标pos，若不存在则返回-1
    bool isEmpty();                                    //判断循环链表是否为空
    int length();                                      //返回循环链表的长度
    void print();                                      //打印循环链表
    void clear();                                      //清空循环链表
};

//构造函数
template<class T>
CircularLinkList<T>::CircularLinkList() {
    head = new LinkNode<T>();
    rear = new LinkNode<T>();
    head->next = head;
    rear = head;
}

//拷贝构造函数
template<class T>
CircularLinkList<T>::CircularLinkList(CircularLinkList<T> &list) {
    head = new LinkNode<T>();
    rear = new LinkNode<T>();
    head->next = head;
    rear = head;

    LinkNode<T> *q;
    if (!list.get_first_node(q))
        return;
    while (q != list.rear) {
        append_last(q->data);
        q = q->next;
    }
    append_last(q->data);
}

//析构函数
template<class T>
CircularLinkList<T>::~CircularLinkList() {
    clear();
}

//头插法，在循环链表头插入数据
template<class T>
void CircularLinkList<T>::append_first(T p) {
    //创建结点
    LinkNode<T> *temp;
    temp = new LinkNode<T>(p);
    //判断链表是否为空
    if (isEmpty()) {
        rear = temp;
        head->next = temp;
        temp->next = temp;
    } else {
        temp->next = head->next;
        head->next = temp;
        rear->next = temp;
    }
}

//尾插法，在循环链表尾插入数据
template<class T>
void CircularLinkList<T>::append_last(T p) {
    //创建结点
    LinkNode<T> *temp;
    temp = new LinkNode<T>(p);
    //判断链表是否为空
    if (isEmpty()) {
        rear = temp;
        head->next = temp;
        temp->next = temp;
    } else {
        rear->next = temp;
        temp->next = head->next;
        rear = temp;
    }
}

//在循环链表第pos个位置插入数据
template<class T>
bool CircularLinkList<T>::append_pos(int pos, T p) {
    if (pos <= 0 || pos > length())   //不存在指定位置
        return false;

    if (pos == 1)
        append_first(p);
    else {
        //创建结点
        LinkNode<T> *temp;
        temp = new LinkNode<T>(p);

        LinkNode<T> *q = head;
        //得到指定位置的前驱节点
        for (int i = 0; i < pos - 1; i++)
            q = q->next;

        temp->next = q->next;
        q->next = temp;
    }
    return true;
}

//删除循环链表头数据
template<class T>
void CircularLinkList<T>::pop_first() {
    if (isEmpty())     //空链表
        return;
    //只有一个结点时
    if (length() == 1) {
        delete head->next;
        head->next = head;
        rear = head;
    } else {
        LinkNode<T> *temp;
        temp = head->next;

        rear->next = temp->next;
        head->next = temp->next;
        delete temp;
    }
}

//删除循环链表尾数据
template<class T>
void CircularLinkList<T>::pop_last() {
    if (isEmpty())     //空链表
        return;
    //只有一个结点时
    if (length() == 1) {
        delete head->next;
        head->next = head;
        rear = head;
    } else {
        LinkNode<T> *temp;

        LinkNode<T> *q = head->next;
        while (q->next != rear)        //循环得到尾结点的前驱节点
            q = q->next;

        rear = q;
        temp = q->next;
        q->next = head->next;
        delete temp;
    }
}

//删除循环链表中第pos个数据
template<class T>
bool CircularLinkList<T>::pop_pos(int pos) {
    if (pos <= 0 || pos > length())   //不存在指定位置
        return false;
    //pos == 1即删除首结点
    if (pos == 1)
        pop_first();
        //pos == length()即删除尾结点
    else if (pos == length())
        pop_last();
    else {
        LinkNode<T> *temp;
        //循环得到待删除结点的前驱节点
        LinkNode<T> *q = head;
        for (int i = 0; i < pos - 1; i++)
            q = q->next;

        temp = q->next;
        q->next = temp->next;
        delete temp;
    }
    return true;
}

//修改循环链表头数据
template<class T>
void CircularLinkList<T>::change_first(T p) {
    if (isEmpty())    //空链表
        return;
    head->next->data = p;
}

//修改循环链表尾数据
template<class T>
void CircularLinkList<T>::change_last(T p) {
    if (isEmpty())    //空链表
        return;
    rear->data = p;
}

//修改循环链表中第pos个数据
template<class T>
bool CircularLinkList<T>::change_pos(int pos, T p) {
        if (pos <= 0 || pos > length())   //不存在指定位置
        return false;

    //循环得到待修改的结点
    LinkNode<T> *q = head;
    for (int i = 0; i < pos; i++)
        q = q->next;

    q->data = p;

    return true;
}

//得到循环链表头结点
template<class T>
bool CircularLinkList<T>::get_first_node(LinkNode<T> *&p) {
    if (isEmpty())    //空链表
        return false;
    p = head->next;
    return true;
}

//得到循环链表尾结点
template<class T>
bool CircularLinkList<T>::get_last_node(LinkNode<T> *&p) {
    if (isEmpty())    //空链表
        return false;
    p = rear;
    return true;
}

//得到循环链表中第pos个结点
template<class T>
bool CircularLinkList<T>::get_pos_node(int pos, LinkNode<T> *&p) {
    if (pos <= 0 || pos > length())   //不存在指定位置
        return false;

    //循环得到第pos个结点
    LinkNode<T> *q = head;
    for (int i = 0; i < pos; i++)
        q = q->next;
    p = q;

    return true;
}

//得到循环链表头数据
template<class T>
bool CircularLinkList<T>::get_first_data(T &p) {
    LinkNode<T> *temp;
    if (get_first_node(temp)) {
        p = temp->data;
        return true;
    }
    return false;
}

//得到循环链表尾数据
template<class T>
bool CircularLinkList<T>::get_last_data(T &p) {
    LinkNode<T> *temp;
    if (get_last_node(temp)) {
        p = temp->data;
        return true;
    }
    return false;
}

//得到循环链表中第pos个数据
template<class T>
bool CircularLinkList<T>::get_pos_data(int pos, T &p) {
    LinkNode<T> *temp;
    if (get_pos_node(pos, temp)) {
        p = temp->data;
        return true;
    }
    return false;
}

//返回循环链表中p相同的第一个元素的下标pos，若不存在则返回-1
template<class T>
int CircularLinkList<T>::search(T p) {
    if (isEmpty())      //空链表
        return -1;
    int pos = 0;       //记录下标
    LinkNode<T> *q = head->next;
    while (q != rear) {
        if (q->data == p)
            return pos;
        q = q->next;
        pos++;
    }
    return -1;
}

//判断循环链表是否为空
template<class T>
bool CircularLinkList<T>::isEmpty() {
    return head->next == head;
}

//返回循环链表的长度
template<class T>
int CircularLinkList<T>::length() {
    int len = 0;
    if (isEmpty())           //空链表时返回0
        return 0;

    LinkNode<T> *p = head;
    while (p != rear) {
        len++;
        p = p->next;
    }
    return len;
}

//打印循环链表
template<class T>
void CircularLinkList<T>::print() {
    if (isEmpty())
        return;
    LinkNode<T> *p = head->next;
    while (p != rear) {
        cout << p->data << " ---> ";
        p = p->next;
    }
    cout << p->data << endl;
}

//清空循环链表
template<class T>
void CircularLinkList<T>::clear() {
    if (isEmpty())
        return;

    LinkNode<T> *temp;

    while (head->next != rear) {
        temp = head->next;
        head->next = temp->next;
        delete temp;
    }
    delete head->next;
    head->next = head;
    rear = head;
}

#endif //MY_DS_CIRCULARLINKLIST_H