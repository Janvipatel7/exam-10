#include<iostream>

using namespace std;

class Node{
    public:
     int data;
     Node *next;

     Node(int data){
        this->data = data;
        this->next = NULL;
     }
};

class LinkedList{
    public:
     Node *head;
     int count;

    LinkedList(){
        this->head = NULL;
        this->count = 0;
    }

    void addAtStart(int data){
        Node *newNode = new Node(data);

        newNode->next = this->head;
        this->head = newNode;

        this->count++;

        cout << "Value Inserted At Start " << endl;

    }

    void viewAll(){

       if(count == 0){
            cout << "Linked is Empty!!!";
            return;
        }
        Node *temp = this->head;
        while(temp != NULL){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    void update(int data,int pos){
        if(this->count == 0 || this->head == nullptr){
            cout << "Linked List Empty...";
            return;
        }

        Node *temp = head;
        for(int i=0; i < pos; i++){
            temp = temp->next;
        }
        temp->data = data;
        cout << "Data is Updated....." << endl;


    }
     

    void deletAtStart(){
        if(this->count == 0 || this->head == nullptr){
            cout << "Linked List is Empty....";
            return;
        }
        Node *temp = this->head;
        this->head = this->head->next;

        delete temp;
        temp =  nullptr;

        this->count--;
    }

    void deleteAtAny(int pos){
        if(this->count == 0 || this->head == nullptr){
           
           cout <<"Linked List is empty...." << endl;
           return;
        }

        if(pos == 0){
            this->deletAtStart();
            cout <<"Deleted Successfully...." << endl;
            return; 
        }
        Node *temp = this->head , *curr = this->head;
        for(int i=0; i < pos ; i++){
            curr = curr->next;
        }
        for(int i=0; i < pos-1; i++){
            temp = temp->next;
        }
        temp->next = curr->next;

        delete curr;
        curr = NULL;

        temp = NULL;
        delete temp;

        this->count--;
        cout << "Delete Element ...." << endl;


    }

    
};

int main(){
    LinkedList list;
    int choice;

    do{
        cout << "\n--------------C R U D--------------" << endl;
        cout << "Enter 1 For Insert At Beginning...." << endl;
        cout << "Enter 2 For Delete At Any Position...." << endl;
        cout << "Enter 3 For Search...." << endl;
        cout << "Enter 4 For View All...." << endl;
        cout << "Enter 5 For Update...." << endl;
        cout << "Enter 0 For Exit...." << endl;
        cout << "--------------C R U D--------------" << endl;

        cout << "Enter Your Choice:- ";
        cin >> choice;

        switch(choice){
            case 1:{
                int data;

                cout << "Enter Your Data :- ";
                cin >> data;

                list.addAtStart(data);
                break;
            }
            case 2:{
                int data, pos;

                cout << "Enter your Position :- ";
                cin >> pos;

                

                list.deleteAtAny(pos);
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                list.viewAll();
                break;
            }
            case 5:{
                int data,pos;

                cout << "Enter your Position :- ";
                cin >> pos;

                cout << "Enter your data :- ";
                cin >> data;

                list.update(data,pos);
               
                break;
            }
            case 0:{
                cout << "Thank you ....";
                break;
            }
           default:
              cout << "Invalid Case!!!!";

        }
    }while (choice != 0);
   return 0;
}