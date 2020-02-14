/*
        @作者:        CYX
        @文件:        main.cpp
        @时间:        2020/2/10 9:54
*/

#include <iostream>
#include "LinkList.h"

using namespace std;

LinkList<int> myList;

void menu() {
    cout << "\t*****************************************************" << endl;
    cout << "\t*     1.头插法插入数据        2.尾插发插入数据         *" << endl;
    cout << "\t*     3.数据x后面插入数据     4.数据x前面插入数据       *" << endl;
    cout << "\t*     5.删除表头数据          6.删除表尾数据           *" << endl;
    cout << "\t*     7.删除特定数据          8.删除表中第pos个数据    *" << endl;
    cout << "\t*     9.输出表头数据         10.输出表尾数据           *" << endl;
    cout << "\t*    11.输出表中第pos个数据                           *" << endl;
    cout << "\t*    12.修改表头数据         13.修改表尾数据           *" << endl;
    cout << "\t*    14.修改特定数据         15.修改表中第pos个数据    *" << endl;
    cout << "\t*    16.得到表长度           17.打印表中数据           *" << endl;
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
            cout << "\t数据x后面插入数据" << endl;
            input("数据x：", x);
            input("待插入的数据：", data);
            if (!myList.push_node_next(x, data))
                cout << "插入失败" << endl;
            break;
        case 4:
            cout << "\t数据x前面插入数据" << endl;
            input("数据x：", x);
            input("待插入的数据：", data);
            if (!myList.push_node_prev(x, data))
                cout << "插入失败" << endl;
            break;
        case 5:
            cout << "\t删除表头数据" << endl;
            myList.pop_first();
            break;
        case 6:
            cout << "\t删除表尾数据" << endl;
            myList.pop_last();
            break;
        case 7:
            cout << "\t删除特定数据" << endl;
            input("待删除数据：", data);
            if (!myList.pop_node_data(data))
                cout << "删除失败" << endl;
            break;
        case 8:
            cout << "\t删除表中第pos个数据" << endl;
            input("待删除数据的位置：", pos);
            if (!myList.pop_node_cur(pos))
                cout << "删除失败" << endl;
            break;
        case 9:
            cout << "\t输出表头数据" << endl;
            if (myList.get_first_data(data))
                cout << "表头数据：" << data << endl;
            break;
        case 10:
            cout << "\t输出表尾数据" << endl;
            if (myList.get_last_data(data))
                cout << "表头数据：" << data << endl;
            break;
        case 11:
            cout << "\t输出表中第pos个数据" << endl;
            input("待输出数据位置：", pos);
            if (myList.get_data(data, pos))
                cout << "表中第pos个数据：" << data << endl;
            break;
        case 12:
            cout << "\t修改表头数据" << endl;
            input("修改后的数据：", data);
            myList.change_first_data(data);
            break;
        case 13:
            cout << "\t修改表尾数据" << endl;
            input("修改后的数据：", data);
            myList.change_last_data(data);
            break;
        case 14:
            cout << "\t修改特定数据" << endl;
            input("待修改的数据：", x);
            input("修改后的数据：", data);
            if (!myList.change_node_data(x, data))
                cout << "修改失败" << endl;
            break;
        case 15:
            cout << "\t修改表中第pos个数据" << endl;
            input("需要修改数据的位置：", pos);
            input("修改后的数据：", data);
            if (!myList.change_node_cur(data, pos))
                cout << "修改失败" << endl;
            break;
        case 16:
            cout << "\t得到表长度" << endl;
            cout << "表长：" << myList.length() << endl;
            break;
        case 17:
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
        if (sel == 0)
            break;
    }

    return 0;
}