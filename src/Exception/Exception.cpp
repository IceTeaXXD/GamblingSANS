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

ReverseNext::ReverseNext(){}

void ReverseNext::what() const throw(){
    cout << "";
}

EndTurnErr::EndTurnErr(){}

void EndTurnErr::what() const throw(){
    cin.get();
    cout << "Silakan melakukan putcard terlebih dahulu!\n";
    cout << "Press enter to continue...";
    cin.get();
}

WrongCard::WrongCard(){}

void WrongCard::what() const throw(){
    cin.get();
    cout << "Kartu yang anda masukkan tidak sesuai, pastikan memiliki warna/angka/tipe yang sama!\n";\
    cout << "Press enter to continue...";
    cin.get();
}

DifferentType::DifferentType(){}

void DifferentType::what() const throw(){
    cin.get();
    cout << "Kartu yang anda masukkan tidak sesuai, untuk melakukan combo, pastikan angka kartu sama!\n";
    cout << "Press enter to continue...";
    cin.get();
}

WrongInput::WrongInput(){}

void WrongInput::what() const throw(){
    cin.get();
    cout << "Input yang anda masukkan salah, silakan ulangi!\n";
    cout << "Press enter to continue...";
    cin.get();
}

CardIndexErr::CardIndexErr(){}

void CardIndexErr::what() const throw(){
    cin.get();
    cout << "Index kartu yang anda masukkan salah, silakan ulangi!\n";
    cout << "Press enter to continue...";
    cin.get();
}