#include <stdio.h>

//Emirhan Dizdaroğlu 2. section Programming Homework 3

//Takes string str and converts all non-letters to the ‘*’ character in it.
//Ex: “a1b2c” becomes “a*b*c”
void A(char str[]) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            str[i] = '*';// Stringimizdeki karakterlerlerimiz, kücük a ve z arasındaki karakterler ile
            // büyük A ve B karakterleri arasında değil ise * bastırıyoruz
        }
    }
    printf("%s\n", str);
}

//Swaps the first half of str with the second half of str
//Ex: “abcxyz” becomes “xyzabc”
void B(char str[]) {
    int length = 0;
    while (str[length] != '\0') {// stringin sonuna gelene kadar devam etsin
        length++;
    }
    int middle = length / 2; //stringimizin ortasını bulmak için stringin uzunluğunu 2 ye böldük
    if (length % 2 == 0) { //stringimizin karakter sayısı çift ise :1. yarısı ile 2. yarısını swap ediyoruz.
        for (int i = 0; i < middle; ++i) {
            char temp = str[i];
            str[i] = str[middle + i];
            str[middle + i] = temp;
        }
        printf("%s\n", str);
    } else { // string odd ise ortada kalan değerin değişmemesini sağlıyoruz.
        for (int i = 0; i < middle; ++i) {
            char temp = str[i];
            str[i] = str[middle + 1 + i];
            str[middle + 1 + i] = temp;
        }
        printf("%s\n", str);
    }
}

//Reverses the order of the characters in the first half of str.
//Ex: “abcxyzd” becomes “cbaxyzd”
void C(char str[]) {
    int length = 0;
    while (str[length] != '\0') { //karakter dizisi sona kadar devam etsin
        length++;
    }
    int middle = length / 2;
    if (length % 2 == 0) {// we do not need to control this condition. But I wrote that because of HW pdf said to check
        for (int i = 0; i < middle / 2; i++) {
            char temp = str[i];
            str[i] = str[middle - 1 - i];
            str[middle - 1 - i] = temp;
        }
        printf("%s\n", str);
    } else {// we do not need to control this condition. Because the second half not change and middle is staying same.
        for (int i = 0; i < middle / 2; ++i) {
            char temp = str[i];
            str[i] = str[middle - 1 - i];
            str[middle - 1 - i] = temp;
        }
        printf("%s\n", str);
    }
}

//Reverses the order of the characters in the second half of str.
//Ex: “abcxyz” becomes “abczyx” Ex: “abcdxyz” becomes “abcdzyx”
void D(char str[]) {
    int length = 0;
    while (str[length] != '\0') { //karakter dizisi sona kadar devam etsin
        length++;
    }
    int middle = length / 2;
    int startSecondHalf = middle + (length % 2);  // Adjusted to handle odd lengths
    int end = length - 1;

    while (startSecondHalf <= end) {
        char temp = str[startSecondHalf];
        str[startSecondHalf] = str[end];
        str[end] = temp;

        startSecondHalf++;
        end--;
    }
    printf("%s\n", str);
}

int main() {
    //Those are the controlled of functions. And also I also took this warning message
    // into consideration: B, C, and D, if the length of str is odd then the character
    // in the middle of str will not change.
    //char str[]={"a1b2c"};
    //A(str);
    //char str[]={"abcxyz"};
    //B(str);
    //char str[]={"abcxyz"};
    //C(str);
    //char str[]={"abcxyz"};
    //D(str);

    char str[] = "Zg5bA?*6h"; //the example of our hw.
    char order[] = "BCADAD"; // this is the order what will happen to our string orderly:

    printf("Current string: %s The order is: %s\n", str, order);
    for (int i = 0; order[i] != '\0'; i++) {
        if        (order[i] == 'B') {
            B(str);
        } else if (order[i] == 'C') {
            C(str);
        } else if (order[i] == 'A') {
            A(str);
        } else if (order[i] == 'D') {
            D(str);
        } else if (order[i] == 'A') {
            A(str);
        } else if (order[i] == 'D') {
            D(str);
        }
    }
    return 0;
}
