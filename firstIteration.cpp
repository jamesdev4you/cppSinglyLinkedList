// I am going to try an create a bank statement.

#include <iostream>


using namespace std;

//Nodes are little gobbers.
class Node
{
    public:
        int data;
        Node* next;
        Node(int data){
            //New Node(8)
            //THIS node has data from INPUT!
            this->data=data;
            //THIS node has NULL point!
            this->next = nullptr;
        }
};

//Printed Goobers.
void PrintNodes(Node* head, int balence){
    Node* temp;
    temp = head;
    while(temp != nullptr){

        cout << "$" << abs(temp->data); 
        balence = balence + temp->data;
        if(temp->data >= 0 ){
            cout << " Has been added to your account."
            << " Your currend balance is: " << balence;
           
        }else{
            cout << " Has been removed from your account." 
            << " Your currend balance is: $" << balence;
            
        }

        head = head->next;

        if(temp->next != nullptr){
            cout << "\n";
        }

        temp = head;

    }
};

int main(){
    Node* head = new Node(-800);
    head->next = new Node(-100);
    head->next->next = new Node(-2000);
    PrintNodes(head, 5000);
    return 0;
};



