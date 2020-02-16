//
// Created by 17558 on 2020/2/10.
//

#ifndef MY_DS_LINKLIST_H
#define MY_DS_LINKLIST_H

#include <iostream>

using namespace std;

template<class T>
class LinkList;

template<class T>
class LinkNode {
    friend class LinkList<T>;

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
class LinkList {
private:
    LinkNode<T> *head;

public:
    LinkList();                              //构造函数
    ~LinkList();                             //析构函数
    void push_first(T p);                    //在单链表头添加数据
    void push_last(T p);                     //在单链表尾添加数据
    bool push_node_prev(T x, T p);           //在单链表数据x前面添加数据
    bool push_node_next(T x, T p);           //在单链表数据x后面添加数据
    void pop_first();                        //删除单链表头的数据
    void pop_last();                         //删除单链表尾的数据
    bool pop_node_data(T x);                 //删除单链表中的数据x
    bool pop_node_cur(int pos);              //删除第pos个数据
    bool get_first_node(LinkNode<T> *&p);    //得到单链表的头结点
    bool get_last_node(LinkNode<T> *&p);     //得到单链表的尾结点
    bool get_node(LinkNode<T> *&p, int pos); //得到单链表中第pos个结点
    bool get_first_data(T &p);               //得到单链表头的数据
    bool get_last_data(T &p);                //得到单链表尾的数据
    bool get_data(T &x, int pos);            //得到单链表中第pos个数据
    void change_first_data(T p);             //修改单链表中头的数据
    void change_last_data(T p);              //修改单链表尾的数据
    bool change_node_data(T x, T p);         //修改单链表中的数据x修改为数据p
    bool change_node_cur(T p, int pos);      //修改单链表中第pos个数据
    LinkNode<T> *search(T p);                //查找单链表数据为p的结点
    LinkNode<T> *search_prev(T p);           //查找单链表数据为p的结点的前驱节点
    LinkNode<T> *search_next(T p);           //查找单链表数据为p的结点的后续节点
    bool isEmpty();                          //判断单链表是否为空
    int length();                            //返回单链表的长度
    void print();                            //打印单链表
    void delete_link();                      //摧毁单链表
};

//初始化单链表
template<class T>
inline LinkList<T>::LinkList() {
    head = new LinkNode<T>();
}

//析构函数
template<class T>
inline LinkList<T>::~LinkList() {
    delete_link();
}

//前插法建立单链表
template<class T>
inline void LinkList<T>::push_first(T p) {
    //创建结点
    LinkNode<T> *temp;
    temp = new LinkNode<T>(p);

    //插入结点
    temp->next = head->next;
    head->next = temp;
}

//后插法建立单链表
template<class T>
inline void LinkList<T>::push_last(T p) {
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

//在单链表数据x前面添加数据
template<class T>
inline bool LinkList<T>::push_node_prev(T x, T p) {
    LinkNode<T> *temp;
    temp = search_prev(x);    //在单链表中查找结点x的前驱节点
    if (temp)   //存在结点，在x结点的前驱节点后面插入节点p（也就是在x结点前面插入）
    {
        //给结点分配空间
        LinkNode<T> *q;
        q = new LinkNode<T>(p);

        //插入节点
        q->next = temp->next;
        temp->next = q;

        return true;
    }
    return false;    //不存在，返回false
}

//在单链表数据x后面添加数据
template<class T>
inline bool LinkList<T>::push_node_next(T x, T p) {
    LinkNode<T> *temp;
    temp = search(x);    //在单链表中查找结点x
    if (temp)   //存在结点，在x结点后面插入节点p
    {
        //给结点分配空间
        LinkNode<T> *q;
        q = new LinkNode<T>(p);

        //插入节点
        q->next = temp->next;
        temp->next = q;

        return true;
    }
    return false;    //不存在，返回false
}

//删除单链表头的数据
template<class T>
inline void LinkList<T>::pop_first() {
    LinkNode<T> *temp = NULL;    //存储删除的结点
    if (head->next != NULL) {
        //将删除的结点与前驱节点和后继节点断开
        temp = head->next;
        head->next = head->next->next;
    }
    delete temp;     //释放空间
}

//删除单链表尾的数据
template<class T>
inline void LinkList<T>::pop_last() {
    LinkNode<T> *q = head;
    LinkNode<T> *temp = NULL;    //存储删除的结点
    //循环，直到q的下一个结点为尾结点时
    while (q->next->next != NULL)
        q = q->next;
    temp = q->next;
    q->next = NULL;

    delete temp;     //释放空间
}

//删除单链表中的数据x
template<class T>
inline bool LinkList<T>::pop_node_data(T x) {
    LinkNode<T> *q = search_prev(x);    //得到待删除结点的前驱节点
    if (q != NULL)    //若查找到该结点的前驱节点，删除结点x
    {
        //待删除的结点
        LinkNode<T> *temp;
        //删除结点
        temp = q->next;
        q->next = q->next->next;
        //释放空间
        delete temp;
        return true;
    }
    return false;
}

//删除第pos个结点
template<class T>
inline bool LinkList<T>::pop_node_cur(int pos) {
    if (pos <= length() && pos > 0)      //存在第pos个数据
    {
        LinkNode<T> *q = head;
        //循环，直到q为第pos-1个结点时
        for (int i = 0; i < pos - 1; i++)
            q = q->next;
        //待删除的结点
        LinkNode<T> *temp;
        //删除结点
        temp = q->next;
        q->next = q->next->next;
        //释放空间
        delete temp;
        return true;
    }
    return false;
}

//得到单链表的头结点
template<class T>
inline bool LinkList<T>::get_first_node(LinkNode<T> *&p) {
    if (head->next == NULL)     //没有头结点返回false
        return false;

    p = head->next;     //头结点存在，返回true
    return true;
}

//得到单链表的尾结点
template<class T>
inline bool LinkList<T>::get_last_node(LinkNode<T> *&p) {
    if (head->next == NULL)     //没有头结点返回false
        return false;

    p = head;
    while (p->next != NULL)      //循环得到最后一个结点
        p = p->next;
    return true;
}

//得到单链表中第pos个结点
template<class T>
inline bool LinkList<T>::get_node(LinkNode<T> *&p, int pos) {
    if (pos <= length() && pos > 0) {
        LinkNode<T> *q = head;
        for (int i = 0; i < pos; i++)     //循环直到p为第pos个结点时
            q = q->next;

        p = q;
        return true;
    }
    return false;
}

//得到单链表头的数据
template<class T>
inline bool LinkList<T>::get_first_data(T &p) {
    LinkNode<T> *temp;
    if (get_first_node(temp))     //存在头结点返回true
    {
        p = temp->data;
        return true;
    } else
        return false;
}

//得到单链表尾的数据
template<class T>
inline bool LinkList<T>::get_last_data(T &p) {
    LinkNode<T> *temp;
    if (get_last_node(temp))     //存在头结点返回true
    {
        p = temp->data;
        return true;
    } else
        return false;
}

//得到单链表中第pos个数据
template<class T>
inline bool LinkList<T>::get_data(T &x, int pos) {
    if (pos <= length() && pos > 0)      //当存在第pos个数据时
    {
        LinkNode<T> *p;
        get_node(p, pos);

        x = p->data;
        return true;
    }
    return false;
}

//修改单链表头的数据
template<class T>
inline void LinkList<T>::change_first_data(T p) {
    LinkNode<T> *temp;
    if (get_first_node(temp))      //存在头结点
        temp->data = p;
}

//修改单链表尾的数据
template<class T>
inline void LinkList<T>::change_last_data(T p) {
    LinkNode<T> *temp;
    if (get_last_node(temp))      //存在尾结点
        temp->data = p;
}

//修改单链表中的数据x修改为数据p
template<class T>
inline bool LinkList<T>::change_node_data(T x, T p) {
    LinkNode<T> *temp;
    temp = search(x);     //查找数据为x的结点

    if (temp != NULL)      //该结点不为空，则修改data
    {
        temp->data = p;
        return true;
    }
    return false;
}

//修改单链表中第pos个数据
template<class T>
inline bool LinkList<T>::change_node_cur(T p, int pos) {
    LinkNode<T> *temp;
    if (get_node(temp, pos))     //存在第pos个结点，则修改data
    {
        temp->data = p;
        return true;
    }
    return false;
}

//查找单链表数据为p的结点
template<class T>
inline LinkNode<T> *LinkList<T>::search(T p) {
    LinkNode<T> *q = head;
    while (q) {
        //查找结点数据等于p的结点
        if (q->data == p)
            return q;    //找到，返回该结点
        q = q->next;
    }
    return NULL;   //未找到，返回NULL
}

//查找单链表数据为p的结点的前驱节点
template<class T>
inline LinkNode<T> *LinkList<T>::search_prev(T p) {
    LinkNode<T> *q = head;
    while (q->next != NULL) {
        //循环查找结点数据等于p的结点的前驱节点
        if (q->next->data == p)
            return q;    //找到，返回该结点
        q = q->next;
    }
    return NULL;   //未找到，返回NULL
}

//查找单链表数据为p的结点的后续节点
template<class T>
inline LinkNode<T> *LinkList<T>::search_next(const T p) {
    LinkNode<T> *q = head;
    while (q) {
        //查找结点数据等于p的结点
        if (q->data == p)
            return q->next;    //找到，返回该结点的后继节点
        q = q->next;
    }
    return NULL;   //未找到，返回NULL
}

//判断单链表是否为空
template<class T>
inline bool LinkList<T>::isEmpty() {
    return head->next == NULL;
}

//返回单链表的长度
template<class T>
inline int LinkList<T>::length() {
    int len = 0;   //存储单链表的长度

    LinkNode<T> *q = head;
    while (q->next != NULL) {
        len++;
        q = q->next;
    }

    return len;
}

//打印单链表
template<class T>
inline void LinkList<T>::print() {
    LinkNode<T> *p = head->next;
    if (p == NULL)
        return;
    while (p->next != NULL) {
        cout << p->data << " ---> ";
        p = p->next;
    }
    cout << p->data << endl;
}

//摧毁单链表
template<class T>
inline void LinkList<T>::delete_link() {
    LinkNode<T> *temp;

    while(head->next != NULL) {
        temp = head->next;
        head->next = temp->next;
        delete temp;
    }
}

#endif //MY_DS_LINKLIST_H
