#include <bits/stdc++.h>
using namespace std;

struct jadwal_kereta {
    string kode_kereta;
    string asal;
    string tujuan;
    string waktu_keberangkatan;
    string waktu_kedatangan;
    int kapasitas;
};

jadwal_kereta jadwal[21];
int jumlah_jadwal = 0;

bool file_exists(const string &path) {
    fstream file(path, ios::in);
    return file.is_open();
}

string generate_kode_tiket() {
    string kode_tiket;
    do {
        kode_tiket = "TIKET" + to_string(rand() % 1000000);
    } while (file_exists(kode_tiket + ".txt"));
    return kode_tiket;
}

void load_jadwal(){
    jumlah_jadwal = 0;
    fstream file("jadwal_kereta.txt", ios::in);
    if (!file.is_open()) {
        cout << "Gagal membuka file jadwal_kereta.txt" << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string kapasitas_str;
        if (!getline(ss, jadwal[jumlah_jadwal].kode_kereta, ',')) continue;
        if (!getline(ss, jadwal[jumlah_jadwal].asal, ',')) continue;
        if (!getline(ss, jadwal[jumlah_jadwal].tujuan, ',')) continue;
        if (!getline(ss, jadwal[jumlah_jadwal].waktu_keberangkatan, ',')) continue;
        if (!getline(ss, jadwal[jumlah_jadwal].waktu_kedatangan, ',')) continue;
        if (!getline(ss, kapasitas_str)) continue;
        try {
            jadwal[jumlah_jadwal].kapasitas = stoi(kapasitas_str);
        } catch (...) {
            continue;
        }
        jumlah_jadwal++;
        if (jumlah_jadwal >= 20) break;
    }
    file.close();
}

void save_jadwal() {
    fstream file("jadwal_kereta.txt", ios::out | ios::trunc);
    if (!file.is_open()) {
        cout << "Gagal membuka file jadwal_kereta.txt" << endl;
        return;
    }
    for (int i = 0; i < jumlah_jadwal; i++) {
        file << jadwal[i].kode_kereta << "," << jadwal[i].asal << "," << jadwal[i].tujuan << "," << jadwal[i].waktu_keberangkatan << "," << jadwal[i].waktu_kedatangan << "," << jadwal[i].kapasitas << endl;
    }
    file.close();
}

void save_file_tiket(const string &kode_tiket, const string &nama_penumpang, const string &kode_kereta, const string &tanggal_keberangkatan) {
    fstream file(kode_tiket + ".txt", ios::out | ios::trunc);
    if (!file.is_open()) {
        cout << "Gagal membuka file " << kode_tiket << ".txt" << endl;
        return;
    }
    file << "E-Tiket Kereta Api" << endl << endl;
    file << "Kode Tiket: " << kode_tiket << endl;
    file << "Nama Penumpang: " << nama_penumpang << endl;
    file << "Kode Kereta: " << kode_kereta << endl;
    file << "Tanggal Keberangkatan: " << tanggal_keberangkatan << endl;
    file.close();
}

bool baca_file_tiket(const string &kode_tiket, string &nama_penumpang, string &kode_kereta, string &tanggal_keberangkatan) {
    fstream file(kode_tiket + ".txt", ios::in);
    if (!file.is_open()) {
        cout << "Kode tiket tidak ditemukan." << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        if (line.rfind("Nama Penumpang: ", 0) == 0) {
            nama_penumpang = line.substr(16);
        } else if (line.rfind("Kode Kereta: ", 0) == 0) {
            kode_kereta = line.substr(13);
        } else if (line.rfind("Tanggal Keberangkatan: ", 0) == 0) {
            tanggal_keberangkatan = line.substr(23);
        }
    }
    return !nama_penumpang.empty() && !kode_kereta.empty() && !tanggal_keberangkatan.empty();
}

bool hapus_file_tiket(const string &kode_tiket) {
    return remove((kode_tiket + ".txt").c_str()) == 0;
}

bool file_jadwal_kosong() {
    fstream file("jadwal_kereta.txt", ios::in);
    if (!file.is_open()) {
        return true;
    }
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            return false;
        }
    }
    return true;
}

