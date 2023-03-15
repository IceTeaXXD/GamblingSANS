#include "TwentyFourGameManager.hpp"

TwentyFourGameManager::TwentyFourGameManager()
{
    player = new ArrOfPlayer<CandyGamePlayer>(1);
    DeckCard c1,c2,c3,c4;
    operator-(c1);operator-(c2);operator-(c3);operator-(c4);
    this->playCards + c1;
    this->playCards + c2;
    this->playCards + c3;
    this->playCards + c4;

    for(int i = 0; i < 4; i++){
        cout << "Kartu " << i+1 <<": ";
        cout << playCards.getCard(i).getNum() << endl;
    }
}

// void TwentyFourGameManager::findTwentyFour()
// {
//     /* OPERASI DENGAN TANDA KURUNG */

//     /* (a operator b) operator (c operator d) */
//     for(int i = 0; i < 4; i++){
//         double ab, cd;
//         string abText = "(";
//         ab = value((double)playCards.getCard(0).getNum(), i, (double)playCards.getCard(1).getNum());
//         abText += makestringFromOp((double)playCards.getCard(0).getNum(), i, (double)playCards.getCard(1).getNum());
//         abText += ")";
//         for (int j = 0 ; j < 4; j++){
//             cd = value((double)playCards.getCard(2).getNum(), j, (double)playCards.getCard(3).getNum());
//             string cdText = "(";
//             cdText += makestringFromOp((double)playCards.getCard(2).getNum(), j, (double)playCards.getCard(3).getNum()) + ")";
//             for (int k = 0; k < 4; k++){
//                 if(value(ab, k, cd) == 24){
//                     operationText = concateOperationsstring(abText, k, cdText);
//                     found();
//                 }
//             }
//         }
//     }

//     /* ((a operator b) operator c) operator d */
//     for (int i = 0; i < 4; i++){
//         double ab;
//         string abText = "(";
//         ab = value((double)playCards.getCard(0).getNum(), i, (double)playCards.getCard(1).getNum());
//         abText += makestringFromOp((double)playCards.getCard(0).getNum(), i, (double)playCards.getCard(1).getNum()) + ")";
//         for (int j = 0; j < 4 ; j++){
//             double c;
//             c = value(ab, j, (double)playCards.getCard(2).getNum());
//             string cText = "(" + concatestringOp(abText, j, (double)playCards.getCard(2).getNum()) + ")";
//             for (int k = 0; k<4 ;k++){
//                 if(value(c, k, (double)playCards.getCard(3).getNum()) == 24){
//                     operationText = concatestringOp(cText, k, (double)playCards.getCard(3).getNum());
//                     found();
//                 }
//             }
//         }
//     }

//     /* (a operator (b operator c)) operator d */
//     for (int i = 0; i < 4; i++){
//         double bc;
//         bc = value((double)playCards.getCard(1).getNum(), i, (double)playCards.getCard(2).getNum());
//         string bcText = "(" + makestringFromOp((double)playCards.getCard(1).getNum(), i, (double)playCards.getCard(2).getNum()) + ")";
//         for (int j = 0; j < 4 ; j++){
//             double abc;
//             abc = value((double)playCards.getCard(0).getNum(), j, bc);
//             string abcText = "(" + concateOpstring((double)playCards.getCard(0).getNum(), j, bcText) +")";
//             for (int k = 0; k<4; k++){
//                 if(value(abc, k, (double)playCards.getCard(3).getNum()) == 24){
//                     operationText = concatestringOp(abcText, k, (double)playCards.getCard(3).getNum());
//                     found();
//                 }
//             }
//         }
//     }

//     /* a operator (b operator c) operator d */
//     for (int i = 0; i < 4 ; i++){
//         double bc;
//         bc = value((double)playCards.getCard(1).getNum(), i, (double)playCards.getCard(2).getNum());
//         string bcText = "(" + makestringFromOp((double)playCards.getCard(1).getNum(), i, (double)playCards.getCard(2).getNum()) + ")";
//         for (int j = 0; j < 4 ; j++){
//             for(int k = 0; k < 4 ;k++){
//                 if((j >= 2 & k < 2) | (j >= 2 & k >=2) | (j < 2 & k < 2)){
//                     double abc;
//                     abc = value((double)playCards.getCard(0).getNum(), j, bc);
//                     string abcText = concateOpstring((double)playCards.getCard(0).getNum(), j, bcText);
//                     if(value(abc, k, (double)playCards.getCard(3).getNum())==24 & j != 2){
//                         operationText = concatestringOp(abcText, k, (double)playCards.getCard(3).getNum());
//                         found();
//                     }
//                 }else{
//                     double bcd;
//                     bcd = value(bc, k, (double)playCards.getCard(3).getNum());
//                     string bcdText = concatestringOp(bcText, k, (double)playCards.getCard(3).getNum());
//                     if(value((double)playCards.getCard(0).getNum(), j, bcd)==24){
//                         operationText = concateOpstring((double)playCards.getCard(0).getNum(), j, bcdText);
//                         found();
//                     }
//                 }
//             }
//         }
//     }

