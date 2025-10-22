# lg-cpp-assignment1
This repo contains code solutions for assignment1 in the course C/C++ Programming

# LÄNK TILL GITHUB
https://github.com/LGruvberg/IoT25_LovGru-cpp-assignment1

# Beskrivning
Det här programmet låter användaren mata in 5 mätvärden (hel- eller flyttal går bra) manuellt eller genererat 
slumpmässigt (genereras som flyttal/decimaltal. Kanske en framtida uppgradering: 'hur stora tal vill du generera?').

Efter inmatning ska användaren kunna ta fram statistik som visar de angivna värdenas: 
-   Summa
-   Medelvärde
-   Lägsta angivna tal
-   Högsta angivna tal
-   Varians och standardavvikelse
-   Sortera: ascending ↔ descending

##### Potentiella förbättringar inför framtida git:
-   Göra felInputMsg(); (och kanske t.o.m. menyn) till strängvariabler istället.
-   Vissa funktioner hade jag kunnat slå ihop, som delen för summa och medelvärde, men för läsbarheten behöll jag det.
-   Att inte blanda svenska och engelska, som jag ju har gjort.

# Funktionerna
Jag valde att placera funktionerna i botten då jag tycker att det blir mer användarvänligt (kanske bara jag?) att 
man får se main-delen (helikopterperspektivet) först.

Det finns funktioner för inmatning, beräkning, sökning och sortering (bl.a.).
Vektorerna använder jag för att lagra värden, de kan växa/krympa dynamiskt, jämfört med arrayer som är statiska i storlek.


#### Information om funktionerna:
## felInputMsg();  
    Info: 
    Den här funktionen ör egentligen bara ett meddelande, inga beräkningar görs här så det är (väl) ingen "riktig funktion". (Kan göras om till strängvariabel)
## dataInmatning(std::vector<double>& data);
    Info: 
    '&' betyder att vektorn blir en referens så att funktionen kan ändra originalet(?)
## funkRandom();
    Info: 
    Slumpar decimaltal över 0.0 och under 101.0 (det var inte lika lätt som i Python).
## funkStat();
    summa   = funkSumma(data);
    medel   = funkMedelV(data);
    varians = funkVarians(data);
    stdAv   = sqrt(varians);
    minv    = *min_element(data.begin(), data.end());
    maxv    = *max_element(data.begin(), data.end());
## funkSearch();
    Info: 
    Användaren får ange variabeln 'double searchV'. 
    Om data-buffern är tom → hoppa ur funktionen.
    Om data-buffern inte är tom → for-loopa sökvärdet 'searchV' i 'data'-kontainern där den 
    ... verifieras mot var och en position i 'data' (data[i], och nästa: data[i++], och nästa...).
    Antalet loopar är 'i < data.size' (för varje buffrade mätvärde) eftersom att användaren kan ha matat in färre än 5 mätvärden.
    Om skillnaden mellan sökvärdet och data[i] är mindre än 1e-9 (som man kan skriva istället för 0.000000001)
    ... då "ska" de vara likadana, då blir 'bool finns' = true.
## funkSort();
    Info: 
    Användaren anger alternativ 1 eller 2,
        1: "Stigande"   använder std::sort, hjälper till att sortera var och ett data-värdena i ordning, 
                        från lägsta värdet med 'data.begin' till det högsta värdet 'data.end'.
        2: "Fallande" här gör vi samma sak fast med 'r'(everse), 'data.rbegin' och 'data.rend'.
## funkSumma();
    Info:
    Accumulate på datat från början till slut, 0.0 är startsumma
## funkMedelV();
    Info:
    Dividera summan (alla + alla) av datat med datastorleken (antalet värden).
## funkVarians();
    Info: 
-    Ta fram medelvärdet
-    Loopa igenom varje värde (vi kallar den 'v') i 'data'
-    Skapa variabeln 'diff', som är [datavärde subtraherat med medelvärdet]
-    Skapa variabeln 'kvadrat', den är ['diff' upphöjt till 2]
-    Lägg till värdet i totalen (när loopen är klar har vi en summa)

# EXTRA-APP -   tickTock.cpp
Jag ville prova att göra en klocka som är live, men som först frågar vad du anser att klockan är, och räknar därifrån. 
Antingen går man in i story-mode (som egentligen gör programmet onödigt stort), eller så tar man TLDR (too long didn't read) och hoppar in i klockinmatningen direkt.