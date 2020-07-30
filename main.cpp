#include <iostream>
#include "Node.h"
#include "Edge.h"

using namespace std;

//Prints basic node data from a Node array
void displayNodeInfo(Node *nodeList[], int nodeListSize)
{
	cout << "::Node Data::" << endl;
	for (int i = 0; i < nodeListSize; i++)
	{
		cout << nodeList[i]->getName() << "::: Edges: " << nodeList[i]->getEdgeCount() << " :: " <<
		"dijkstraDistance: " << nodeList[i]->getDijkstraDistance() << endl;
	}
}

//Prints basic edge data from a Edge array
void displayEdgeInfo(Edge *edgeList[], int edgeListSize)
{
	cout << "::Edge Data::" << endl;
	for (int i = 0; i < edgeListSize; i++)
	{
		cout << "edge" << edgeList[i]->getPoint1()->getName() << edgeList[i]->getPoint2()->getName() << "::: " <<
			 "Point1: " << edgeList[i]->getPoint1()->getName() << " :: " <<
			 "Point2: " << edgeList[i]->getPoint2()->getName() << " :: " <<
			 "Weight: " << edgeList[i]->getWeight() << endl;
	}
}

//Returns true if node is in nodeList
bool doesListContainNode(Node *node, Node *nodeList[], int nodeListSize)
{
	bool contains = false;
	for (int i = 0; i <= nodeListSize - 1; i++)
	{
		if (nodeList[i] == node)
		{
			contains = true;
			return contains;
		}
	}
	return contains;
}

//Returns true if node1 and node 2 are directly connected via edge
bool isConnected(Node *node1, Node *node2, Edge *edgeList[], int edgeListSize)
{
	bool connected = false;
	for (int i = 0; i <= edgeListSize - 1; i++)
	{
		if ((edgeList[i]->getPoint1() == node1 || edgeList[i]->getPoint2() == node1) &&
			//If edgeList contains edge with node1 and node2
			(edgeList[i]->getPoint1() == node2 || edgeList[i]->getPoint2() == node2))
		{
			connected = true;
			return connected;
		}
	}
	return connected;
}

//Will set dijkstraDistance and previousNode values and will print the shortest path from startNode to endNode
void findDijkstrasShortestPath(Node *nodeList[], Edge *edgeList[], Node *startNode, Node *endNode, int nodeCount, int edgeCount)
{
	//Initialize dijkstra distance and previous node pointers back to their default values
	for (int i = 0; i <= nodeCount-1; i++)
	{
		nodeList[i]->setDijkstraDistance(-1);
		nodeList[i]->setPreviousNode(NULL);
	}

	//Sets current node to the starting node
	Node *currentNode = startNode;

	//Sets distance value from start to current node (ZERO)
	startNode->setDijkstraDistance(0);

	//Create visitedNodes array
	Node *visitedNodes[nodeCount];

	//Integer acts as the array size value
	int visitedNodesCount = 0;

	//While there are still unvisited nodes on graph
	while (visitedNodesCount != nodeCount)
	{
		//Iterates through every node
		for (int i = 0; i <= nodeCount; i++)
		{
			//Determines if node is directly linked to currentNode
			if (isConnected(currentNode, nodeList[i], edgeList, edgeCount))
			{
				//If node is not in visited node list and is not current node
				if (doesListContainNode(nodeList[i], visitedNodes, visitedNodesCount) == false &&
					nodeList[i] != currentNode)
				{
					Edge *e;
					int leastWeight = -2; //leastWeight initialized at -2 to mark it has not been set yet

					//Iterates through every edge in graph
					for (int j = 0; j <= edgeCount - 1; j++)
					{
						//If edge contains currentNode and pointed node
						if ((edgeList[j]->getPoint1() == nodeList[i] || edgeList[j]->getPoint2() == nodeList[i]) &&
						(edgeList[j]->getPoint1() == currentNode || edgeList[j]->getPoint2() == currentNode))
						{
							//If leastWeight is default or if edge weight is less than current leastWeight
							if (leastWeight == -2 || edgeList[j]->getWeight() < leastWeight)
							{
								e = edgeList[j];
								leastWeight = e->getWeight();
							}
						}
					}

					int weight = e->getWeight();

					//If a node's previousNode pointer is NULL
					if (nodeList[i]->getPreviousNode() == NULL)
					{
						nodeList[i]->setPreviousNode(currentNode);
					}

					//If node's dijkstra distance is still default
					if (nodeList[i]->getDijkstraDistance() == -1)
					{
						nodeList[i]->setDijkstraDistance(currentNode->getDijkstraDistance() + weight);
					}

					else
					{
						//If node's dijkstra distance is greater than currentNode's distance plus the weight value
						if (nodeList[i]->getDijkstraDistance() > currentNode->getDijkstraDistance() + weight)
						{
							nodeList[i]->setDijkstraDistance(currentNode->getDijkstraDistance() + weight);
							nodeList[i]->setPreviousNode(currentNode);
						}
					}
				}
			}
		}

		visitedNodes[visitedNodesCount] = currentNode; //Sets current node as a visited node
		visitedNodesCount += 1;

		//Iterates through every node in graph
		for (int i = 0; i <= nodeCount; i++)
		{
			//If node's dijkstra distance is default value and is not in visitedNodes[]
			if (nodeList[i]->getDijkstraDistance() != -1 &&
				doesListContainNode(nodeList[i], visitedNodes, nodeCount) == false)
			{
				currentNode = nodeList[i];
				break;
			}
		}
	}

	Node *reverse = endNode; //Used as temporary pointer as we retrace from the end point to start point

	int size = 1;
	//While Loop that will obtain the size needed to instantiate the array
	while(reverse->getPreviousNode() != NULL)
	{
		size++;
		reverse = reverse->getPreviousNode();
	}

	//Constant int used to instantiate the array size
	const int arraySize = size;
	char shortestPathArray[arraySize];
	int index = size-1;
	reverse = endNode;

	//While loop that will fill the shortestPathArray with the order of nodes for the shortestPath
	while(reverse != NULL)
	{
		shortestPathArray[index] = reverse->getName();
		index--;
		reverse = reverse->getPreviousNode();
	}

	cout << "\nShortest Path from " << startNode->getName() << " to " << endNode->getName() << ": ";
	//For loop that will output the shortest path array
	for(int i = 0; i <= size-1; i++)
	{
		cout << " " << shortestPathArray[i];
	}
}

