//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* head){
        
        if(head==NULL ||head->next==NULL) return head;
        struct Node* temp = head;
        struct Node* curr = head;
        struct Node* prev = NULL;
        
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* head1, struct Node* head2)
    {
        // code here
        struct Node* dummy = new Node(0);
        struct Node* temp = dummy;
        
        head1 = reverse(head1);
        head2 = reverse(head2);
        
         int carry = 0;
        while((head1!=NULL||head2!=NULL)||carry){
            int ans = 0;
            
            if(head1!=NULL) {
            ans += (head1->data);
            head1 = head1->next;
            
        }
        
        if(head2!=NULL) {
            ans += (head2->data);
            head2 = head2->next;
           
        }
        
           ans += carry; //carry can be 0
           carry = ans/10;
           struct Node* res = new Node(ans%10);
           temp->next = res;
           temp =  temp->next;
       
        }
        
       struct Node* result = reverse(dummy->next);
        return result;
         
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends