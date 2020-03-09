/*
        @作者:        cloudYun
        @文件:        SeqStack
        @时间:        2020/3/9 8:44
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
    int maxSize{};       //能存储的最大数据量
    int last{};          //当前存储的元素个数（并非元素下标）
public:
    SeqStack();                              //构造函数
    SeqStack(SeqStack<T> &list);             //拷贝构造函数
    ~SeqStack();                             //析构函数
    void reSize();                           //增加空间大小
    void push(T p);                          //进栈
    void pop();                              //出栈
    bool top(T &p);                          //取栈顶
    bool isEmpty();                          //判断栈是否为空
    int size();                              //返回栈的大小
    void print();                            //打印顺序栈
    void clear();                            //清空顺序栈
    void delete_link();                      //摧毁顺序栈
};

//构造函数
template<class T>
SeqStack<T>::SeqStack() {
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
SeqStack<T>::SeqStack(SeqStack<T> &list) {
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
SeqStack<T>::~SeqStack() {
    delete_link();
}

//增加空间大小
template<class T>
void SeqStack<T>::reSize() {
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

//进栈
template<class T>
void SeqStack<T>::push(T p) {
    if (last + 1 > maxSize)    //空间不足
        reSize();
    data[last++] = p;
}

//出栈
template<class T>
void SeqStack<T>::pop() {
    if (isEmpty())        //空表直接返回
        return;
    last--;     //数据个数-1
}

//取栈顶
template<class T>
bool SeqStack<T>::top(T &p) {
    if (isEmpty())        //空表直接返回
        return false;
    p = data[last - 1];
    return true;
}

//判断栈是否为空
template<class T>
bool SeqStack<T>::isEmpty() {
    return last == 0;
}

//清空顺序栈
template<class T>
void SeqStack<T>::clear() {
    delete data;
    maxSize = 50;
    last = 0;
    data = new T[maxSize];
}

//摧毁顺序栈
template<class T>
void SeqStack<T>::delete_link() {
    delete data;
}

//返回栈的大小
template<class T>
int SeqStack<T>::size() {
    return last;
}

//打印顺序栈
template<class T>
void SeqStack<T>::print() {
    if (isEmpty())        //空表直接返回
        return;
    cout << "顺序栈中的数据为： "<<endl;
    for (int i = last-1; i >= 0; i--)
        cout <<"|"<<setw(6)<< data[i] << "|"<<endl<<"┼──────┼"<<endl;
}

#endif //MY_DS_STACK_H