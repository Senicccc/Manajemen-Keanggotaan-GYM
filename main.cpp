#include <iostream>
#include <string>

using namespace std;

//deklarasi fungsi-fungsi sebelum digunakan
void menu();
void registrasi();
void header();
void bersih();
void tampilAnggota();
void cariAnggota();
void editAnggota();
void tambahKelas();
void tampilKelas();
void cariKelas();

//deklarasi fungsi yang sudah memiliki sebuah string didalamnya
// string itu nantinya akan mengarahkan ke data mana yang sedang dituju
void editKelas(string namaKelas);
void hapusAnggota(string nama);
void editAnggota(string nama);

//struct buat nyimpen data anggota gym
struct anggotaGym
{
    string nama;
    string tglLahir;
    string alamat;
    string noTelp;
    string gender;
    string expire;

    anggotaGym *next, *prev;
};

//pointer ke anggota pertama sama anggota teakhir
anggotaGym *awal = NULL, *akhir = NULL, *baru;

//struct buat nyimpen data kelas
struct dataKelas
{
   string namaKelas;
   string jamKelas;
   string hariKelas;
   string pengurus;
};

//pake const int agar nilainya tidak bisa diubah-ubah
const int jmlKelas = 10;
dataKelas kelas[jmlKelas];
//array sebanyak jumlah kelas yang dapat ditampung, ditulis jmlkelas agar kalau dirubah tidak ribet
//kelas hanya boleh ada 10 kelas di gym, maka dibatasi jadi 10

//fungsi paling utama dari kodingan ini, agar dapat masuk ke menu 
int main()
{
    do
    {
        bersih();
        header();
        menu();
    } while (true);
}
// pakai do while untuk looping 

//buat bersihin output sebelumnya, biar rapih
void bersih()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//header yang akan ada disetiap program, disetiap void akan dipanggil supaya setiap halaman selaras
void header()
{
    cout << "       \t    MANAJEMEN KEANGGOTAAN PUSAT KEBUGARAN\n\t    \t\tWE GO GYM!\n";
    cout << "==============================================================\n";
}

//fungsi menu utama dari program
void menu()
{
    bersih();
    header();
    int pilihan;
    cout << "||                      MENU UTAMA                          ||\n";
    cout << "==============================================================\n";
    cout << "[1] Tambah Anggota Baru\n";
    cout << "[2] Cari Data Anggota\n";
    cout << "[3] Tampilkan Seluruh Data Anggota\n";
    cout << "[4] Tambah Data Kelas\n";
    cout << "[5] Cari Data Kelas\n";
    cout << "[6] Tampilkan Seluruh Data Kelas\n";
    cout << "[7] Keluar Program\n";

    //menu pilihan untuk memilih menu yang dituju
    cout << "Pilihan: ";
    cin >> pilihan;

    //switch case untuk menjalankan fungsi pilihan menu
    //setiap menu ada fungsi bersih(); supaya kalo looping kembali ke menu, output yang sebelumnya sudah bersih
    switch (pilihan)
    {
    case 1:
        bersih();
        registrasi();
        break;
    case 2:
        bersih();
        cariAnggota();
        break;
    case 3:
        bersih();
        tampilAnggota();
        break;
    case 4:
        bersih();
        tambahKelas();
        break;
    case 5:
        bersih();
        cariKelas();
        break;
    case 6:
        bersih();
        tampilKelas();
        break;
        default:
        return;
        break;
    case 7:
        exit(0);
    }

}

