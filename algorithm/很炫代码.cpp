#include <algorithm>
#include <iostream>
#include <iterator>
#include <deque>
#include <string>
#include <sstream>
using namespace std;
//主函数
int main(void) {
    //循环处理输入的每组字符串。每次循环一轮要输出最后的0和换行
    for (string strLine; getline(cin, strLine); cout << '0' << endl) {
        //按要求回应输入的字符串行
        cout << strLine << endl;

        //构造字符串流，以遍转换为数字
        istringstream iss(strLine);

        //将字符串转为数字，逆序(最底的在最前)存储在Stack里
        deque<int> Stack;
        for (int nDiam; iss >> nDiam; Stack.push_front(nDiam));


        //从底依次上向进行翻转，保持i上面的都比i小
        for (deque<int>::iterator i = Stack.begin(); i != Stack.end(); ++i) {

            //找出i上面(包括i)的最大元素
            deque<int>::iterator iMax = max_element(i, Stack.end());

            //如果最大元素就是i则继续(将i指向上面一个)
            if (iMax != i) { //否则要进行需翻转操作

                //如果最大的不在最上面，则需先翻转到最上面
                if (iMax != Stack.end() - 1) {
                    reverse(iMax, Stack.end());

                    //输出翻转的起点
                    cout << distance(Stack.begin(), iMax) + 1 << ' ';
                }

                //将最大的从最上面翻转到i的位置上
                reverse(i, Stack.end());

                //输出翻转的起点
                cout << distance(Stack.begin(), i) + 1 << ' ';
            }
        }
    }
    return 0;
}
