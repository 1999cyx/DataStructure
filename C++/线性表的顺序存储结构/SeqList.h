//
// Created by 17558 on 2020/2/13.
//

#ifndef MY_DS_SEQLIST_H
#define MY_DS_SEQLIST_H

#include <iostream>

using namespace std;

template<class T>
class SeqList {
public:
    T *data;
    int maxSize{};       //�ܴ洢�����������
    int last{};          //��ǰ�洢��Ԫ�ظ���������Ԫ���±꣩
public:
    SeqList();                               //���캯��
    SeqList(SeqList<T> &list);               //�������캯��
    ~SeqList();                              //��������
    void reSize();                           //���ӿռ��С
    void push_first(T p);                    //ͷ�巨����˳���ͷ��������
    void push_last(T p);                     //β�巨����˳���β��������
    bool push_pos(int pos, T p);             //��˳����pos��λ�ò�������
    void pop_first();                        //ɾ��˳���ͷ����
    void pop_last();                         //ɾ��˳���β����
    bool pop_pos(int pos);                   //ɾ��˳����pos������
    void change_first(T p);                  //�޸�˳���ͷ����
    void change_last(T p);                   //�޸�˳���β����
    bool change_pos(int pos, T p);           //�޸�˳����pos������
    bool get_first(T &p);                    //�õ�˳���ͷ����
    bool get_last(T &p);                     //�õ�˳���β����
    bool get_pos(int pos, T &p);             //�õ�˳����pos������
    int search(T p);                         //����˳�����p��ͬ�ĵ�һ��Ԫ�ص��±�pos�����������򷵻�-1
    bool isEmpty();                          //�ж�˳����Ƿ�Ϊ��
    int size();                              //����˳����ܴ洢�����������
    int length();                            //����˳���ĳ���
    void print();                            //��ӡ˳���
    void clear();                            //���˳���
    void delete_link();                      //�ݻ�˳���
};

//���캯��
template<class T>
SeqList<T>::SeqList() {
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
SeqList<T>::SeqList(SeqList<T> &list) {
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
SeqList<T>::~SeqList() {
    delete_link();
}

//���ӿռ��С
template<class T>
void SeqList<T>::reSize() {
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

//ͷ�巨����˳���ͷ��������
template<class T>
void SeqList<T>::push_first(T p) {
    if (last + 1 > maxSize)    //�ռ䲻��
        reSize();
    last++;
    for (int i = last - 1; i > 0; i--)   //ȫ�����ݺ���һλ
        data[i] = data[i - 1];
    data[0] = p;
}

//β�巨����˳���β��������
template<class T>
void SeqList<T>::push_last(T p) {
    if (last + 1 > maxSize)    //�ռ䲻��
        reSize();
    data[last++] = p;
}

//��˳����pos��λ�ò�������
template<class T>
bool SeqList<T>::push_pos(int pos, T p) {
    if (pos > last + 1 || pos <= 0)      //�����ڵ�pos������
        return false;
    if (last + 1 > maxSize)    //�ռ䲻��
        reSize();
    last++;
    for (int i = last - 1; i >= pos; i--)   //��pos�����ݺ��������ȫ������һλ
        data[i] = data[i - 1];
    data[pos - 1] = p;
    return true;
}

//ɾ��˳���ͷ����
template<class T>
void SeqList<T>::pop_first() {
    if (isEmpty())        //�ձ�ֱ�ӷ���
        return;
    for (int i = 0; i < last - 1; i++)       //�ӵ�2�����ݿ�ʼȫ��ǰ��һλ
        data[i] = data[i + 1];
    last--;     //���ݸ���-1
}

//ɾ��˳���β����
template<class T>
void SeqList<T>::pop_last() {
    if (isEmpty())        //�ձ�ֱ�ӷ���
        return;
    last--;     //���ݸ���-1
}

//ɾ��˳����pos������
template<class T>
bool SeqList<T>::pop_pos(int pos) {
        if (pos > last || pos <= 0)      //�����ڵ�pos������
        return false;

    for (int i = pos - 1; i < last - 1; i++)       //�ӵ�pos�����ݿ�ʼȫ��ǰ��һλ
        data[i] = data[i + 1];

    last--;     //���ݸ���-1
    return true;
}

//�޸�˳���ͷ����
template<class T>
void SeqList<T>::change_first(T p) {
    if (isEmpty())        //�ձ�ֱ�ӷ���
        return;
    data[0] = p;
}

//�޸�˳���β����
template<class T>
void SeqList<T>::change_last(T p) {
    if (isEmpty())        //�ձ�ֱ�ӷ���
        return;
    data[last - 1] = p;
}

//�޸�˳����pos������
template<class T>
bool SeqList<T>::change_pos(int pos, T p) {
    if (pos > last || pos <= 0)      //�����ڵ�pos������
        return false;
    data[pos - 1] = p;
    return true;
}

//�õ�˳���ͷ����
template<class T>
bool SeqList<T>::get_first(T &p) {
    if (isEmpty())        //�ձ�ֱ�ӷ���
        return false;
    p = data[0];
    return true;
}

//�õ�˳���β����
template<class T>
bool SeqList<T>::get_last(T &p) {
    if (isEmpty())        //�ձ�ֱ�ӷ���
        return false;
    p = data[last - 1];
    return true;
}

//�õ�˳����pos������
template<class T>
bool SeqList<T>::get_pos(int pos, T &p) {
    if (pos > last || pos <= 0)      //�����ڵ�pos������
        return false;
    p = data[pos - 1];
    return true;
}

//����˳�����p��ͬ�ĵ�һ��Ԫ�ص��±�pos�����������򷵻�-1
template<class T>
int SeqList<T>::search(T p) {
    for (int i = 0; i < last; i++) {
        if (data[i] == p)       //��p��ͬ�ĵ�һ��Ԫ�ص��±�pos
            return i;
    }

    return -1;      //�������򷵻�-1
}

//�ж�˳����Ƿ�Ϊ��
template<class T>
bool SeqList<T>::isEmpty() {
    return last == 0;
}

//����˳����ܴ洢�����������
template<class T>
int SeqList<T>::size() {
    return maxSize;
}

//����˳���ĳ���
template<class T>
int SeqList<T>::length() {
    return last;
}

//��ӡ˳���
template<class T>
void SeqList<T>::print() {
    if (isEmpty())        //�ձ�ֱ�ӷ���
        return;
    cout << "���Ա�����Ϊ�� ";
    for (int i = 0; i < last - 1; i++)
        cout << data[i] << " ----> ";
    cout << data[last - 1] << endl;
}

//���˳���
template<class T>
void SeqList<T>::clear() {
    delete data;
    maxSize = 50;
    last = 0;
    data = new T[maxSize];
}

//�ݻ�˳���
template<class T>
void SeqList<T>::delete_link() {
    delete data;
}

#endif //MY_DS_SEQLIST_H
