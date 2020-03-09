/*
        @作者:        cloudYun
        @文件:        LinkStackMain
        @时间:        2020/3/9 9:45
*/

#include <iostream>
#include "LinkStack.h"

using namespace std;

LinkStack<int> myStack;

//菜单
void menu() {
    cout << "\t╔═══╤═════════════════╗" << endl;
    cout << "\t║ 1 │     元素进栈     ║" << endl;
    cout << "\t╟───┼─────────────────╢" << endl;
    cout << "\t║ 2 │     元素出栈     ║" << endl;
    cout << "\t╟───┼─────────────────╢" << endl;
    cout << "\t║ 3 │     取栈顶元素   ║" << endl;
    cout << "\t╟───┼─────────────────╢" << endl;
    cout << "\t║ 4 │     计算栈长度   ║" << endl;
    cout << "\t╟───┼─────────────────╢" << endl;
    cout << "\t║ 5 │     判断栈为空   ║" << endl;
    cout << "\t╟───┼─────────────────╢" << endl;
    cout << "\t║ 6 │     打印顺序栈   ║" << endl;
    cout << "\t╟───┼─────────────────╢" << endl;
    cout << "\t║ 0 │     退出该程序   ║" << endl;
    cout << "\t╚═══╧═════════════════╝" << endl;
}

//输入函数
template<class T>
void input(const string &str, T &x) {
    cout << "请输入" << str;
    //cout<<"Please input"<<str<<"data: ";
    cin >> x;
}

void Realization(int sel) {
    int data;    //进栈元素或取栈顶元素
    switch (sel) {
        case 0:
            cout << "\t程序退出" << endl;
            break;
        case 1:
            cout << "\t元素进栈" << endl;
            input("进栈的数据：", data);
            myStack.push(data);
            break;
        case 2:
            cout << "\t元素出栈" << endl;
            myStack.pop();
            break;
        case 3:
            cout << "\t取栈顶元素" << endl;
            if (myStack.top(data))
                cout << "栈顶元素为：" << data << endl;
            else
                cout << "栈为空，栈顶元素" << endl;
            break;
        case 4:
            cout << "\t计算栈的长度" << endl;
            cout << "栈的长度为：" << myStack.size() << endl;
            break;
        case 5:
            cout << "\t判断栈是否为空" << endl;
            if (myStack.isEmpty())
                cout << "栈为空" << endl;
            else
                cout << "栈不为空" << endl;
            break;
        case 6:
            cout << "\t打印顺序栈" << endl;
            myStack.print();
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
        cout << endl;
        if (sel == 0)
            break;
    }

    return 0;
}