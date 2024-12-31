#include <iostream>
#include <vector>
#include <string>

struct Barang {
    int id;
    std::string nama;
    std::string kualitas;
};

class ManajemenKualitas {
private:
    std::vector<Barang> daftarBarang;
    int idCounter;

public:
    ManajemenKualitas() : idCounter(1) {}

    void tambahBarang(const std::string& nama, const std::string& kualitas) {
        Barang barang;
        barang.id = idCounter++;
        barang.nama = nama;
        barang.kualitas = kualitas;
        daftarBarang.push_back(barang);
        std::cout << "Barang berhasil ditambahkan!\n";
    }

    void tampilkanBarang() const {
        if (daftarBarang.empty()) {
            std::cout << "Tidak ada barang dalam daftar.\n";
            return;
        }

        std::cout << "\nDaftar Barang:\n";
        for (size_t i = 0; i < daftarBarang.size(); ++i) {
            std::cout << "ID: " << daftarBarang[i].id
                      << ", Nama: " << daftarBarang[i].nama
                      << ", Kualitas: " << daftarBarang[i].kualitas << "\n";
        }
    }

    void cekKualitas(int id) const {
        for (size_t i = 0; i < daftarBarang.size(); ++i) {
            if (daftarBarang[i].id == id) {
                std::cout << "Kualitas barang dengan ID " << id << " adalah: " << daftarBarang[i].kualitas << "\n";
                return;
            }
        }
        std::cout << "Barang dengan ID " << id << " tidak ditemukan.\n";
    }
};

int main() {
    ManajemenKualitas manajemen;
    int pilihan;

    do {
        std::cout << "\n=== Manajemen Kualitas Barang ===\n";
        std::cout << "1. Tambah Barang\n";
        std::cout << "2. Tampilkan Semua Barang\n";
        std::cout << "3. Cek Kualitas Barang\n";
        std::cout << "4. Keluar\n";
        std::cout << "Pilih opsi: ";
        std::cin >> pilihan;

        switch (pilihan) {
        case 1: {
            std::string nama, kualitas;
            std::cin.ignore(); // Membersihkan buffer input
            std::cout << "Masukkan nama barang: ";
            std::getline(std::cin, nama);
            std::cout << "Masukkan kualitas barang (Baik/Cukup/Buruk): ";
            std::getline(std::cin, kualitas);
            manajemen.tambahBarang(nama, kualitas);
            break;
        }
        case 2:
            manajemen.tampilkanBarang();
            break;
        case 3: {
            int id;
            std::cout << "Masukkan ID barang: ";
            std::cin >> id;
            manajemen.cekKualitas(id);
            break;
        }
        case 4:
            std::cout << "Keluar dari program.\n";
            break;
        default:
            std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 4);

    return 0;
}

