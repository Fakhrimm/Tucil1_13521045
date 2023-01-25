# Tugas kecil 1 Strategi Algoritma

Fakhri Muhammad Mahendra - 13521045

## Daftar Isi

- [Tugas kecil 1 Strategi Algoritma](#tugas-kecil-1-strategi-algoritma)
  - [Daftar Isi](#Daftar-Isi)
  - [Deskripsi Permasalahan](#Deskripsi-Permasalahan)
  - [Algoritma yang digunakan](#Algoritma-yang-digunakan)
  - [Cara Menggunakan Program](#Cara-Menggunakan-Program)
  - [Library yang Dipakai](#Library-yang-Dipakai)


## Deskripsi Permasalahan

Permasalahan yang diusung adalah tentang menyelesaiakan permaianan 24 dengan melakukan pendekatan brute force

Permainan 24 ada adalah permainan kartu dimana tiap pemain diberi tugas untuk menyusun 4 kartu bernilai 1-13 yang terpilih secara acak, sedemikian rupa sehingga kombinasi angka-angka tersebut bersama dengan operator-operator (tambah, kurang, kali, dan bagi) bisa memiliki nilai 24

## Algoritma yang digunakan

Pada permasalahan ini digunakan algoritma pendekatan brute force, yaitu dengan exhaustive search. Dimana program akan mencari setiap kombinasi yang mungkin dari kartu-kartu yang tersedia beserta permutasi dari operator-operatornya yang mungkin


## Cara Menggunakan Program

Pada Windows, program bisa dikompilasi pada *root directory* dengan menjalankan
```
g++ src/main.cpp -o bin/main
```
Maka *file executable* akan berada di folder bin

File tersebut bisa di *run* dengan perintah
```
bin/main.exe
```
di terminal

## Library yang Dipakai

1. iostream (c++)
2. vector (c++)
3. string (c++)
4. cstdio (c++)
5. vector (c++)
6. cstdlib (c++)
7. time.h (c++)
8. chrono (c++)