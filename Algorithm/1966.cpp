#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct node
{
    int data;
    int idx;
    struct node *next;
} Node;

Node *start = NULL;
void insert(int, int);

Node *createNode(int data, int idx)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = NULL;
    temp->data = data;
    temp->idx = idx;
    return temp;
}

// void addNode(Node **head, int data, int idx)
// {
//     Node *newNode = createNode(data, idx);

//     if (*head == NULL)
//     {
//         *head = newNode;
//     }
//     else
//     {
//         Node *temp = *head;
//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

int main()
{
    int T;
    int impt;
    cin >> T;
    int N, M;
    cin >> N >> M;
    int temp[2] = {0, 0};
    vector<int> printQ;

    Node *head = NULL;

    for (int i = 0; i < N; i++)
    {
        cin >> impt;
        insert(impt, i);
    }

    head = start;
    while (head->next != NULL)
    {
        printQ.push_back(head->idx);
        cout << head->idx << endl;
        head = head->next;
    }
    cout << printQ[M] << endl;

    return 0;
}

void insert(int data, int idx)
{
    Node *newnode, *cur;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->next = NULL;
    newnode->data = data;
    newnode->idx = idx;
    cur = start;
    if (start == NULL)
    {
        start = newnode;
        return;
    }
    else if (start->data < newnode->data)
    {
        newnode->next = start;
        start = newnode;
        return;
    }
    else
    {
        while (cur->next != NULL)
        {
            if (cur->next->data < newnode->data)
            {
                newnode->next = cur->next;
                cur->next = newnode;
                return;
            }
            cur = cur->next;
        }
    }
    cur->next = newnode;
}