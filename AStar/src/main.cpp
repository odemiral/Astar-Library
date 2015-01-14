/* Written By Onur Demiralay 
 * Github: @odemiral
 * MIT License Copyright(c) 2014 Onur Demiralay
 */
#include "Astar.h"
using namespace std;



/* Simple function displays all the elements in the vector 
* uses the display() function for Node class
*/
void displayVec(vector<Node> &vec)
{
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		(it)->display();
	}
	cout << endl;
}


void gridTestUsingClass()
{
	Node *start = new Node(4, 1);
	Node *goal = new Node(7, 0);
	int rows = 10;
	int cols = 10;
	Grid::movementType movement = Grid::movementType::FOUR_DIRECTIONS;
	vector<Node> obstacles;
	obstacles.push_back(Node(1, 4));
	obstacles.push_back(Node(2, 4));
	obstacles.push_back(Node(3, 4));

	obstacles.push_back(Node(3, 2));
	obstacles.push_back(Node(3, 3));
	obstacles.push_back(Node(3, 5));

	obstacles.push_back(Node(4, 5));
	obstacles.push_back(Node(5, 5));
	obstacles.push_back(Node(6, 5));
	obstacles.push_back(Node(7, 5));

	obstacles.push_back(Node(4, 2));
	obstacles.push_back(Node(4, 3));

	obstacles.push_back(Node(5, 0));
	obstacles.push_back(Node(5, 1));
	displayVec(obstacles);

	/*	S -> Start,
		G -> Goal
		_ -> Obstacle
		X -> Visited Nodes from Goal to Start

		0	0	0	0	0	0	0	0	0	0	
		0	0	0	0	0	0	0	0	0	0	 
		0	0	0	0	0	0	0	0	0	0	
		0	0	X	X	X	X	X	X	X	0	
		X	X	X	_	_	_	_	_	X	0	
		X	_	_	_	0	0	0	X	X	0	
		X	X	X	_	0	0	0	X	0	0	
		0	0	X	_	_	_	0	X	0	0	
		0	0	X	X	S	_	0	X	0	0	
		0	0	0	0	0	_	0	G	0	0	
	*/

	Grid *grid = new Grid(cols, rows, movement, obstacles);
	AStar astar(grid);
	vector<Node> path = astar.search(start, goal);
	displayVec(path);
}


int main(int argc, char* argv[])
{
	gridTestUsingClass();
	return 0;
}

