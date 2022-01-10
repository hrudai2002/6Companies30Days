/* 

Problem - https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=dbedccfc91f872448aba76c66d3ed59d&pid=700021&user=sayihrudai

*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}

 // } Driver Code Ends
/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
    int size(struct Node *head) {
        int c = 0;
        while(head) {
            c += 1; 
            head = head->next;
        }
        return c;
    }
    void linkdelete(struct Node  *head, int M, int N)
    {
        if(M == 0) {
            struct Node* temp = head;
            for(int i = 1; temp != NULL && i <= N; ++i) 
                temp = temp->next; 
            head = temp;
            return;
        }
        int n = size(head);
        
        struct Node* temp = head;
        struct Node* prev;
        int c = 0;
        for(int i = 1; temp != NULL && i <= n; ++i) {
            prev = temp;
            temp = temp->next;
            c += 1;
            
            if(c == M) {
                c = 0;
                for(int i = 1; temp != NULL && i <= N; ++i) 
                temp = temp->next; 
                prev->next = temp;
            }
        }
    }
};



// { Driver Code Starts.
int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}
  // } Driver Code Ends
