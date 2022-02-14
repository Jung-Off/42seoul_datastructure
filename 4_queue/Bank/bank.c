#include "bank.h"

void insertCutomer(int arrivalTime, int processTime, LinkedDeque *pQueue)
{
    DequeNode element;

	element.data.arrivalTime = arrivalTime;
	element.data.serviceTime = processTime;
    element.data.startTime = 0;
    element.data.endTime = 0;
    element.data.status = arrival;

	insertRearLD(pQueue, element);
}

void processArrival(int currentTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue)
{
    DequeNode *temp;
    
    temp = deleteFrontLD(pArrivalQueue);
    insertRearLD(pWaitQueue, *temp);
    free(temp);
}

DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue)
{
    // printf("processServiceNodeStart\n");
    DequeNode *ret;

    if (pWaitQueue->pFrontNode == NULL)
        return (NULL);
    else
    {
        ret = deleteFrontLD(pWaitQueue);
        ret->data.startTime = currentTime;
        ret->data.endTime = currentTime + ret->data.serviceTime;
        ret->data.status = start;
        ret->pRLink = NULL;
        return (ret);
    }
}

DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
    // printf("processServiceNodeEnd\n");
    (*pServiceUserCount)++;
    pServiceNode->data.status = end;
    (*pTotalWaitTime) += (pServiceNode->data.startTime - pServiceNode->data.arrivalTime);
    free(pServiceNode);
    return (NULL);
}

void printarrivalQueueStatus(int currentTime, LinkedDeque *arrivalqueue)
{
    printf(GREEN"=== printarrivalQueueStatus ===\n"RESET);
    if(arrivalqueue->pFrontNode == NULL)
    {
        printf("waitlist is NULL\n");
        return;
    }
    displayDeque(arrivalqueue);
}


void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue)
{
    printf(BLUE"\n=== printWaitQueueStatus ===\n"RESET);
    if(pWaitQueue->pFrontNode == NULL)
    {
        printf("waitlist is NULL\n");
        return;
    }
    displayDeque(pWaitQueue);
}

void printReport(LinkedDeque *pWaitQueue,int serviceUserCount, int totalWaitTime)
{
    printf(YELLOW"\n=== printReport ===\n"RESET);
    printf("user count : %d , wait time : %d\n", serviceUserCount, totalWaitTime);

    // displayDeque(pWaitQueue);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	printf(RED"\n=== now service node ===\n"RESET);
	printf("arrival time : %d, time taken : %d\n", customer.arrivalTime, customer.serviceTime);
	printf("start time : %d, end time : %d\n", customer.startTime, customer.endTime);
}

int come_here()
{
    printf("Are guests here? : (o, x) ");
    char c;
    fflush(stdin);
    scanf("%c", &c);
    if (c == 'o')
        return (2);
    else if (c == 'x')
        return (1);
    return (0);
}

int main()
{
    LinkedDeque *arrivalqueue = createLinkedDeque();
    LinkedDeque *waitqueue = createLinkedDeque();
    DequeNode *service = NULL;
    DequeNode *end;
    int pTotalWaitTime = 0;
    int pServiceUserCount = 0;

    int currentTime = 0;
    int arrivalTime = 0;
    int serviceTime = 0;

	for(int i = 0; i < MAX_TIME; i++)
	{
        //1초에 두명이상은 받을 수 없다!
        printf("--------------------------------\n");
        printf(RED"We are open until %d\n"RESET, MAX_TIME);
        printf("current time : [%d]\n", currentTime);
        int select = come_here();
        if (select == 1)
        {
            //메인로직
            printarrivalQueueStatus(currentTime, arrivalqueue);
            if (service && currentTime == service->data.endTime)
                service = processServiceNodeEnd(currentTime, service, &pServiceUserCount, &pTotalWaitTime);
            if (!service)
                service = processServiceNodeStart(currentTime, waitqueue);
            if (service)
                printSimCustomer(currentTime, service->data);
            else
            {
                printf(RED"=== now service node ===\n"RESET);
                printf("(NULL)\n");
            }
            printWaitQueueStatus(currentTime, waitqueue);
            printReport(waitqueue, pServiceUserCount, pTotalWaitTime);
            currentTime++;
            ///
            continue;
        }
        else if (select == 2)
        {
            printf("\nArrival time : %d\n", currentTime);
            fflush(stdin);
            printf("Service time : ");
            scanf("%d", &serviceTime);
            printf("\n");

            insertCutomer(currentTime, serviceTime, arrivalqueue);
            printarrivalQueueStatus(currentTime, arrivalqueue);

            //메인 로직
            processArrival(currentTime, arrivalqueue, waitqueue);
            if (service && currentTime == service->data.endTime)
                service = processServiceNodeEnd(currentTime, service, &pServiceUserCount, &pTotalWaitTime);
            if (!service)
                service = processServiceNodeStart(currentTime, waitqueue);
            if (service)
                printSimCustomer(currentTime, service->data);
            else
            {
                printf(RED"=== now service node ===\n"RESET);
                printf("(NULL)");
            }
            printWaitQueueStatus(currentTime, waitqueue);
            currentTime++;
            printReport(waitqueue, pServiceUserCount, pTotalWaitTime);
        }
        else
        {
            printReport(waitqueue, pServiceUserCount, pTotalWaitTime);
            exit(1);
	    }
    }
    printf("\n=====================\n");
    printf(RED"end of business\n"RESET);
    printf("\nnow current time is %d\n", MAX_TIME);
    printf("=====================\n");
    printReport(waitqueue, pServiceUserCount, pTotalWaitTime);
}