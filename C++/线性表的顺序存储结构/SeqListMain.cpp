/*
        @����:        CYX
        @�ļ�:        main.cpp
        @ʱ��:        2020/2/13 15:21
*/

#include <iostream>
#include "SeqList.h"

using namespace std;

SeqList<int> myList;

void menu() {
    cout << "\t*****************************************************" << endl;
    cout << "\t*     1.ͷ�巨��������        2.β�巢��������         *" << endl;
    cout << "\t*     3.���뵽��pos��λ��                             *" << endl;
    cout << "\t*     4.ɾ����ͷ����          5.ɾ����β����           *" << endl;
    cout << "\t*     6.ɾ�����е�pos������                           *" << endl;
    cout << "\t*     7.�޸ı�ͷ����          8.�޸ı�β����           *" << endl;
    cout << "\t*     9.�޸ı��е�pos������                           *" << endl;
    cout << "\t*    10.�����ͷ����         11.�����β����           *" << endl;
    cout << "\t*    12.������е�pos������                           *" << endl;
    cout << "\t*    13.��������             14.�õ�����������       *" << endl;
    cout << "\t*    15.�õ�����           16.��ӡ��������           *" << endl;
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
            cout << "\t���뵽��pos��λ��" << endl;
            input("λ��pos��", x);
            input("����������ݣ�", data);
            if (!myList.push_pos(x, data))
                cout << "����ʧ��" << endl;
            break;
        case 4:
            cout << "\tɾ����ͷ����" << endl;
            myList.pop_first();
            break;
        case 5:
            cout << "\tɾ����β����" << endl;
            myList.pop_last();
            break;
        case 6:
            cout << "\tɾ�����е�pos������" << endl;
            input("��ɾ������λ��pos��", data);
            if (!myList.pop_pos(data))
                cout << "ɾ��ʧ��" << endl;
            break;
        case 7:
            cout << "\t�޸ı�ͷ����" << endl;
            input("�޸ĺ�����ݣ�", data);
            myList.change_first(data);
            break;
        case 8:
            cout << "\t�޸ı�β����" << endl;
            input("�޸ĺ�����ݣ�", data);
            myList.change_last(data);
            break;
        case 9:
            cout << "\t�޸ı��е�pos������" << endl;
            input("λ��pos��", pos);
            input("�޸ĺ�����ݣ�", data);
            if (!myList.change_pos(pos, data))
                cout << "�޸�ʧ��" << endl;
            break;
        case 10:
            cout << "\t�����ͷ����" << endl;
            if (myList.get_first(data))
                cout << "��ͷ���ݣ�" << data << endl;
            break;
        case 11:
            cout << "\t�����β����" << endl;
            if (myList.get_last(data))
                cout << "��ͷ���ݣ�" << data << endl;
            break;
        case 12:
            cout << "\t������е�pos������" << endl;
            input("���������λ�ã�", pos);
            if (myList.get_pos(pos, data))
                cout << "���е�pos�����ݣ�" << data << endl;
            break;
        case 13: {
            cout << "\t��������" << endl;
            input("���������ݣ�", data);
            int is = myList.search(data);
            if (is == -1)
                cout << "����ʧ��" << endl;
            else
                cout << "�������ݵ��±�Ϊ��" << is << endl;
            break;
        }
        case 14:
            cout << "\t�õ�����������" << endl;
            cout << "���������" << myList.size() << endl;
            break;
        case 15:
            cout << "\t�õ�����" << endl;
            cout << "����" << myList.length() << endl;
            break;
        case 16:
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
        cout<<endl;
        if (sel == 0)
            break;
    }

    return 0;
}