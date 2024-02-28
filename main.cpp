#include <iostream>

struct Node{
    std::string nama;
    int nim;
    Node* next = nullptr;
};

struct SinglyLinkedList{
    Node* head = nullptr;
    Node* tail = nullptr;

    void push_back(const int& n, const std::string& name){
        Node* temp = new Node();
        temp -> nama = name;
        temp -> nim = n;
        if(head == nullptr){
            head = temp;
            tail = temp;
        } else{
            tail -> next = temp;
            tail = temp;
        }
    }

    void transverse() const{
        Node* current = head;
        int count = 1;
        while(current != nullptr){
            std::cout<<"Index-"<<count<<" :\nNama -- "<<current -> nama<<" (NIM: "<<current -> nim<<")\n-------------------------------"<<std::endl;
            current = current -> next;
            count++;
        }
    }

};

int main(){
    SinglyLinkedList list;
    list.push_back(143, "Danial");
    list.push_back(163, "Dicky");
    list.push_back(130,"Antonio");
    list.transverse();
}