// Program treba provjerit je li string palindrom ili ne pomocu pointera i dinamicke alokacije.

#include <stdio.h>
#include<stdlib.h>

int je_palindrom(char*);
void kopiraj(char*, char*);
void obrnut_string(char*);
int duljina_stringa(char*);
int usporedi(char*, char*);

int main()
{
        char string[100];
        int result;

        printf("Unesi neki string: ");
        scanf("%s",string);

        result = je_palindrom(string);

        if ( result == 1 )
              printf("\n[ %s ] je palindrom.\n", string);
    else
              printf("\n[ %s ] nije palindrom.\n", string);

        return 0;
}

int je_palindrom(char *string) {
        int provjeri, duljina;
        char *obrni;
        duljina = duljina_stringa(string);
        obrni = (char*)malloc(duljina+1);
        kopiraj(obrni, string);
        obrnut_string(obrni);
        provjeri = usporedi(string, obrni);
        free(obrni);
        if ( provjeri == 0 )
              return 1; else
              return 0;
}


int duljina_stringa(char *string) {
        int duljina = 0;
        while(*string) {
                duljina++;
                string++;
        }
        return duljina;
}


void kopiraj(char *cilj, char *izvor) {
        while(*izvor) {
                *cilj = *izvor;
                izvor++;
                cilj++;
        }
        *cilj = '\0';
}


void obrnut_string(char *string) {
        int duljina, c;
        char *pocetak, *kraj, temp;
        duljina = duljina_stringa(string);
        pocetak = string;
        kraj = string;
        for ( c = 0 ; c < ( duljina - 1 ) ; c++ )
               kraj++;
        for ( c = 0 ; c < duljina/2 ; c++ ) {
                temp = *kraj;
                *kraj = *pocetak;
                *pocetak = temp;
                pocetak++;
                kraj--;
        }
}


int usporedi(char *prvi, char *drugi) {
        while(*prvi==*drugi) {
                if ( *prvi == '\0' || *drugi == '\0' )
                         break;
                prvi++;
                drugi++;
        }
        if( *prvi == '\0' && *drugi == '\0' )
              return 0; else
              return -1;
}
