#pragma once

#include <vector>

struct BNode
{
	int size = 0;
	std::vector<int> keys;
	std::vector<BNode *> children;
	bool leaf = false;
};

class BTree
{
public:
	// constant time
	explicit BTree(unsigned uMinDegree) noexcept;
	~BTree();

	// logarithmic time
	void insert(int nValue);

	// logarithmic time
	void remove(int nValue);

	// logarithmic time
	std::pair<BNode *, unsigned> search(int nValue);

	// linear time
	void print();

private:
	// debug
	void printNode(BNode *pNode, int tab);

	void initializeNode(BNode *pNode);

	void insertInNode(BNode *pNode, int nValue);

	void deleteFromNode(BNode *pNode, int index);

	void freeNode(BNode *pNode);

	void splitNode(BNode *pNode, int index);

	bool isFull(BNode *pNode) const;

	int findIndex(BNode *pNode, int nValue) const;

	void fixChildSize(BNode *pNode, int index);

	bool itemFound(BNode *pNode, int index, int nValue) const;

	bool isLeaf(BNode *pNode) const;

	BNode *m_pRoot = nullptr;
	int m_iMinDegree = 0;
};
