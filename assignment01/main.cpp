#include <iostream>     // i/o, c(haracter)out(put), c(haracter)in(put))
#include <vector>       // Dynamiska arrayer
#include <limits>       // 'std::numeric_limits', för hantering av irrelevant input (t ex att användaren anger char eller flyt-tal istället för heltal i huvudmenyn)
#include <algorithm>    // för sort
#include <cmath>        // för sq(uare)r(oo)t och pow (power of ... (pow(3, 3) -> '3 x 3 x 3 = 27'))
#include <string>
#include <numeric>      // för 'std::accumulate ...' i funktionen för summering
#include <iomanip>      // för 'std::setprecision(2)' som formatterar längden på flyttal i programmet (den är fast på 2 siffror efter decimaltecknet) 
#include <random>       // för random-generatorn

int count = 1, 
    menyVal, 
    antalVLimit;  // Gräns för antal värden att räkna ut

void    felInputMsg();
double  funkVarians(const std::vector<double>& data);
double  funkMedelV(const std::vector<double>& data);
double  funkSumma(const std::vector<double>& data);
void    funkSearch(const std::vector<double>& data);
void    dataInmatning(std::vector<double>& data);
void    funkStat(const std::vector<double>& data);
void    funkRandom(std::vector<double>& data);
void    funkSort(std::vector<double>& data);

int main() {
    std::vector<double> maetvaerden;
    int val;

    do {
        int count = 1;
        std::cout << "\n::::::::::::::::::MENY::::::::::::::::::\n"
        << "1.\tLägg till mätvärden\n"
        << "2.\tVisa statistik\n"
        << "3.\tSök efter ett befintligt värde\n"
        << "4.\tSortera befintliga värden\n"
        << "5.\tAvsluta\n"
        << "\nSvar: \t";
        std::cin >> val;

        if (std::cin.fail()) {  // Vid felaktig input (utkommenterade rader ingår i funktionen felInputMsg)
            // std::cin.clear();
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            felInputMsg();
            continue;
        }

        switch (val) {
            case 1:
                std::cout   << "Hur många värden vill du räkna?\n\tSvar: ";
                std::cin    >> antalVLimit;
                if (std::cin.fail()) {  // Vid felaktig input
                    felInputMsg();
                    continue;
                }
                dataInmatning(maetvaerden);
                break;
            case 2:
                funkStat(maetvaerden);
                break;
            case 3:
                funkSearch(maetvaerden);
                break;
            case 4:
                funkSort(maetvaerden);
                break;
            case 5:
                std::cout << "Avslutar...\n";
                break;
            default:
                // void felInputMsg();
                felInputMsg();
                break;
        }
    }
    while (val != 5); // Tills användaren avslutar programmet
    return 0;
}

void felInputMsg() {
    //
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //
    std::cout   
        << "::::::::::::::::::::::::::::::::::::::::\n"
        << "Det där är inte ett giltigt alternativ :/\n\t"
        << "Försök igen\n"
        << "::::::::::::::::::::::::::::::::::::::::\n";
}

void dataInmatning(std::vector<double>& data) {     // Vector med double-värden
    std::cout << "Ange ...\n1. Manuell inmatning (Ange " << antalVLimit << " st värden eller 'q' om du vill ange färre)\n2. Generera " << antalVLimit << " random-värden\n\tSvar:\t";
    int count = 1;
    std::string strAntalV = "värden lagrade";
    std::cin >> menyVal;
    if (menyVal == 2) {
            funkRandom(data);
        }
    if (menyVal == 1) {
        while (count <= antalVLimit) {
            std::cout << "Värde " << count << ":\t";
            std::string input;
            std::cin >> input;
        
        if (input == "q") {
            int antalV = count;
            if (data.size() == 1) {     // värdeantalet är i singular
                strAntalV = "lagrat värde";
            }
            break;
        }
        try {
            double value = stod(input);
            data.push_back(value);
        } catch(...) {
            // void felInputMsg();
            felInputMsg();
        }
        count++;
    }
}


std::cout << "\nDet finns " << data.size() << " " << strAntalV << ".\n";
}

