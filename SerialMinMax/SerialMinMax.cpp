#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>
#include <omp.h>

void RandomDataInitialization(double* pArray, int Size) {
    srand((unsigned)time(NULL));
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

int main() {
    double* pArray = NULL;
    int Size;
    double Min, Max;
    double Start, Finish, Duration;

    printf("Serial min/max search program\n");
    ProcessInitialization(pArray, Size);
    PrintArray(pArray, Size);

    Start = omp_get_wtime();
    ResultCalculation(pArray, Size, Min, Max);
    Finish = omp_get_wtime();
    Duration = Finish - Start;

    printf("\nMinimum value    : %.6f\n", Min);
    printf("Maximum value    : %.6f\n", Max);
    printf("Time of execution: %.6f sec\n", Duration);

    ProcessTermination(pArray);
    return 0;
}