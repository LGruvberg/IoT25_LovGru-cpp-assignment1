#include <iostream>
#include <limits> // för hantering av irrelevant input.
#include <string>

int val;
double input1, input2, result; // double för att kunna cout:a och cin:a decimaltal
std::string oper;
std::string symbol;

// arrayer med 4 string-värden, 0 är Addition +, 1 är Subtraktion -, osv.
std::string operNames[4] = { "Addition", "Subtraktion", "Multiplikation", "Division" };
std::string operSymbol[4] = { "+", "-", "x", "/" };

void felInput();
void minimenyA();   //  För att kunna ha mina minimenyfunktioner i botten - istället för här uppe - så måste jag först kalla
void minimenyB();   //  på dem här i början (förbereda C++ i förväg, eftersom att kodraderna exekveras uppifrån och nedåt)

int main() {
    int menyVal;
    while (true) {
        std::cout 
            << ".:HUVUDMENY:.\n"
            << "1. Minimeny A\n"
            << "2. Minimeny B\n"
            << "3. Avsluta\n\n\tSvar:\t";
        std::cin >> menyVal;

        switch (menyVal) {
            case 1: 
                minimenyA(); 
                break;
            case 2: 
                minimenyB(); 
                break;
            case 3:
                std::cout << "\n\t... Avslutar ...\n";
                return 0;
            default:
                // std::cout << "Felaktigt val!\n";
                felInput();
        }
    }
}
void felInput(){
    int menyVal = menyVal;
    if (std::cin.fail() || menyVal < 1 || menyVal > 5) { // Här hamnar vi vid felaktig input (t ex 'abc') ELLER om input är mindre än 1 ELLER större än 5
        std::cout   
        << "::::::::::::::::::::::::::::::::::::::::\n"
        << "Det där är inte ett alternativ mellan 1-3 :/\n\t"
        << "Försök igen\n"
        << "::::::::::::::::::::::::::::::::::::::::\n";
        std::cin.clear();   // Reset:ar flag för "dålig character input" 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }
}
void minimenyA() {
    int menyA;
    int buffertA = 0;
    while (true) {
        std::cout << "\n\t.:Minimeny A:.\n"
                  << "\t1. Skapa värden\n"
                  << "\t2. Visa statistik\n"
                  << "\t3. Tillbaka till huvudmeny\n\n\t\tSvar:\t";
        std::cin >> menyA;

        if (menyA == 3) {
            break;
    }
        if (menyA == 2 && buffertA == 0) {
            std::cout << "Det finns ingen data att visa statistik på!\nGenomför alternativ '2. Skapa värden' först.\n";
            continue;
        }

        if (menyA == 1) {
            std::cout << "\n\t\t1. Ange 5 värden\n\t\t2. Generera 5 random-värden\n";
            std::cin >> menyA;
            buffertA = 1;
        }
    }
}
void minimenyB() {
    int menyB;
    while (true) {
        std::cout << "\n\t.:Minimeny B:.\n"
                  << "\t1. Annan grej 1\n"
                  << "\t2. Annan grej 2\n"
                  << "\t3. Tillbaka till huvudmeny\n\n\t\tSvar:\t";
        std::cin >> menyB;

        if (menyB == 3) {
            break;
        }
    }
}
