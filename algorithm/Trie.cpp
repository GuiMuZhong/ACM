#include <bits/stdc++.h>
using namespace std;

const int maxnode = 1000;
const int sigma_size = 1000;

//字母表为全体小写字母
struct Trie
{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int sz;                         //节点总数
    Trie(){sz = 1; memset(ch, 0, sizeof(ch[sz]));}    //初始时只有一个根节点
    int idx(char c){return c - 'a';}    //字符c的编号

    //插入字符串s，附加信息v。注意v必须非0，因为0代表本节点不是单词节点
    void Insert(char* s, int v)
    {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i++){
            int c = idx(s[i]);
            if(!ch[u][c]){              //节点不存在
                memset(ch[sz], 0, sizeof(ch));
                val[sz] = 0;         //中间节点的附加消息为0
                ch[u][c] = sz++;            //新建节点
            }
            u = ch[u][c];           //往下走
        }
        val[u] = v;             //字符串的最后一个字符的附加信息为0
    }

    //查找字符串s，返回最后一个字符位置，不存在返回-1。
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
