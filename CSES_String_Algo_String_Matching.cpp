#include<bits/stdc++.h>
using namespace std;
struct Node{

int countPrefix=0;
int countEnd=0;
Node* links[26];
bool isExist(char ch)
{
    return (links[ch-'a']!=NULL);
}
void createLink(char ch,Node* node)
{
    links[ch-'a']=node;

}
Node* next(char ch)
{
    return links[ch-'a'];
}

void increaseCountEnd()
{
    countEnd++;
}
void increaseCountPrefix()
{
    countPrefix++;
}
int getCountPrefix()
{
    return countPrefix;
}

};

class Trie{


public:
    Node* root;
    Trie()
    {
        root=new Node();
    }

    void insert(string s)
    {
        Node* node=root;
        for(int i=0;i<s.size();i++)
        {
            if(node->isExist(s[i])==false)
            {
                node->createLink(s[i],new Node());
            }
            node=node->next(s[i]);
            node->increaseCountPrefix();

        }
        node->increaseCountEnd();
    }

    int getAns(string s)
    {
        Node* node=root;
        for(int i=0;i<s.size();i++)
        {
            if(!node->isExist(s[i]))
            {
                return 0;
            }
            node=node->next(s[i]);
        }
        return node->getCountPrefix();
    }

};







int main()
{
  string s;
  string ss;
  cin>>s;
  cin>>ss;
  Trie* t=new Trie();
  for(int i=0;i<s.size();i++)
  {
      string temp="";
      temp=temp+s[i];
      t->insert(temp);

  }

  //int ans=t->getAns(ss);
  int ans=0;
  for(int i=0;i<ss.size();i++)
  {
      string temp="";
      temp=temp+ss[i];
      ans=ans+t->getAns(temp);
  }
  cout<<ans<<endl;
}