//     /* a operator b operator (c operator d) */
//     for (int i = 0; i < 4; i++){
//         double cd;
//         cd = value((double)playCards.getCard(2).getNum(), i, (double)playCards.getCard(3).getNum());
//         string cdText = "(" + makestringFromOp((double)playCards.getCard(2).getNum(), i, (double)playCards.getCard(3).getNum()) + ")";
//         for (int j = 0; j < 4; j++){
//             for (int k = 0; k < 4; k++){
//                 if((j >= 2 & k < 2) | (j>=2 & k >= 2) | (j < 2 & k < 2)){
//                     double ab;
//                     ab = value((double)playCards.getCard(0).getNum(), j, (double)playCards.getCard(1).getNum());
//                     string abText = makestringFromOp((double)playCards.getCard(0).getNum(), j, (double)playCards.getCard(1).getNum());
//                     if(value(ab, k, cd) == 24){
//                         operationText = concateOperationsstring(abText, k, cdText);
//                         found();
//                     }
//                 }else{
//                     double bcd;
//                     bcd = value((double)playCards.getCard(1).getNum(), k,cd);
//                     string bcdText = concateOpstring((double)playCards.getCard(1).getNum(), k, cdText);
//                     if(value((double)playCards.getCard(0).getNum(), j, bcd) == 24){
//                         operationText = concateOpstring((double)playCards.getCard(0).getNum(), j, bcdText);
//                         found();
//                     }
//                 }
//             }
//         }
//     }

//     /* a operator (b operator (c operator d)) */
//     for (int i = 0; i < 4; i++){
//         double cd;
//         cd = value((double)playCards.getCard(2).getNum(), i, (double)playCards.getCard(3).getNum());
//         string cdText = "("+makestringFromOp((double)playCards.getCard(2).getNum(), i, (double)playCards.getCard(3).getNum())+")";
//         for (int j = 0; j < 4; j++){
//             double bcd = value((double)playCards.getCard(1).getNum(), j, cd);
//             string bcdText = "(" + concateOpstring((double)playCards.getCard(1).getNum(), j, cdText) + ")";
//             for (int k = 0; k < 4; k++){
//                 if(value((double)playCards.getCard(0).getNum(), k, bcd) == 24){
//                     operationText = concateOpstring((double)playCards.getCard(0).getNum(), k, bcdText);
//                     found();
//                 }
//             }
//         }
//     }

//     /* a operator ((b operator c) operator d) */
//     for (int i = 0; i < 4; i++){
//         double bc = value((double)playCards.getCard(1).getNum(), i, (double)playCards.getCard(2).getNum());
//         string bcText = "(" + makestringFromOp((double)playCards.getCard(1).getNum(), i, (double)playCards.getCard(2).getNum()) + ")";
//         for (int j = 0; j < 4; j++){
//             double bcd = value(bc, j, (double)playCards.getCard(3).getNum());
//             string bcdText = "(" + concatestringOp(bcText, j, (double)playCards.getCard(3).getNum()) + ")";
//             for (int k = 0; k < 4 ; k++){
//                 if(value((double)playCards.getCard(0).getNum(), k,bcd) == 24){
//                     operationText = concateOpstring((double)playCards.getCard(0).getNum(), k, bcdText);
//                     found();
//                 }
//             }
//         }
//     }

//     /* (a value b value c) value d */
//     for (int i =0; i < 4; i++){
//         for (int j = 0; j < 4; j++){
//             double temp;
//             string tempText;
//             if ((i >= 2 & j < 2) | (i < 2 & j < 2) | (i >= 2 & j >= 2)){
//                 temp = value((double)playCards.getCard(0).getNum(), i, (double)playCards.getCard(1).getNum());
//                 temp = value(temp, j, (double)playCards.getCard(2).getNum());
//             }else{
//                 temp = value((double)playCards.getCard(1).getNum(),j, (double)playCards.getCard(2).getNum());
//                 temp = value((double)playCards.getCard(0).getNum(), i, temp);
//             }
//             tempText = "(" + makestringFromOp((double)playCards.getCard(0).getNum(),i, (double)playCards.getCard(1).getNum());
//             tempText = concatestringOp(tempText, j, (double)playCards.getCard(2).getNum()) + ")";
//             for (int k = 0; k < 4; k++){
//                 if(value(temp, k, (double)playCards.getCard(3).getNum()) == 24){
//                     operationText = concatestringOp(tempText, k, (double)playCards.getCard(3).getNum());
//                     found();
//                 }
//             }
//         }
//     }

