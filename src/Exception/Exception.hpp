#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
using namespace std;

class Exception{
    public:
        Exception();
        virtual void what() const throw() = 0;
};

class SalahFormatFile: public Exception{
    public:
        SalahFormatFile();
        void what() const throw();
};

class BelumAdaAbility: public Exception{
    public:
        BelumAdaAbility();
        void what() const throw();
};

class InputSalah: public Exception{
    public:
        InputSalah();
        void what() const throw();
};

class TidakPunyaKartuAbility: public Exception{
    public:
        TidakPunyaKartuAbility();
        void what() const throw();
};

class KartuDimatikan: public Exception{
    public:
        KartuDimatikan();
        void what() const throw();  
};

class ReverseNext: public Exception{
    public:
        ReverseNext();
        void what() const throw();
};

class EndTurnErr: public Exception{
    public:
        EndTurnErr();
        void what() const throw();
};

class WrongCard: public Exception{
    public :
        WrongCard();
        void what() const throw();
};

class DifferentType: public Exception{
    public:
        DifferentType();
        void what() const throw();
};

class WrongInput: public Exception{
    public:
        WrongInput();
        void what() const throw();
};

class CardIndexErr: public Exception{
    public:
        CardIndexErr();
        void what() const throw();
};

#endif