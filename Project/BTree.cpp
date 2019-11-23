#include "BTree.h"

#include <utility>
#include <iostream>

BTree::BTree(unsigned uMinDegree) noexcept
	: m_pRoot(new BNode)
	, m_iMinDegree(uMinDegree)
{
	initializeNode(m_pRoot);
	m_pRoot->leaf = true;
}

BTree::~BTree()
{
	freeNode(m_pRoot);
}

void BTree::freeNode(BNode *pNode)
{

}

bool BTree::isFull(BNode *pNode) const
{
	return pNode->size == 2 * m_iMinDegree - 1;
}

void BTree::insert(int nValue)
{
	if (isFull(m_pRoot))
	{
		auto pNewRoot = new BNode;
		initializeNode(pNewRoot);
		pNewRoot->leaf = false;

		pNewRoot->children[0] = m_pRoot;

		m_pRoot = pNewRoot;
		splitNode(m_pRoot, 0);
	}

	auto pCurrentNode = m_pRoot;
	while (!pCurrentNode->leaf)
	{
		int index = pCurrentNode->size - 1;
		while (index >= 0 && nValue < pCurrentNode->keys[index])
			--index;

		++index;

		if (isFull(pCurrentNode->children[index]))
		{
			splitNode(pCurrentNode, index);
			if (pCurrentNode->keys[index] < nValue)
				++index;
		}

		pCurrentNode = pCurrentNode->children[index];
	}

	insertInNode(pCurrentNode, nValue);
}

void BTree::splitNode(BNode *pParentNode, int index)
{
	auto pNodeToSplit = pParentNode->children[index];

	auto pNewNode = new BNode;
	initializeNode(pNewNode);
	pNewNode->leaf = pNodeToSplit->leaf;
	pNewNode->size = m_iMinDegree - 1;

	// move data to new node
	for (auto i = 0; i < m_iMinDegree - 1; ++i)
		pNewNode->keys[i] = pNodeToSplit->keys[i + m_iMinDegree];

	if (!pNodeToSplit->leaf)
	{
		for (auto i = 0; i < m_iMinDegree; ++i)
			pNewNode->children[i] = pNodeToSplit->children[i + m_iMinDegree];
	}

	pNodeToSplit->size = m_iMinDegree - 1;

	insertInNode(pParentNode, pNodeToSplit->keys[m_iMinDegree - 1]);
	pParentNode->children[index + 1] = pNewNode;
}

void BTree::insertInNode(BNode *pNode, int nValue)
{
	auto index = 0;
	for (index = pNode->size; index > 0 && nValue < pNode->keys[index - 1]; --index)
	{
		pNode->keys[index] = pNode->keys[index - 1];
		pNode->children[index + 1] = pNode->children[index];
	}

	pNode->children[index + 1] = pNode->children[index];
	pNode->keys[index] = nValue;
	++pNode->size;
}

void BTree::remove(int nValue)
{
	auto pCurrentNode = m_pRoot;
	while (true)
	{
		auto idx = findIndex(pCurrentNode, nValue);

		// item found
		if (itemFound(pCurrentNode, idx, nValue))
		{
			if (isLeaf(pCurrentNode))
				deleteFromNode(pCurrentNode, idx);
			else
			{
				// replace with predecessor/successor or merge children
			}
			return;
		}
		else
		{
			auto pLeftChild = pCurrentNode->children[idx];
			auto pRightChild = pCurrentNode->children[idx + 1];

			if (pLeftChild->size >= m_iMinDegree)
			{
				// replace with predecessor
				while (!isLeaf(pLeftChild))
				{
					fixChildSize(pLeftChild, pLeftChild->size);
					pLeftChild = pLeftChild->children[pLeftChild->size];
				}

				//pCurrentNode->keys[idx] =  
			}
			else if (pRightChild->size >= m_iMinDegree)
			{
				// replace with successor
				while (!isLeaf(pRightChild))
				{
					fixChildSize(pRightChild, 0);
					pRightChild = pRightChild->children[0];
				}
			}
			else
			{
				// merge
			}

			return;
		}
	}
}

void BTree::fixChildSize(BNode *pNode, int index)
{

}

void BTree::deleteFromNode(BNode *pNode, int index)
{
	--pNode->size;
	while (index < pNode->size)
	{
		pNode->keys[index] = pNode->keys[index + 1];
		pNode->children[index + 1] = pNode->children[index + 2];
		++index;
	}
}

std::pair<BNode *, unsigned> BTree::search(int nValue)
{
	auto pCurrentNode = m_pRoot;
	while (true)
	{
		auto idx = findIndex(pCurrentNode, nValue);

		// item found
		if (itemFound(pCurrentNode, idx, nValue))
			return std::make_pair(pCurrentNode, idx);

		if (isLeaf(pCurrentNode))
			break;

		pCurrentNode = pCurrentNode->children[idx];
	}

	return std::make_pair(nullptr, -1);
}

bool BTree::itemFound(BNode *pNode, int index, int nValue) const
{
	return index < pNode->size && pNode->keys[index] == nValue;
}

bool BTree::isLeaf(BNode *pNode) const
{
	return pNode->leaf;
}

int BTree::findIndex(BNode *pNode, int nValue) const
{
	int idx = 0;
	while (idx < pNode->size && pNode->keys[idx] < nValue)
		++idx;

	return idx;
}

void BTree::print()
{
	std::cout << '\n';
	printNode(m_pRoot, 0);
	std::cout << '\n';
}

void BTree::initializeNode(BNode *pNode)
{
	pNode->size = 0;
	pNode->keys.resize(2 * static_cast<std::size_t>(m_iMinDegree) - 1);
	pNode->children.resize(2 * static_cast<std::size_t>(m_iMinDegree));
}

void BTree::printNode(BNode *pNode, int tab)
{
	//std::cout << "size: " << pNode->size << '\n';
	//std::cout << "keys size: " << pNode->keys.size() << '\n';
	//std::cout << "children size: " << pNode->children.size() << '\n';
	//std::cout << "is leaf?: " << pNode->leaf << '\n';

	for (auto i = 0; i < tab; ++i)
		std::cout << '\t';

	for (auto i = 0; i < pNode->size; ++i)
		std::cout << pNode->keys[i] << ' ';

	std::cout << '\n';

	if (!isLeaf(pNode))
	{
		++tab;
		for (auto i = 0; i < pNode->size + 1; ++i)
			printNode(pNode->children[i], tab);
	}
}