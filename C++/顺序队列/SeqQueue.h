/*
        @����:        cloudYun
        @�ļ�:        SeqQueue
        @ʱ��:        2020/3/17 8:22
        @������:      Clion
*/

#ifndef MY_DS_SEQQUEUE_H
#define MY_DS_SEQQUEUE_H

#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class SeqQueue {
public:
    T *data;
    int maxSize{};       //�ܴ洢�����������
    int last{};          //��ǰ�洢��Ԫ�ظ���������Ԫ���±꣩
public:
    SeqQueue();                              //���캯��
    SeqQueue(SeqQueue<T> &list);             //�������캯��
    ~SeqQueue();                             //��������
    void reSize();                           //���ӿռ��С
    void push(T p);                          //������
    void pop();                              //������
    bool front(T &p);                        //ȡ���ж�
    bool isEmpty();                          //�ж�ջ�Ƿ�Ϊ��
    int size();                              //���ض��еĴ�С
    void print();                            //��ӡ����
    void clear();                            //��ն���
    void delete_link();                      //�ݻٶ���
};

//���캯��
template<class T>
SeqQueue<T>::SeqQueue() {
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
SeqQueue<T>::SeqQueue(SeqQueue<T> &list) {
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
SeqQueue<T>::~SeqQueue() {
    delete_link();
}

//���ӿռ��С
template<class T>
void SeqQueue<T>::reSize() {
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

//������
template<class T>
void SeqQueue<T>::push(T p) {
    if (last + 1 > maxSize)    //�ռ䲻��
        reSize();
    data[last++] = p;
}

//������
template<class T>
void SeqQueue<T>::pop() {
    if (isEmpty())        //�ձ�ֱ�ӷ���
        return;
    for(int i=0;i<last;i++)     //ȫ��ǰ��һλ
        data[i] = data[i+1];
    last--;     //���ݸ���-1
}

//ȡ���ж�
template<class T>
bool SeqQueue<T>::front(T &p) {
    if (isEmpty())        //�ձ�ֱ�ӷ���
        return false;
    p = data[0];
    return true;
}

//�ж϶����Ƿ�Ϊ��
template<class T>
bool SeqQueue<T>::isEmpty() {
    return last == 0;
}

//��ն���
template<class T>
void SeqQueue<T>::clear() {
    delete data;
    maxSize = 50;
    last = 0;
    data = new T[maxSize];
}

//�ݻٶ���
template<class T>
void SeqQueue<T>::delete_link() {
    delete data;
}

//���ض��еĴ�С
template<class T>
int SeqQueue<T>::size() {
    return last;
}

//��ӡ����
template<class T>
void SeqQueue<T>::print() {
    if (isEmpty())        //�ձ�ֱ�ӷ���
        return;
    cout << "˳������е�����Ϊ�� "<<endl;
    for(int i=0;i<3;i++)
    {
        if(i==0||i==2)
        {
            cout<<"����������������������";
            for(int j=0;j<last;j++)
                    cout<<"��������������";
            cout<<"��������������������"<<endl;
            if(i==0)
                cout<<"˳������� ";
        }
        else
        {
            cout<<"|";
            for (int j = last-1; j >= 0; j--)
                cout <<setw(6)<< data[j] << "|";
            cout<<"˳�����β "<<endl;
        }
    }
}

#endif //MY_DS_SEQQUEUE_H