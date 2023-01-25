#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

/**
 * @brief Fungsi menerima masukan bilangan bulat, dan mengeluarkan 
 * string kartu yang merepresentasikan nilai tersebut 
 * 
 * 
 * @param i masukan nilai bilangan bulat
 * @return string kartu yang direpresentasikan
 */
string cardToString(int i) {
    switch(i) {
        case 1:
            return "A";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "10";
        case 11:
            return "J";
        case 12:
            return "Q";
        case 13:
            return "K";
        default:
            return "0";
    }
}
/**
 * @brief Fungsi merubah representasi kartu dalam char
 * dengan nilai bilangan bulatnya
 * 
 * @param c string masukan
 * @return int bilangan bulat yang merepresentasikan kartu
 * tersebut
 */
int stringToCard(char c) {
    switch(c) {
        case 'A':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'J':
            return 11;
        case 'Q':
            return 12;
        case 'K':
            return 13;
        default:
            return 0;
    }
}
/**
 * @brief Fungsi yang mengembalikan suatu vektor beranggotakan 4
 * yang merepresentasikan nilai dari 4 kartu yang dipilih acak
 * 
 * @return vector<int> Keluaran vector berisi 4 kartu
 */
vector<int> random_input () {
    // KAMUS LOKAL
    int i, holder;
    vector<int> card;
    // ALGORITMA
    srand(time(0));
    printf("Masukan Random:\n");
    for (i = 0; i <= 3; i++) {
        holder = (rand() % 12) + 1;
        card.push_back(holder);
        cout << cardToString(holder) + " ";
    }
    cout << "\n";
    return card;
}
/**
 * @brief Fungsi menghandle validasi sekaligus mengambil input
 * pengguna dari 4 kartu yang bisa dipilih
 * 
 * @return vector<int> 4 kartu pilihan pengguna
 */
vector<int> user_input () {
    // KAMUS LOKAL
    bool valid;
    int i;
    int string_length;
    string input_string;
    vector<int> card;
    // ALGORITMA
    valid = false;
    while (!valid) {
        printf("Masukkan 4 simbol kartu\n");
        printf("Daftar simbol valid: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K\n");
        printf("Input: ");
        cin.clear(); cin.sync();
        getline (cin, input_string);
        string_length = input_string.size();
        card.clear();
        i = 0;
        if ((string_length < 7) || (input_string[0] == ' ')) {
            printf("Masukkan kurang tepat, coba diulangi lagi\n");
            continue;
        }
        if ((input_string[i] == '1') && (input_string[i+1] == '0')) {
            card.push_back(10);
            i = i + 2;
        } else if (stringToCard(input_string[i]) != 0) {
            card.push_back(stringToCard((input_string[i])));
            i = i + 1;
        } else {
            printf("Masukkan kurang tepat, coba diulangi lagi\n");
            continue;
        }
        if (input_string[i] != ' ') {
            printf("Masukkan kurang tepat, coba diulangi lagi\n");
            continue;
        } 
        i = i+1;
        if ((input_string[i] == '1') && (input_string[i+1] == '0')) {
            card.push_back(10);
            i = i + 2;
        } else if (stringToCard(input_string[i]) != 0) {
            card.push_back(stringToCard((input_string[i])));
            i = i + 1;
        } else {
            printf("Masukkan kurang tepat, coba diulangi lagi\n");
            continue;
        }
        if (input_string[i] != ' ') {
            printf("Masukkan kurang tepat, coba diulangi lagi\n");
            continue;
        }
        i = i+1;
        if ((i + 1 < string_length) && (input_string[i] == '1') && (input_string[i+1] == '0')) {
            card.push_back(10);
            i = i + 2;
        } else if ((i < string_length) && (stringToCard(input_string[i]) != 0)) {
            card.push_back(stringToCard((input_string[i])));
            i = i + 1;
        } else {
            printf("Masukkan kurang tepat, coba diulangi lagi\n");
            continue;
        }
        if (input_string[i] != ' ') {
            printf("Masukkan kurang tepat, coba diulangi lagi\n");
            continue;
        }
        i = i+1;
        if ((i + 1 < string_length) && (input_string[i] == '1') && (input_string[i+1] == '0')) {
            card.push_back(10);
            i = i + 2;
        } else if ((i < string_length) && (stringToCard(input_string[i]) != 0)) {
            card.push_back(stringToCard((input_string[i])));
            i = i + 1;
        } else {
            printf("Masukkan kurang tepat, coba diulangi lagi\n");
            continue;
        }
        if (i != string_length) {
            printf("Masukkan kurang tepat, coba diulangi lagi\n");
            continue;
        }
        valid = true;
    }
    return card;

}
/**
 * @brief Fungsi melakukan sorting dengan skema selection sort dari
 * 4 kartu yang sudah terpilih
 * 
 * @param card vector yang berisi 4 kartu
 * @return vector<int> vector yang berisi 4 kartu terurut menaik
 */
vector<int> four_sort (vector<int> card) {
    // KAMUS LOKAL
    int i, pass, imin, temp;
    // ALGORITMA
    for (pass = 0; pass <= 2; pass++) {
        imin = pass;
        for (i = pass+1; i <= 3; i++) {
            if (card.at(i) < card.at(imin)) {
                imin = i;
            }
        }
        temp = card.at(pass);
        card.at(pass) = card.at(imin);
        card.at(imin) = temp;
    }
    return card;
}
/**
 * @brief Fungsi melakukan permutasi pada vektor berisi 4 kartu
 * dan mengembalikan vector yang berisi seluruh kemungkinan
 * permutasi tersebut
 * 
 * @param card 4 kartu yang ingin di permutasi
 * @return vector<vector<int>> daftar semua permutasi yang mungkin
 */
