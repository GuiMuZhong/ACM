#include <bits/stdc++.h>
using namespace std;

const int maxnode = 1000;
const int sigma_size = 1000;

//��ĸ��Ϊȫ��Сд��ĸ
struct Trie
{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int sz;                         //�ڵ�����
    Trie(){sz = 1; memset(ch, 0, sizeof(ch[sz]));}    //��ʼʱֻ��һ�����ڵ�
    int idx(char c){return c - 'a';}    //�ַ�c�ı��

    //�����ַ���s��������Ϣv��ע��v�����0����Ϊ0�����ڵ㲻�ǵ��ʽڵ�
    void Insert(char* s, int v)
    {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i++){
            int c = idx(s[i]);
            if(!ch[u][c]){              //�ڵ㲻����
                memset(ch[sz], 0, sizeof(ch));
                val[sz] = 0;         //�м�ڵ�ĸ�����ϢΪ0
                ch[u][c] = sz++;            //�½��ڵ�
            }
            u = ch[u][c];           //������
        }
        val[u] = v;             //�ַ��������һ���ַ��ĸ�����ϢΪ0
    }

    //�����ַ���s���������һ���ַ�λ�ã������ڷ���-1��
    int Find(char* s)
    {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i++){
            int c = idx(s[i]);
            if(!ch[u][c]) return -1;
            u = ch[u][c];
        }
        return u;
    }
};
