/*
        @作者:        cloudYun
        @文件:        SeqQueueMain
        @时间:        2020/3/17 8:21
        @描述:        
        @编译器:      Clion
*/

#include <iostream>
#include "SeqQueue.h"

using namespace std;

SeqQueue<int> myQueue;

//菜单
void menu() {
    cout << "\t╔═══╤═════════════════╗" << endl;
    cout << "\t║ 1 │     元素进队列   ║" << endl;
    cout << "\t╟───┼─────────────────╢" << endl;
    cout << "\t║ 2 │     元素出队列   ║" << endl;
    cout << "\t╟───┼─────────────────╢" << endl;
    cout << "\t║ 3 │     返回队列首   ║" << endl;
    cout << "\t╟───┼─────────────────╢" << endl;
    cout << "\t║ 4 │     队列的长度   ║" << endl;
    cout << "\t╟───┼─────────────────╢" << endl;
    cout << "\t║ 5 │     判断队列空   ║" << endl;
    cout << "\t╟───┼─────────────────╢" << endl;
    cout << "\t║ 6 │     打印该队列   ║" << endl;
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
    int data;    //进队列元素或取队列顶元素
    switch (sel) {
        case 0:
            cout << "\t程序退出" << endl;
            break;
        case 1:
            cout << "\t元素进队列" << endl;
            input("进队列的数据：", data);
            myQueue.push(data);
            break;
        case 2:
            cout << "\t元素出队列" << endl;
            myQueue.pop();
            break;
        case 3:
            cout << "\t返回队列首" << endl;
            if (myQueue.front(data))
                cout << "队列首元素为：" << data << endl;
            else
                cout << "队列为空，无队列首元素" << endl;
            break;
        case 4:
            cout << "\t队列的长度" << endl;
            cout << "队列的长度为：" << myQueue.size() << endl;
            break;
        case 5:
            cout << "\t判断队列是否为空" << endl;
            if (myQueue.isEmpty())
                cout << "队列为空" << endl;
            else
                cout << "栈不为空" << endl;
            break;
        case 6:
            cout << "\t打印顺序队列" << endl;
            myQueue.print();
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