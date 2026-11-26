#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V) {
        numVertices = V;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void addEdge(int i, int j) {
        // i dan j dikurang satu supaya sesuai dengan angka di gambar
        i--;
        j--;
        if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1; // karena graf tidak berarah
        } else {
            cout << "Indeks simpul tidak valid." << endl;
        }
    }

    void printAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // ----- BAGIAN DFS -----
    void dfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        cout << "Depth-First Traversal (dari vertex " << startVertex << "):" << endl;

        // TODO: panggil fungsi dfsUtil di sini
        dfsUtil(startVertex, visited);

        cout << endl;
    }

    void dfsUtil(int currentVertex, vector<bool>& visited) {
        // TODO: isi logika DFS di sini
        // 1. Tandai simpul sekarang sudah dikunjungi
        visited[currentVertex] = true;

        // 2. Cetak simpul sekarang
        int currentRealVertex = currentVertex + 1;
        cout << currentRealVertex << " ";

        // 3. Kunjungi semua simpul yang terhubung (rekursif)
        for(int i = 0; i < numVertices; i++) {
            if(adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                dfsUtil(i, visited);
            }
        }

    }
};

int main() {
    Graph g(8);

    // Parameter fungsi addEdge sekarang menerima angka sesuai gambar
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 7);
    g.addEdge(6, 8);

    // Cetak adjacency matrix untuk melihat representasi graf
    g.printAdjMatrix();
    cout << endl;

    // Panggil fungsi DFS mulai dari vertex 0 (yakni simpul 1)
    g.dfs(0);

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    system("CLS");
    int n;
    cout << "Masukkan jumlah pesanan: "; cin >> n;
    cout << endl;

    string* nama_hewan = new string[n];
    string* menu = new string[n];
    int* status = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Pesanan " << i + 1 << endl;
        cout << "Nama hewan: "; cin >> nama_hewan[i];
        cin.ignore();
        cout << "Menu pesanan: "; getline(cin, menu[i]);
        cout << "Status VIP (1=biasa, 2=VIP): "; cin >> status[i];
        cout << endl;
    }

    cout << "\n--- Daftar Pesanan (Prioritas VIP) ---\n";
    int nomor = 1;
    for (int i = 0; i < n; i++) {
        if (status[i] == 2) {
            for (int j = 0; j < nama_hewan[i].length(); j++) {
                nama_hewan[i][j] = toupper(nama_hewan[i][j]);
            }
            cout << nomor++ << ". " << nama_hewan[i] << " - " << menu[i] << " [VIP]" << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        if (status[i] == 1) {
            for (int j = 0; j < nama_hewan[i].length(); j++) {
                nama_hewan[i][j] = toupper(nama_hewan[i][j]);
            }
            cout << nomor++ << ". " << nama_hewan[i] << " - " << menu[i] << endl;
        }
    }

    delete[] nama_hewan;
    delete[] menu;
    delete[] status;

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

// Struktur Node untuk Linked List
struct Node {
    string nama_barang;
    int harga;
    int jumlah;
    Node* next;
};

// Fungsi untuk menambahkan barang ke linked list
void tambahBarang(Node*& head, string nama, int harga, int jumlah) {
    Node* newNode = new Node();
    newNode->nama_barang = nama;
    newNode->harga = harga;
    newNode->jumlah = jumlah;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menghapus barang berdasarkan nama
void hapusBarang(Node*& head, string nama) {
    if (head == nullptr) {
        cout << "Keranjang belanja kosong.\n";
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // Jika barang yang ingin dihapus ada di node pertama (head)
    if (temp != nullptr && temp->nama_barang == nama) {
        head = temp->next;
        delete temp;
        cout << "Barang \"" << nama << "\" berhasil dihapus.\n";
        return;
    }

    // Mencari barang di node selanjutnya
    while (temp != nullptr && temp->nama_barang != nama) {
        prev = temp;
        temp = temp->next;
    }

    // Jika barang tidak ditemukan
    if (temp == nullptr) {
        cout << "Barang tidak ada.\n";
        return;
    }

    // Melepaskan node dan menghapusnya
    prev->next = temp->next;
    delete temp;
    cout << "Barang \"" << nama << "\" berhasil dihapus.\n";
}

// Fungsi untuk menampilkan keranjang belanja dan total
void tampilkanKeranjang(Node* head) {
    if (head == nullptr) {
        cout << "\nKeranjang belanja kosong.\n";
        return;
    }

    Node* temp = head;
    int total_barang = 0;
    int total_harga = 0;

    while (temp != nullptr) {
        cout << temp->nama_barang << " - Rp" << temp->harga << " x" << temp->jumlah << endl;
        total_barang++;
        total_harga += (temp->harga * temp->jumlah);
        temp = temp->next;
    }

    cout << "\nTotal barang: " << total_barang << endl;
    cout << "Total harga: Rp" << total_harga << endl;
}

int main() {
    Node* head = nullptr;
    int n;

    cout << "Masukkan jumlah barang awal: ";
    cin >> n;
    cin.ignore(); // Membersihkan buffer

    for (int i = 0; i < n; i++) {
        cout << "\nBarang " << i + 1 << ":" << endl;
        string nama;
        int harga, jumlah;

        cout << "Nama: ";
        getline(cin, nama);
        cout << "Harga: ";
        cin >> harga;
        cout << "Jumlah: ";
        cin >> jumlah;
        cin.ignore();

        tambahBarang(head, nama, harga, jumlah);
    }

    char pilihan_hapus;
    cout << "\nApakah ingin menghapus barang? (y/n): ";
    cin >> pilihan_hapus;
    cin.ignore();

    if (pilihan_hapus == 'y' || pilihan_hapus == 'Y') {
        string nama_hapus;
        cout << "Masukkan nama barang yang ingin dihapus: ";
        getline(cin, nama_hapus);
        hapusBarang(head, nama_hapus);
        cout << endl;
    }

    cout << "Contoh Keluaran :" << endl;
    tampilkanKeranjang(head);

    // Dealokasi memori Linked List
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}