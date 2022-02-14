#ifndef BANK_H
#define  BANK_H

#include "linkeddeque.h"
#include "linkeddeque.c"
#include <sys/time.h>

#define MAX_TIME 15

#define RED 	"\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW 	"\x1b[33m"
#define BLUE 	"\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET 	"\x1b[0m"

void insertCutomer(int arrivalTime, int processTime, LinkedDeque *pQueue);
DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue);
void processArrival(int currentTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue);
DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue); 
void printReport(LinkedDeque *pWaitQueue,int serviceUserCount, int totalWaitTime);

#endif