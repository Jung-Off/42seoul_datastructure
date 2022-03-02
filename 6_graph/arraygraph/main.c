#include "arraygraph.h"

void make_weight_graph(void)
{
	ArrayGraph *pGraph;
	int i;

	pGraph = createArrayDirectedGraph(6);
	i = 0;
	while (i < pGraph->maxVertexCnt)
		addVertexAG(pGraph, i++);
	addEdgewithWeightAG(pGraph, 0, 1, 4);
	addEdgewithWeightAG(pGraph, 1, 2, 1);
	addEdgewithWeightAG(pGraph, 2, 1, 3);
	addEdgewithWeightAG(pGraph, 2, 0, 2);
	addEdgewithWeightAG(pGraph, 2, 3, 2);
	addEdgewithWeightAG(pGraph, 3, 2, 1);
	addEdgewithWeightAG(pGraph, 3, 4, 1);
	addEdgewithWeightAG(pGraph, 4, 5, 1);
	addEdgewithWeightAG(pGraph, 5, 3, 2);
	displayArrayGraph(pGraph);
	printf("\n");
	removeEdgeAG(pGraph, 5, 3);
	displayArrayGraph(pGraph);
	printf("\n");
	removeVertexAG(pGraph, 2);
	displayArrayGraph(pGraph);
	deleteArrayGraph(pGraph);
}

void make_graph(void)
{
	ArrayGraph *pGraph;
	int i;

	pGraph = createArrayGraph(6);
	i = 0;
	while (i < pGraph->maxVertexCnt)
		addVertexAG(pGraph, i++);
	addEdgeAG(pGraph, 0, 1);
	addEdgeAG(pGraph, 1, 2);
	addEdgeAG(pGraph, 2, 0);
	addEdgeAG(pGraph, 2, 3);
	addEdgeAG(pGraph, 3, 4);
	addEdgeAG(pGraph, 4, 5);
	addEdgeAG(pGraph, 5, 3);
	displayArrayGraph(pGraph);
	printf("\n");
	// removeEdgeAG(pGraph, 5, 3);
	removeVertexAG(pGraph, 2);
	displayArrayGraph(pGraph);
	removeVertexAG(pGraph, 2);
	displayArrayGraph(pGraph);
	removeVertexAG(pGraph, 3);
	displayArrayGraph(pGraph);
	addVertexAG(pGraph, 2);
	displayArrayGraph(pGraph);
	deleteArrayGraph(pGraph);
}

int main(void)
{
	printf("==== make_weight_graph ====\n\n");
	make_weight_graph();
	printf("==== make_graph ====\n\n");
	make_graph();
	system("leaks a.out");
	return (0);
}
