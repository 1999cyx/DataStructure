/*
        @����:        CYX
        @�ļ�:        main.cpp
        @ʱ��:        2020/2/10 9:54
*/

#include <iostream>
#include "LinkList.h"

using namespace std;

LinkList<int> myList;

void menu() {
    cout << "\t*****************************************************" << endl;
    cout << "\t*     1.ͷ�巨��������        2.β�巢��������         *" << endl;
    cout << "\t*     3.����x�����������     4.����xǰ���������       *" << endl;
    cout << "\t*     5.ɾ����ͷ����          6.ɾ����β����           *" << endl;
    cout << "\t*     7.ɾ���ض�����          8.ɾ�����е�pos������    *" << endl;
    cout << "\t*     9.�����ͷ����         10.�����β����           *" << endl;
    cout << "\t*    11.������е�pos������                           *" << endl;
    cout << "\t*    12.�޸ı�ͷ����         13.�޸ı�β����           *" << endl;
    cout << "\t*    14.�޸��ض�����         15.�޸ı��е�pos������    *" << endl;
    cout << "\t*    16.�õ�����           17.��ӡ��������           *" << endl;
    cout << "\t*     0.�˳�����                                     *" << endl;
    cout << "\t*****************************************************" << endl;
}

//���뺯��
template<class T>
void input(const string &str, T &x) {
    cout << "������" << str;
    //cout<<"Please input"<<str<<"data: ";
    cin >> x;
}

void Realization(int sel) {
    int data;      //�����롢ɾ����������޸ĺ������
    int x;         //���롢�޸�ǰ������
    int pos;       //�����롢ɾ�����޸ĵ�λ��
    switch (sel) {
        case 0:
            cout << "\t�����˳�" << endl;
            break;
        case 1:
            cout << "\tͷ�巨��������" << endl;
            input("����������ݣ�", data);
            myList.push_first(data);
            break;
        case 2:
            cout << "\tβ�巢��������" << endl;
            input("����������ݣ�", data);
            myList.push_last(data);
            break;
        case 3:
            cout << "\t����x�����������" << endl;
            input("����x��", x);
            input("����������ݣ�", data);
            if (!myList.push_node_next(x, data))
                cout << "����ʧ��" << endl;
            break;
        case 4:
            cout << "\t����xǰ���������" << endl;
            input("����x��", x);
            input("����������ݣ�", data);
            if (!myList.push_node_prev(x, data))
                cout << "����ʧ��" << endl;
            break;
        case 5:
            cout << "\tɾ����ͷ����" << endl;
            myList.pop_first();
            break;
        case 6:
            cout << "\tɾ����β����" << endl;
            myList.pop_last();
            break;
        case 7:
            cout << "\tɾ���ض�����" << endl;
            input("��ɾ�����ݣ�", data);
            if (!myList.pop_node_data(data))
                cout << "ɾ��ʧ��" << endl;
            break;
        case 8:
            cout << "\tɾ�����е�pos������" << endl;
            input("��ɾ�����ݵ�λ�ã�", pos);
            if (!myList.pop_node_cur(pos))
                cout << "ɾ��ʧ��" << endl;
            break;
        case 9:
            cout << "\t�����ͷ����" << endl;
            if (myList.get_first_data(data))
                cout << "��ͷ���ݣ�" << data << endl;
            break;
        case 10:
            cout << "\t�����β����" << endl;
            if (myList.get_last_data(data))
                cout << "��ͷ���ݣ�" << data << endl;
            break;
        case 11:
            cout << "\t������е�pos������" << endl;
            input("���������λ�ã�", pos);
            if (myList.get_data(data, pos))
                cout << "���е�pos�����ݣ�" << data << endl;
            break;
        case 12:
            cout << "\t�޸ı�ͷ����" << endl;
            input("�޸ĺ�����ݣ�", data);
            myList.change_first_data(data);
            break;
        case 13:
            cout << "\t�޸ı�β����" << endl;
            input("�޸ĺ�����ݣ�", data);
            myList.change_last_data(data);
            break;
        case 14:
            cout << "\t�޸��ض�����" << endl;
            input("���޸ĵ����ݣ�", x);
            input("�޸ĺ�����ݣ�", data);
            if (!myList.change_node_data(x, data))
                cout << "�޸�ʧ��" << endl;
            break;
        case 15:
            cout << "\t�޸ı��е�pos������" << endl;
            input("��Ҫ�޸����ݵ�λ�ã�", pos);
            input("�޸ĺ�����ݣ�", data);
            if (!myList.change_node_cur(data, pos))
                cout << "�޸�ʧ��" << endl;
            break;
        case 16:
            cout << "\t�õ�����" << endl;
            cout << "����" << myList.length() << endl;
            break;
        case 17:
            cout << "\t��ӡ��������" << endl;
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
        cout << "ѡ���ܣ�";
        cin >> sel;
        Realization(sel);
        if (sel == 0)
            break;
    }

    return 0;
}