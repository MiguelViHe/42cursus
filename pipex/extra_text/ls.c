#include <stdio.h>
#include <ctype.h>

int main() {
    int c;

    // Leer desde la entrada estándar (stdin)
    while ((c = getchar()) != EOF) {
        // Convertir a mayúsculas y escribir en la salida estándar (stdout)
        putchar(toupper(c));
    }

    return 0;
}