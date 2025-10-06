//  Kravspecifikation:
/* 1. Datainmatning     DONE
    a. Användaren ska kunna ange ett antal mätvärden manuellt.
    b. Programmet ska hantera ogiltig input på ett robust sätt.
    c. (Utmaning: tillåt både hel- och decimaltal)  */
/* 2. Databehandling
    a. Beräkna och visa:
        i. Antal värden
        ii. Summa
        iii. Medelvärde
        iv. Min- och max-värde
        v. Varians och standardavvikelse    */
/* 3. Menygränssnitt (UI)
    a. Användaren ska kunna välja va de vill göra via en meny:
        i. Lägg till nya mätvärden
        ii. Visa statistiken
        iii. Söka efter ett visst värde
        iv. Sortera listan av mätvärden (valfritt: stigande/fallande)
        v. Avsluta programmet   */
/* 4. Struktur och kvalitet
    a. Programmet ska vara uppdelat i flera funktioner (eller metoder om du vill använda C++)
    b. Koden ska vara väl kommenterad och dokumenterad
    c. Programmet ska hantera fel (t.ex. tom lista vid analys)  */
/* 5. Extra utmaningar för högre betyg (välj en eller två, eller kom med eget förslag)
    a. Simulera en sensorström
        i. Generera slumpmässiga temperaturvärden (t.ex. 20–30 °C).
        ii. Låt användaren välja antalet värden att simulera.
        iii. Analysera sedan dessa värden (som om de kom från en IoT-sensor).
    b. Tidsstämpla värden/mätningar
        i. Koppla varje mätvärde till en enkel tidsstämpel (t.ex. "mätning 1 kl. 10:01").
        ii. Vid utskrift av statistiken, visa vilket mätvärde som var högst/lägst och vid vilken tidpunkt. Påminner om verkliga IoT-loggar, där varje datapunkt har metadata.
    c. Tröskelvärdesanalys (threshold detection)
        i. Låt användaren ange en kritisk gräns, t.ex. 25 °C.
        ii. Programmet ska räkna hur många gånger värdet låg över eller under gränsen. Liknarl larmfunktioner i IoT-system (”för varmt i serverrummet”).
    d. Glidande medelvärde (moving average)
        i. Implementera en funktion som räknar ut ett medelvärde över de senaste 3 (eller 5) mätvärdena.
        ii. Jämför med det totala medelvärdet. Vanlig metod för att jämna ut brusiga sensordata.
    e. Visuell representation (ASCII-diagram)
        i. Rita t.ex. ett histogram av mätvärdena i terminalen. */
//  Godkänd: Uppfyller kraven 1-4 enligt specifikation.
/*  Väl Godkänd: Studenten har dessutom implementerat minst en eller två extra funktionaliteter, beroende på utmaningens komplexitet. 
    Studenten har även motiverat sina tekniska val i dokumentationen.*/

#include <iostream>
#include <limits>   // den här behövde jag för hantering av att användaren anger irrelevanta datatyper (line 73).
#include <string>

// int val;
int val;                        
double input1, input2, result;  // Här anges i förväg att det finns tre double-variabler. Värdet på dessa (även 'int val') kommer att defineras av användaren. 
                                // Jag använder double för att kunna cout:a och cin:a både hel- och decimaltal från användaren
std::string operNames[4] = { "Addition", "Subtraktion", "Multiplikation", "Division" }; // Jag gör operNames till en string-array som håller 4 värden, där 0 är Addition, 1 är Subtraktion, osv.

int main() {
    while (true) {
        std::cout   <<  "Meny | Välj mellan alternativen 1 till 5\n"
        << "\t1. " << operNames[0] << "\n"  //  Cout:ar arrayens första strängvariabel (dvs 0) som ju är 'Addition'
        << "\t2. " << operNames[1] << "\n"  //  Cout:ar arrayens andra strängvariabel (dvs 1), 'Subtraktion'
        << "\t3. " << operNames[2] << "\n"  //  osv...
        << "\t4. " << operNames[3] << "\n"
        << "\t5. Avsluta\n\n"
        << "\tSvar: ";
        std::cin >> val;
        
        if (std::cin.fail() || val < 1 || val > 5) {  // Felaktig input (char) ELLER om input är mindre än 1 ELLER större än 5
            std::cout << "::::::::::::::::::::::::::::::::::::::::\n"
            << "Det där är inte en siffra mellan 1-5 :/\n"
                      << "\tFörsök igen\n"
                      << "::::::::::::::::::::::::::::::::::::::::\n";          
            std::cin.clear();   // Reset:ar flag för "dålig character input" 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Rensar lagrad input
            /*  cin.ignore →        ignorera lagrad input ... 
                numeric_limits → ... av aritmetiska typer (integraltal och flyt-tal)
                streamsize>::max(), '\n'); → från största möjliga värdet från dataflöde, tills du når '\n'
                
            Jag hade kunnat skriva "std::cin.ignore(10)", men genom att använda 
            numeric_limits<streamsize>::max() så behöver jag inte oroa mig om 
            användaren skulle ange inputs över 10 eller 100 (jag klistrade in Hamlet som input, det klarade den av väldigt bra) */
            continue;           // skippa resten, återgå
        }
        if (val == 5) {
            std::cout << "\n\tOK\n\tHEJDÅ\n";
            break;
        }
        switch (val) {
            case 1: {
                std::string oper = operNames[val-1]; // Kallar på operNames-arrayen, använder användarens input ('val', som här är 1), men subtraherar 1 så att det blir enligt arrayens "ordning", dvs 0 ('Addition')
                std::cout << oper << ", tal 1:\t";
                std::cin >> input1;
                std::cout << oper << ", tal 2:\t+ ";
                std::cin >> input2;
                result = input1 + input2;
                std::cout << "\n" << oper << "\nResultat:\t" 
                << input1 << " + " << input2 << " = " << result << "\n\n";
                break;
            }
            case 2: {
                std::string oper = operNames[val-1];    //  Tidigare std::string oper = "Subtraktion";
                std::cout << oper << ", tal 1:\t";
                std::cin >> input1;
                std::cout << oper << ", tal 2:\t- ";
                std::cin >> input2;
                result = input1 - input2;
                std::cout << "\n" << oper << "\nResultat:\t" 
                << input1 << " - " << input2 << " = " << result << "\n\n";
                break;
            }
            case 3: { 
                std::string oper = operNames[val-1];    // Tidigare std::string oper = "Multiplikation";
                std::cout << oper << ", tal 1:\t";
                std::cin >> input1;
                std::cout << oper << ", tal 2:\tx ";
                std::cin >> input2;
                result = input1 * input2;
                std::cout << "\n" << oper << "\nResultat:\t" 
                << input1 << " x " << input2 << " = " << result << "\n\n";
                break;
            }
            case 4: {
                std::string oper = operNames[val-1];    // Tidigare std::string oper = "Division";
                std::cout << oper << ", tal 1:\t";
                std::cin >> input1;
                std::cout << oper << ", tal 2:\t/ ";
                std::cin >> input2;
                if (input1 == 0 && input2 == 0) {
                    while (true) {  //  Straffar användaren med obehaglig loop utan break
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