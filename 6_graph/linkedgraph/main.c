#include "linkedgraph.h"

void make_weight_graph(void)
{
	LinkedGraph *pGraph;
	int i;

	pGraph = createLinkedDirectedGraph(6);
	i = 0;
	while (i < pGraph->maxVertexCount)
		addVertexLG(pGraph, i++);
	addEdgewithWeightLG(pGraph, 0, 1, 4);
	addEdgewithWeightLG(pGraph, 1, 2, 1);
	addEdgewithWeightLG(pGraph, 2, 1, 3);
	addEdgewithWeightLG(pGraph, 2, 0, 2);
	addEdgewithWeightLG(pGraph, 2, 3, 2);
	addEdgewithWeightLG(pGraph, 3, 2, 1);
	addEdgewithWeightLG(pGraph, 3, 4, 1);
	addEdgewithWeightLG(pGraph, 4, 5, 1);
	addEdgewithWeightLG(pGraph, 5, 3, 2);
	displayLinkedGraph(pGraph);
	printf("\n");
	// removeEdgeLG(pGraph, 5, 3);
	removeVertexLG(pGraph, 2);
	displayLinkedGraph(pGraph);
	deleteLinkedGraph(pGraph);// -> USED/NOT_USED 고려
}

void make_graph(void)
{
	LinkedGraph *pGraph;
	int i;

	pGraph = createLinkedGraph(6);
	i = 0;
	while (i < pGraph->maxVertexCount)
		addVertexLG(pGraph, i++);
	addEdgeLG(pGraph, 0, 1);
	addEdgeLG(pGraph, 1, 2);
	addEdgeLG(pGraph, 2, 0);
	addEdgeLG(pGraph, 2, 3);
	addEdgeLG(pGraph, 3, 4);
	addEdgeLG(pGraph, 4, 5);
	addEdgeLG(pGraph, 5, 3);
	printf("info: %d %d\n", pGraph->currentVertexCount, pGraph->currentEdgeCount);
	displayLinkedGraph(pGraph);
	printf("\n");
	// removeEdgeLG(pGraph, 5, 3);
	// removeVertexLG(pGraph, 2);
	// removeVertexLG(pGraph, 3);
	// addVertexLG(pGraph, 2);
	// displayLinkedGraph(pGraph);
	// deleteLinkedGraph(pGraph);
}

int main(void)
{
	make_weight_graph();
	// make_graph();
	// system("leaks a.out");
	return (0);
}

