//Node.cpp
//Implementation of Node class
//Documentation is in header file (Node.h)

#include "Node.h"
#include "Edge.h"

Node::Node(char label)
{
	Node::dDistance = -1;
	Node::nodeName = label;
	Node::numOfEdges = 0;
	Node::dPrevPathNode = nullptr;
}

char Node::getName()
{
	return Node::nodeName;
}

int Node::getEdgeCount()
{
	return Node::numOfEdges;
}

int Node::getDijkstraDistance()
{
	return Node::dDistance;
}

Node* Node::getPreviousNode()
{
	return Node::dPrevPathNode;
}

void Node::setEdgeCount(int edgeCount)
{
	Node::numOfEdges = edgeCount;
}

void Node::setDijkstraDistance(int distance)
{
	Node::dDistance = distance;
}

void Node::setPreviousNode(Node *prevNode)
{
	Node::dPrevPathNode = prevNode;
}

