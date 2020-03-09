/*
        @����:        cloudYun
        @�ļ�:        LinkStack
        @ʱ��:        2020/3/9 9:46
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
    LinkStack();                              //���캯��
    ~LinkStack();                             //��������
    void push(T p);                           //��ջ
    void pop();                               //��ջ
    bool top(T &p);                           //ȡջ��
    bool isEmpty();                           //�ж�ջ�Ƿ�Ϊ��
    int size();                               //����ջ�Ĵ�С
    void print();                             //��ӡ
    void clear();                             //���
};

//��ʼ��������
template<class T>
inline LinkStack<T>::LinkStack() {
    head = new LinkNode<T>();
}

//��������
template<class T>
inline LinkStack<T>::~LinkStack() {
    clear();
}

//��ջ
template<class T>
void LinkStack<T>::push(T p) {
    //�������
    LinkNode<T> *temp;
    temp = new LinkNode<T>(p);

    //������
    temp->next = head->next;
    head->next = temp;
}

//��ջ
template<class T>
void LinkStack<T>::pop() {
    LinkNode<T> *temp = NULL;    //�洢ɾ���Ľ��
    if (head->next != NULL) {
        //��ɾ���Ľ����ǰ���ڵ�ͺ�̽ڵ�Ͽ�
        temp = head->next;
        head->next = head->next->next;
    }
    delete temp;     //�ͷſռ�
}

//ȡջ��
template<class T>
bool LinkStack<T>::top(T &p) {
    if(isEmpty())
        return false;
    p = head->next->data;
    return true;
}

//�ж�ջ�Ƿ�Ϊ��
template<class T>
bool LinkStack<T>::isEmpty() {
    return head->next == NULL;
}

//����ջ�Ĵ�С
template<class T>
int LinkStack<T>::size() {
    int len = 0;   //�洢������ĳ���

    LinkNode<T> *q = head;
    while (q->next != NULL) {
        len++;
        q = q->next;
    }

    return len;
}

//��ӡջ
template<class T>
void LinkStack<T>::print() {
    LinkNode<T> *p = head->next;
    if (p == NULL)
        return;
    while (p->next != NULL) {
        cout <<"|"<<setw(6)<< p->data << "|"<<endl<<"�੤������������"<<endl;
        p = p->next;
    }
    cout <<"|"<<setw(6)<< p->data << "|"<<endl<<"�੤������������"<<endl;
}

//���
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