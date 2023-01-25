#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <vector>
#include "module.cpp"
#include <cstdio> 

using namespace std;
using namespace std::chrono;

int main () {
    // KAMUS
    bool valid;
    int i, j, k, m, holder;
    int op1, op2, op3, bracketType;
    int permutation_count, solution_count, string_length;
    string input_string, file_name;
    vector<int> card;
    vector<vector<int>> permutation_result;
    vector<string> solution;

    // ALGORITMA UTAMA
    // Inisialisasi
    valid = false;
    // Validasi input pilihan 4 kartu
    while (!valid) {
        printf("Apakah ingin memasukkan input sendiri\natau random ?\n");
        printf("1. Random Saja\n");
        printf("2. Masukkan Sendiri\n");
        printf("Input: ");
        cin >> input_string;
        if (input_string == "1") {
            card = random_input();
            valid = true;
        } else if (input_string  == "2") {
            card = user_input();
            valid = true;
        } else {
            printf("Masukkan input yang sesuai (1 atau 2)\n");
        }
    }
    // Dimulainya perhitungan waktu
    auto start = high_resolution_clock::now();
    // Didapatkan daftar dari semua permutas 4 kartu yang mungkin
    permutation_result = four_permutator(card);
    permutation_count = permutation_result.size();
    
    // Dilakukan iterasi terhadap seluruh kemungkinan operator yang mungkin dan seluruh kemungkinan
    // skema kurung yang mungkin
    for (i = 0; i <= permutation_count - 1; i++) {
        for (op1 = 1; op1 <= 4; op1++) {
            for (op2 = 1; op2 <= 4; op2++) {
                for (op3 = 1; op3 <= 4; op3++) {
                    for (bracketType = 1; bracketType <= 5; bracketType++) {
                        // Dilakukan evaluasi dari nilai-nilai operator dan skema yang didapat
                        if (24 == evaluator(permutation_result.at(i), bracketType, op1, op2, op3)) {
                            // Jika nilai nya sudah pas 24, maka representasi string nya akan dimasukan ke vector solution
                            solution.push_back(stringConverter(permutation_result.at(i), bracketType, op1, op2, op3));
                        }
                    }
                }
            }
        }
    }
    // Perhentian menghitung waktu dan handling output waktu
    auto stop = high_resolution_clock::now();
    solution_count = solution.size();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() <<  " microseconds" << endl;
    
    // Handling kasus tidak ada solusi
    if (solution_count == 0) {
        printf("Tidak ada solusi yang ditemukan");
    } else {
        cout << "Banyak nya solusi adalah " << solution_count;
        cout << "\n";

        valid = false;
        // Handling valisasi input, dimana pengguna bisa memilih tempat
        // Untuk menaruh jawaban
        while (!valid) {
            printf("Apakah ingin tunjukan solusi di\nterminal atau simpan ke file ?\n");
            printf("1. Simpan ke file\n");
            printf("2. Tunjukkan ke terminal\n");
            printf("Input: ");
            scanf("%d", &holder);
            if (holder == 1) {
                printf("Tulis nama file txt untuk menyimpan\nsolusi\n");
                printf("Input nama file: ");
                cin >> file_name;
                file_name = "test/" + file_name + ".txt";
                freopen(file_name.c_str(),"w+",stdout); 
                for (i = 0; i <= solution_count - 1; i++) {
                    cout << solution.at(i) + "\n";
                }
                valid = true;
            } else if (holder == 2) {
                for (i = 0; i <= solution_count - 1; i++) {
                    cout << solution.at(i) + "\n";
                }
                valid = true;
            } else {
                printf("Masukkan input yang sesuai (1 atau 2)\n");
            }

        }
    }
    

    
    
    return 0;
}