#include <iostream> // cout, cin, endl
#include <conio.h>  // getch()
#include <string.h> // memanipulasi string ==> strcpy()
#include <windows.h> // system("cls"), system("color")
#include <stdio.h> // gets() = fungsi masukkan yang khusus untuk menerima masukkan tipe data string.

using namespace std; // menggunakan namespase std

// typedef untuk mendeklarasikan tipe data dengan nama lain atau alias (tipe data baru)
typedef struct // mempersingkat penulisan tipe data agar tipe data semakin jelas
{
    // pendefinisian variabel struct
    int kode;
    char nama[20];
    int stock;
    char lokasi[20];
} jaya;
// pendefinisian nama variabel baru
jaya barang[5];
jaya temp; //temp sebagai tempat penyimpanan sementara saat menukar nilai
int n, i, b, cari, ada = 0;

// untuk Perulangan Menu
char kembali1;

int main()
{
menu:;
    system("cls");      // Membersihkan layar
    system("color F5"); // F = Bright White 5 = Ungu // Huruf Pertama untuk Mengganti Warna Background, dan Huruf Kedua Mengganti Warna Teks

    // tampilan menu awal
    cout << "\t\t"
         << "==================================================" << endl;
    cout << "\t\t"
         << "|        PROGRAM SORTING & SEARCHING BARANG      |" << endl;
    cout << "\t\t"
         << "|                PT. JAYA JAYA JAYA              |" << endl;
    cout << "\t\t"
         << "|       PAKAIAN DAN PERALATAN REKREASI ALAM      |" << endl;
    cout << "\t\t"
         << "| JL.RAYA LAIN HATI,KAB.CINTA SEJATI, JAWA BARAT |" << endl;
    cout << "\t\t"
         << "==================================================" << endl;
    
    cout << "\t"<< "Masukkan Banyak Data = ";
    cin >> n;

    // perulangan for, agar bisa menyesuaikan dengan banyak data yang diinput
    for (i = 0; i < n; i++)
    {
        cout << endl;
        cout << "Data Ke- " << (i + 1) << ":" << endl;
        cout << "Input Kode Barang   : ";
        cin >> barang[i].kode;
        cout << "Input Nama Barang   : ";
        cin >> gets(barang[i].nama); // gets() untuk mengambil input dalam satu baris
        cout << "Input Stock Barang  : ";
        cin >> barang[i].stock;
        cout << "Input Lokasi Barang : ";
        cin >> gets(barang[i].lokasi);
        cout << endl;
    }
    // proses cetak sebelum diurutkan
    cout << "\t\t\t"
         << "Data Barang Anda" << endl;
    cout << "\t\t\t"
         << "==========================================================================" << endl;
    cout << "\t\t\t"
         << "|   Kode Barang   |   Nama Barang   |   Stock Barang   |   Lokasi Barang  |" << endl;

    for (b = 0; b < n; b++)
    {
        cout << "\t\t\t"
             << "|   " << barang[b].kode << "\t\t\t " << barang[b].nama << "\t\t\t" << barang[b].stock << "\t\t" << barang[b].lokasi << "        |" << endl;
    }
    cout << endl;
    cout << "\t\t\t"
         << "==========================================================================" << endl;

// Fungsi Sorting dengan BubbleSort
    for (i = 0; i < n; i++) //looping pertama
    {
        for (b = 0; b < n - 1; b++)// looping kedua
        {
            // fungsi swapping
            if (barang[b].kode > barang[b + 1].kode)
            {
                // menampilkan kode barang
                temp.kode = barang[b].kode;
                barang[b].kode = barang[b + 1].kode;
                barang[b + 1].kode = temp.kode; //temp sebagai tempat penyimpanan sementara saat menukar nilai

                // menampilkan nama barang
                strcpy(temp.nama, barang[b].nama);
                strcpy(barang[b].nama, barang[b + 1].nama);
                strcpy(barang[b + 1].nama, temp.nama);

                // menampilkan stok barang
                temp.stock = barang[b].stock;
                barang[b].stock = barang[b + 1].stock;
                barang[b + 1].stock = temp.stock;

                // menampilkan lokasi barang
                strcpy(temp.lokasi, barang[b].lokasi);
                strcpy(barang[b].lokasi, barang[b + 1].lokasi);
            }
        }
    }
    cout << endl;

    // menampilkan urutan barang sesudah di sorting (Ascending)
    cout << "\t\t\t"
         << "Setelah Data Diurutkan berdasarkan kode terkecil: " << endl;
    cout << "\t\t\t"
         << "==========================================================================" << endl;
    cout << "\t\t\t"
         << "|   Kode Barang   |   Nama Barang   |   Stock Barang   |   Lokasi Barang  |" << endl;
    cout << "\t\t\t"
         << "==========================================================================" << endl;

    for (b = 0; b < n; b++)
    {
        cout << "\t\t\t"
             << "|   " << barang[b].kode << "\t\t\t" << barang[b].nama << "\t\t\t" << barang[b].stock << "\t\t" << barang[b].lokasi << "        |" << endl;
    }
    cout << endl;

    cout << "\t\t\t"
         << "==========================================================================" << endl;

    cout << endl;

    // searching barang
    cout << "\t\t\t"
         << "Masukkan Kode Barang Untuk Mencari : ";
    cin >> cari;

    for (b = 0; b < n; b++)
    {
        if (barang[b].kode == barang[cari].kode)
        {

            cout << "\t\t\t"
                 << "==========================================================================" << endl;
            cout << "\t\t\t"
                 << "|       Kode Barang     |   Stock Barang       |     Lokasi Barang       |" << endl;
            cout << "\t\t\t"
                 << "==========================================================================" << endl;
            cout << "\t\t\t"
                 << "|   " << barang[cari].kode << "\t\t\t\t" << barang[cari].stock << "\t\t\t\t" << barang[cari].lokasi << "       |" << endl;
            cout << "\t\t\t"
                 << "==========================================================================" << endl;
        }
        else if (cari >= n)
        {
            cout << "Data Tidak di Temukkan " << endl;
        }
    }
    // untuk Fungsi Kembali
    cout << "Apakah Anda Ingin Kembali Ke Menu (Y/T) ? : ";
    cin >> kembali1;

    // jika kembali1 = y atau Y, kode akan dieksekusi
    if (kembali1 == 'y' || kembali1 == 'Y')
    {
        goto menu;
    }

    // jika kembali1 = t atau T, kode akan dieksekusi
    else if (kembali1 == 't' || kembali1 == 'T')
    {
        system("cls");      // Membersihkan Layar
        system("color F5"); // Mengganti Warna, F = Bright White 5 = Ungu.
        // Huruf Pertama untuk Mengganti Warna Background, dan Huruf Kedua Mengganti Warna Teks
        cout << "==================================================================" << endl;
        cout << "#      Terima Kasih Telah Berkunjung KE PT. JAYA JAYA JAYA       #" << endl;
        cout << "#             Kami Menanti Kedatangan Anda Kembali               #" << endl;
        cout << "==================================================================" << endl;
    }
    getch();
}