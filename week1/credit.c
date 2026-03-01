#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // 1. Kullanıcıdan kredi kartı numarasını al
    long card_number = get_long("Number: ");

    // -----------------------------------------------------------------------
    // ADIM 1 ve 4'e Hazırlık: Uzunluğu ve İlk İki Haneyi Bulma
    // -----------------------------------------------------------------------
    int length = 0;
    long temp = card_number;
    long first_two = card_number;

    // Sayıyı sürekli 10'a bölerek kaç basamaklı olduğunu buluyoruz
    while (temp > 0)
    {
        temp = temp / 10;
        length++;
    }

    // İlk iki haneyi bulmak için sayıyı 100'den küçük kalana kadar 10'a bölüyoruz
    while (first_two >= 100)
    {
        first_two = first_two / 10;
    }

    // -----------------------------------------------------------------------
    // ADIM 2: Luhn Algoritmasını Uygulama
    // -----------------------------------------------------------------------
    long cc = card_number; // Kart numarasının kopyası üzerinden çalışıyoruz
    int sum_doubled = 0;   // 2 ile çarpılanların rakamları toplamı
    int sum_rest = 0;      // Çarpılmayanların toplamı
    int i = 0;             // Basamak pozisyonu (0: son basamak, 1: sondan bir önceki...)

    while (cc > 0)
    {
        int digit = cc % 10; // Sayının en sağındaki (son) basamağı al

        // Eğer pozisyon TEK ise (sondan bir önceki, sondan üçüncü...)
        if (i % 2 == 1)
        {
            int doubled = digit * 2;
            // Çıkan sonucun rakamlarını topluyoruz (Örn: 14 ise 1 + 4 = 5 yapmalı)
            // doubled % 10 (son basamağı verir) + doubled / 10 (ilk basamağı verir)
            sum_doubled += (doubled % 10) + (doubled / 10);
        }
        // Eğer pozisyon ÇİFT ise (son basamak, sondan ikinci...)
        else
        {
            sum_rest += digit;
        }

        cc = cc / 10; // En sağdaki basamağı silip bir yandakine geç
        i++;          // Pozisyonu 1 artır
    }

    // -----------------------------------------------------------------------
    // ADIM 3: Geçerlilik Kontrolü
    // -----------------------------------------------------------------------
    int total_sum = sum_doubled + sum_rest;

    // Eğer toplamın son basamağı 0 değilse (10'a tam bölünmüyorsa) kart geçersizdir
    if (total_sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0; // Programı burada bitir
    }

    // -----------------------------------------------------------------------
    // ADIM 4: Kart Tipini Belirleme
    // -----------------------------------------------------------------------
    if (length == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (first_two >= 51 && first_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && (first_two / 10 == 4)) // İlk hane 4 ise
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
