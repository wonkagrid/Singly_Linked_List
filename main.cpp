#include <bits/stdc++.h>
using namespace std;
class Node{ //звено
public:
    int value;
    Node* next;
    Node(int value){ //конструктор звена
        this->value = value;
        this->next = NULL;
    };
};
class Linked{
public:
    Node* root;
    Linked(){
        root = NULL;
    };
    void add(int value){
        Node* new_node = new Node(value); //выделение места
        if (root == NULL || value < root->value){ //если список пустой или значение нового звена меньше, чем значение в корне, то мы вставляем новое звено перед корнем
            new_node->next = root;
            root = new_node;
        }
        else{ //в противном случае, мы двигаемся по списку, останавливаемся или в конце или в том месте, где значение нового звена больше чем значение рассматриваемого
            //и вставляем между рассматриваемым и следующим за ним новое, ну или вставляем его в конец.
            Node* current = root;
            while(current->next != NULL && value > current->next->value){
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    };
    void remove(int value){
        Node* for_deletion = root;
        Node* previous = NULL;
        while(for_deletion != NULL){
            if(for_deletion->value == value) { //если заданное значение есть в списке
                if (previous == NULL) { //удаляемое в начале
                    root = for_deletion->next;
                    delete for_deletion;
                    for_deletion = root;
                }
                else { //удаляемое в середине или в конце
                    previous->next = for_deletion->next;
                    delete for_deletion;
                    for_deletion = previous->next;
                }
            }
            else{ //такого значения в списке нет
                previous = for_deletion;
                for_deletion = for_deletion->next;
            }
         }
    };
    void print_list(){ //ну тут вывод
        Node* current = root;
        while (current != NULL){
            if(current->next == NULL) {
                cout << current->value;
                current = current->next;
            }
            else {
                cout << current->value << " " << "->" << " ";
                current = current->next;
            }
        }
    };
};
int main(){
    system("chcp 65001");
    //srand(time(NULL));
    Linked list;
    int size; int value;
    char decision;
    int for_removal;
    int for_addition;
    cout << "how many????" << endl;
    cin >> size;
    cout << "type your values cherez probel: ";
    for(int i = 0; i < size; i++)
    {
        cin >> value;
        list.add(value);
        //list.add(rand()%100000-rand()%100000);
    }
    cout << "[ " ; list.print_list(); cout << "]" << endl;
    cout << endl;
    start:
    cout << "wanna add or remove smth????" << endl;
    cin >> decision;
    switch(decision){
        case 'y':
            cout << "add or remove?" << endl;
            cin >> decision;
            switch(decision) {
                case 'a':
                    cout << "how many nodes do you want to add?" << endl;
                    int quantity;
                    cin >> quantity;
                    for(int i = 0; i < quantity; i++) {
                        cout << "type your value cherez probel: " << endl;
                        cin >> for_addition;
                        list.add(for_addition);
                    }
                    cout << "[ " ; list.print_list(); cout << "]" << endl;
                    goto start;
                case 'r':
                    cout << "type your value: " << endl;
                    cin >> for_removal;
                    list.remove(for_removal);
                    cout << "[ " ; list.print_list(); cout << "]" << endl;
                    goto start;
                default: cout << "THINK AGAIN!!!!!!!" << endl; goto start;
            }
        case 'n':
            cout << "here is your linked list!!" << endl;
            goto stop;
        default: cout << "THINK AGAIN!!!!!!!" << endl; goto start;
    }
    stop:
    return 0;
}