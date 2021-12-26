#include <iostream>
#include <fstream>
#include <string>


/***
 * First make file with data
 * Second put it into order
*/

#define N 6
#define SAVE
// #define READ

struct Client{
    std::string name;
    std::string surname;
    // char post_code[6];
    int age;
};

void sort_clients(Client *clients, size_t size);
template<typename T>
void swap(T& x, T& y);
void write_clients(Client *clients);
void save_clients(Client *clients);
void read_clients(Client *clients);

int main(){

    Client clients[N];

#ifdef SAVE
    save_clients(clients);
    write_clients(clients);
#endif

#ifdef READ
    read_clients(clients);
    sort_clients(clients, N);
    write_clients(clients);

#endif

    return 0;
}

template<typename T>
void swap(T& x, T& y){
    Client temp = x;
    x = y;
    y = temp;
}

void sort_clients(Client *clients, size_t size){
    int comp;
    for(size_t i = 0; i < size; i++){
        for(size_t j = 0; j < size - i - 1; j++){
            comp = clients[j].surname.compare(clients[j+1].surname);
            if(comp > 0) 
                swap<Client>(clients[j], clients[j+1]);
            else{
                comp = clients[j].name.compare(clients[j+1].name);
                if(comp > 0) swap<Client>(clients[j], clients[j+1]);
            }
        }
    }
}

void write_clients(Client *clients){
    int i;
    std::ofstream write("Clients.txt");
    for(i = 0; i < N; i++){
        write << clients[i].name << " " << clients[i].surname << " " << clients[i].age << std::endl;    // while writing to file blank spaces and newlines must be written
    }
    write.close();
}

void save_clients(Client *clients){
    int i;
    std::cout << "Name Surname Age" << std::endl;
    for(i = 0; i < N; i++){
        std::cin >> clients[i].name >> clients[i].surname >> clients[i].age;    // works like scanf (to the first blank space)
    }
}

void read_clients(Client *clients){
    int i;
    std::ifstream read("Clients.txt");
    for(i = 0; i < N; i++){
        read >> clients[i].name >> clients[i].surname >> clients[i].age;
    }
    read.close();
}