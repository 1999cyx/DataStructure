/*
        @����:        cloudYun
        @�ļ�:        SeqStack
        @ʱ��:        2020/3/9 8:44
*/

#ifndef MY_DS_STACK_H
#define MY_DS_STACK_H

#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class SeqStack {
public:
    T *data;
    int maxSize{};       //�ܴ洢�����������
    int last{};          //��ǰ�洢��Ԫ�ظ���������Ԫ���±꣩
public:
    SeqStack();                              //���캯��
    SeqStack(SeqStack<T> &list);             //�������캯��
    ~SeqStack();                             //��������
    void reSize();                           //���ӿռ��С
    void push(T p);                          //��ջ
    void pop();                              //��ջ
    bool top(T &p);                          //ȡջ��
    bool isEmpty();                          //�ж�ջ�Ƿ�Ϊ��
    int size();                              //����ջ�Ĵ�С
    void print();                            //��ӡ˳��ջ
    void clear();                            //���˳��ջ
    void delete_link();                      //�ݻ�˳��ջ
};

//���캯��
template<class T>
SeqStack<T>::SeqStack() {
    maxSize = 50;       //��ʼ���洢��Ϊ50
    last = 0;
    data = new T[maxSize];   //���������ռ�

    if (data == NULL)           //��̬����ʧ��
    {
        cerr << "�洢�������" << endl;
        exit(1);
    }
}

//�������캯��
template<class T>
SeqStack<T>::SeqStack(SeqStack<T> &list) {
    maxSize = list.maxSize;
    last = list.last;

    data = new T[maxSize];
    if (data == NULL)           //��̬����ʧ��
    {
        cerr << "�洢�������" << endl;
        exit(1);
    }

    for (int i = 0; i < maxSize; i++)
        data[i] = list.data[i];
}

//��������
template<class T>
SeqStack<T>::~SeqStack() {
    delete_link();
}

//���ӿռ��С
template<class T>
void SeqStack<T>::reSize() {
    maxSize += 10;

    T *temp = new T[maxSize];
    if (data == NULL)           //��̬����ʧ��
    {
        cerr << "�洢�������" << endl;
        exit(1);
    }

    for (int i = 0; i < maxSize; i++)
        temp[i] = data[i];

    delete data;
    data = temp;
}

//��ջ
template<class T>
void SeqStack<T>::push(T p) {
    if (last + 1 > maxSize)    //�ռ䲻��
        reSize();
    data[last++] = p;
}

//��ջ
template<class T>
void SeqStack<T>::pop() {
    if (isEmpty())        //�ձ�ֱ�ӷ���
        return;
    last--;     //���ݸ���-1
}

//ȡջ��
template<class T>
bool SeqStack<T>::top(T &p) {
    if (isEmpty())        //�ձ�ֱ�ӷ���
        return false;
    p = data[last - 1];
    return true;
}

//�ж�ջ�Ƿ�Ϊ��
template<class T>
bool SeqStack<T>::isEmpty() {
    return last == 0;
}

//���˳��ջ
template<class T>
void SeqStack<T>::clear() {
    delete data;
    maxSize = 50;
    last = 0;
    data = new T[maxSize];
}

//�ݻ�˳��ջ
template<class T>
void SeqStack<T>::delete_link() {
    delete data;
}

//����ջ�Ĵ�С
template<class T>
int SeqStack<T>::size() {
    return last;
}

//��ӡ˳��ջ
template<class T>
void SeqStack<T>::print() {
    if (isEmpty())        //�ձ�ֱ�ӷ���
        return;
    cout << "˳��ջ�е�����Ϊ�� "<<endl;
    for (int i = last-1; i >= 0; i--)
        cout <<"|"<<setw(6)<< data[i] << "|"<<endl<<"�੤������������"<<endl;
}

#endif //MY_DS_STACK_H