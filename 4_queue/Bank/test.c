#include "bank.h"
#include <stdio.h>

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
	DequeNode *element;

	element = pArrivalQueue->pFrontNode;
	while (element && element->data.arrivalTime == currentTime)
	{
		element = deleteFrontLD(pArrivalQueue);
		insertRearLD(pWaitQueue, *element);
		element = element->pRLink;
	}
}

DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue)
{
	if (!pWaitQueue->pFrontNode)
		return (NULL);
	DequeNode *service;
	service = deleteFrontLD(pWaitQueue);
	service->data.status = start;
	service->data.startTime = currentTime;
	service->data.endTime = currentTime + service->data.serviceTime;
	return (service);
}

DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	pServiceNode->data.status = end;
	(*pServiceUserCount)++;
	*pTotalWaitTime += pServiceNode->data.startTime - pServiceNode->data.arrivalTime;
	return (NULL);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	printf("\n\n\n현재 서비스 노드\n");
	printf("도착 시간 : %d   소요 시간 : %d\n", customer.arrivalTime, customer.serviceTime);
	printf("시작 시간 : %d   종료 시간 : %d\n", customer.startTime, customer.endTime);
}

void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue)
{
	if (!pWaitQueue->pFrontNode)
	{	
		printf("\n\n\n대기 손님 없음\n");
		return ;
	}
	printf("\n\n\nWait List\n");
	displayDeque(pWaitQueue);
}

void printarrivalQueueStatus(int currentTime, LinkedDeque *pQueue)
{
	if (!pQueue->pFrontNode)
	{
		printf("\n도착 손님 없음\n");
		return ;
	}
	printf("\nArrival List\n");
	displayDeque(pQueue);
}

void printReport(LinkedDeque *pWaitQueue,int serviceUserCount, int totalWaitTime)
{
	printf("\n-----------------------------\n");
	printf("손님 총 %d명, 총 대기시간 %d\n", serviceUserCount, totalWaitTime);
}

int main()
{
	LinkedDeque *arrivalqueue = createLinkedDeque();
	LinkedDeque *waitqueue = createLinkedDeque();


	insertCutomer(0, 3, arrivalqueue);
    insertCutomer(2, 2, arrivalqueue);
    insertCutomer(4, 1, arrivalqueue);
	insertCutomer(6, 1, arrivalqueue);
    insertCutomer(8, 3, arrivalqueue);

	int currentTime = 0;
	int pServiceUserCount;
	int pTotalWaitTime;

	pServiceUserCount = 0;
	pTotalWaitTime = 0;
	DequeNode *serviceNode;
	serviceNode = NULL; 
	while (currentTime < MAX_TIME) // 최대 15까지 (운행시간 종료 후에도 대기 고객이 존재할까봐)
	{
		processArrival(currentTime, arrivalqueue, waitqueue); // cur = arrivalTime  : 도착 큐 -> 대기 큐
		if (serviceNode && (currentTime - serviceNode->data.startTime == serviceNode->data.serviceTime)) // 서비스 중이고, 그 서비스가 서비스타임만큼 진행됐으면 종료
			serviceNode = processServiceNodeEnd(currentTime, serviceNode, &pServiceUserCount, &pTotalWaitTime);
		if (!serviceNode) // 서비스노드가 없으면 start함수 실행
			serviceNode = processServiceNodeStart(currentTime, waitqueue);
		if (!waitqueue->pFrontNode && !arrivalqueue->pFrontNode && !serviceNode) // 서비스 노드, 대기, 도착 큐 모두 비면 종료
			break ;
		printf("\n----------CUR : %d-----------\n", currentTime);
		printarrivalQueueStatus(currentTime, arrivalqueue); // 도착 큐 출력
		printWaitQueueStatus(currentTime, waitqueue); // 대기 큐 출력
		if (serviceNode) //서비스 노드가 존재하면
			printSimCustomer(currentTime, serviceNode->data); // 서비스 노드의 정보 출력
		currentTime++;
	}
	printReport(waitqueue, pServiceUserCount, pTotalWaitTime); // 최종 보고
}