//fungsi untuk input data baru member
void registrasi()
{
    bersih();
    header();

    //buat node baru untuk input anggota baru
    baru = new anggotaGym;
    baru->next = NULL;
    baru->prev = NULL;

    cout << "||                 REGISTRASI KEANGGOTAAN                   ||\n";
    cout << "==============================================================\n";
    cout << "Nama\t\t\t: ";
    cin.ignore();
    getline(cin, baru->nama);

    //memeriksa ada nama yang sama atau tidak
    anggotaGym *cekMember = awal;
    while (cekMember != NULL)
    {
        if (cekMember->nama == baru->nama)
        {
            cout << "Anggota dengan nama tersebut sudah terdaftar." << endl;
            delete baru;
            cout << "Tekan ENTER untuk kembali ke menu" << endl;
            cin.ignore();
            menu();
            return;
        }
        cekMember = cekMember->next;
    }

    cout << "Alamat\t\t\t: ";
    getline(cin, baru->alamat);

    cout << "Nomor Telepon\t\t: ";
    getline(cin, baru->noTelp);

    cout << "Tanggal Lahir\t\t: ";
    getline(cin, baru->tglLahir);

    cout << "Jenis Kelamin\t\t: ";
    getline(cin, baru->gender);

    cout << "Tanggal Kadaluarsa\t: ";
    getline(cin, baru->expire);

    if (awal == NULL)
    {
        awal = akhir = baru;
    }
    else
    {
        akhir->next = baru;
        baru->prev = akhir;
        akhir = baru;
    }

    cout << "Data telah tersimpan, tekan ENTER untuk kembali ke menu" << endl;
    cin.ignore();
    return menu();
}

//fungsi mencari seorang anggota yang nantinya ada opsi untuk menghapus dan edit data anggota yang dicari
void cariAnggota()
{
    bersih();
    header();
    cout << "||                      CARI ANGGOTA                        ||\n";
    cout << "==============================================================\n";
    string nama;
    cout << "Masukkan nama anggota yang ingin dicari: ";
    cin.ignore();
    getline(cin, nama);

    anggotaGym *skrg = awal;
    bool ditemukan = false;

    while (skrg != NULL)
    {
        if (skrg->nama == nama)
        {
            cout << "Anggota berhasil ditemukan!" << endl;
            cout << "Nama\t\t\t\t: " << skrg->nama << endl;
            cout << "Alamat\t\t\t\t: " << skrg->alamat << endl;
            cout << "Nomor Telepon\t\t\t: " << skrg->noTelp << endl;
            cout << "Tanggal Lahir\t\t\t: " << skrg->tglLahir << endl;
            cout << "Jenis Kelamin\t\t\t: " << skrg->gender << endl;
            cout << "Tanggal Kadaluarsa\t\t: " << skrg->expire << endl;
            ditemukan = true;
        }
        skrg = skrg->next;
    }
    if (!ditemukan)
    {
        cout << "Anggota dengan nama '" << nama << "' tidak berhasil ditemukan." << endl;
    }

    //deklarasi input untuk pilihan
    string balik;
    //deklarasi untuk mengkonfirmasi data yang akan dihapus
    string confirmasi;

    //pilihan buat user ingin kemana
    cout << "\nPilihan: \n";
    cout << "1. Cari lagi\n";
    cout << "2. Edit data anggota\n";
    cout << "3. Hapus data anggota\n";
    cout << "4. Kembali ke menu\n";
    cin >> balik;

    if (balik == "1"){
        bersih();
        cariAnggota();
    } else if (balik == "2"){
        bersih();
        editAnggota(nama);
    } else if (balik == "3"){
        cout << "Apakah anda yakin ingin menghapus data? (Y/N)";
        cin >> confirmasi;

        if (confirmasi == "Y" || confirmasi == "y"){
        //setelah dikonfirmasi akan dihapus, maka fungsi hapus akan dipanggil
        hapusAnggota(nama);
        } else
        cout << "Tekan ENTER untuk kembali ke menu" << endl;
        cin.ignore();
        cin.get();
        bersih();
        return menu();
    } else {
        bersih();
        header();
        return menu();
    }

    cin.ignore();
    cin.get();
}

//fungsi buat nampilin seluruh anggota gym yang telah terdaftar
void tampilAnggota()
{
    bersih();
    header();
    cout << "||                   SELURUH ANGGOTA GYM                    ||\n";
    cout << "==============================================================\n";
    anggotaGym *sementara = awal;
    while (sementara != NULL)
    {
        cout << "Nama\t\t\t\t: " << sementara->nama << endl;
        cout << "Alamat\t\t\t\t: " << sementara->alamat << endl;
        cout << "Nomor Telepon\t\t\t: " << sementara->noTelp << endl;
        cout << "Tanggal Lahir\t\t\t: " << sementara->tglLahir << endl;
        cout << "Jenis Kelamin\t\t\t: " << sementara->gender << endl;
        cout << "Tanggal Kadaluarsa\t\t: " << sementara->expire << endl;
        cout << endl;
        sementara = sementara->next;
    }
    cout << "tekan ENTER untuk kembali ke menu" << endl;
    cin.ignore();
    cin.get();
}