void dump_jadwal() {
    if (!file_jadwal_kosong()) {
        return;
    }
    jumlah_jadwal = 5;
    jadwal[0] = {"GA012", "Jakarta", "Bandung", "11:00", "13:00", 10};
    jadwal[1] = {"GA345", "Jakarta", "Yogyakarta", "12:00", "14:00", 10};
    jadwal[2] = {"GA789", "Jakarta", "Medan", "10:00", "12:00", 10};
    jadwal[3] = {"GA123", "Jakarta", "Bali", "08:00", "10:00", 10};
    jadwal[4] = {"GA456", "Jakarta", "Surabaya", "09:00", "11:00", 10};
    save_jadwal();
}

void tampil_jadwal() {
    load_jadwal();
    cout << "Jadwal Kereta Api" << endl << endl;
    const int w1 = 15, w2 = 20, w3 = 20, w4 = 15, w5 = 15, w6 = 15;
    cout << left << setw(w1) << "Kode" << setw(w2) << "Asal" << setw(w3) << "Tujuan" << setw(w4) << "Berangkat" << setw(w5) << "Tiba" << setw(w6) << "Kapasitas" << endl;
    cout << string(w1 + w2 + w3 + w4 + w5 + w6, '-') << endl;
    for(int j = 0; j < jumlah_jadwal - 1; j++) {
        for(int k = 0; k < jumlah_jadwal - j - 1; k++) {
            if(jadwal[k].waktu_keberangkatan > jadwal[k + 1].waktu_keberangkatan) {
                swap(jadwal[k], jadwal[k + 1]);
            }
        }
    }
    for (int i = 0; i < jumlah_jadwal; i++) {
        cout << left << setw(w1) << jadwal[i].kode_kereta
             << setw(w2) << jadwal[i].asal
             << setw(w3) << jadwal[i].tujuan
             << setw(w4) << jadwal[i].waktu_keberangkatan
             << setw(w5) << jadwal[i].waktu_kedatangan
             << setw(w6) << jadwal[i].kapasitas
             << endl;
    }
    cout << endl;
    system("pause");
}

void tambah_jadwal(){
    load_jadwal();
    if (jumlah_jadwal >= 20) {
        cout << "Jadwal sudah penuh." << endl;
        system("pause");
        return;
    }
    cout << "Masukkan kode kereta: ";
    cin >> jadwal[jumlah_jadwal].kode_kereta;
    cin.ignore();
    cout << "Masukkan asal: ";
    getline(cin, jadwal[jumlah_jadwal].asal);
    cout << "Masukkan tujuan: ";
    getline(cin, jadwal[jumlah_jadwal].tujuan);
    cout << "Masukkan waktu keberangkatan: ";
    getline(cin, jadwal[jumlah_jadwal].waktu_keberangkatan);
    cout << "Masukkan waktu kedatangan: ";
    getline(cin, jadwal[jumlah_jadwal].waktu_kedatangan);
    cout << "Masukkan kapasitas: ";
    cin >> jadwal[jumlah_jadwal].kapasitas;
    jumlah_jadwal++;
    save_jadwal();
    cout << "Jadwal berhasil ditambahkan." << endl;
    system("pause");
}

void ubah_jadwal(){
    load_jadwal();
    string kode;
    bool ketemu = false;
    cout << "Masukkan kode kereta yang ingin diubah: ";
    cin >> kode;
    for (int i = 0; i < jumlah_jadwal; i++) {
        if (jadwal[i].kode_kereta == kode) {
        cin.ignore();
        cout << "Masukkan asal baru: ";
        getline(cin, jadwal[i].asal);
        cout << "Masukkan tujuan baru: ";
        getline(cin, jadwal[i].tujuan);
        cout << "Masukkan waktu keberangkatan baru: ";
        getline(cin, jadwal[i].waktu_keberangkatan);
        cout << "Masukkan waktu kedatangan baru: ";
        getline(cin, jadwal[i].waktu_kedatangan);
        cout << "Masukkan kapasitas baru: ";
        cin >> jadwal[i].kapasitas;
        ketemu = true;
        break;
    }
    }
    if (ketemu) {
        save_jadwal();
        cout << "Jadwal berhasil diubah." << endl;
    } else {
        cout << "Kode kereta tidak ditemukan." << endl;
    }
    system("pause");
}

