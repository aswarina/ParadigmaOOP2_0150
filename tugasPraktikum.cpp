#include <iostream>
#include <string>

using namespace std;

class RekeningBank {
protected:
    string namaPemilik;
    double saldo;

public:
    RekeningBank(string nama, double saldoAwal) {
        namaPemilik = nama;
        saldo = saldoAwal;
    }

    virtual ~RekeningBank() {}

    virtual void potongAdmin() = 0;

    void tampilkanInfo() {
        cout << "Nama Nasabah: " << namaPemilik << " | Saldo Saat Ini: Rp " << saldo << endl;
    }
};

class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        cout << "[Syariah] Atas nama " << namaPemilik << ": Bebas biaya admin bulanan." << endl;
    }
};

class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << "[Konvensional] Atas nama " << namaPemilik << ": Saldo otomatis dipotong Rp 15.000." << endl;
    }
};

class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "[Premium] Atas nama " << namaPemilik << ": Saldo di atas 10 Juta, bebas biaya admin." << endl;
        } else {
            saldo -= 50000;
            cout << "[Premium] Atas nama " << namaPemilik << ": Saldo <= 10 Juta, saldo dipotong Rp 50.000." << endl;
        }
    }
};

int main() {
    RekeningBank* daftarRekening[4];

    daftarRekening[0] = new RekeningSyariah("Ahmad", 4500000);
    daftarRekening[1] = new RekeningKonvensional("Rizky", 2500000);
    daftarRekening[2] = new RekeningPremium("Siti", 15000000);
    daftarRekening[3] = new RekeningPremium("Fajar", 8000000);

    cout << "=== PROSES SISTEM OTOMATISASI AKHIR BULAN ===" << endl << endl;

    for (int i = 0; i < 4; i++) {
        daftarRekening[i]->potongAdmin();
        daftarRekening[i]->tampilkanInfo();
        cout << "------------------------------------------------" << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete daftarRekening[i];
    }

    return 0;
}