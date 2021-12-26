#include <iostream>
#include <string>
#include <cstdio>

template <typename T>
struct node{
    node *next;
    T value;
};

template <typename T>
class List{
private:
    node<T> *head;
public:
    List();
    int add_element(T val);
    T delete_element();
    void print_list();
    ~List();
};


int main(){

    List<int> integer_list;
    integer_list.add_element(2);
    integer_list.add_element(1);
    integer_list.add_element(3);
    integer_list.add_element(7);
    integer_list.print_list();
    std::cout << integer_list.delete_element() << std::endl;
    integer_list.print_list();
    std::cout << "________________" << std::endl;
    List<std::string> string_lsit;
    string_lsit.add_element("Szalenie ważne twierdzenie!");
    string_lsit.add_element("Ale to już wiemy!");
    string_lsit.add_element(":)");
    string_lsit.print_list();
    std::cout << "POP: " << string_lsit.delete_element() << std::endl;
    string_lsit.print_list();

    return 0;
}

template <typename T>
List<T>::List(){
    this->head = nullptr;
}

template <typename T>
int List<T>::add_element(T val){
    
    node<T> *temp = new node<T>(); // chuj nie umiem w cepa
    if(!head){
        head = temp;
        head->next = nullptr;
        head->value = val;
        return 1;
    }
    if(!temp){
        return 0;
    }
    if(head){
        
        temp->value = head->value;
    }
    temp->next = head->next;
    temp->value =  head->value;
    head->next = temp;
    head->value = val;
    return 1;
}
template <typename T>
T List<T>::delete_element(){
    if(!this->head){
        return 0;
    }
    node<T> *temp = head;
    head = head->next;
    T val = temp->value;
    delete temp;
    return val;
}
template <typename T>
void List<T>::print_list(){
    node<T> *temp = this->head;
    while(temp){
        std::cout << temp->value << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}
template <typename T>
List<T>::~List(){
    while(head){
        delete_element();
    }
}
