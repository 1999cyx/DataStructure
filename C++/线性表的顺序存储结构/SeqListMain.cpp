/*
        @作者:        CYX
        @文件:        main.cpp
        @时间:        2020/2/13 15:21
*/

#include <iostream>
#include "SeqList.h"

using namespace std;

SeqList<int> myList;

void menu() {
    cout << "\t*****************************************************" << endl;
    cout << "\t*     1.头插法插入数据        2.尾插发插入数据         *" << endl;
    cout << "\t*     3.插入到第pos个位置                             *" << endl;
    cout << "\t*     4.删除表头数据          5.删除表尾数据           *" << endl;
    cout << "\t*     6.删除表中第pos个数据                           *" << endl;
    cout << "\t*     7.修改表头数据          8.修改表尾数据           *" << endl;
    cout << "\t*     9.修改表中第pos个数据                           *" << endl;
    cout << "\t*    10.输出表头数据         11.输出表尾数据           *" << endl;
    cout << "\t*    12.输出表中第pos个数据                           *" << endl;
    cout << "\t*    13.查找数据             14.得到表的最大容量       *" << endl;
    cout << "\t*    15.得到表长度           16.打印表中数据           *" << endl;
    cout << "\t*     0.退出程序                                     *" << endl;
    cout << "\t*****************************************************" << endl;
}

//输入函数
template<class T>
void input(const string &str, T &x) {
    cout << "请输入" << str;
    //cout<<"Please input"<<str<<"data: ";
    cin >> x;
}

void Realization(int sel) {
    int data;      //待插入、删除、输出或修改后的数据
    int x;         //插入、修改前的数据
    int pos;       //待插入、删除或修改的位置
    switch (sel) {
        case 0:
            cout << "\t程序退出" << endl;
            break;
        case 1:
            cout << "\t头插法插入数据" << endl;
            input("待插入的数据：", data);
            myList.push_first(data);
            break;
        case 2:
            cout << "\t尾插发插入数据" << endl;
            input("待插入的数据：", data);
            myList.push_last(data);
            break;
        case 3:
            cout << "\t插入到第pos个位置" << endl;
            input("位置pos：", x);
            input("待插入的数据：", data);
            if (!myList.push_pos(x, data))
                cout << "插入失败" << endl;
            break;
        case 4:
            cout << "\t删除表头数据" << endl;
            myList.pop_first();
            break;
        case 5:
            cout << "\t删除表尾数据" << endl;
            myList.pop_last();
            break;
        case 6:
            cout << "\t删除表中第pos个数据" << endl;
            input("待删除数据位置pos：", data);
            if (!myList.pop_pos(data))
                cout << "删除失败" << endl;
            break;
        case 7:
            cout << "\t修改表头数据" << endl;
            input("修改后的数据：", data);
            myList.change_first(data);
            break;
        case 8:
            cout << "\t修改表尾数据" << endl;
            input("修改后的数据：", data);
            myList.change_last(data);
            break;
        case 9:
            cout << "\t修改表中第pos个数据" << endl;
            input("位置pos：", pos);
            input("修改后的数据：", data);
            if (!myList.change_pos(pos, data))
                cout << "修改失败" << endl;
            break;
        case 10:
            cout << "\t输出表头数据" << endl;
            if (myList.get_first(data))
                cout << "表头数据：" << data << endl;
            break;
        case 11:
            cout << "\t输出表尾数据" << endl;
            if (myList.get_last(data))
                cout << "表头数据：" << data << endl;
            break;
        case 12:
            cout << "\t输出表中第pos个数据" << endl;
            input("待输出数据位置：", pos);
            if (myList.get_pos(pos, data))
                cout << "表中第pos个数据：" << data << endl;
            break;
        case 13: {
            cout << "\t查找数据" << endl;
            input("待查找数据：", data);
            int is = myList.search(data);
            if (is == -1)
                cout << "查找失败" << endl;
            else
                cout << "查找数据的下标为：" << is << endl;
            break;
        }
        case 14:
            cout << "\t得到表的最大容量" << endl;
            cout << "最大容量：" << myList.size() << endl;
            break;
        case 15:
            cout << "\t得到表长度" << endl;
            cout << "表长：" << myList.length() << endl;
            break;
        case 16:
            cout << "\t打印表中数据" << endl;
            myList.print();
            cout << endl;
            break;
        default:
            break;
    }
}

int main() {
    int sel;
    while (true) {
        menu();
        cout << "选择功能：";
        cin >> sel;
        Realization(sel);
        cout<<endl;
        if (sel == 0)
            break;
    }

    return 0;
}