//fungsi buat edit data anggota yang bisa diakses melalui cari data lalu setelah data ketemu pilih opsi edit data
void editAnggota(string nama)
{
    bersih();
    header();
    cout << "||                   EDIT DATA ANGGOTA                      ||\n";
    cout << "==============================================================\n";

    //cari data anggotanya dan dipindahkan ke wadah sementara yaitu skrg
    anggotaGym *skrg=awal;

    while (skrg != NULL)
    {
        if (skrg->nama == nama)
        {
            //input data baru lagi untuk menggantikan data lama
            cout << "Masukkan data baru untuk '" << nama << "'" << endl;
            cout << "Nama\t\t\t: ";
            cin.ignore();
            getline(cin, skrg->nama);
            cout << "Alamat\t\t\t: ";
            getline(cin, skrg->alamat);
            cout << "Nomor Telepon\t\t: ";
            getline(cin, skrg->noTelp);
            cout << "Tanggal Lahir\t\t: ";
            getline(cin, skrg->tglLahir);
            cout << "Jenis Kelamin\t\t: ";
            getline(cin, skrg->gender);
            cout << "Tanggal Kadaluarsa\t: ";
            getline(cin, skrg->expire);

            cout << "Data anggota telah berhasil diubah, tekan ENTER untuk kembali ke menu" << endl;
            return menu();
        }
        skrg = skrg->next;
    }
    cout << "Anggota dengan nama '" << nama << "' tidak berhasil ditemukan." << endl;

}


//fungsi hapus data anggota yang dipanggil di menu cari anggota
void hapusAnggota(string nama) {
    anggotaGym *skrg = awal;
    anggotaGym *hapus = NULL;

    while (skrg != NULL) {
        if (skrg->nama == nama) {
            hapus = skrg;
            //setelah data ditemukan dan dipindahkan dari wadah skrg ke wadah hapus untuk dihapus
            //dibawah ini adalah proses penyambungan kembali pointer setelah salah satu data dihapus
            if (skrg == awal) {
                awal = skrg->next;
                if (awal != NULL)
                    awal->prev = NULL;
            } else if (skrg == akhir) {
                akhir = skrg->prev;
                akhir->next = NULL;
            } else {
                skrg->prev->next = skrg->next;
                skrg->next->prev = skrg->prev;
            }

            //disini maka data resmi dihapus
            delete hapus;
            cout << "Data anggota tersebut berhasil dihapus\n\nTekan ENTER untuk kembali ke menu" << endl;
            return;
        }

        skrg = skrg->next;
    }
    cout << "Anggota dengan nama '" << nama << "' tidak ditemukan.\n\nTekan ENTER untuk kembali ke menu" << endl;
}

//fungsi menambahkan kelas yang ada di gym
void tambahKelas()
{
    bersih();
    header();
    cout << "||                   TAMBAH DATA KELAS                      ||\n";
    cout << "==============================================================\n";

    //karena menggunakan array 1 dimensi, maka menggunakan iterasi untuk mencari slot kosong karena array terbatas
    for (int i = 0; i < jmlKelas; i++) {
        if (kelas[i].namaKelas == "") {
            cout << "Nama Kelas\t\t: ";
            cin.ignore();
            getline(cin, kelas[i].namaKelas);
            cout << "Jam Kelas\t\t: ";
            getline(cin, kelas[i].jamKelas);
            cout << "Hari Kelas\t\t: ";
            getline(cin, kelas[i].hariKelas);
            cout << "Nama Pengurus\t\t: ";
            getline(cin, kelas[i].pengurus);
            cout << "Data berhasil ditambahkan, tekan ENTER untuk kembali ke menu." << endl;
            cin.ignore();
            return menu();

        }
    }

    //kalau sudah tidak ada tempat lagi di array
    cout << "Tidak dapat menambahkan kelas baru. Kapasitas maksimum telah tercapai." << endl;
    cout << "Tekan ENTER untuk kembali ke menu." << endl;
    cin.ignore();
    cin.get();
    return menu();
}

