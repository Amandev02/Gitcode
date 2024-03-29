//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // if first Node is NULL return other Node
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    //head1 should be small 
    if(head1->data > head2->data) swap(head1,head2);
     
     //Head of the initial Node 
     Node* res = head1;
     
    while(head1!=NULL && head2!=NULL){
        //temp  refer to prev node to the current node
        Node* temp = NULL;
        
        while(head1!=NULL && head1->data <= head2->data){
            temp = head1;
            head1 = head1->next;
        }
        //if we encounter a smaller element we break the bond 
        //and connect it to head2 and swap h1 & h2
        
        temp->next = head2;
        swap(head1,head2);
        
    }
    //return head to initial node
    return res;
}  