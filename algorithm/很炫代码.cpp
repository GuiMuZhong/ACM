#include <algorithm>
#include <iostream>
#include <iterator>
#include <deque>
#include <string>
#include <sstream>
using namespace std;
//������
int main(void) {
    //ѭ�����������ÿ���ַ�����ÿ��ѭ��һ��Ҫ�������0�ͻ���
    for (string strLine; getline(cin, strLine); cout << '0' << endl) {
        //��Ҫ���Ӧ������ַ�����
        cout << strLine << endl;

        //�����ַ��������Ա�ת��Ϊ����
        istringstream iss(strLine);

        //���ַ���תΪ���֣�����(��׵�����ǰ)�洢��Stack��
        deque<int> Stack;
        for (int nDiam; iss >> nDiam; Stack.push_front(nDiam));


        //�ӵ�����������з�ת������i����Ķ���iС
        for (deque<int>::iterator i = Stack.begin(); i != Stack.end(); ++i) {

            //�ҳ�i����(����i)�����Ԫ��
            deque<int>::iterator iMax = max_element(i, Stack.end());

            //������Ԫ�ؾ���i�����(��iָ������һ��)
            if (iMax != i) { //����Ҫ�����跭ת����

                //������Ĳ��������棬�����ȷ�ת��������
                if (iMax != Stack.end() - 1) {
                    reverse(iMax, Stack.end());

                    //�����ת�����
                    cout << distance(Stack.begin(), iMax) + 1 << ' ';
                }

                //�����Ĵ������淭ת��i��λ����
                reverse(i, Stack.end());

                //�����ת�����
                cout << distance(Stack.begin(), i) + 1 << ' ';
            }
        }
    }
    return 0;
}