//fungsi menampilkan seluruh data kelas
void tampilKelas()
{
    bersih();
    header();
    cout << "||                   SELURUH JADWAL KELAS                   ||\n";
    cout << "==============================================================\n";

    for (int i = 0; i < jmlKelas; i++){
         if (kelas[i].namaKelas != "") {
            cout << "Nama Kelas\t\t: " << kelas[i].namaKelas << endl;
            cout << "Waktu Kelas\t\t: " << kelas[i].jamKelas << endl;
            cout << "Hari Kelas\t\t: " << kelas[i].hariKelas << endl;
            cout << "Nama Pengurus\t\t: " << kelas[i].pengurus << endl;
            cout << endl;
        }
    }
    cout << "Tekan ENTER untuk kembali ke menu" << endl;
    cin.ignore();
    cin.get();
    return menu();
}

//fungsi mencari data kelas, setelah ketemu kelasnya dapat diedit maupun dihapus
void cariKelas()
{
    bersih();
    header();
    bool ketemu = false;
    string cariDataKelas;
    cout << "||                     CARI JADWAL KELAS                    ||\n";
    cout << "==============================================================\n";
    cout << "Masukkan nama dari kelas yang ingin anda cari: ";
    cin >> cariDataKelas;

    for (int i = 0; i < jmlKelas; i++)
    {
        if (kelas[i].namaKelas == cariDataKelas)
        {
            cout << "Data berhasil ditemukan!\n";
            cout << "Nama Kelas\t\t: " << kelas[i].namaKelas << endl;
            cout << "Waktu Kelas\t\t: " << kelas[i].jamKelas << endl;
            cout << "Hari Kelas\t\t: " << kelas[i].hariKelas << endl;
            cout << "Nama Pengurus\t\t: " << kelas[i].pengurus << endl;
            ketemu = true;

            //pilihan buat melakukan tindakan selanjutnya
            cout << "\nPilihan: \n";
            cout << "[1] Hapus Data\n";
            cout << "[2] Edit Data\n";
            cout << "[3] Kembali ke Menu Pilihan\n";
            cout << "Masukkan pilihan: ";
            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
{
    char hapusKelas;
    cout << "Apakah anda yakin ingin menghapus data? (Y/N)";
    cin >> hapusKelas;

    //untuk data kelas karena menggunakan array maka hapus suatu data tidak sepanjang di linked list, makanya ga dibuat fungsi khusus
    if (hapusKelas == 'Y' || hapusKelas == 'y') {
        for (int i = 0; i < jmlKelas; i++) {
            if (kelas[i].namaKelas == cariDataKelas) {
                for (int j = i; j < jmlKelas - 1; j++) {
                    kelas[j] = kelas[j + 1];
                }
                kelas[jmlKelas - 1] = {};
                cout << "\nData kelas berhasil dihapus." << endl;
                cin.ignore();
                cin.get();
                return menu();
            }
        }
    }
    else {
        cout << "\nPenghapusan data kelas dibatalkan." << endl;
    }
    break;

    return menu();
}
            case 2:
                bersih();
                editKelas(kelas[i].namaKelas);
                break;
            default:
                return menu();
                break;
            }
        }
    }

    if (!ketemu)
    {
        cout << "Data kelas tidak berhasil ditemukan" << endl;
    }

    cout << "Tekan ENTER untuk kembali ke menu." << endl;
    cin.ignore();
    cin.get();
    return menu();
}

//fungsi editkelas yang nanti dipanggil di cari kelas
void editKelas(string namaKelas)
{
    bersih();
    header();
    cout << "||                     EDIT DATA KELAS                      ||\n";
    cout << "==============================================================\n";
    for (int i = 0; i < jmlKelas; i++)
    {
        if (kelas[i].namaKelas == namaKelas)
        {
            cout << "Masukkan data kelas baru" << endl;
            cout << "Nama Kelas\t\t: ";
            cin.ignore();
            getline(cin, kelas[i].namaKelas);
            cout << "Waktu Kelas\t\t: ";
            getline(cin, kelas[i].jamKelas);
            cout << "Hari Kelas\t\t: ";
            getline(cin, kelas[i].hariKelas);
            cout << "Nama Pengurus\t\t: ";
            getline(cin, kelas[i].pengurus);

            cout << "Data kelas berhasil diubah, tekan ENTER untuk kembali ke menu." << endl;
            cin.ignore();
            return menu();

        }
    }
}
