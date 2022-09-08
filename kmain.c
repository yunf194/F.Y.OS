#include "task.h"
#include "interrupt.h"
#include "screen.h"
#include "memory.h"
#include "mutex.h"
#include "keyboard.h"

extern int gMemSize;

void KMain()
{
    void (*AppModInit)() = (void*)BaseOfApp;
    byte* pn = (byte*)0x475;
    
    PrintString("D.T.OS\n");
    
    PrintString("GDT Entry: ");
    PrintIntHex((uint)gGdtInfo.entry);
    PrintChar('\n');
    
    PrintString("GDT Size: ");
    PrintIntDec((uint)gGdtInfo.size);
    PrintChar('\n');
    
    PrintString("IDT Entry: ");
    PrintIntHex((uint)gIdtInfo.entry);
    PrintChar('\n');
    
    PrintString("IDT Size: ");
    PrintIntDec((uint)gIdtInfo.size);
    PrintChar('\n');
    
    PrintString("Number of Hard Disk: ");
    PrintIntDec(*pn);
    PrintChar('\n');
    
    MemModInit((byte*)KernelHeapBase, HeapSize);
    
    KeyboardModInit();
    
    MutexModInit();
    
    // AppModInit();
    
    TaskModInit();
    
    IntModInit();
    
    ConfigPageTable();
    
    while(1);
    
    LaunchTask();
    
}
