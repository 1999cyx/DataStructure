/*
        @����:        cloudYun
        @�ļ�:        LinkQUeue
        @ʱ��:        2020/3/27 20:37
        @������:      Clion
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
    LinkQueue();                              //���캯��
    ~LinkQueue();                             //��������
    void push(T p);                           //������
    void pop();                               //������
    bool front(T &p);                         //ȡ���ж�
    bool isEmpty();                           //�ж϶����Ƿ�Ϊ��
    int size();                               //���ض��еĴ�С
    void print();                             //��ӡ
    void clear();                             //���
};

//���캯��
template<class T>
inline LinkQueue<T>::LinkQueue() {
    head = new LinkNode<T>();
}

//��������
template<class T>
inline LinkQueue<T>::~LinkQueue() {
    clear();
}

//������
template<class T>
void LinkQueue<T>::push(T p) {
    //�������
    LinkNode<T> *temp;
    temp = new LinkNode<T>(p);

    //������
    LinkNode<T> *q = head;
    while (q) {
        //��Ϊ�ҵ����һ�����ʱ�������
        if (q->next == NULL) {
            q->next = temp;
            temp->next = NULL;
            break;
        }
        q = q->next;
    }
}

//������
template<class T>
void LinkQueue<T>::pop() {
    LinkNode<T> *temp = NULL;    //�洢ɾ���Ľ��
    if (head->next != NULL) {
        //��ɾ���Ľ����ǰ���ڵ�ͺ�̽ڵ�Ͽ�
        temp = head->next;
        head->next = head->next->next;
    }
    delete temp;     //�ͷſռ�
}

//ȡ���ж�
template<class T>
bool LinkQueue<T>::front(T &p) {
    if(isEmpty())
        return false;
    p = head->next->data;
    return true;
}

//�ж϶����Ƿ�Ϊ��
template<class T>
bool LinkQueue<T>::isEmpty() {
    return head->next == NULL;
}

//���ض��еĴ�С
template<class T>
int LinkQueue<T>::size() {
    int len = 0;   //�洢��ĳ���

    LinkNode<T> *q = head;
    while (q->next != NULL) {
        len++;
        q = q->next;
    }

    return len;
}

//��ӡ����
template<class T>
void LinkQueue<T>::print() {
    LinkNode<T> *p = head->next;
    if (p == NULL)      //�ձ�
        return;
    cout << "˳������е�����Ϊ�� "<<endl;
    int len = size();
    for(int i=0;i<3;i++)
    {
        if(i==0||i==2)
        {
            cout<<"����������������������";
            for(int j=0;j<len;j++)
                cout<<"��������������";
            cout<<"��������������������"<<endl;
            if(i==0)
                cout<<"˳������� ";
        }
        else
        {
            cout<<"|";
            while(p!=NULL)
            {
                cout <<setw(6)<< p->data << "|";
                p=p->next;
            }
            cout<<"˳�����β "<<endl;
        }
    }
}

//���
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