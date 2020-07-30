#ifndef DATASTRUCTURESPROJECT_NODE_H
#define DATASTRUCTURESPROJECT_NODE_H


class Node
{
public:
	Node(char label);
	char getName(); //Returns nodeName
	int getEdgeCount(); //Returns numOfEdges
	int getDijkstraDistance(); //Returns dDistance
	Node* getPreviousNode(); //Returns dPrevPathNode
	void setEdgeCount(int edgeCount); //Sets EdgeCount
	void setDijkstraDistance(int distance); //Sets dDistance
	void setPreviousNode(Node *dPrevPathNode); //Sets dPrevPathNode


private:
	char nodeName; //Label name for the node
	int numOfEdges; //Number of edges touching a node
	int dDistance; //The placeholder distance value that is modified via Dijkstra's Algorithm
	Node *dPrevPathNode; //The placeholder value for shortest previous node modified in Dijkstra's Algorithm
};

#endif //DATASTRUCTURESPROJECT_NODE_H