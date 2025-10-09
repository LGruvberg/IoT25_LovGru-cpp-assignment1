#include <iostream>
#include <limits> // för hantering av irrelevant input.
#include <string>

int val; // Här anges i förväg att det finns 4 variabler som användaren kommer att ange värdet på senare.
double input1, input2, result; // double för att kunna cout:a och cin:a decimaltal
std::string oper;
std::string symbol;

// arrayer med 4 string-värden, 0 är Addition +, 1 är Subtraktion -, osv.
std::string operNames[4] = { "Addition", "Subtraktion", "Multiplikation", "Division" };
std::string operSymbol[4] = { "+", "-", "x", "/" };

void menyUI() {
    int val;
    std::cout   <<  "Meny | Välj mellan alternativen 1 till 5\n"
        << "\t1. " << operNames[0] << "\n"  //  Cout:ar arrayens första strängvariabel (dvs 0) som ju är 'Addition'
        << "\t2. " << operNames[1] << "\n"  //  osv...
        << "\t3. " << operNames[2] << "\n"
        << "\t4. " << operNames[3] << "\n"
        << "\t5. Avsluta\n\n"
        << "\tAlternativ:\t";
    }

std::string inputOperations() {
    oper    = operNames[val-1];     // användarinput (exempelvis 'val = 1') subtraheras med 1 och blir 0, enligt "array-ordning", 0 (oper = "Addition")
    symbol  = operSymbol[val-1];    // -||-
    
    std::cout   << oper << ", tal 1:\t";
    std::cin    >> input1;
    std::cout   << oper << ", tal 2:\t" << symbol << " ";
    std::cin    >> input2;
    return oper;
}

int main() {
    while (true) {
        menyUI(); // Kalla funktion menyUI
        std::cin >> val;
        
        if (std::cin.fail() || val < 1 || val > 5) { // Här hamnar vi vid felaktig input (t ex 'abc') ELLER om input är mindre än 1 ELLER större än 5
            std::cout   << "::::::::::::::::::::::::::::::::::::::::\n"
                        << "Det där är inte en siffra mellan 1-5 :/\n\t"
                        << "Försök igen\n"
                        << "::::::::::::::::::::::::::::::::::::::::\n";          
            std::cin.clear();   // Reset:ar flag för "dålig character input" 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
/* Ledsen för GIGANTISKT kommentarsblock nedan (ville bara dokumentera min uppfattning av 
raderna ovan. Rätta gärna om jag har missuppfattat, annars helt OK att titta bort!)
'cin.ignore'
    → ignorera lagrad character input
'numeric_limits<streamsize>::max()'
    →   ... av datatyper (numeric_limits) från största möjliga (max) dataflöde (streamsize) 
        ... tills vi når '\n' (alltså där användaren matade in ENTER).
Jag hade kunnat skriva "cin.ignore(100)", men genom att använda max() så behöver vi inte 
oroa oss för att användaren skulle ange över 100 i length.
Jag testade att klistra in hela Hamlet som input, efter att ha tryckt 
ENTER så avvärjade den det lika snabbt som en normalstor input, coolt :o */
            continue; // lämna if och hoppa tillbaka upp till toppen av loopen igen/ta fram menyn
        }

        if (val == 5) {
            std::cout << "\n\tOK\n\tHEJDÅ\n";
            break;
        }

        switch (val) {
            case 1: {   // Addition
                std::string oper = inputOperations();
                result = input1 + input2;
                std::cout << "\n" << oper << "\nResultat:\t" 
                << input1 << " + " << input2 << " = " << result << "\n\n";
                break;
            }
            case 2: {   // Subtraktion
                std::string oper = inputOperations();
                result = input1 - input2;
                std::cout << "\n" << oper << "\nResultat:\t" 
                << input1 << " - " << input2 << " = " << result << "\n\n";
                break;
            }
            case 3: {   // Multiplikation
                std::string oper = inputOperations();
                result = input1 * input2;
                std::cout << "\n" << oper << "\nResultat:\t" 
                << input1 << " x " << input2 << " = " << result << "\n\n";
                break;
            }
            case 4: {   // Division
                std::string oper = inputOperations();
                if (input1 == 0 && input2 == 0) {   // Hantera 0/0
                    while (true) {  //  Straff i form av obehaglig loop utan break
                        std::cout << "( ctrl + c )\nVAD\tHAR\tDU\tGJORT\t?\t!\tskäms!\t";
                    }
                } else {
                    result = input1 / input2;
                    std::cout << "\n" << oper << "\nResultat:\t" 
                    << input1 << " / " << input2 << " = " << result << "\n\n";
                }
                break;
            }
        }
    }
    return 0;
}