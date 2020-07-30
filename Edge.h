#ifndef DATASTRUCTURESPROJECT_EDGE_H
#define DATASTRUCTURESPROJECT_EDGE_H

#include "Node.h"


class Edge
{

private:
	Node *point1; //connected point 1
	Node *point2; //connected point 2
	int weight; //The numerical edge weight value

public:
	Edge(Node *point1, Node *point2, int weight); //Node Constructor
	int getWeight(); //Returns weight
	void setWeight(int weight); //Sets weight
	Node *getPoint1(); //Gets point1
	void setPoint1(Node *point1); //Sets point1
	Node *getPoint2(); //Gets point2
	void setPoint2(Node *point2); //Sets point2
};
#endif //DATASTRUCTURESPROJECT_EDGE_H
