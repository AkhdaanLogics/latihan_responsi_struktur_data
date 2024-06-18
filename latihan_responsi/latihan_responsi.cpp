#include <iostream>
#define max 5
using namespace std;

struct Perpustakaan
{
	string judul;
	string pengarang;
	int tahun;
}buku;

// Queue dimulai disini

struct Queue
{
	Perpustakaan buku[max];
	int head, tail;
}antrian;

// Menghapus data dari antrian
void init()
{
	// Mengubah head / paling depan menjadi 0 begitupun tail / paling belakang menjadi 0 juga
	antrian.head == 0;
	antrian.tail == 0;
}

bool kosong()
{
	// Jika tail = 0 maka antrian kosong (benar)
	if (antrian.tail == 0)
	{
		return true;
	}

	// Jika tidak maka antrian tidak kosong (salah)
	else
	{
		return false;
	}
}

bool penuh()
{
	// Jika tail = max maka antrian penuh (benar)
	if (antrian.tail == max)
	{
		return true;
	}

	// Jika tidak maka antrian tidak penuh (salah)
	else
	{
		return false;
	}
}

void tampilData()
{
	if (!kosong())
	{
		cout << "Data Buku yang ada di dalam antrian : " << endl;
		cout << "--------------------------------------" << endl;
		for (int i = antrian.head; i <= antrian.tail - 1; i++)
		{
			cout << "Judul Buku : " << antrian.buku[i].judul << endl;
			cout << "Pengarang : " << antrian.buku[i].pengarang << endl;
			cout << "Tahun Terbit : " << antrian.buku[i].tahun << endl;
			cout << "--------------------------------------" << endl;
		}
	}
	cout << endl;
}

void enqueue()
{
	tampilData();
	if (penuh())
	{
		cout << "Antrian Penuh" << endl;
	}
	else
	{
		cout << "Masukkan Judul Buku : ";
		cin >> antrian.buku[antrian.tail].judul;
		cout << "Masukkan Nama Pengarang : ";
		cin >> antrian.buku[antrian.tail].pengarang;
		cout << "Masukkan Tahun Terbit : ";
		cin >> antrian.buku[antrian.tail].tahun;
		antrian.tail++;
	}
	tampilData();
}

void dequeue()
{
	tampilData();
	if (kosong())
	{
		cout << "Antrian Kosong" << endl;
	}
	else
	{
		cout << "Data Buku yang dihapus : " << endl;
		cout << "--------------------------------------" << endl;
		for (int i = antrian.head; i <= antrian.tail - 1; i++)
		{
			cout << "Judul Buku : " << antrian.buku[i].judul << endl;
			cout << "Pengarang : " << antrian.buku[i].pengarang << endl;
			cout << "Tahun Terbit : " << antrian.buku[i].tahun << endl;
			cout << "--------------------------------------" << endl;
		}
		antrian.tail--;
	}
	tampilData();
}

// Queue berhenti disini


// Sorting dimulai disini

int i, j, temp;
void sortAsc()
{
	cout << "Bubble Sort Ascending" << endl;
	for (i = 0; i < antrian.tail - 1; i++)
	{
		for (j = 0; j < antrian.tail - i - 1; j++)
		{
			if (antrian.buku[j].tahun > antrian.buku[j + 1].tahun)
			{
				Perpustakaan temp = antrian.buku[j];
				antrian.buku[j] = antrian.buku[j + 1];
				antrian.buku[j + 1] = temp;
			}
		}
	}
}

void sortDes()
{
	cout << "Insertion Sort Descending" << endl;
	for (i = 1; i < antrian.tail; i++)
	{
		Perpustakaan temp = antrian.buku[i];
		j = i - 1;
		while (j >= 0 && temp.tahun > antrian.buku[j].tahun)
		{
			antrian.buku[j + 1] = antrian.buku[j];
			j = j - 1;
		}
		antrian.buku[j + 1] = temp;
	}
}

// Sorting berhenti disini

// Searching dimulai disini

int ketemu, posisi[max], cari;
int x = 0;
void searching()
{
	if (kosong())
	{
		cout << "Anda belum memasukkan data buku" << endl;
	}
	else
	{
		cout << "Masukkan Tahun Terbit Buku yang dicari : ";
		cin >> cari;
		for (int i = 0; i < antrian.buku[i].tahun; i++)
		{
			if (antrian.buku[i].tahun == cari)
			{
				posisi[x] = i;
				x++;
			}
		}
		cout << endl;
		if (x == 0)
		{
			cout << "Data tidak ditemukan" << endl;
		}
		else
		{
			cout << "Data ditemukan pada posisi ke : ";
			for (int i = 0; i < x; i++)
			{
				cout << posisi[i] + 1 << " ";
			}
		}
	}
}

// Searching berhenti disini

int main()
{
	int pilihan;
	do
	{
		cout << "Menu Perpustakaan : " << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Bubble Sort Ascending" << endl;
		cout << "4. Insertion Sort Descending" << endl;
		cout << "5. Searching" << endl;
		cout << "6. Exit" << endl;
		cout << "Masukkan Pilihan : ";
		cin >> pilihan;
		switch (pilihan)
		{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			sortAsc();
			tampilData();
			break;
		case 4:
			sortDes();
			tampilData();
			break;
		case 5:
			searching();
			break;
		case 6:
			cout << "Terima Kasih" << endl;
			break;
		default:
			cout << "Pilihan tidak ada" << endl;
			break;
		}
	} while (pilihan != 6);
	return 0;
}