//     /* a value (b value c value d) */
//     for (int i =0; i < 4; i++){
//         for (int j = 0; j < 4; j++){
//             double bc, cd, bcd;
//             string tempText;
//             if ((i >= 2 & j < 2) | (i < 2 & j < 2) | (i >= 2 & j >= 2)){
//                 bc = value((double)playCards.getCard(1).getNum(), i, (double)playCards.getCard(2).getNum());
//                 bcd = value(bc, j, (double)playCards.getCard(3).getNum());
//             }else{
//                 cd = value((double)playCards.getCard(2).getNum(),j, (double)playCards.getCard(3).getNum());
//                 bcd = value((double)playCards.getCard(1).getNum(), i, cd);            
//             }
//             tempText = "(" + makestringFromOp((double)playCards.getCard(1).getNum(),i, (double)playCards.getCard(2).getNum());
//             tempText = concatestringOp(tempText, j, (double)playCards.getCard(3).getNum()) + ")";
//             for (int k = 0; k < 4; k++){
//                 if(value((double)playCards.getCard(0).getNum(), k, bcd) == 24){
//                     operationText = concateOpstring((double)playCards.getCard(0).getNum(), k, tempText);
//                     found();
//                 }
//             }
//         }
//     }
// }

void TwentyFourGameManager::findTwentyFour(){}

bool TwentyFourGameManager::parseCommand(string input)
{
    vector<string>::iterator it;
    it = find(solutions.begin(), solutions.end(), input);
    if(it != solutions.end()){
        cout << "SOLUTION CORRECT!" << endl;
        return true;
    }else{
        cout << "SOLUTION INCORRECT :(" << endl;
        return false;
    }
}

double TwentyFourGameManager::value (double a, int op, double b){
    double ret = 0;
    if (op == 0){
        ret = a + b;
    } else if (op == 1){
        ret = a - b;
    } else if (op == 2){
        ret = a * b;
    } else if (op == 3){
        ret = a / b;
    }
    return ret;
}

// string TwentyFourGameManager::concateOperationsstring(string a, int op, string b){
//     string text;
//     text = "";
//     text.append(a);
//     if(op == 0){
//         text.append(" + ");
//     }else if(op == 1){
//         text.append(" - ");
//     }else if(op == 2){
//         text.append(" * ");
//     }else if(op == 3){
//         text.append(" / ");
//     }
//     text.append(b);
//     return text;
// }

// string TwentyFourGameManager::concatestringOp(string a, int op, double b){
//     string text;
//     text = "";
//     text.append(a);
//     if(op == 0){
//         text.append(" + ");
//     }else if(op == 1){
//         text.append(" - ");
//     }else if(op == 2){
//         text.append(" * ");
//     }else if(op == 3){
//         text.append(" / ");
//     }
//     text.append(b);
//     return text;
// }

// string TwentyFourGameManager::concateOpstring(double a, int op, string b){
//     string text;
//     text = "";
//     text += a;
//     if(op == 0){
//         text += " + ";
//     }else if(op == 1){
//         text += " - ";
//     }else if(op == 2){
//         text += " * ";
//     }else if(op == 3){
//         text += " / ";
//     }
//     text+=b;
//     return text;
// }

// string TwentyFourGameManager::makestringFromOp(double a, int op, double b){
//     string text;
//     text = "";
//     text += a;
//     if(op == 0){
//         text += " + ";
//     }else if(op == 1){
//         text += " - ";
//     }else if(op == 2){
//         text += " * ";
//     }else if(op == 3){
//         text += " / ";
//     }
//     text+=b;
//     return text;
// }

void TwentyFourGameManager::found()
{
    vector<string>::iterator it;
    it = find(solutions.begin(), solutions.end(), operationText);

    if(it == solutions.end())
    {
        solutions.push_back(operationText);
    }
}

string TwentyFourGameManager::getSolution(int i){
    return solutions[i];
}

int TwentyFourGameManager::getNumSolution(){ return solutions.size();}