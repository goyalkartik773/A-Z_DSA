#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Node
{
public:
    char character;
    int freq;
    Node *left;
    Node *right;
    Node(char character, int freq)
    {
        this->character = character;
        this->freq = freq;
        left = NULL;
        right = NULL;
    }
};
bool copa(pair<char, string> a, pair<char, string> b)
{
    return a.first < b.first;
}
class comp
{
public:
    bool operator()(Node *a, Node *b)
    {
        // heap mai comparator ka function ulta work karta hai as compare to normal comparator (bss comparison sign ulta hoga);
        return a->freq > b->freq;
    }
};

Node *huffmann_tree(vector<char> &chars, vector<int> &freqs)
{
    priority_queue<Node *, vector<Node *>, comp> pq; // min heap
    int n = freqs.size();
    // push all the nodes in the min heap
    // T.C --> O(nlogn)
    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node(chars[i], freqs[i]);
        pq.push(temp);
    }
    // start building the tree
    while (pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *root = new Node('$', left->freq + right->freq);
        root->left = left;
        root->right = right;
        pq.push(root);
    }
    Node *root = pq.top();
    pq.pop();
    return root;
}
void show_tree(Node *root, string code, vector<pair<char, string>> &ans)
{
    if (root->left == NULL && root->right == NULL)
    {
        // leaf Node
        ans.push_back({root->character, code});
        return;
    }
    show_tree(root->left, code + '0', ans);
    show_tree(root->right, code + '1', ans);
    return;
}
int main()
{
    // huffmann decoder is the text compressor it converts the large input file into small binary codded format such that the size of the file reduces
    vector<pair<char, string>> ans;
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    Node *root = huffmann_tree(chars, freq);
    show_tree(root, "", ans);
    sort(ans.begin(), ans.end(), copa);
    int size = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        char ch = ans[i].first;
        string str = ans[i].second;
        cout << ch << "->" << str << endl;
        size = size + freq[i] * str.size();
    }
    cout<<"size of input binary codded compress file is -> "<<size;
}