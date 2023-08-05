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
    
    public:
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* newFirst = reverse(first);
        Node* newSec = reverse(second);
        Node* final = NULL;
        Node* head = final;
        int carry = 0;
        while(newFirst!=NULL || newSec!=NULL||carry){
            int ans = 0;
            
            if(newFirst){ 
                ans += newFirst->data;
                newFirst = newFirst->next;
                
            }
            if(newSec){
                ans+= newSec->data;
                newSec = newSec->next;
            }
            
            ans += carry;
             carry = ans/10;
            Node* tmp = new Node(ans%10);
            tmp->next = head;
            head = tmp;
            
           
        }
        return head;
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