void funkRandom(std::vector<double>& data) {
    // std::cout << "Genererar " << data.size() << "random-värden:\n";
    int count = 1;

    std::random_device rd;   // Seed ("frövärde") 
    std::mt19937 gen(rd());  // Mersenne Twister (random-generator)
    std::uniform_real_distribution<> dist(0.0, 101.0);

    // for (int i = 0; i < 5; ++i) {
    for (int i = 0; i < antalVLimit; ++i) {
        double rand = dist(gen);
        data.push_back(rand);
        std::cout << "Värde " << count << ":\t" << std::fixed << std::setprecision(2) << rand << std::endl;
        count++;
    }
}

void funkStat(const std::vector<double>& data) {
    if (data.empty()) {
        std::cout << "OBS: Du har inte lagt till några värden (välj '1' för att lägga till mätvärden).\n";
        return;
    }
    std::cout << std::fixed << std::setprecision(2);
    double sum = funkSumma(data);
    double medel = funkMedelV(data);
    double varians = funkVarians(data);
    double stdAv = sqrt(varians);
    double minv = *min_element(data.begin(), data.end());
    double maxv = *max_element(data.begin(), data.end());

    std::cout << "\n.:Statistik:.\nAv följande värden:";    // Här vill jag kunna se inmatade eller random-genererade värden
    for (double v : data) {
        std::cout << "\n->\t" << v;
    }
    std::cout << std::endl;

    std::cout << "Antal värden:\n->\t " << data.size() << "\n";
    std::cout 
    << "Summa:              \n->\t" << sum << "\n"
    << "Medelvärde:         \n->\t" << medel << "\n"
    << "Minsta värde:       \n->\t" << minv << "\n"
    << "Högsta värde:       \n->\t" << maxv << "\n"
    << "Varians:            \n->\t" << varians << "\n"
    << "Standardavvikelse:  \n->\t" << stdAv << "\n";
}

// Sök efter ett specifikt värde
void funkSearch(const std::vector<double>& data) {
    if (data.empty()) {
        std::cout << "OBS: det finns inget att söka på ... ju.\n";
        return;
    }

    std::cout << "Sök:\t";
    double searchV;
    std::cin >> searchV;

    bool finns = false;
    for (size_t i = 0; i < data.size(); ++i) {
        if (abs(data[i] - searchV) < 1e-9) {
            std::cout << "Värdet " << searchV << " hittades på position " << i + 1 << ".\n";
            finns = true;
        }
    }
    if (!finns)
        std::cout << "OBS: värdet " << searchV << " finns inte i listan.\n";
}
void funkSort(std::vector<double>& data) {
    if (data.empty()) {
        std::cout << "OBS: det finns inga värden att sortera :o\n";
        return;
    }
    // std::cout << ;
    std::cout << "Sortera:\n\t1. Stigande (ASC)\n\t2. Fallande (DESC)\n\tSvar:\t";
    int ascDesc;
    std::cin >> ascDesc;

    if (ascDesc == 1)
        sort(data.begin(), data.end());
    else if (ascDesc == 2)
        sort(data.rbegin(), data.rend());
    else {
        felInputMsg();
        return;
    }
    std::cout << "Sorterad lista:\n";
    for (double v : data) {
        std::cout << "\t" << v;
        std::cout << "\n";
    }
}
double funkSumma(const std::vector<double>& data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
        return sum;
}

double funkMedelV(const std::vector<double>& data) {
    return funkSumma(data) / data.size();   // allt i databuffern divideras med antalet element i data (och avrundas)
}
double funkVarians(const std::vector<double>& data) {
    if (data.size() < 2) { // Undvik division med 0
        return 0.0;
     } 
    double sum = 0.0;
    double medel = funkMedelV(data);
    for (double v : data) {
        double diff = v - medel;
        sum += diff * diff;
    }
    return sum / (data.size() - 1); // Dividera totalen med antalet mätvärden -1
}
