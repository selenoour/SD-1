#include <iostream>
using namespace std;

#define MAX 5 // slot nya sebanyak 5
int stack[MAX]; // int stack[s]
int top = -1; // awalnya stack kosong

// TODO : Operasi Push
void push (int value) {
    if (top == MAX - 1){ //slot terakhir sudah berisi
        cout << "stack penuh\n";
    }
    else { //slot masih ada
        top++;
        stack[top] = value;
        cout << value << " ditambahkan dlm stack\n";
    }
    //top = 0
    // stack[0] = 50
}

// TODO : Operasi Pop
void pop (){
    if(top == -1) {
        cout << "stack kosong\n";
    }
    else {
        cout << "\n" << stack[top] << " dihapus dari stack\n";
        top--;
    }
}

// TODO : Nampilin Stack
void display() {
    if (top == -1) {    
        cout << "stack kosong\n";
    }
    else {
        cout << "isi dari text:\n";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }

}

int main (){
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);

    display();
    pop();
    display;

    return 0;
}