void hapus_jadwal(){
    load_jadwal();
    string kode;
    bool found = false;
    cout << "Masukkan kode kereta yang ingin dihapus: ";
    cin >> kode;
    for (int i = 0; i < jumlah_jadwal; i++) {
        if (jadwal[i].kode_kereta == kode) {
            found = true;
            for (int j = i; j < jumlah_jadwal - 1; j++) {
                jadwal[j] = jadwal[j + 1];
            }
            jumlah_jadwal--;
            save_jadwal();
            cout << "Jadwal kereta berhasil dihapus." << endl;
            system("pause");
            break;
        }
    }
    if (!found) {
        cout << "Kode kereta tidak ditemukan." << endl;
        system("pause");
    }
}

void cari_kereta(){
    load_jadwal();
    string asal, tujuan;
    cout << "Masukkan asal: ";
    if(cin.peek() == '\n') cin.ignore();
    getline(cin, asal);
    cout << "Masukkan tujuan: ";
    if(cin.peek() == '\n') cin.ignore();
    getline(cin, tujuan);
    cout << "Hasil pencarian kereta dari " << asal << " ke " << tujuan << ":" << endl;
    const int w1 = 15, w2 = 20, w3 = 20, w4 = 15, w5 = 15, w6 = 15;
    cout << left << setw(w1) << "Kode" << setw(w2) << "Asal" << setw(w3) << "Tujuan" << setw(w4) << "Berangkat" << setw(w5) << "Tiba" << setw(w6) << "Kapasitas" << endl;
    cout << string(w1 + w2 + w3 + w4 + w5 + w6, '-') << endl;
    vector<string> kode_hasil;
    for (int i = 0; i < jumlah_jadwal; i++) {
        if (jadwal[i].asal == asal && jadwal[i].tujuan == tujuan) {
            kode_hasil.push_back(jadwal[i].kode_kereta);
            cout << left << setw(w1) << jadwal[i].kode_kereta
                 << setw(w2) << jadwal[i].asal
                 << setw(w3) << jadwal[i].tujuan
                 << setw(w4) << jadwal[i].waktu_keberangkatan
                 << setw(w5) << jadwal[i].waktu_kedatangan
                 << setw(w6) << jadwal[i].kapasitas
                 << endl;
        }
    }
    if (kode_hasil.empty()) {
        cout << "Tidak ada kereta yang cocok dengan rute tersebut." << endl;
        cout << endl;
        system("pause");
        return;
    }
    cout << "Apakah Anda ingin memesan tiket untuk salah satu kereta di atas? (y/n): ";
    char pesan;
    cin >> pesan;
    if (pesan == 'y' || pesan == 'Y') {
        string kode_kereta;
        cout << "Masukkan kode kereta yang ingin dipesan: ";
        cin >> kode_kereta;
        bool found = false;
        bool valid_hasil = false;
        for (const string &kode : kode_hasil) {
            if (kode == kode_kereta) {
                valid_hasil = true;
                break;
            }
        }
        if (!valid_hasil) {
            cout << "Kode kereta tidak termasuk hasil pencarian." << endl;
            cout << endl;
            system("pause");
            return;
        }
        for (int i = 0; i < jumlah_jadwal; i++) {
            if (jadwal[i].kode_kereta == kode_kereta) {
                found = true;
                if (jadwal[i].kapasitas <= 0) {
                    cout << "Maaf, kapasitas untuk kereta ini sudah penuh." << endl;
                    break;
                }
                string nama_penumpang, tanggal_keberangkatan;
                cout << "Masukkan nama penumpang: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, nama_penumpang);
                cout << "Masukkan tanggal keberangkatan (YYYY-MM-DD): ";
                cin >> tanggal_keberangkatan;
                string kode_tiket = generate_kode_tiket();
                jadwal[i].kapasitas--;
                save_jadwal();
                save_file_tiket(kode_tiket, nama_penumpang, kode_kereta, tanggal_keberangkatan);
                cout << "Tiket berhasil dipesan! Kode tiket Anda: " << kode_tiket << endl;
                break;
            }
        }
        if (!found) {
            cout << "Kode kereta tidak ditemukan." << endl;
        }
    } else {
        cout << "Pemesanan tiket dibatalkan." << endl;
    }
    cout << endl;
    system("pause");
}

