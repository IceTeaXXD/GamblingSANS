#include "Exception.hpp"

Exception::Exception(){}

SalahFormatFile::SalahFormatFile(){}

void SalahFormatFile::what() const throw(){
    cout << "Salah format. Perhatikan warna dan angka yang dimasukkan!\n";
}

BelumAdaAbility::BelumAdaAbility(){}

void BelumAdaAbility::what() const throw(){
    cout << "Anda belum memiliki kartu ability!\n";
}

InputSalah::InputSalah(){}

void InputSalah::what() const throw(){
    cout << "Input Anda salah, silakan ulangi!\n";
}

TidakPunyaKartuAbility::TidakPunyaKartuAbility(){}

void TidakPunyaKartuAbility::what() const throw(){
    cout << "Eits, kamu tidak punya kartunya 😛\n";
}

KartuDimatikan::KartuDimatikan(){}

void KartuDimatikan::what() const throw(){
    cout << "Kartu anda telah dimatikan\nSilakan ulangi!\n";
}