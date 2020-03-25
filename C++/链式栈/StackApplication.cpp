/*
        @作者:        cloudYun
        @文件:        StackApplication
        @时间:        2020/3/9 10:07
        @描述:        栈的应用：主要包括（1）进制的转换；（2）括号的匹配；（3）简单表达式求值。分别用三个函数实现
*/

#include <iostream>
#include <stack>

using namespace std;

//菜单
void menu() {
    cout << "\t╔═══╤═════════════════╗" << endl;
    cout << "\t║ 1 │     进制的转换   ║" << endl;
    cout << "\t╟───┼─────────────────╢" << endl;
    cout << "\t║ 2 │     括号的匹配   ║" << endl;
    cout << "\t╟───┼─────────────────╢" << endl;
    cout << "\t║ 3 │     表达式求值   ║" << endl;
    cout << "\t╟───┼─────────────────╢" << endl;
    cout << "\t║ 0 │     退出该程序   ║" << endl;
    cout << "\t╚═══╧═════════════════╝" << endl;
}

//进制转化
void BinaryConversion(int num, int transform) {
    char Letter[26];
    for (int i = 0; i < 26; i++)
        Letter[i] = 'A' + i;
    stack<int> Binary;

    //计算转化结构
    while (num) {
        Binary.push(num % transform);
        num /= transform;
    }

    //输出结果
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

//括号匹配
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

//优先级判断
int priori(char c) {
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

/*
 * 判断是数字还是操作符
 * 数字返回：true
 * 操作符返回：false
*/
bool is_num(char c) {
    return !(c == '+' || c == '-' || c == '*' || c == '/');
}

/*
 * c:操作符
 * num1,num2:操作数
 * 返回的是num2 c num1 的值
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

//简单表达式求值
void ExpressionEvaluation(string str) {
    stack<char> operate;
    stack<double> num;
    int len = str.length();

    int n = 0;
    for (int i = 0; i < len; i++) {
        //为数字时
        if (is_num(str[i])) {
            n = 10 * n + str[i] - '0';
            if (!is_num(str[i + 1]) || str[i + 1] == '\0') {
                num.push(n);
                n = 0;
            }
        }
        //为操作符时
        else {
            //操作符栈非空
            if (!operate.empty()) {
                char temp = operate.top();
                //栈顶操作符优先级大
                if (priori(temp) >= priori(str[i])) {
                    //取数据
                    double n1 = num.top();
                    num.pop();
                    double n2 = num.top();
                    num.pop();
                    //运算并进数字栈
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
    //进制转化所用变量
    int num;             //待转化数
    int transform;       //进制
    //括号匹配所用变量
    char c;              //匹配的括号类型
    string str;          //带匹配字符串
    //表达式求值所用变量
    string str2;         //输入的表达式
    switch (sel) {
        case 0:
            cout << "\t程序退出" << endl;
            break;
        case 1:
            cout << "\t进制的转换" << endl;
            cout << "输入转化的数：";
            cin >> num;
            cout << "请输入将十进制数转化为多少进制（1~16进制）：";
            cin >> transform;
            BinaryConversion(num, transform);
            break;
        case 2:
            cout << "\t括号的匹配" << endl;
            cout << "请输入匹配的括号类型'('、'{'或者'[': ";
            cin >> c;
            cout << "请输入带匹配字符串: ";
            cin >> str;
            if (ParenthesisMatching(c, str))
                cout << "括号是匹配的" << endl;
            else
                cout << "括号不匹配" << endl;
            break;
        case 3:
            cout << "\t简单表达式求值" << endl;
            cout << "请输入表达式(没有括号，只有加减乘除的整数计算，中间无空格等多余符号，如：36+26*6-6/3): ";
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
        cout << "选择功能：";
        cin >> sel;
        Realization(sel);
        cout << endl;
        if (sel == 0)
            break;
    }

    return 0;
}