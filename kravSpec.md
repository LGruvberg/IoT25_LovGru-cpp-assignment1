# Kravspecifikation:
## 1. Datainmatning
#####    a. Användaren ska kunna ange ett antal mätvärden manuellt.
#####    b. Programmet ska hantera ogiltig input på ett robust sätt.
#####    c. (Utmaning: tillåt både hel- och decimaltal)
## 2. Databehandling
#####    a. Beräkna och visa:
######        i. Antal värden
######        ii. Summa
######        iii. Medelvärde
######        iv. Min- och max-värde
######        v. Varians och standardavvikelse
## 3. Menygränssnitt (UI)
#####    a. Användaren ska kunna välja va de vill göra via en meny:
######        i. Lägg till nya mätvärden
######        ii. Visa statistiken
######        iii. Söka efter ett visst värde
######        iv. Sortera listan av mätvärden (valfritt: stigande/fallande)
######        v. Avsluta programmet
## 4. Struktur och kvalitet
#####    a. Programmet ska vara uppdelat i flera funktioner (eller metoder om du vill använda C++)
#####    b. Koden ska vara väl kommenterad och dokumenterad
#####    c. Programmet ska hantera fel (t.ex. tom lista vid analys)
## 5. Extra utmaningar för högre betyg (välj en eller två, eller kom med eget förslag)
#####    a. Simulera en sensorström
######        i. Generera slumpmässiga temperaturvärden (t.ex. 20–30 °C).
######        ii. Låt användaren välja antalet värden att simulera.
######        iii. Analysera sedan dessa värden (som om de kom från en IoT-sensor).
#####    b. Tidsstämpla värden/mätningar
######        i. Koppla varje mätvärde till en enkel tidsstämpel (t.ex. "mätning #1 kl. 10:01").
######        ii. Vid utskrift av statistiken, visa vilket mätvärde som var högst/lägst och vid vilken tidpunkt. Påminner om verkliga IoT-loggar, där varje datapunkt har metadata.
#####    c. Tröskelvärdesanalys (threshold detection)
######        i. Låt användaren ange en kritisk gräns, t.ex. 25 °C.
######        ii. Programmet ska räkna hur många gånger värdet låg över eller under gränsen. Liknarl larmfunktioner i IoT-system (”för varmt i serverrummet”).
#####    d. Glidande medelvärde (moving average)
######        i. Implementera en funktion som räknar ut ett medelvärde över de senaste 3 (eller 5) mätvärdena.
######        ii. Jämför med det totala medelvärdet. Vanlig metod för att jämna ut brusiga sensordata.
#####    e. Visuell representation (ASCII-diagram)
######        i. Rita t.ex. ett histogram av mätvärdena i terminalen.
######        ii. Exempel:

### Godkänd: Uppfyller kraven 1-4 enligt specifikation.
#### Väl Godkänd: Studenten har dessutom implementerat minst en eller två extra funktionaliteter, beroende på utmaningens komplexitet. Studenten har även motiverat sina tekniska val i dokumentationen.