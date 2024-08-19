# CPSE2 Herkansing 2023/24 - Opdracht 3 - Tom Noordermeer

Dit is een project voor CPSE2, gemaakt door Tom Noordermeer. Het project is bedoeld voor Opdracht 3 van het vak CPSE2.

## Projectinformatie

- Type: BMPTK project
- Configuratiebestand: shape_info.txt
- Commandline-parameters: N.V.T.
- Handleiding shape_info.txt: 
  - De regels bevatten de informatie over de figuren, in de volgende volgorde:
    - De X en Y positie van het figuur tussen haakjes (x,y)
    - het soort figuur (Cirkel, Rectangle, Line, Picture zijn ondersteund)
    - De kleur van het figuur (White, Red, Green, Blue, Yellow, Magenta, Cyan zijn ondersteund, andere kleuren worden niet weergeven)
    - De grootte van de figuren 
        - Voor een cirkel: de straal (één getal)
        - Voor een rechthoek: de breedte en hoogte (twee getallen(x,y))
        - Voor een lijn: de eindpositie (twee getallen(x,y))
- Handleiding gebruik binnen het programma

    - (EENMALIG) Start het programma door te navigeren naar de map in de terminal en het volgende commando uit te voeren:
        ```bash
        bmptk-make run
        ```
    0.  (OPTIONEEL) Voeg eventueel figuren toe aan het bestand "shape_info. txt" volgens de handleiding hierboven.

    1. navigeer naar de map van het programma en start het programma door 2 keer op het bestand main.exe te klikken.
    2. Als het programma wordt opgestart, wordt de informatie over de figuren geladen vanuit het bestand "shape_info.txt".
    3. Klik met de Linker muisknop om een figuur.
    4. Houd de Linker muisknop ingedrukt om een beweeg de muis om een figuur te verplaatsen.
    5. Laat de linker muisknop weer los om het figuur op de nieuwe positie te plaatsen.
    6. Zodra het programma wordt afgesloten, wordt de informatie over de figuren opgeslagen in een bestand genaamd "shape_info.txt".