void cetak_etiket() {
    load_jadwal();
    cout << "Masukkan kode tiket: ";
    string kode_tiket;
    cin >> kode_tiket;
    string nama_penumpang, kode_kereta, tanggal_keberangkatan;
    if (!baca_file_tiket(kode_tiket, nama_penumpang, kode_kereta, tanggal_keberangkatan)) {
        cout << "Kode tiket tidak ditemukan." << endl;
        system("pause");
        return;
    }
    jadwal_kereta kereta;
    bool found = false;
    for (int j = 0; j < jumlah_jadwal; j++) {
        if (jadwal[j].kode_kereta == kode_kereta) {
            kereta = jadwal[j];
            found = true;
            break;
        }
    }
    cout << "E-Tiket Kereta Api" << endl << endl;
    cout << "Kode Tiket: " << kode_tiket << endl;
    cout << "Nama Penumpang: " << nama_penumpang << endl;
    cout << "Kode Kereta: " << kode_kereta << endl;
    if (found) {
        cout << "Asal: " << kereta.asal << endl;
        cout << "Tujuan: " << kereta.tujuan << endl;
        cout << "Waktu Keberangkatan: " << kereta.waktu_keberangkatan << endl;
        cout << "Waktu Kedatangan: " << kereta.waktu_kedatangan << endl;
    }
    cout << "Tanggal Keberangkatan: " << tanggal_keberangkatan << endl;
    system("pause");
}

void cancel_tiket() {
    load_jadwal();
    cout << "Masukkan kode tiket yang ingin dibatalkan: ";
    string kode_tiket;
    cin >> kode_tiket;
    string nama_penumpang, kode_kereta, tanggal_keberangkatan;
    if (!baca_file_tiket(kode_tiket, nama_penumpang, kode_kereta, tanggal_keberangkatan)) {
        cout << "Kode tiket tidak ditemukan." << endl;
        cout << endl;
        system("pause");
        return;
    }
    for (int j = 0; j < jumlah_jadwal; j++) {
        if (jadwal[j].kode_kereta == kode_kereta) {
            jadwal[j].kapasitas++;
            break;
        }
    }
    save_jadwal();
    if (hapus_file_tiket(kode_tiket)) {
        cout << "Tiket berhasil dibatalkan." << endl;
    } else {
        cout << "Tiket dibatalkan, tetapi file tiket gagal dihapus." << endl;
    }
     cout << endl;
    system("pause");
}

void menu_admin() {
    string user, pass;
    cout << "Masukkan username: ";
    cin >> user;
    cout << "Masukkan password: ";
    cin >> pass;

    if (user != "admin" || pass != "admin123") {
        cout << "Username atau password salah." << endl;
        system("pause");
        return;
    }

    int pilih;
    do {
        cout << "Menu Admin Aplikasi Tiket Kereta Api" << endl;
        cout << "1. Tambah Jadwal" << endl;
        cout << "2. Ubah Jadwal" << endl;
        cout << "3. Hapus Jadwal" << endl;
        cout << "4. Kembali" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                tambah_jadwal();
                break;
            case 2:
                ubah_jadwal();
                break;
            case 3:
                hapus_jadwal();
                break;
            case 4:
                cout << "Kembali ke menu utama..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                system("pause");
        }
    } while (pilih != 4);
}

void menu_user(){
    int pil;
    do {
    cout << "Menu User Aplikasi Tiket Kereta Api" << endl;
    cout << "1. Lihat Jadwal Kereta" << endl;
    cout << "2. Cari dan Pesan Kereta Berdasarkan Asal dan Tujuan" << endl;
    cout << "3. Cetak E-Tiket" << endl;
    cout << "4. Cancel Tiket" << endl;
    cout << "5. Keluar" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pil;
    switch (pil) {
        case 1:
            cout << "Menampilkan jadwal kereta..." << endl;
            tampil_jadwal();
            break;
        case 2:
            cout << "Mencari kereta berdasarkan asal dan tujuan..." << endl;
            cari_kereta();
            break;
        case 3:
            cout << "Mencetak e-tiket..." << endl;
            cetak_etiket();
            break;
        case 4:
            cout << "Membatalkan tiket..." << endl;
            cancel_tiket();
            break;
        case 5:
            cout << "Keluar dari aplikasi..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;}
    } while (pil != 5);
}

int main (){
    dump_jadwal();
    srand((unsigned)time(nullptr));
    int pilih;
    while (true) {
        cout << "Selamat datang di Aplikasi Tiket Kereta Api" << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                menu_admin();
                break;
            case 2:
                menu_user();
                break;
            case 3:
                cout << "Keluar dari aplikasi..." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                system("pause");
        }
    }
}
