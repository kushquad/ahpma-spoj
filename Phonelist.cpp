#include<iostream>
#include<algorithm>
#include<cstring>

#define NO_OF_DIGITS 10
using namespace std;

struct TrieNode
{
    int prefix;
    int word;
    TrieNode* child[NO_OF_DIGITS];
};

void initialize(TrieNode &temp)
{
    temp.prefix = 0;
    temp.word = 0;
    for(int i=0;i<NO_OF_DIGITS;i++)
        temp.child[i]=NULL;
}

bool addWord(TrieNode &temp, const char* word)
{
    if(temp.word>=1)
        return true;
    int len = strlen(word);
    if(len==0)
        temp.word++;
    else
    {
        temp.prefix++;
        int idx = (word[0]-'0') ;
        if(temp.child[idx]==NULL)
        {
            temp.child[idx] = (TrieNode*)malloc(sizeof(TrieNode));
            initialize(*temp.child[idx]);
        }
        return addWord(*temp.child[idx],word+1);
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int T,n;
    bool flag;   //Indicates if we have found a prefix match

    cin>>T;
    while(T--)
    {
        TrieNode trie;
        initialize(trie);
        flag = false;
        cin>>n;

        string str[n];
        for(int i=0;i<n;i++)
            cin>>str[i];
        sort(str,str+n);

        for(int i=0;i<n;i++)
        {
            flag = addWord(trie,str[i].c_str());
            if(flag)
                break;
        }

        if(flag)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}
