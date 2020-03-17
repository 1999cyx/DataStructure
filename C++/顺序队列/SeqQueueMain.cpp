/*
        @����:        cloudYun
        @�ļ�:        SeqQueueMain
        @ʱ��:        2020/3/17 8:21
        @����:        
        @������:      Clion
*/

#include <iostream>
#include "SeqQueue.h"

using namespace std;

SeqQueue<int> myQueue;

//�˵�
void menu() {
    cout << "\t�X�T�T�T�h�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
    cout << "\t�U 1 ��     Ԫ�ؽ�����   �U" << endl;
    cout << "\t�c�������੤���������������������������������f" << endl;
    cout << "\t�U 2 ��     Ԫ�س�����   �U" << endl;
    cout << "\t�c�������੤���������������������������������f" << endl;
    cout << "\t�U 3 ��     ���ض�����   �U" << endl;
    cout << "\t�c�������੤���������������������������������f" << endl;
    cout << "\t�U 4 ��     ���еĳ���   �U" << endl;
    cout << "\t�c�������੤���������������������������������f" << endl;
    cout << "\t�U 5 ��     �ж϶��п�   �U" << endl;
    cout << "\t�c�������੤���������������������������������f" << endl;
    cout << "\t�U 6 ��     ��ӡ�ö���   �U" << endl;
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
    int data;    //������Ԫ�ػ�ȡ���ж�Ԫ��
    switch (sel) {
        case 0:
            cout << "\t�����˳�" << endl;
            break;
        case 1:
            cout << "\tԪ�ؽ�����" << endl;
            input("�����е����ݣ�", data);
            myQueue.push(data);
            break;
        case 2:
            cout << "\tԪ�س�����" << endl;
            myQueue.pop();
            break;
        case 3:
            cout << "\t���ض�����" << endl;
            if (myQueue.front(data))
                cout << "������Ԫ��Ϊ��" << data << endl;
            else
                cout << "����Ϊ�գ��޶�����Ԫ��" << endl;
            break;
        case 4:
            cout << "\t���еĳ���" << endl;
            cout << "���еĳ���Ϊ��" << myQueue.size() << endl;
            break;
        case 5:
            cout << "\t�ж϶����Ƿ�Ϊ��" << endl;
            if (myQueue.isEmpty())
                cout << "����Ϊ��" << endl;
            else
                cout << "ջ��Ϊ��" << endl;
            break;
        case 6:
            cout << "\t��ӡ˳�����" << endl;
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
        cout << "ѡ���ܣ�";
        cin >> sel;
        Realization(sel);
        cout << endl;
        if (sel == 0)
            break;
    }

    return 0;
}