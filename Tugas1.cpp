#include <iostream>
#include <algorithm>
using namespace std;

struct Roti {
    string kode;
    string nama;
    int harga;
};

const int JUMLAH_ROTI = 5;
Roti daftarRoti[JUMLAH_ROTI] = {
    {"R01", "Roti Tawar", 11000},
    {"R02", "Roti Coklat", 22000},
    {"R03", "Roti Keju", 20000},
    {"R04", "Roti Pisang", 14000},
    {"R05", "Roti Gandum", 18000}
};

void tampilkanRoti(Roti *roti) {
    cout << "========== Toko Roti AK ===========\n";
    for (int i = 0; i < JUMLAH_ROTI; i++) {
        cout << roti[i].kode << " - " << roti[i].nama << " - Rp" << roti[i].harga << endl;
    }
}

int sequentialSearch(string kode) {
    for (int i = 0; i < JUMLAH_ROTI; i++) {
        if (daftarRoti[i].kode == kode) {
            return i;
        }
    }
    return -1;
}

int binarySearch(string nama) {
    int left = 0, right = JUMLAH_ROTI - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (daftarRoti[mid].nama == nama) {
            return mid;
        } else if (daftarRoti[mid].nama < nama) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void sortHargaAscending() {
    sort(daftarRoti, daftarRoti + JUMLAH_ROTI, [](Roti a, Roti b) {
        return a.harga < b.harga;
    });
}

void sortHargaDescending() {
    sort(daftarRoti, daftarRoti + JUMLAH_ROTI, [](Roti a, Roti b) {
        return a.harga > b.harga;
    });
}

int main() {
    int pilihan;
    do {
        cout << "========== Toko Roti AK ===========\n";
        cout << "1. Tampilkan Roti\n";
        cout << "2. Cari berdasarkan kode\n";
        cout << "3. Cari berdasarkan nama\n";
        cout << "4. Sort Harga Roti (asc)\n";
        cout << "5. Sort Harga Roti (desc)\n";
        cout << "6. Exit\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tampilkanRoti(daftarRoti);
                break;
            case 2: {
                string kode;
                cout << "Masukkan kode roti: ";
                cin >> kode;
                int idx = sequentialSearch(kode);
                if (idx != -1) {
                    cout << "Ditemukan: " << daftarRoti[idx].nama << " - Rp" << daftarRoti[idx].harga << endl;
                } else {
                    cout << "Roti tidak ditemukan!" << endl;
                }
                break;
            }
            case 3: {
                string nama;
                cout << "Masukkan nama roti: ";
                cin.ignore();
                getline(cin, nama);
                sort(daftarRoti, daftarRoti + JUMLAH_ROTI, [](Roti a, Roti b) { return a.nama < b.nama; });
                int idx = binarySearch(nama);
                if (idx != -1) {
                    cout << "Ditemukan: " << daftarRoti[idx].kode << " - Rp" << daftarRoti[idx].harga << endl;
                } else {
                    cout << "Roti tidak ditemukan!" << endl;
                }
                break;
            }
            case 4:
                sortHargaAscending();
                cout << "Roti telah diurutkan berdasarkan harga (Ascending)\n";
                break;
            case 5:
                sortHargaDescending();
                cout << "Roti telah diurutkan berdasarkan harga (Descending)\n";
                break;
            case 6:
                cout << "Terima kasih telah berbelanja di Toko Roti AK!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 6);
    return 0;
}
