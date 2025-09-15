#include <iostream>
#include <cstdlib>
#include <ctime>    
using namespace std;

int main() {
    const int MAX_TRIES = 5;   
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 100;

    char playAgain = 'y';   

    while (playAgain == 'y' || playAgain == 'Y') {
        srand(time(NULL));        
        int secretNumber = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;   

        cout << "Sayi Tahmin Oyununa Hosgeldiniz!\n";
        cout << "Bir sayi tuttum. " << MIN_VALUE << " ile " << MAX_VALUE << " arasinda. " << endl;
        cout << "Bakalim " << MAX_TRIES << " tahmin icinde bulabilecek misin?\n";

        int guess;
        bool found = false;

        for (int i = 1; i <= MAX_TRIES; i++) {
            cout << i << ". tahmininizi girin: ";
            cin >> guess;

            if (guess == secretNumber) {
                cout << "Tebrikler! Dogru tahmin ettiniz!\n";
                found = true;
                break;
            }
            else if (guess > secretNumber) {
                cout << "Tuttugum sayi girdiginiz sayidan kucuk!\n";
            }
            else {
                cout << "Tuttugum sayi girdiginiz sayidan buyuk!\n";
            }
        }

        if (!found) {
            cout << "Uzgunum, tahmin haklariniz bitti. Tuttugum sayi: " << secretNumber << " idi.\n\n";
        }

        cout << "Tekrar oynamak ister misini? (y/n): ";
        cin >> playAgain;
        cout << endl << endl;
    }

    cout << "Oyunu oynadiginiz icin tesekkurler!\n";
    return 0;
}
