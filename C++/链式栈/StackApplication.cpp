/*
        @����:        cloudYun
        @�ļ�:        StackApplication
        @ʱ��:        2020/3/9 10:07
        @����:        ջ��Ӧ�ã���Ҫ������1�����Ƶ�ת������2�����ŵ�ƥ�䣻��3���򵥱��ʽ��ֵ���ֱ�����������ʵ��
*/

#include <iostream>
#include <stack>

using namespace std;

//�˵�
void menu() {
    cout << "\t�X�T�T�T�h�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
    cout << "\t�U 1 ��     ���Ƶ�ת��   �U" << endl;
    cout << "\t�c�������੤���������������������������������f" << endl;
    cout << "\t�U 2 ��     ���ŵ�ƥ��   �U" << endl;
    cout << "\t�c�������੤���������������������������������f" << endl;
    cout << "\t�U 3 ��     ���ʽ��ֵ   �U" << endl;
    cout << "\t�c�������੤���������������������������������f" << endl;
    cout << "\t�U 0 ��     �˳��ó���   �U" << endl;
    cout << "\t�^�T�T�T�k�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
}

//����ת��
void BinaryConversion(int num, int transform) {
    char Letter[26];
    for (int i = 0; i < 26; i++)
        Letter[i] = 'A' + i;
    stack<int> Binary;

    //����ת���ṹ
    while (num) {
        Binary.push(num % transform);
        num /= transform;
    }

    //������
    int len = Binary.size();
    for (int i = 0; i < len && Binary.empty(); i++) {
        int p = Binary.top();
        if (p < 10)
            cout << p;
        else
            cout << Letter[p - 10];
        Binary.pop();
    }
}

//����ƥ��
bool ParenthesisMatching(char c, string str) {
    char c0;
    if (c == '(')
        c0 = ')';
    else if (c == '{')
        c0 = '}';
    else
        c0 = ']';

    stack<char> Matching;

    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] == c)
            Matching.push(c);
        if (str[i] == c0) {
            if (!Matching.empty())
                return false;
            else
                Matching.pop();
        }
    }
    return !Matching.empty();
}

//���ȼ��ж�
int priori(char c) {
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

/*
 * �ж������ֻ��ǲ�����
 * ���ַ��أ�true
 * ���������أ�false
*/
bool is_num(char c) {
    return !(c == '+' || c == '-' || c == '*' || c == '/');
}

/*
 * c:������
 * num1,num2:������
 * ���ص���num2 c num1 ��ֵ
*/
double calculation(char c, double num2, double num1) {
    if (c == '*')
        return num2 * num1;
    if (c == '/')
        return num2 / num1;
    if (c == '+')
        return num2 + num1;
    if (c == '-')
        return num2 - num1;
    return 0;
}

//�򵥱��ʽ��ֵ
void ExpressionEvaluation(string str) {
    stack<char> operate;
    stack<double> num;
    int len = str.length();

    int n = 0;
    for (int i = 0; i < len; i++) {
        //Ϊ����ʱ
        if (is_num(str[i])) {
            n = 10 * n + str[i] - '0';
            if (!is_num(str[i + 1]) || str[i + 1] == '\0') {
                num.push(n);
                n = 0;
            }
        }
        //Ϊ������ʱ
        else {
            //������ջ�ǿ�
            if (!operate.empty()) {
                char temp = operate.top();
                //ջ�����������ȼ���
                if (priori(temp) >= priori(str[i])) {
                    //ȡ����
                    double n1 = num.top();
                    num.pop();
                    double n2 = num.top();
                    num.pop();
                    //���㲢������ջ
                    num.push(calculation(temp, n2, n1));

                    operate.pop();
                    operate.push(str[i]);
                } else
                    operate.push(str[i]);
            } else
                operate.push(str[i]);
        }
    }
    while(!operate.empty()){
        char t=operate.top();operate.pop();
        double t1=num.top();num.pop();
        double t2=num.top();num.pop();
        num.push(calculation(t,t2,t1));
    }
    cout<<num.top()<<endl;
}

void Realization(int sel) {
    //����ת�����ñ���
    int num;             //��ת����
    int transform;       //����
    //����ƥ�����ñ���
    char c;              //ƥ�����������
    string str;          //��ƥ���ַ���
    //���ʽ��ֵ���ñ���
    string str2;         //����ı��ʽ
    switch (sel) {
        case 0:
            cout << "\t�����˳�" << endl;
            break;
        case 1:
            cout << "\t���Ƶ�ת��" << endl;
            cout << "����ת��������";
            cin >> num;
            cout << "�����뽫ʮ������ת��Ϊ���ٽ��ƣ�1~16���ƣ���";
            cin >> transform;
            BinaryConversion(num, transform);
            break;
        case 2:
            cout << "\t���ŵ�ƥ��" << endl;
            cout << "������ƥ�����������'('��'{'����'[': ";
            cin >> c;
            cout << "�������ƥ���ַ���: ";
            cin >> str;
            if (ParenthesisMatching(c, str))
                cout << "������ƥ���" << endl;
            else
                cout << "���Ų�ƥ��" << endl;
            break;
        case 3:
            cout << "\t�򵥱��ʽ��ֵ" << endl;
            cout << "��������ʽ(û�����ţ�ֻ�мӼ��˳����������㣬�м��޿ո�ȶ�����ţ��磺36+26*6-6/3): ";
            cin >> str2;
            ExpressionEvaluation(str2);
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