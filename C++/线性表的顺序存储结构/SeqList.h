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
    int maxSize{};       //能存储的最大数据量
    int last{};          //当前存储的元素个数（并非元素下标）
public:
    SeqList();                               //构造函数
    SeqList(SeqList<T> &list);               //拷贝构造函数
    ~SeqList();                              //析构函数
    void reSize();                           //增加空间大小
    void push_first(T p);                    //头插法，在顺序表头插入数据
    void push_last(T p);                     //尾插法，在顺序表尾插入数据
    bool push_pos(int pos, T p);             //在顺序表第pos个位置插入数据
    void pop_first();                        //删除顺序表头数据
    void pop_last();                         //删除顺序表尾数据
    bool pop_pos(int pos);                   //删除顺序表第pos个数据
    void change_first(T p);                  //修改顺序表头数据
    void change_last(T p);                   //修改顺序表尾数据
    bool change_pos(int pos, T p);           //修改顺序表第pos个数据
    bool get_first(T &p);                    //得到顺序表头数据
    bool get_last(T &p);                     //得到顺序表尾数据
    bool get_pos(int pos, T &p);             //得到顺序表第pos个数据
    int search(T p);                         //返回顺序表中p相同的第一个元素的下标pos，若不存在则返回-1
    bool isEmpty();                          //判断顺序表是否为空
    int size();                              //返回顺序表能存储的最大数据量
    int length();                            //返回顺序表的长度
    void print();                            //打印顺序表
    void clear();                            //清空顺序表
    void delete_link();                      //摧毁顺序表
};

//构造函数
template<class T>
SeqList<T>::SeqList() {
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
SeqList<T>::SeqList(SeqList<T> &list) {
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
SeqList<T>::~SeqList() {
    delete_link();
}

//增加空间大小
template<class T>
void SeqList<T>::reSize() {
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

//头插法，在顺序表头插入数据
template<class T>
void SeqList<T>::push_first(T p) {
    if (last + 1 > maxSize)    //空间不足
        reSize();
    last++;
    for (int i = last - 1; i > 0; i--)   //全部数据后移一位
        data[i] = data[i - 1];
    data[0] = p;
}

//尾插法，在顺序表尾插入数据
template<class T>
void SeqList<T>::push_last(T p) {
    if (last + 1 > maxSize)    //空间不足
        reSize();
    data[last++] = p;
}

//在顺序表第pos个位置插入数据
template<class T>
bool SeqList<T>::push_pos(int pos, T p) {
    if (pos > last + 1 || pos <= 0)      //不存在第pos个数据
        return false;
    if (last + 1 > maxSize)    //空间不足
        reSize();
    last++;
    for (int i = last - 1; i >= pos; i--)   //第pos个数据后面的数据全部后移一位
        data[i] = data[i - 1];
    data[pos - 1] = p;
    return true;
}

//删除顺序表头数据
template<class T>
void SeqList<T>::pop_first() {
    if (isEmpty())        //空表直接返回
        return;
    for (int i = 0; i < last - 1; i++)       //从第2个数据开始全部前移一位
        data[i] = data[i + 1];
    last--;     //数据个数-1
}

//删除顺序表尾数据
template<class T>
void SeqList<T>::pop_last() {
    if (isEmpty())        //空表直接返回
        return;
    last--;     //数据个数-1
}

//删除顺序表第pos个数据
template<class T>
bool SeqList<T>::pop_pos(int pos) {
        if (pos > last || pos <= 0)      //不存在第pos个数据
        return false;

    for (int i = pos - 1; i < last - 1; i++)       //从第pos个数据开始全部前移一位
        data[i] = data[i + 1];

    last--;     //数据个数-1
    return true;
}

//修改顺序表头数据
template<class T>
void SeqList<T>::change_first(T p) {
    if (isEmpty())        //空表直接返回
        return;
    data[0] = p;
}

//修改顺序表尾数据
template<class T>
void SeqList<T>::change_last(T p) {
    if (isEmpty())        //空表直接返回
        return;
    data[last - 1] = p;
}

//修改顺序表第pos个数据
template<class T>
bool SeqList<T>::change_pos(int pos, T p) {
    if (pos > last || pos <= 0)      //不存在第pos个数据
        return false;
    data[pos - 1] = p;
    return true;
}

//得到顺序表头数据
template<class T>
bool SeqList<T>::get_first(T &p) {
    if (isEmpty())        //空表直接返回
        return false;
    p = data[0];
    return true;
}

//得到顺序表尾数据
template<class T>
bool SeqList<T>::get_last(T &p) {
    if (isEmpty())        //空表直接返回
        return false;
    p = data[last - 1];
    return true;
}

//得到顺序表第pos个数据
template<class T>
bool SeqList<T>::get_pos(int pos, T &p) {
    if (pos > last || pos <= 0)      //不存在第pos个数据
        return false;
    p = data[pos - 1];
    return true;
}

//返回顺序表中p相同的第一个元素的下标pos，若不存在则返回-1
template<class T>
int SeqList<T>::search(T p) {
    for (int i = 0; i < last; i++) {
        if (data[i] == p)       //与p相同的第一个元素的下标pos
            return i;
    }

    return -1;      //不存在则返回-1
}

//判断顺序表是否为空
template<class T>
bool SeqList<T>::isEmpty() {
    return last == 0;
}

//返回顺序表能存储的最大数据量
template<class T>
int SeqList<T>::size() {
    return maxSize;
}

//返回顺序表的长度
template<class T>
int SeqList<T>::length() {
    return last;
}

//打印顺序表
template<class T>
void SeqList<T>::print() {
    if (isEmpty())        //空表直接返回
        return;
    cout << "线性表数据为： ";
    for (int i = 0; i < last - 1; i++)
        cout << data[i] << " ----> ";
    cout << data[last - 1] << endl;
}

//清空顺序表
template<class T>
void SeqList<T>::clear() {
    delete data;
    maxSize = 50;
    last = 0;
    data = new T[maxSize];
}

//摧毁顺序表
template<class T>
void SeqList<T>::delete_link() {
    delete data;
}

#endif //MY_DS_SEQLIST_H
