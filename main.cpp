/*
 * Tugas Minggu-3 : Singly Linked List
 * Buatlah sebuah node yang merepresentasikan mahasiswa yang berisi data mahasiswa:
 * nim bertipe integer dan nama bertipe string. Acuan data adalah nim.
 * Buat operasi (tambah data) linked list, (print data), insert data, dan delete data
 */


#include <iostream>

struct Node{
    std::string nama;
    int nim;
    Node* next = nullptr;
};

struct SinglyLinkedList{
    Node* head = nullptr;
    Node* tail = nullptr;

    void push_back(const int& id, const std::string& name){
        Node* temp = new Node();
        temp -> nama = name;
        temp -> nim = id;
        if(head == nullptr){
            head = temp;
            tail = temp;
        } else{
            tail -> next = temp;
            tail = temp;
        }
        tail -> next = nullptr;
    }

    void transverse() const{
        Node* current = head;
        int count = 1;
        while(current != nullptr){
            std::cout<<"Index-"<<count<<" :\n(Nama = "<<current -> nama<<") (NIM = "<<current -> nim<<")\n-------------------------------"<<std::endl;
            current = current -> next;
            count++;
        }
    }

    void insert_before(int flag, int id, const std::string& name){
        Node* temp = new Node();
        temp -> nama = name;
        temp -> nim = id;
        Node* current = head;
        if(flag == head->nim){
            temp -> next = head;
            head = temp;
        } else {
            while (current != nullptr) {
                if ((current->next)->nim == flag) {
                    temp->next = current->next;
                    current->next = temp;
                    break;
                } else {
                    current = current->next;
                }
            }
        }
    }

    void insert_after(int flag, int id, const std::string& name){
        Node* temp = new Node();
        temp -> nama = name;
        temp -> nim = id;
        Node* current = head;
        if(flag == tail->nim){
            temp -> next = nullptr;
            tail -> next = temp;
            tail = temp;
        } else {
            while (current != nullptr) {
                if(current -> nim == flag){
                    temp->next = current->next;
                    current->next = temp;
                    break;
                } else {
                    current = current->next;
                }
            }
        }
    }

};

int main(){
    SinglyLinkedList list;
    list.push_back(143, "Danial");
    list.push_back(163, "Dicky");
    list.push_back(130,"Antonio");
    list.insert_after(130,142,"Yusuf");
    list.transverse();
}