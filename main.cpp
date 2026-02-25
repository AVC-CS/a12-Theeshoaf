#include <iostream>
#include <cstdlib>  // for malloc
using namespace std;

// TODO: Declare 2 initialized global variables (DATA segment)
int globalVar = 100;
static int staticGlobalVar = 200;
// TODO: Declare 2 uninitialized global variables (BSS segment)
int uninitGlobal1;
int uninitGlobal2;

// Stack check function: receives address from caller (parent frame)
// and compares with a local variable (child frame)
void checkStack(int* parentAddr) {
    int childVar = 0;
    cout << "--- STACK SEGMENT (Cross-function comparison) ---" << endl;
    // TODO: Print parentAddr value (points to main's local var - parent frame)
    // TODO: Print &parentAddr (parameter's own address - child frame)
    // TODO: Print &childVar (local var address - child frame)
    // TODO: Print "Stack grows: DOWN" or "UP" based on comparison
    //       Compare: parentAddr > &childVar ? "DOWN" : "UP"
    //       (parent frame address vs child frame address)
    cout << "main local address (paretn frame): " << (void*)parentAddr << endl;
    cout << "parameter address (child frame): " << (void*)&parentAddr << endl;
    cout << "child local address (child frame): " << (void*)&childVar << endl;
    cout << "Stack grows: " << (parentAddr > &childVar ? "DOWN" : "UP") << endl;
    cout << endl;
}

int main() {

    // TODO: Declare a local variable (STACK - will be passed to checkStack)
    int mainVar = 10;
    checkStack(&mainVar);
    // TODO: Allocate 2 heap variables using malloc (use larger sizes, e.g. 1024)
    //       Note: new may not allocate sequentially; malloc with larger sizes
    //       is more reliable for demonstrating heap growth direction
    char* heapVar1 = (char*)malloc(1024);
    char* heapVar2 = (char*)malloc(1024);
    cout << "=== MEMORY SEGMENT BOUNDARIES ===" << endl;
    cout << endl;

    // TODO: Print TEXT segment - 2 function addresses
    //       e.g., (void*)&main and (void*)&checkStack
    cout << "--- TEXT SEGMENT (Code) ---" << endl;
    cout << "Address of main: " << (void*)&main << endl;
    cout << "Address of checkStack: " << (void*)&checkStack << endl;
    cout << endl;

    // TODO: Print DATA segment - 2 initialized global addresses + values
    cout << "--- DATA SEGMENT (Initialized Globals) ---" << endl;
    cout << "globalVar  addr : " << (void*)&globalVar
         << " value: " << globalVar << endl;
    cout << "staticGlobalVar  addr : " << (void*)&staticGlobalVar
         << " value: " << staticGlobalVar << endl;
    cout << endl;

    // TODO: Print BSS segment - 2 uninitialized global addresses + values
    cout << "--- BSS SEGMENT (Uninitialized Globals) ---" << endl;
    cout << "uninitGlobal1  addr : " << (void*)&uninitGlobal1
         << " value: " << uninitGlobal1 << endl;
    cout << "uninitGlobal2  addr : " << (void*)&uninitGlobal2
         << " value: " << uninitGlobal2 << endl;         
    cout << endl;

    // STACK: call checkStack with address of your local variable
    // TODO: checkStack(&yourLocalVar);

    // TODO: Print HEAP segment - 2 heap addresses + comparison
    //       Print "Heap grows: UP" or "DOWN"
    cout << "--- HEAP SEGMENT (Dynamic Allocation) ---" << endl;
    cout << "heapVar1  addr : " << (void*)heapVar1 << endl;
    cout << "heapVar2  addr : " << (void*)heapVar2 << endl;
    cout << "Heap grows: " << (heapVar2 > heapVar1 ? "UP" : "DOWN") << endl;
    cout << endl;

    // TODO: Print relative position summary
    cout << "=== RELATIVE POSITION SUMMARY ===" << endl;
    cout << "Text (lowest): " << (void*)&main << endl;
    cout << "Data: " << (void*)&globalVar << endl;
    cout << "BSS: " << (void*)&uninitGlobal1 << endl;
    cout << "Heap: " << (void*)heapVar1 << endl;
    cout << "Stack (highest): " << (void*)&mainVar << endl;
    cout << endl;

    // TODO: Free all heap allocations
    free(heapVar1);
    free(heapVar2);

    return 0;
}

/*
 * EXPERIMENTAL RESULTS:
 * TODO: After running your program, explain what you observed:
 * - Which segment has the lowest addresses?
 * - Which has the highest?
 * - Does stack grow down? How did you verify this?
 * - Does heap grow up? How did you verify this?
 * - What is the gap between HEAP and STACK?
 */
