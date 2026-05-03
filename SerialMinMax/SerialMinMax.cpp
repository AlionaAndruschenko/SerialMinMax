#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>


void RandomDataInitialization(double* pArray, int Size) {
    srand(unsigned(clock()));
    for (int i = 0; i < Size; i++) {
        pArray[i] = (rand() / double(RAND_MAX)) * 2000.0 - 1000.0; 
    }
}


void ProcessInitialization(double*& pArray, int& Size) {
    do {
        printf("\nEnter the size of the array: ");
        scanf("%d", &Size);
        if (Size <= 0)
            printf("Size must be greater than 0!\n");
    } while (Size <= 0);

    pArray = new double[Size];
    RandomDataInitialization(pArray, Size);
}


void ResultCalculation(double* pArray, int Size, double& Min, double& Max) {
    Min = pArray[0];
    Max = pArray[0];
    for (int i = 1; i < Size; i++) {
        if (pArray[i] < Min) Min = pArray[i];
        if (pArray[i] > Max) Max = pArray[i];
    }
}


void PrintArray(double* pArray, int Size) {
    int printCount = (Size < 10) ? Size : 10;
    printf("Array (first %d elements): ", printCount);
    for (int i = 0; i < printCount; i++)
        printf("%.2f ", pArray[i]);
    printf("\n");
}


void ProcessTermination(double* pArray) {
    delete[] pArray;
}

void main() {
    double* pArray;
    int Size;
    double Min, Max;
    time_t start, finish;
    double duration;

    printf("Serial min/max search program\n");

    ProcessInitialization(pArray, Size);

    PrintArray(pArray, Size);

    start = clock();
    ResultCalculation(pArray, Size, Min, Max);
    finish = clock();
    duration = (finish - start) / double(CLOCKS_PER_SEC);

    printf("\nMinimum value: %.6f\n", Min);
    printf("Maximum value: %.6f\n", Max);
    printf("Time of execution: %.6f sec\n", duration);

    ProcessTermination(pArray);
}