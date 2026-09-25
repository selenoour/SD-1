#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// TODO : Menambahkan karakter ke stack
void push(char value) {
    if (top == MAX - 1){ //slot terakhir sudah berisi
        cout << "stack penuh\n";
    }
    else { //slot masih ada
        top++;
        stack[top] = value;
    }
}


// TODO : Mengambil karakter paling atas
char pop() {
    if(top == -1) {
        cout << "stack kosong\n";
    }
    else {
        cout << "\n" << stack[top] << " dihapus dari stack\n";
        top--;
    }
}
}

int main() {

    string kata;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    // TODO : Memasukkan setiap karakter ke stack

    // TODO Mengeluarkan karakter dari stack
    
    cout << endl;

    return 0;
}