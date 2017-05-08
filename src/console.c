// Datei : Console.c
// Zweck : Einige Funktionen zur Steuerung der Ausgabe im Consolen-Fenster

#include "console.h" 

static HANDLE hStdout; 
static CONSOLE_SCREEN_BUFFER_INFO csbInfo; 

////////////////////////////////////////////////////////////////////////
// Funktion setCursor : Cursor auf die angegebene Position setzen.

BOOL setCursor( int zeile, int spalte)
{
    COORD dwCursorPos;  // = {spalte, zeile};
    dwCursorPos.X = spalte;
    dwCursorPos.Y = zeile;   

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    return SetConsoleCursorPosition(hStdout, dwCursorPos) != 0;
}
    
////////////////////////////////////////////////////////////////////////
// Funktion setColor : Vorder- und Hintergrundfarbe setzen.

BOOL setColor( int color )
{
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    return SetConsoleTextAttribute(hStdout, (WORD)color) != 0;
}

////////////////////////////////////////////////////////////////////////
// Funktion cls() : Consolen-Puffer mit aktuellem Attribut l�schen und 
//                  Cursor auf die Home-Position setzen.

BOOL cls()
{
    COORD home = { 0, 0 };          // Home-Position
    DWORD dwCellsWritten;           // Anzahl beschriebener Char-Zellen 
    DWORD dwConSize;                // Anzahl Zeichen im Puffer

    // Gr��e des Puffers und das aktuelle Attribut holen:
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    GetConsoleScreenBufferInfo(hStdout, &csbInfo);
    
    dwConSize = csbInfo.dwSize.X * csbInfo.dwSize.Y;
 
    // Den Puffer mit Blanks f�llen:
    if( ! FillConsoleOutputCharacter(hStdout, (TCHAR)' ', dwConSize,
                                     home, &dwCellsWritten) )
        return FALSE;

    // Attribute setzen:
    if( ! FillConsoleOutputAttribute(hStdout, csbInfo.wAttributes, dwConSize,
                                     home, &dwCellsWritten) )
        return FALSE;

    // Cursor auf Home-Position setzen 

    if( ! SetConsoleCursorPosition(hStdout, home) )
        return FALSE;

    return TRUE;
}

void cursorOff()
{
    CONSOLE_CURSOR_INFO cursorInfo;   
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 

    GetConsoleCursorInfo( hStdout, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo( hStdout, &cursorInfo);
}

void cursorOn()
{
    CONSOLE_CURSOR_INFO cursorInfo;   
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 

    GetConsoleCursorInfo( hStdout, &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo( hStdout, &cursorInfo);
}

