#include <iostream>
using namespace std;

class Bankstatement
{
    public:
        int balence = 5000;
};

class Node
{
    public: 
        Node(int moneyInOrOut, Node* next)
        {
            this->moneyInOrOut = moneyInOrOut;
            this->next = next;
        };
        Node* next;
        int moneyInOrOut;

};

class SinglyLinkedList
{
    public:
    int balance;
        SinglyLinkedList()
        {
            next = nullptr;
        }
        void AddNode(int moneyInOrOut)
        {
            balance += moneyInOrOut;
            Node* temp = new Node(moneyInOrOut, next);
            next = temp;
        }
        void PrintMe()
        {
        Node* temp = next;
        while (temp != nullptr)
        {
            cout << temp->moneyInOrOut << endl;
            temp = temp->next;
        }
            cout << "Final Balance: " << balance << endl;
        }
    
    private:
        Node* next;
        
};

int main()
{
    SinglyLinkedList list;

    list.balance = 5000;
    cout << "Starting Balence is: " << list.balance << endl;

    list.AddNode(-400);
    list.AddNode(-600);
    list.AddNode(-800);
    list.AddNode(600);
    list.AddNode(6000);
    list.AddNode(-5403);
    list.PrintMe();

}