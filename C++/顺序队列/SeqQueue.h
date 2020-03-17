/*
        @作者:        cloudYun
        @文件:        SeqQueue
        @时间:        2020/3/17 8:22
        @编译器:      Clion
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
    int maxSize{};       //能存储的最大数据量
    int last{};          //当前存储的元素个数（并非元素下标）
public:
    SeqQueue();                              //构造函数
    SeqQueue(SeqQueue<T> &list);             //拷贝构造函数
    ~SeqQueue();                             //析构函数
    void reSize();                           //增加空间大小
    void push(T p);                          //进队列
    void pop();                              //出队列
    bool front(T &p);                        //取队列顶
    bool isEmpty();                          //判断栈是否为空
    int size();                              //返回队列的大小
    void print();                            //打印队列
    void clear();                            //清空队列
    void delete_link();                      //摧毁队列
};

//构造函数
template<class T>
SeqQueue<T>::SeqQueue() {
    maxSize = 50;       //初始最大存储量为50
    last = 0;
    data = new T[maxSize];   //给数组分配空间

    if (data == NULL)           //动态分配失败
    {
        cerr << "存储分配错误！" << endl;
        exit(1);
    }
}

//拷贝构造函数
template<class T>
SeqQueue<T>::SeqQueue(SeqQueue<T> &list) {
    maxSize = list.maxSize;
    last = list.last;

    data = new T[maxSize];
    if (data == NULL)           //动态分配失败
    {
        cerr << "存储分配错误！" << endl;
        exit(1);
    }

    for (int i = 0; i < maxSize; i++)
        data[i] = list.data[i];
}

//析构函数
template<class T>
SeqQueue<T>::~SeqQueue() {
    delete_link();
}

//增加空间大小
template<class T>
void SeqQueue<T>::reSize() {
    maxSize += 10;

    T *temp = new T[maxSize];
    if (data == NULL)           //动态分配失败
    {
        cerr << "存储分配错误！" << endl;
        exit(1);
    }

    for (int i = 0; i < maxSize; i++)
        temp[i] = data[i];

    delete data;
    data = temp;
}

//进队列
template<class T>
void SeqQueue<T>::push(T p) {
    if (last + 1 > maxSize)    //空间不足
        reSize();
    data[last++] = p;
}

//出队列
template<class T>
void SeqQueue<T>::pop() {
    if (isEmpty())        //空表直接返回
        return;
    for(int i=0;i<last;i++)     //全部前移一位
        data[i] = data[i+1];
    last--;     //数据个数-1
}

//取队列顶
template<class T>
bool SeqQueue<T>::front(T &p) {
    if (isEmpty())        //空表直接返回
        return false;
    p = data[0];
    return true;
}

//判断队列是否为空
template<class T>
bool SeqQueue<T>::isEmpty() {
    return last == 0;
}

//清空队列
template<class T>
void SeqQueue<T>::clear() {
    delete data;
    maxSize = 50;
    last = 0;
    data = new T[maxSize];
}

//摧毁队列
template<class T>
void SeqQueue<T>::delete_link() {
    delete data;
}

//返回队列的大小
template<class T>
int SeqQueue<T>::size() {
    return last;
}

//打印队列
template<class T>
void SeqQueue<T>::print() {
    if (isEmpty())        //空表直接返回
        return;
    cout << "顺序队列中的数据为： "<<endl;
    for(int i=0;i<3;i++)
    {
        if(i==0||i==2)
        {
            cout<<"──────────┼";
            for(int j=0;j<last;j++)
                    cout<<"──────┼";
            cout<<"──────────"<<endl;
            if(i==0)
                cout<<"顺序队列首 ";
        }
        else
        {
            cout<<"|";
            for (int j = last-1; j >= 0; j--)
                cout <<setw(6)<< data[j] << "|";
            cout<<"顺序队列尾 "<<endl;
        }
    }
}

#endif //MY_DS_SEQQUEUE_H