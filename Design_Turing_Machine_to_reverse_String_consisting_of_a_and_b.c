#include <stdio.h> // library
#include <string.h> // library
#include <stdlib.h> // library
#include <conio.h> // library

int main()
{
    int i, j, q = 0, spasi = 1, r = 0, s = 0, arah = 0; // pendeklarasian variabel
    char string[100]; // mendeklarasikan string yang akan dicek 
    char kiri_atas = 201, atasbawah_tengah = 205, kanan_atas = 187, kirikanan_tengah = 186, kiri_bawah = 200, kanan_bawah = 188, atas_sambung = 203, bawah_sambung = 202;

    menu:
    system("cls"); 
    printf("===============================================================\n");
    printf("= Turing Machine to reverse String consisting of a's and b's  =\n");
    printf("===============================================================\n");
    printf("= Ketentuan String yang dimasukkan adalah :                   =\n");
    printf("=-------------------------------------------------------------=\n");
    printf("= 1. String yang dimasukkan hanya berisikan                   =\n");
    printf("=    karakter 'a' dan 'b'.                                    =\n");
    printf("= 2. String yang dimasukkan harus lebih dari 0                =\n");
    printf("=    karakter                                                 =\n");
    printf("=-------------------------------------------------------------=\n");
    printf("= Contoh masukkan string = aabb, bbaab, abaab                 =\n");
    printf("=-------------------------------------------------------------=\n");
    printf("= Masukkan string = ");
    scanf("%s",&string); // meminta masukkan client mengenai string yang ingin di reverse
    printf("===============================================================\n");
    int indeks = strlen(string); // digunakan untuk membuat string baru
    i, j, q = 0, spasi = 1, r = 0, s = 0, arah = 0; // i dan j untuk perulangan, q untuk state, spasi untuk menentukan spasi di tiap proses

    char string_baru[100]; // deklarasi string baru yang terdapat blank
    int ind = 0; // deklarasi variabel yang digunakan untuk proses string baru

    // PROSES UNTUK MEMASUKKAN BLANK KE DALAM STRING YANG DI INPUT TADI

    for (i = 0; i < indeks*2+2; i++)
    {
        if (i == 0)
        {
            string_baru[i] = '_';
        }
        else if (ind < indeks)
        {
            string_baru[i] = string[ind];
            ind++;
        }
        else
        {
            string_baru[i] = '_';
        }
    }

    indeks = i;
    q = 0;
    
    // PROSES REVERSE STRING

    i = 1; // inisialisasi string pertama yang di cek
    do
    {
        if (q == 0) // Fungsi Transisi State q0
        {
            if (string_baru[i] == 'b')  // b/b,R, stay di q0
            {                           // apabila bertemu karakter b, maka menggantinya dengan karakter b pula, lalu geser ke kanan
                string_baru[i] = 'b';
                i++;
                arah = 1;
                spasi+=2;
                s = q;
            }
            else if (string_baru[i] == 'a') // a/a,R, stay di q0
            {                               // apabila bertemu karakter a, maka menggantinya dengan karakter a pula, lalu geser ke kanan
                string_baru[i] = 'a';
                i++;
                arah = 1;
                spasi+=2;
                s = q;
            }
            else if (string_baru[i] == '_') // blank/blank,L, maju ke state q1
            {                               // apabila bertemu blank, maka menggantinya dengan blank pula, lalu geser ke kiri, dan pindah ke state q1
                string_baru[i] = '_';
                i--;
                arah = 0;
                spasi+=2;
                s = q;
                q = 1;
                r++;
            }
            else // bertemu dengan karakter lain selain a, dan b, maupun blank. Maka otomatis failed
            {
                i++;
                spasi+=2;
                q = 7;
                s = q;
            }
        }
        else if (q == 1) // Fungsi Transisi State q1
        {
            if (string_baru[i] == 'X') // X/X,L. stay di q1
            {                          // apabila bertemu X, maka menggantinya dengan X, lalu geser ke kiri
                string_baru[i] = 'X';
                i--;
                arah = 0;
                spasi+=2;
                s = q;
                r++;
            }
            else if (string_baru[i] == 'a') // a/X,R. maju ke state q2
            {                               // apabila bertemu a, maka menggantinya dengan X, lalu geser ke kanan, dan pindah ke state q2
                string_baru[i] = 'X';
                i++;
                arah = 1;
                spasi+=2;
                s = q;
                q = 2;
            }
            else if (string_baru[i] == 'b') // b/X,R, maju ke state q3
            {                               // apabila bertemu b, maka menggantinya dengan X, lalu geser ke kanan, dan pindah ke state q3
                string_baru[i] = 'X';
                i++;
                arah = 1;
                spasi+=2;
                s = q;
                q = 3;
            }
            else if (string_baru[i] == '_') // blank/X,R. maju ke state q5
            {                               // apabila bertemu blank, maka menggantinya dengan blank pula, lalu geser ke kanan, dan pindah ke state q5
                string_baru[i] = '_';
                i++;
                arah = 1;
                spasi+=2;
                s = q;
                q = 5;
            }
            else // bertemu dengan karakter selain a,b,X, dan blank. Maka otomatis failed
            {
                i++;
                spasi+=2;
                q = 7;
                s = q;
            }
        }
        else if (q == 2) // Fungsi Transisi State q2
        {
            if (string_baru[i] == 'X') // X/X,R. stay di q2
            {                          // apabila bertemu X, maka mengganti dengan X pula, dan geser ke kanan
                string_baru[i] = 'X';
                i++;
                arah = 1;
                spasi+=2;
                s = q;
            }
            else if (string_baru[i] == 'a')  // a/a,R. stay di q2
            {                                // apabila bertemu a, maka mengganti dengan a pula, dan geser ke kanan
                string_baru[i] = 'a';
                i++;
                arah = 1;
                spasi+=2;
                s = q;
            }
            else if (string_baru[i] == 'b') // b/b, R. stay di q2
            {                               // apabila bertemu b, maka mengganti dengan b pula, dan geser ke kanan
                string_baru[i] = 'b';
                i++;
                arah = 1;
                spasi+=2;
                s = q;
            }
            else if (string_baru[i] == '_') // blank/a,L. pindah ke state q4
            {                               // apabila bertemu blank, maka menggantinya dengan karakter a, lalu geser ke kiri, dan lanjut ke state q4
                string_baru[i] = 'a';
                i--;
                arah = 0;
                spasi+=2;
                s = q;
                q = 4;
                r++;
            }
            else // bertemu dengan karakter selain a,b,X, dan blank. Maka otomatis failed
            {
                i++;
                spasi+=2;
                q = 7;
                s = q;
            }
        }
        else if (q == 3) // Fungsi transisi state q3
        {
            if (string_baru[i] == 'X') // X/X,R. stay di q3
            {                          // apabila bertemu karakter X, maka mengganti dengan X pula, dan geser ke kanan
                string_baru[i] = 'X';
                i++;
                arah = 1;
                spasi+=2;
                s = q;
            }
            else if (string_baru[i] == 'a') // a/a,R. stay di q3
            {                               // apabila bertemu karakter a, maka mengganti dengan a pula, dan geser ke kanan
                string_baru[i] = 'a';   
                i++;
                arah = 1;
                spasi+=2;
                s = q;
            }
            else if (string_baru[i] == 'b') // b/b,R. stay di q3
            {                               // apabila bertemu karakter b, maka mengganti dengan b pula, dan geser ke kanan
                string_baru[i] = 'b';
                i++;
                arah = 1;
                spasi+=2;
                s = q;
            }
            else if (string_baru[i] == '_') // blank/b,L. pindah ke state q4
            {                               // apabila bertemu blank, maka menggantinya dengan karakter b, dan geser ke kiri. pindah ke state q4
                string_baru[i] = 'b';
                i--;
                arah = 0;
                spasi+=2;
                s = q;
                q = 4;
                r++;
            }
            else // bertemu dengan karakter selain a,b,X, dan blank. Maka otomatis failed
            {
                i++;
                spasi+=2;
                q = 7;
                s = q;
            }
        }
        else if (q == 4) // fungsi transisi state q4
        {
            if (string_baru[i] == 'a') // a/a,L. stay state q4
            {                          // apabila bertemu a, maka menggantinya dengan a pula, geser ke kiri
                string_baru[i] = 'a';
                i--;
                arah = 0;
                spasi+=2;
                s = q;
                r++;
            }
            else if (string_baru[i] == 'b')// b/b,L. stay state q4
            {                              // apabila bertemu b, maka menggantinya dengan b pula, geser ke kiri
                string_baru[i] = 'b';
                i--;
                arah = 0;
                spasi+=2;
                s = q;
                r++;
            }
            else if (string_baru[i] == 'X') // X/X,L. pindah state q1
            {                               // apabila bertemu X, maka menggantinya dengan X pula, geser ke kiri, dan pindah ke state q1
                string_baru[i] = 'X';
                i--;
                arah = 0;
                spasi+=2;
                s = q;
                q = 1;
                r++;
            }
            else // bertemu dengan karakter selain a,b, dan X. Maka otomatis failed
            {
                i++;
                spasi+=2;
                q = 7;
                s = q;
            }
        }
        else if (q == 5) // fungsi transisi state q5
        {
            if (string_baru[i] == 'X') // X/blank,R. stay q5
            {                          // apabila bertemu X, maka menggantinya dengan Blank, geser ke kanan.
                string_baru[i] = '_';
                i++;
                arah = 1;
                spasi+=2;
                s = q;
            }
            else if (string_baru[i] == 'a') // a,a/N. pindah ke state q6
            {                               // apabila bertemu a, maka menggantinya dengan a pula, berhenti, dan pindah ke state q6 yang merupakan halt
                string_baru[i] = 'a';
                i++;
                arah = 1;
                spasi+=2;
                q = 6;
                s = q;
            }
            else if (string_baru[i] == 'b') // b,b/N. pindah ke state q6
            {                               // apabila bertemu b, maka menggantinya dengan b pula, berhenti, dan pindah ke state q6 yang merupakan halt
                string_baru[i] = 'b';
                i++;
                arah = 1;
                spasi+=2;
                q = 6;
                s = q;
            }
            else // bertemu dengan karakter selain a,b, dan X. Maka otomatis failed
            {
                i++;
                spasi+=2;
                q = 7;
                s = q;
            }
        }

        for (j = 0; j < indeks; j++)
        {
            if (j == 0)
            {
                printf("%c%c%c",kiri_atas,atasbawah_tengah,atas_sambung);
            }
            else if (j < indeks-1)
            {
                printf("%c%c",atasbawah_tengah,atas_sambung);
            }   
            else if (j == indeks-1)
            {
                printf("%c%c",atasbawah_tengah,kanan_atas);
            }
        }
        printf("\n");
        for (j = 0; j < indeks; j++)
        {
            printf("%c%c",kirikanan_tengah,string_baru[j]);
            if (j == indeks-1)
            {
                printf("%c", kirikanan_tengah);
            }
        }
        printf("\n");
        for (j = 0; j < indeks; j++)
        {
            if (j == 0)
            {
                printf("%c%c%c",kiri_bawah,atasbawah_tengah,bawah_sambung);
            }
            else if (j < indeks-1)
            {
                printf("%c%c",atasbawah_tengah,bawah_sambung);
            }
            else if (j == indeks-1)
            {
                printf("%c%c",atasbawah_tengah,kanan_bawah);
            }
        }
        printf("\n");
        for (j = 0; j < spasi; j++)
        {
            printf(" ");
        }
        printf("^\n");
        for (j = 0; j < spasi; j++)
        {
            printf(" ");
        }
        if (q != 7)
        {
            printf("q%d\n",s);
        }
        else
        {
            printf("FAILED\n");
        }

        if ((arah == 0) && (q != 7))
        {
            for (j = 0; j < spasi-3; j++)
            {
                printf(" ");
            }
            printf("<---\n\n");
        }
        else if ((arah == 1) && (q != 6) && (q != 7)) 
        {
            for (j = 0; j < spasi; j++)
            {
                printf(" ");
            }
            printf("--->\n\n");
        }

        if (r > 0)
        {
            spasi-=4;
            r = 0;
        }
        //system("pause");
    } while ((q != 6) && (q != 7));

    if ( q == 6 )
    {
        printf("================================================\n");
        printf("= String sebelum di reverse adalah %s\n", string);
        printf("================================================\n");

        printf("================================================\n");
        printf("= String setelah di reverse adalah ");
        for (i = 0; i < indeks; i++)
        {
            if ( (string_baru[i] == 'a') || (string_baru[i] == 'b') )
            {
                printf("%c", string_baru[i]);
            }
        }
        printf("\n================================================\n");

        system("pause");
        goto ulang;
    }
    else if ( q == 7 ) 
    {
        printf("================================================\n");
        printf("= Mohon maaf, string %s tidak dapat diterima\n", string);
        printf("================================================\n");
        system("pause");
        goto ulang;
    }

    ulang:
    system("cls");
    char reset;
    printf("================================================\n");
    printf("= Apakah ingin mencoba lagi?                   =\n");
    printf("================================================\n");
    printf("= Input Y / N (Yes/No) = ");
    scanf(" %c", &reset);
    printf("================================================\n");
    if (reset == 'Y')
    {
        goto menu;
    }
    else if (reset == 'N')
    {
        return 0;
    }
    
    return 0;
}