#include <iostream>
using namespace std;

int Arr[10] = { 9, 4, 5, 1, 2, 3, 8, 7, 9, 6 };
int N = 10;

void bubbleSort() {
    _asm
    {
        dec N;
    LoopEnd:
        xor ebx, ebx;
        mov ecx, N;
        mov esi, 0;
    LoobIn:
        mov edi, Arr[esi];
        cmp edi, Arr[esi + 4];
        jg Swap;
        add esi, 4;
        loop LoobIn;
        jmp Check;
    Swap:
        mov ebx, Arr[esi + 4];
        mov Arr[esi + 4], edi;
        mov Arr[esi], ebx;
        add esi, 4;
        loop LoobIn;
    Check:
        cmp ebx, 0;
        je Exit;
        jmp LoopEnd;
    Exit:

    }
}

int main()
{
    cout << "Initial Array:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << Arr[i] << " ";
    }
    cout << "Sorting..." << endl;

    bubbleSort();

    cout << "Sorted Array:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << Arr[i] << " ";
    }
    return 0;
}
