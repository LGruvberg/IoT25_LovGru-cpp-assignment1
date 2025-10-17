#include <iostream>
#include <iomanip>  //  För std::setw, std::setfill
#include <thread>   //  För std::this_thread::sleep_for
#include <chrono>   //  För std::chrono::seconds
#include <string>

void dinKlocka();
void felInput();
void storyDuSaNej();

bool taskig = false;
int h, m, s, menyVal;
std::string svar, nyttSvar;

int main() {

    while (true) {
        std::cout << "Klockan är ";
        // dinKlocka();
        std::cout << "det är hög tid att välja:\n1. TLDR\n2. Story-mode\n\tSvar: ";
        std::cin >> menyVal;
        if (std::cin.fail()) {  // Fånga upp dålig input
            felInput();
            continue;
        }
        std::cout << "Främling:\n\t'Ursäkta, kan du kolla hur mycket klockan är?'\n";
        switch (menyVal) {
            case 1:
                taskig == false;
                svar == "ja";
                break;
            case 2:
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "\n[Du tänker]";                               std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << ":\n\tHmm... Jag kan antingen svara 'ja'";     std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "\n\t...eller så kan jag svara 'nej' \n\n";    std::this_thread::sleep_for(std::chrono::seconds(2));

                std::cout << "\nDu svarar:\n\t'Hmm... ";
                std::cin >> svar;
            if (std::cin.fail()) {
                felInput();
                continue;
            }
            if (svar == "nej") {
                std::cout << "\t...det får du kolla upp själv.'";
                taskig = true;
                storyDuSaNej();

                std::cin >> nyttSvar;
                if (std::cin.fail()) {
                    felInput();
                    continue;
                }
                if (nyttSvar == "förlåt") {
                    // Hoppa till klockdelen direkt
                    taskig = false;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    std::cout << "\tjag spårade liksom UR\n\tKlockan är faktiskt...'\n\n";
                    svar = "ja";  // Trigga samma väg som om man svarade "ja"
        } else {
            std::cout << "\t...hejdå'";
            return 0; // Avsluta om man inte sa "förlåt"
        }
    }
    break;
}
    if (taskig == false || svar == "ja") {  // om: "nej" OCH "förlåt" ELLER "ja"
        std::this_thread::sleep_for(std::chrono::seconds(1));
        do {    // Gör: ifrågasätt input 
            std::cout << "-> Timme: \t";
            std::cin >> h;
            if (h < 0 || h > 23) {
                std::cout << "Främling:\n\tDen timmen har jag aldrig hört talas om!\n";
            }
        } while (h < 0 || h > 23);   // ...Medan timme är mindre än 0 ELLER timme är större än 23 (24 visas ju som 00:00)

        do {
            std::cout << "-> Minut: \t";
            std::cin >> m;
            if (m < 0 || m > 59) {
                std::cout << "Främling:\n\t" << h << ":" << m << "...?! Är det inte något mellan siffrorna 0 till 59?\n";
            }
        } while (m < 0 || m > 59);

        do {
            std::cout << "-> Sekund: \t";
            std::cin >> s;
            if (s < 0 || s > 59) {
                std::cout << "Ogiltig sekund... Välj bland siffrorna 0–59.\n";
            }
        } while (s < 0 || s > 59);
        
        const char pendel[] = { '|', '\\', '|', '/' };
        int pendelIndex = 0;

        std::cout << "\n:::::::::::::::\n\nDu svarar:\n\t'Självklart. Klockan är' ...\n";

        while (true) {
            std::cout << "\r\t"
                << std::setw(2) << std::setfill('0') << h << ":"
                << std::setw(2) << std::setfill('0') << m << ":"
                << std::setw(2) << std::setfill('0') << s << "\t"
                << pendel[pendelIndex] << "\t\t" << std::flush;

            pendelIndex = (pendelIndex + 1) % 4;
            std::this_thread::sleep_for(std::chrono::seconds(1));

            s++;
            if (s == 60) { s = 0; m++; }
            if (m == 60) { m = 0; h++; }
            if (h == 24) { h = 0; }
        }
    }
}
    return 0;
}

void dinKlocka() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&now_time);
    std::cout << std::setw(2) << std::setfill('0') << local_time->tm_hour << ":"
              << std::setw(2) << std::setfill('0') << local_time->tm_min << std::endl;
}
void felInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void storyDuSaNej(){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "\n\n[Främlingen ser besviken ut och svarar]\n\n\t'Ok.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\tJag kan fråga gudarna\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\t... enligt väderstrecken är hon ...\n\t";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    dinKlocka();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\t...hejdå'";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "\n\n[En del av dig vill säga 'förlåt'? Du ropar]:";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "\n\t'Halt!'";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "\n\n[Främlingen haltar och vänder sakta på huvudet]:\n\t'jöÖöh?'\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Du:\n\t'Kolla, öhh...";
}