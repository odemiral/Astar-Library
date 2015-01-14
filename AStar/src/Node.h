#pragma once

#include <vector>
#include <iostream>
class Node
{


// TODO: Make this to accomadete N-dimensions by using templates
public:
	Node(int x, int y, int cost);
	Node(int x, int y);
	Node();
	~Node();

	//get rid of these later.
	int getX() const;
	int getY() const;
	int getCost() const;

	int getPriority() const;
	void setPriority(int priority);

	void setCost(int cost);
	bool operator==(Node const &rhs) const;
	bool operator!=(Node const &rhs) const;

	//in case if i ever want to conver it to work with multi dimensions.
	std::vector<int> getDimensions() const;


	// bool Node::nodePtrEqualityPredicate(Node const* n1, Node const* n2) const;

	void display() const; /* for debugging only */

private:
	std::vector<int> dimensions;
	int X, Y;
	int m_cost;
	int m_priority; // this is purely for the priority queue to keep 

};


/* works just like boost's hash_combine */
template <class T>
inline void hash_combine(std::size_t& seed, const T& v)
{
	std::hash<T> hasher;
	seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}



/* Template specialisation to accomodate Node type in cpp containters such as unoredered_set */
namespace std
{
	template<>
	struct hash<Node>
	{
		std::size_t operator()(const Node &node) const
		{
			//starts with hash value 0 of 0 will be modified by XORing and bit-shifting in hash_combine function.
			size_t seed = 0;
			hash_combine(seed, node.getX());
			hash_combine(seed, node.getY());
			return seed;
		}
	};

	//delete this
	template<>
	struct hash<Node*>
	{
		std::size_t operator()(const Node* node) const
		{
			return hash<Node>()(*node);
		}
	};

	/*
	template<>
	struct equal_to < Node*>
	{
		bool operator()(Node const &n1, Node const &n2) const {
			return n1 == n2;
		}
	};
	*/
}

