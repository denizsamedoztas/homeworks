#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Kullanıcıdan ismini al
    string name = get_string("What is your name? ");

    // İsmi ekrana yazdır
    printf("hello, %s\n", name);
}
