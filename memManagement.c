#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 2048
#define NUM_PROCESSES 10

typedef struct {
    int stackSize;
    int priority;
    void (*function)();
} Process;

typedef struct {
    int start;
    int end;
    int size;
} MemoryBlock;

MemoryBlock memoryBlocks[MEMORY_SIZE];
Process processes[NUM_PROCESSES];

void clearMemory() {
    MemoryBlock initialBlock;
    initialBlock.start = 0;
    initialBlock.end = MEMORY_SIZE - 1;
    initialBlock.size = MEMORY_SIZE;

    memoryBlocks[0] = initialBlock;
}

void printMemory() {
    printf("Memory Blocks:\n");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memoryBlocks[i].size != 0) {
            printf("Start: %d, End: %d, Size: %d\n",
                memoryBlocks[i].start, memoryBlocks[i].end, memoryBlocks[i].size);
        }
    }
    printf("----------------------\n");
}

int findBestFit(int size) {
    int bestFitIndex = -1;
    int minSizeDiff = MEMORY_SIZE;

    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memoryBlocks[i].size >= size && memoryBlocks[i].size - size < minSizeDiff) {
            bestFitIndex = i;
            minSizeDiff = memoryBlocks[i].size - size;
        }
    }

    return bestFitIndex;
}

void allocateMemory(int blockIndex, int size) {
    int newBlockSize = memoryBlocks[blockIndex].size - size;

    MemoryBlock newBlock;
    newBlock.start = memoryBlocks[blockIndex].start + size;
    newBlock.end = memoryBlocks[blockIndex].end;
    newBlock.size = newBlockSize;

    memoryBlocks[blockIndex].end = memoryBlocks[blockIndex].start + size - 1;
    memoryBlocks[blockIndex].size = size;

    if (newBlock.size != 0) {
        for (int i = MEMORY_SIZE - 1; i > blockIndex; i--) {
            memoryBlocks[i] = memoryBlocks[i - 1];
        }
        memoryBlocks[blockIndex + 1] = newBlock;
    }
}

void deallocateMemory(int blockIndex) {
    memoryBlocks[blockIndex].size = 0;

    for (int i = blockIndex + 1; i < MEMORY_SIZE; i++) {
        if (memoryBlocks[i].size != 0) {
            memoryBlocks[blockIndex].end = memoryBlocks[i].end;
            memoryBlocks[blockIndex].size += memoryBlocks[i].size;
            memoryBlocks[i].size = 0;
        } else {
            break;
        }
    }
}

void processFunction1() {
    printf("Executing Process 1\n");
    // Function logic for Process 1
}

void processFunction2() {
    printf("Executing Process 2\n");
    // Function logic for Process 2
}

void processFunction3() {
    printf("Executing Process 3\n");
    // Function logic for Process 3
}

void processFunction4() {
    printf("Executing Process 4\n");
    // Function logic for Process 4
}

void processFunction5() {
    printf("Executing Process 5\n");
    // Function logic for Process 5
}

void processFunction6() {
    printf("Executing Process 6\n");
    // Function logic for Process 6
}

void processFunction7() {
    printf("Executing Process 7\n");
    // Function logic for Process 7
}

void processFunction8() {
    printf("Executing Process 8\n");
    // Function logic for Process 8
}

void processFunction9() {
    printf("Executing Process 9\n");
    // Function logic for Process 9
}

void processFunction10() {
    printf("Executing Process 10\n");
    // Function logic for Process 10
}

int main() {
    clearMemory();

    processes[0].stackSize = 100;
    processes[0].priority = 1;
    processes[0].function = processFunction1;

    processes[1].stackSize = 200;
    processes[1].priority = 2;
    processes[1].function = processFunction2;

    processes[2].stackSize = 150;
    processes[2].priority = 3;
    processes[2].function = processFunction3;

    processes[3].stackSize = 180;
    processes[3].priority = 4;
    processes[3].function = processFunction4;

    processes[4].stackSize = 120;
    processes[4].priority = 5;
    processes[4].function = processFunction5;

    processes[5].stackSize = 250;
    processes[5].priority = 6;
    processes[5].function = processFunction6;

    processes[6].stackSize = 90;
    processes[6].priority = 7;
    processes[6].function = processFunction7;

    processes[7].stackSize = 170;
    processes[7].priority = 8;
    processes[7].function = processFunction8;

    processes[8].stackSize = 220;
    processes[8].priority = 9;
    processes[8].function = processFunction9;

    processes[9].stackSize = 140;
    processes[9].priority = 10;
    processes[9].function = processFunction10;

    for (int i = 0; i < NUM_PROCESSES; i++) {
        int bestFitIndex = findBestFit(processes[i].stackSize);

        if (bestFitIndex != -1) {
            printf("Allocating memory for Process %d\n", i + 1);
            allocateMemory(bestFitIndex, processes[i].stackSize);
            processes[i].function();
        } else {
            printf("No suitable memory block found for Process %d\n", i + 1);
            continue;
        }

        printMemory();
    }

    // Deallocate memory
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memoryBlocks[i].size != 0) {
            deallocateMemory(i);
        }
    }

    printf("Memory deallocated.\n");

    return 0;
}