vector<vector<int>> four_permutator (vector<int> card) {
    // KAMUS LOKAL
    int i, j, k;
    int temp;
    vector<int> sorted, card1, card2, card3;
    vector<vector<int>> result;
    // ALGORITMA
    sorted = four_sort(card);
    // Memilih acak dari 4 kartu terdepan dan menaruhnya ke paling belakang
    for (i = 0; i <= 3; i++) {
        card = sorted;
        if ((i >= 1) && (card.at(i-1) == card.at(i))) {
            continue;
        } else {
            temp = card.at(i);
            card.erase(card.begin() + i);
            card.push_back(temp);
            card1 = card;
            // Memilih acak dari 3 kartu terdepan dan menaruhnya ke paling belakang
            for (j = 0; j <= 2; j++) {
                card = card1;
                if ((j >= 1) && (card.at(j-1) == card.at(j))) {
                    continue;
                } else {
                    temp = card.at(j);
                    card.erase(card.begin() + j);
                    card.push_back(temp);
                    card2 = card;
                    // Memilih acak dari 2 kartu terdepan dan menaruhnya ke paling belakang
                    for (k = 0; k <= 1; k++) {
                        card = card2;
                        if ((k >= 1) && (card.at(k-1) == card.at(k))) {
                            continue;
                        } else {
                            temp = card.at(k);
                            card.erase(card.begin() + k);
                            card.push_back(temp);
                            // Menyimpan hasilnya pada vektor result
                            result.push_back(card);
                        }
                    }
                }
            }
        }
    } 
    return result;
}
/**
 * @brief Fungsi menghitung nilai sebuah expresi matematika dari dua
 * bilangan bergantung kepada jenis operator yang menjadi parameter
 * 
 * @param num1 
 * @param num2 
 * @param opType jenis operator yang ingin dibuat 
 * @return double hasil perhitungannya
 */
double op(double num1, double num2, int opType) {
    switch(opType) {
        case 1:
            return num1 + num2;
        case 2:
            return num1 - num2;
        case 3:
            return num1 * num2;
        case 4:
            return num1 / num2;
        default:
            return NAN;
    }
}
/**
 * @brief Dari suatu 4 kartu, dilakukan perhitungan sesuai skema kurung yang menjadi
 * bagian dari parameter, dan operator operator yang dipilih
 * 
 * @param card kumpulan nilai dari 4 kartu
 * @param bracketType skema kurung yang dipilih (1-5)
 * @param op1 
 * @param op2 
 * @param op3 
 * @return double  hasilnya
 */
double evaluator(vector<int> card, int bracketType, int op1, int op2, int op3) {
    switch(bracketType) {
        case 1:
            return op(
                        op(
                            op(double(card.at(0)),
                                double(card.at(1)), op1), 
                                    double(card.at(2)), op2), 
                                        double(card.at(3)), op3);
        case 2:
            return op(double(card.at(0)),
                        op(double(card.at(1)),
                            op(double(card.at(2)),double(card.at(3)), op3), op2), op1);
        case 3:
            return op(
                        op(double(card.at(0)),
                            op(double(card.at(1)),
                                double(card.at(2)), op2), op1), 
                                    double(card.at(3)),  op3);
        case 4:
            return op(double(card.at(0)),
                        op(
                            op(double(card.at(1)),
                                double(card.at(2)), op2),
                                    double(card.at(3)), op3), op1);
        case 5:
            return op(
                        op(double(card.at(0)), double(card.at(1)), op1),
                            op(double(card.at(2)), double(card.at(3)), op3), op2);
        default:
            return NAN;
    }
}
/**
 * @brief Fungsi mengembalikan string yang sesuai dari jenis operator
 * pada parameter
 * 
 * @param opType 
 * @return string 
 */
string opToStr(int opType) {
    switch(opType) {
        case 1:
            return "+";
        case 2:
            return "-";
        case 3:
            return "*";
        case 4:
            return "/";
        default:
            return "";
    }
}
/**
 * @brief Mengmbalikan representasi string dari parameter-parameter berupa
 * tipe kurung, susuanan 4 kartu, dan operator-operator yang tersedia
 * 
 * @param card vector berisi 4 kartu
 * @param bracketType skema kurung yang dipilih (1-5)
 * @param op1 
 * @param op2 
 * @param op3 
 * @return string 
 */
string stringConverter(vector<int> card, int bracketType, int op1, int op2, int op3) {
    switch(bracketType) {
        case 1:
            return "((" + to_string(card.at(0)) + opToStr(op1) + to_string(card.at(1)) + ")" 
                + opToStr(op2) + to_string(card.at(2)) + ")" + opToStr(op3) + to_string(card.at(3));
        case 2:
            return to_string(card.at(0)) + opToStr(op1) + "(" + to_string(card.at(1))  
                + opToStr(op2) + "(" + to_string(card.at(2)) + opToStr(op3) + to_string(card.at(3)) + "))";
        case 3:
            return "(" + to_string(card.at(0)) + opToStr(op1) + "(" + to_string(card.at(1)) 
                + opToStr(op2) + to_string(card.at(2)) + "))" + opToStr(op3) + to_string(card.at(3));
        case 4:
            return to_string(card.at(0)) + opToStr(op1) + "((" + to_string(card.at(1)) 
                + opToStr(op2) + to_string(card.at(2)) + ")" + opToStr(op3) + to_string(card.at(3)) + ")";
        case 5:
            return "(" + to_string(card.at(0)) + opToStr(op1) + to_string(card.at(1)) + ")" 
                + opToStr(op2) + "(" + to_string(card.at(2))  + opToStr(op3) + to_string(card.at(3)) + ")";
        default:
            return "";
    }
}