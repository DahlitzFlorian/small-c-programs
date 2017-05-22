/*  Simple managment of a book catalogue
---------------------------------------------------------*/
#include "catalogue.h"

BOOK catalogue[CAT_SIZE] = 
{
    {1234567L, "MRS FUNNY", "A funny story", 1999, "Desert"},
    {7654321L, "MR BRAVE", "The great coup", 2003, "Vice Lake"},
};

int cat_length = 3;


int main()
{
    int choice;

    while((choice = menu()) != ESC)
    {
        switch(choice)
        {
            case SHOW:
                show();
                break;
            case ADD:
                if(add())
                    ++cat_length;
                break;
            case SORT:
                sort();
                break;
        }
    }

    CLS;

    return 0;
}


int menu(void)
{
    static char options[] = "   1  - Display entries.\n"
                            "   2  - Add an entry.\n"
                            "   3  - Sort entries.\n"
                            "  ESC - End program.\n\n"
                            "Your choice: ";
    
    HEADER;
    LOCATE(6, 1);
    printf(options);

    return getch();
}