//Edge.cpp
//Implementation of Edge Class
//Documentation is in header file (Edge.h)

#include "Edge.h"
#include "Node.h"

Edge::Edge(Node *point1, Node *point2, int weight)
{
	this->point1 = point1;
	this->point2 = point2;
	this->weight = weight;
}

int Edge::getWeight()
{
	return Edge::weight;
}

void Edge::setWeight(int weight)
{
	Edge::weight = weight;
}

Node *Edge::getPoint1()
{
	return point1;
}

void Edge::setPoint1(Node *point1)
{
	Edge::point1 = point1;
}

Node *Edge::getPoint2()
{
	return point2;
}

void Edge::setPoint2(Node *point2)
{
	Edge::point2 = point2;
}
