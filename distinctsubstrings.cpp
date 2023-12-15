#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    bool containskey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
};

int countDistinctSubstrings(string &word)
{
    //    Write your code here.
    Node *root = new Node();
    int cnt = 0;
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
        Node *node = root;
        for (int j = i; j < n; j++)
        {
            if (!node->containskey(word[j]))
            {
                cnt++;
                node->put(word[j], new Node());
            }
            node = node->get(word[j]);
        }
    }
    return cnt + 1;
}
int main()
{

    return 0;
}