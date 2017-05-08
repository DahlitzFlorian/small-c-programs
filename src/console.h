// Datei : Console.h
// Zweck : Prototypen und Konstante f�r Console.cpp 
// 
// Console.h  
// Deklaration der Funktionen cls(), setCursor(), setColor()
// f�r Windows 95, 98, 2000 und NT.
// Diese Funktionen sind mit in console.c definiert.
// 
// Au�erdem einige Konstante f�r Farben

#include <windows.h> 

// Konstante f�r Vordergrund- und Hintergrund-Farben
// Bereits definiert sind:
//   FOREGROUND_RED, FOREGROUND_GREEN, FOREGROUND_BLUE, FOREGROUND_INTENSITY
//   BACKGROUND_RED, BACKGROUND_GREEN, BACKGROUND_BLUE, BACKGROUND_INTENSITY

// Und noch einige Kombinationen davon: 
#define BACKGROUND_CYAN   (BACKGROUND_GREEN | BACKGROUND_BLUE)
#define BACKGROUND_WHITE  (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE)
#define BACKGROUND_YELLOW (BACKGROUND_RED | BACKGROUND_GREEN)

#define FOREGROUND_CYAN   (FOREGROUND_GREEN | FOREGROUND_BLUE |  FOREGROUND_INTENSITY)
#define FOREGROUND_YELLOW (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define FOREGROUND_WHITE  (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

// Prototypen der Funktionen aus console.c

BOOL cls();
BOOL setCursor( int zeile, int spalte);
BOOL setColor( int color );
void cursorOff();
void cursorOn();