int main()
{
	const int nodeCount = 6; //Can be used for various arguments
	const int edgeCount = 7; //Can be used for various arguments

	///////////////////////////////////////
	////////// Creating the graph /////////
	///////////////////////////////////////

	//Manually create nodes
	Node *A = new Node('A');
	Node *B = new Node('B');
	Node *C = new Node('C');
	Node *D = new Node('D');
	Node *E = new Node('E');
	Node *F = new Node('F');

	//Manually give nodes their edgeCount data
	A->setEdgeCount(2);
	B->setEdgeCount(3);
	C->setEdgeCount(2);
	D->setEdgeCount(2);
	E->setEdgeCount(3);
	F->setEdgeCount(2);

	//Manually create edges
	Edge *edgeAB = new Edge(A, B, 2);
	Edge *edgeAC = new Edge(A, C, 3);
	Edge *edgeBD = new Edge(B, D, 4);
	Edge *edgeBE = new Edge(B, E, 5);
	Edge *edgeCE = new Edge(C, E, 5);
	Edge *edgeDF = new Edge(D, F, 8);
	Edge *edgeEF = new Edge(E, F, 4);

	///////////////////////////////////////
	//////// Displaying Graph Info ////////
	///////////////////////////////////////

	cout << "_Initial Graph Info_" << endl;

	//Display Node Info
	Node *nodeSet[] = {A, B, C, D, E, F};
	displayNodeInfo(nodeSet, nodeCount);

	cout << endl;

	//Display Edge Info
	Edge *edgeSet[] = {edgeAB, edgeAC, edgeBD, edgeBE, edgeCE, edgeDF, edgeEF};
	displayEdgeInfo(edgeSet, edgeCount);

	///////////////////////////////////////
	////////// Running Algorithm //////////
	///////////////////////////////////////

	cout << "Graph Demo 1: (A to F)" << endl;

	//Dijkstra's Shortest Path Algorithm
	findDijkstrasShortestPath(nodeSet, edgeSet, A, F, nodeCount, edgeCount);

	cout << endl << endl;

	//Display Node Info -- After Algorithm run #1
	displayNodeInfo(nodeSet, nodeCount);

	cout << endl << endl;

	cout << "----------------------" << endl;
	cout << "Graph Demo 2: (C to D)" << endl;

	//Dijkstra's Shortest Path Algorithm
	findDijkstrasShortestPath(nodeSet, edgeSet, C, D, nodeCount, edgeCount);

	cout << endl << endl;


	//Display Node Info -- After Algorithm run #2
	displayNodeInfo(nodeSet, nodeCount);
	return 0;
}