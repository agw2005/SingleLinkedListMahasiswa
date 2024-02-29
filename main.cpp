/*
 * Tugas Minggu-3 : Singly Linked List
 * Buatlah sebuah node yang merepresentasikan mahasiswa yang berisi data mahasiswa:
 * nim bertipe integer dan nama bertipe string. Acuan data adalah nim.
 * Buat operasi (tambah data) linked list, (print data), (insert data), dan (delete data)
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

    void push_back(int id, const std::string& name){
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

    void push_forward(int id, const std::string& name){
        Node* temp = new Node();
        temp -> nama = name;
        temp -> nim = id;
        if(head == nullptr){
            head = temp;
            tail = temp;
        } else{
            temp -> next = head;
            head = temp;
        }
        tail -> next = nullptr;
    }

    void traverse() const{
        Node* current = head;
        int count = 1;
        if(current == nullptr){std::cout<<"Cannot traverse, List is empty.\n";}
        else {
            while (current != nullptr) {
                std::cout << "Index-" << count << " :\n(Nama = " << current->nama << ") (NIM = " << current->nim
                          << ")\n-------------------------------" << std::endl;
                current = current->next;
                count++;
            }
            std::cout << "Head = " << head->nim << '\n';
            std::cout << "Tail = " << tail->nim << "\n-------------------------------";
        }
    }

    void insert_before(int flag, int id, const std::string& name){
        Node* temp = new Node();
        temp -> nama = name;
        temp -> nim = id;
        Node* current = head;
        bool reachedEnd = false;
        if(flag == head->nim){
            temp -> next = head;
            head = temp;
        } else {
            while (current != nullptr) {
                if(current == tail->next){break;}
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
                if(current == tail->next){break;}
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

    void eraseAt(int flag){
        Node* current = head;
        if(current == nullptr){std::cout<<"Cannot erase the node, List is empty.\n";}
        else {
            while (current != tail) {
                if (current != nullptr && current == head && flag == head->nim) {
                    head = head->next;
                    break;
                } else if (current != nullptr && flag == tail->nim && (current->next) == tail) {
                    //still evaluate the tail even though tail is outside the loop range :)
                    tail = current;
                    tail->next = nullptr;
                    break;
                } else if (current != nullptr && (current->next)->nim == flag) {
                    current->next = (current->next)->next;
                    break;
                } else {
                    current = current->next;
                }
            }
        }
    }

    void eraseLast(){
        Node* current = head;
        if(current == nullptr){std::cout<<"Cannot erase the tail, List is empty.\n";}
        else{
            while(current != tail){
                if( current->next == tail ){
                    delete current->next;
                    current->next = nullptr;
                    tail = current;
                } else {
                    current = current->next;
                }
            }
        }
    }

    void eraseFirst(){
        if(head == nullptr){std::cout<<"Cannot erase the head, List is empty.\n";}
        else{
            head = head-> next;
        }
    }

};

int main(){
    SinglyLinkedList list;/*
    list.push_back(143, "Danial");
    list.push_back(163, "Dicky");
    list.push_back(130,"Antonio");
    list.push_back(150,"Ardi");*/
    list.eraseFirst();
    list.traverse();
}