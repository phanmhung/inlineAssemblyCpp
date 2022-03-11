#include <iostream>
using namespace std;
//Сложение
int Add(int a, int b) {
    int c = 0;
    _asm {
        mov ebx, a
        add ebx, b
        mov c, ebx
    }
    return c;
}
//Вычитание
int Sub(int a, int b) {
    int c = 0;
    _asm {
        mov ebx, a
        sub ebx, b
        mov c, ebx
    }
    return c;
}
//Умножение
int Mul(int a, int b) {
    int c = 0;
    _asm {
        mov eax, a
        imul b
        mov c, eax
    }
    return c;
}
//Деление
int Div(int a, int b) {
    int c = 0;
    _asm {
        mov eax, a
        mov edx, 0
        mov ebx, b
        idiv ebx
        mov c, eax
    }
    return c;
}
//Операция ==
int Equal(int a, int b) {
    int c = 0;
    _asm {
        mov eax, a
        mov ebx, b
        mov ecx, 1
        cmp eax, ebx
        je yes
        mov ecx, 0
        yes:
        mov c, ecx
    }
    return c;
}
//Операция >
int GreaterThan(int a, int b) {
    int c = 0;
    _asm {
        mov eax, a
        mov ebx, b
        mov ecx, 1
        cmp eax, ebx
        jg yes
        mov ecx, 0
        yes:
        mov c, ecx
    }
    return c;
}
//Операция <
int LessThan(int a, int b) {
    int c = 0;
    _asm {
        mov eax, a
        mov ebx, b
        mov ecx, 1
        cmp eax, ebx
        jl yes
        mov ecx, 0
        yes:
        mov c, ecx
    }
    return c;
}
//Операция !=
int NotEqual(int a, int b) {
    int c = 0;
    _asm {
        mov eax, a
        mov ebx, b
        mov ecx, 1
        cmp eax, ebx
        jne yes
        mov ecx, 0
        yes:
        mov c, ecx
    }
    return c;
}
//Операция <=
int LessOrEqual(int a, int b) {
    int c = 0;
    _asm {
        mov eax, a
        mov ebx, b
        mov ecx, 1
        cmp eax, ebx
        jle yes
        mov ecx, 0
        yes:
        mov c, ecx
    }
    return c;
}
//Операция >=
int GreaterOrEqual(int a, int b) {
    int c = 0;
    _asm {
        mov eax, a
        mov ebx, b
        mov ecx, 1
        cmp eax, ebx
        jge yes
        mov ecx, 0
        yes:
        mov c, ecx
    }
    return c;
}
//Логические операции
int Not(int a) {
    int c = 0;
    _asm {
        mov eax, a
        not eax
        mov c, eax
    }
    return c;
}

int And(int a, int b) {
    int c = 0;
    _asm {
        mov eax, a
        mov ebx, b
        and eax, ebx
        mov c, eax
    }
    return c;
}

int Or(int a, int b) {
    int c = 0;
    _asm {
        mov eax, a
        mov ebx, b
        or eax, ebx
        mov c, eax
    }
    return c;
}

int Xor(int a, int b) {
    int c = 0;
    _asm {
        mov eax, a
        mov ebx, b
        xor eax, ebx
        mov c, eax
    }
    return c;
}
//Индексация по массиву
int ElementByIndex(int* a, int b) {
    int c = 0;
    _asm {
        mov eax, a
        mov ebx, b
        mov ebx, [eax + 4 * ebx]
        mov c, ebx
    }
    return c;
}

int LogicRight(int a, int b) {
    int c = 0;

    _asm {
        mov eax, a
        mov ecx, b
        shr eax, cl
        mov c, eax
    }

    return c;
}

int LogicLeft(unsigned char a, unsigned char b) {
    unsigned char c;

    _asm {
        mov al, a
        mov cl, b
        shl al, cl
        mov c, al
    }

    return c;
}

int CicleRight(unsigned char a, unsigned char b) {
    unsigned char c;

    _asm {
        mov al, a
        mov cl, b
        ror al, cl
        mov c, al
    }

    return c;
}

int CicleLeft(unsigned char a, unsigned char b) {
    unsigned char c;

    _asm {
        mov al, a
        mov cl, b
        rol al, cl
        mov c, al
    }

    return c;
}

int main()
{
    cout << "20 + 21 = " << Add(20, 21) << endl; 
    cout << "0 - 32 = " << Sub(0, 32) << endl;
    cout << "-13 * 2 = " << Mul(-13, 2) << endl;
    cout << "200 / 5 = " << Div(200, 5) << endl;

    cout << endl;

    cout << "1 == 1 ? " << Equal(1, 1) << endl;
    cout << "10 == 11 ? " << Equal(10, 11) << endl;
    cout << "7 > 3 ? " << GreaterThan(7, 3) << endl;
    cout << "91 < 43 ? " << LessThan(91, 43) << endl;
    cout << "15 <= 25 ? " << LessOrEqual(15, 25) << endl;
    cout << "5 >= 2 ? " << GreaterOrEqual(5, 2) << endl;
    cout << "5 != 5 ? " << NotEqual(5, 5) << endl;
    
    cout << endl;

    cout << "not 10 => " << Not(10) << endl;
    cout << "10 and 15 => " << And(10, 15) << endl;                     
    cout << "10 or 15 => " << Or(10, 15) << endl;                       
    cout << "10 xor 15 => " << Xor(10, 15) << endl;

    cout << endl;

    int a[] = { 0, 11, 22, 33, 44, 55, 66 };

    cout << "4th element in [ 0, 11, 22, 33, 44, 55, 66 ]: " << ElementByIndex(a, 4) << endl << endl;

    cout << "logic shift right 333 (101001101) by 2 " << LogicRight(333, 2) << endl;  
    cout << "logic shift left 333 (101001101) by 2: " << LogicLeft(333, 2) << endl;    

    cout << "cicle shift right 333 (101001101) by 2: " << CicleRight(333, 2) << endl; 
    cout << "cicle shift left  333 (101001101) by 2: " << CicleLeft(333, 2) << endl;   
}
