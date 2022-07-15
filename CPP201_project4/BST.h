#pragma once
#include "Node.h"
#include <fstream>

using namespace std;


class BST
{
private:
	Node* root;
	void Insert(CarSetting* Car, Node* aNode);
	Node* SearchPersonalKey(string data, Node* aNode);
	Node* SearchOwnerName(string data, Node* aNode);
	void inOrderDisplaySetting(Node* aNode);
	void inOrderSoundSetting(Node* aNode);
	void inOrderGeneralSetting(Node* aNode);
	void inOrderAllSetting(Node* aNode);
	Node* getParentNode(Node*& aNode, string data, Node*& parent);
	Node* getMinimunNode(Node* aNode);
	Node* getMaximunNodeFromLeftChild(Node* aNode);
	void deleteNode(string data, Node* aNode);
	void SearchOwnerNameData(string data, Node* aNode);
	void BTreeData(Node* aNode);
public:
	BST();
	void Insert(CarSetting* Car);
	Node* SearchPersonalKey(string data);
	Node* SearchOwnerName(string data);
	void inOrderDisplaySetting();
	void inOrderSoundSetting();
	void inOrderGeneralSetting();
	void inOrderAllSetting();
	void deleteNode(string data);
	void SearchOwnerNameData(string data);
	void BTreeData();
	vector<Node*> OwnerNameData;
	vector<CarSetting*> CarData;
};

