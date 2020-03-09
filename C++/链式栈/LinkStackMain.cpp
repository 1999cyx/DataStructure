/*
        @����:        cloudYun
        @�ļ�:        LinkStackMain
        @ʱ��:        2020/3/9 9:45
*/

#include <iostream>
#include "LinkStack.h"

using namespace std;

LinkStack<int> myStack;

//�˵�
void menu() {
    cout << "\t�X�T�T�T�h�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
    cout << "\t�U 1 ��     Ԫ�ؽ�ջ     �U" << endl;
    cout << "\t�c�������੤���������������������������������f" << endl;
    cout << "\t�U 2 ��     Ԫ�س�ջ     �U" << endl;
    cout << "\t�c�������੤���������������������������������f" << endl;
    cout << "\t�U 3 ��     ȡջ��Ԫ��   �U" << endl;
    cout << "\t�c�������੤���������������������������������f" << endl;
    cout << "\t�U 4 ��     ����ջ����   �U" << endl;
    cout << "\t�c�������੤���������������������������������f" << endl;
    cout << "\t�U 5 ��     �ж�ջΪ��   �U" << endl;
    cout << "\t�c�������੤���������������������������������f" << endl;
    cout << "\t�U 6 ��     ��ӡ˳��ջ   �U" << endl;
    cout << "\t�c�������੤���������������������������������f" << endl;
    cout << "\t�U 0 ��     �˳��ó���   �U" << endl;
    cout << "\t�^�T�T�T�k�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
}

//���뺯��
template<class T>
void input(const string &str, T &x) {
    cout << "������" << str;
    //cout<<"Please input"<<str<<"data: ";
    cin >> x;
}

void Realization(int sel) {
    int data;    //��ջԪ�ػ�ȡջ��Ԫ��
    switch (sel) {
        case 0:
            cout << "\t�����˳�" << endl;
            break;
        case 1:
            cout << "\tԪ�ؽ�ջ" << endl;
            input("��ջ�����ݣ�", data);
            myStack.push(data);
            break;
        case 2:
            cout << "\tԪ�س�ջ" << endl;
            myStack.pop();
            break;
        case 3:
            cout << "\tȡջ��Ԫ��" << endl;
            if (myStack.top(data))
                cout << "ջ��Ԫ��Ϊ��" << data << endl;
            else
                cout << "ջΪ�գ�ջ��Ԫ��" << endl;
            break;
        case 4:
            cout << "\t����ջ�ĳ���" << endl;
            cout << "ջ�ĳ���Ϊ��" << myStack.size() << endl;
            break;
        case 5:
            cout << "\t�ж�ջ�Ƿ�Ϊ��" << endl;
            if (myStack.isEmpty())
                cout << "ջΪ��" << endl;
            else
                cout << "ջ��Ϊ��" << endl;
            break;
        case 6:
            cout << "\t��ӡ˳��ջ" << endl;
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
        cout << "ѡ���ܣ�";
        cin >> sel;
        Realization(sel);
        cout << endl;
        if (sel == 0)
            break;
    }

    return 0;
}