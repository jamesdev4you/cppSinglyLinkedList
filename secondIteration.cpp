#include <iostream>

using namespace std;

template <typename T1>
class bankStatement
{
    public: 
        string date;
        T1 description;
        string ref;
        int withdrawl = 0;
        int deposit = 0;
        int choice;

        //Constructor
        bankStatement(string inputDate, T1 inputDescription, string ref = "n/a"){
            cout << "Please press 1 for withdrawl, or 0 for deposit. \n";
            cin >> choice;
            date = inputDate;
            description = inputDescription;
            ref = ref;
            if(choice == 0){
                cout << "Enter deposit amount: ";
                cin >> deposit;
                cout << "\n";
            }else if(choice == 1){
                cout << "Enter withdrawl amount: ";
                cin >> withdrawl;
                cout << "\n";
            }else{
                cout << "Number Unfamiliar. Please try again.";
                cout << "\n";
                return;
            }

        }
        

};

class Node
{
    public:
        bankStatement<string> *data;
        Node* next;
    
        Node(bankStatement<string> *data, Node *next = nullptr){
            this->data = data;
            this->next = next;
        }
};

template <typename T2>
class SinglyLinkedList
{
    public: 
        T2 ownerOfBankstatements;
        int balance = 0;
        Node* head = nullptr;
        Node* start;
        Node* temp;
        
    //Constructor. Createst first node.
    SinglyLinkedList(Node* head, T2 ownerOfBankstatements, int balance)
    {
        this->ownerOfBankstatements = ownerOfBankstatements;
        this->start = head;
        this->balance = balance + head->data->deposit; 
        this->balance = balance - head->data->withdrawl;
        start->next = this->head;
    };

    void AddANode(bankStatement<string>* pointer)
    {
        if(head == nullptr){
            head = new Node(pointer);
            balance = balance + head->data->deposit; 
            balance = balance - head->data->withdrawl;
            start->next = head;
        }else{
        Node* newNode = new Node(pointer);
        balance = balance + newNode->data->deposit; 
        balance = balance - newNode->data->withdrawl;
        head->next = newNode;
        head = newNode;
        }
    };

    void PrintMe()
    {
        cout << ownerOfBankstatements << " Bank Statements:\n" << "Current Balance: $" << balance << "\n";
        temp = start;
        
            while(temp != nullptr){
                    cout << "Date: " << temp->data->date << " | Desposit: " << temp->data->deposit << " | Description: " << temp->data->description << " | Ref: " << temp->data->ref << " | Withdrawl: " << temp->data->withdrawl << "\n";
                    temp = temp->next;
                
            }
    
    }
};

int main(){

    bankStatement<string> bankstatement("10-10-2026", "ALDI FOOD");
    bankStatement<string> bankstatement2("10-10-2026", "ALDI FOOD");
    bankStatement<string>* pointer;
    bankStatement<string>* pointer2;
    pointer = &bankstatement;
    pointer2 = &bankstatement2;
    Node firstNode(pointer);
    Node* listPointer;
    listPointer = &firstNode;
    SinglyLinkedList<string> List(listPointer, "James", 10);
    List.AddANode(pointer2);
    List.PrintMe();
   

    


    return 0;
}