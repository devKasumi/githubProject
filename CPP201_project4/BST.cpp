#include "BST.h"

void BST::Insert(CarSetting* Car, Node* aNode)		// ham insert node va du lieu xe 
{
	if (Car->getPersonalKey() < aNode->Car->getPersonalKey()) {
		if (aNode->left != NULL) {
			Insert(Car, aNode->left);
		}
		else {
			aNode->left = new Node(Car);
			aNode->left->left = NULL;
			aNode->left->right = NULL;
		}
	}
	else if (Car->getPersonalKey() > aNode->Car->getPersonalKey()) {
		if (aNode->right != NULL) {
			Insert(Car, aNode->right);
		}
		else {
			aNode->right = new Node(Car);
			aNode->right->left = NULL;
			aNode->right->right = NULL;
		}
	}
}

Node* BST::SearchPersonalKey(string data, Node* aNode)
{
	if (aNode != NULL) {
		if (data == aNode->Car->getPersonalKey()) {
			return aNode;
		}
		else if (data < aNode->Car->getPersonalKey()) {
			return SearchPersonalKey(data, aNode->left);
		}
		else {
			return SearchPersonalKey(data, aNode->right);
		}
	}
	else {
		return NULL;
	}
}

Node* BST::SearchOwnerName(string data, Node* aNode)
{
	if (aNode != NULL) {
		if (data == aNode->Car->getCarName()) {
			return aNode;
		}
		else if (data < aNode->Car->getCarName()) {
			return SearchOwnerName(data, aNode->left);
		}
		else {
			return SearchOwnerName(data, aNode->right);
		}
	}
	else {
		return NULL;
	}
}

void BST::inOrderDisplaySetting(Node* aNode)
{
	if (aNode != NULL) {
		inOrderDisplaySetting(aNode->left);
		aNode->Car->xuat();
		aNode->Car->getDisplay()->xuat();
		inOrderDisplaySetting(aNode->right);
	}
}

void BST::inOrderSoundSetting(Node* aNode)
{
	if (aNode != NULL) {
		inOrderSoundSetting(aNode->left);
		aNode->Car->xuat();
		aNode->Car->getSound()->xuat();
		inOrderSoundSetting(aNode->right);
	}
}

void BST::inOrderGeneralSetting(Node* aNode)
{
	if (aNode != NULL) {
		inOrderGeneralSetting(aNode->left);
		aNode->Car->xuat();
		aNode->Car->getGeneral()->xuat();
		inOrderGeneralSetting(aNode->right);
	}
}

void BST::inOrderAllSetting(Node* aNode)
{
	if (aNode != NULL) {
		inOrderAllSetting(aNode->left);
		aNode->Car->xuat();
		aNode->Car->getDisplay()->xuat();
		aNode->Car->getSound()->xuat();
		aNode->Car->getGeneral()->xuat();
		inOrderAllSetting(aNode->right);
	}
}

Node* BST::getParentNode(Node*& aNode, string data, Node*& parent)
{
	while (aNode != nullptr && aNode->Car->getPersonalKey() != data) {
		parent = aNode;
		if (data < aNode->Car->getPersonalKey()) {
			aNode = aNode->left;
		}
		else {
			aNode = aNode->right;
		}
	}
	return parent;
}

Node* BST::getMinimunNode(Node* aNode)
{
	while (aNode->left != NULL) {
		aNode = aNode->left;
	}
	return aNode;
}

Node* BST::getMaximunNodeFromLeftChild(Node* aNode)
{
	Node* leftChild = aNode->left;
	while (leftChild->right != NULL) {
		aNode = leftChild->right;
	}
	return aNode;
}

void BST::deleteNode(string data, Node* aNode)
{
	Node* parent = NULL;
	parent = getParentNode(aNode, data, parent);
	if (aNode == NULL) {
		return;				// exit the function immediately and back to the caller 
	}
	if (aNode->left == NULL && aNode->right == NULL) {
		if (aNode != root) {
			if (parent->left == aNode) {
				parent->left = NULL;
			}
			else {
				parent->right = NULL;
			}
		}
		else {
			root = NULL;
		}
		free(aNode);
	}
	else if (aNode->left != NULL && aNode->right != NULL) {
		Node* successor = NULL;
		/*if (aNode->right->right != NULL) {
			successor = getMinimunNode(aNode->right);
		}
		else {
			successor = getMaximunNodeFromLeftChild(aNode);
		}*/
		successor = getMinimunNode(aNode->right);
		string val = successor->Car->getPersonalKey();
		deleteNode(successor->Car->getPersonalKey(), aNode);
		aNode->Car->getPersonalKey() = val;
	}
	else {
		Node* child = (aNode->left) ? aNode->left : aNode->right; // child = aNode->left if (aNode->left != NULL) or else !
		if (aNode != root) {
			if (aNode == parent->left) {
				parent->left = child;
			}
			else {
				parent->right = child;
			}
		}
		else {
			root = child;
		}
		free(aNode);
	}
}

void BST::SearchOwnerNameData(string data, Node* aNode)
{
	if (aNode != NULL) {
		if (aNode->left != NULL && aNode->right != NULL) {
			if (aNode->Car->getCarName() == data) {
				OwnerNameData.push_back(aNode);
				SearchOwnerNameData(data, aNode->left);
				SearchOwnerNameData(data, aNode->right);
			}
			else {
				SearchOwnerNameData(data, aNode->left);
				SearchOwnerNameData(data, aNode->right);
			}
		}
		else if (aNode->left == NULL && aNode->right != NULL) {
			if (aNode->Car->getCarName() == data) {
				OwnerNameData.push_back(aNode);
				SearchOwnerNameData(data, aNode->right);
			}
			else {
				SearchOwnerNameData(data, aNode->right);
			}
		}
		else if (aNode->left != NULL && aNode->right == NULL) {
			if (aNode->Car->getCarName() == data) {
				OwnerNameData.push_back(aNode);
				SearchOwnerNameData(data, aNode->left);
			}
			else {
				SearchOwnerNameData(data, aNode->left);
			}
		}
		else if (aNode->left == NULL && aNode->right == NULL) {
			if (aNode->Car->getCarName() == data) {
				OwnerNameData.push_back(aNode);
			}
		}
	}
}

void BST::BTreeData(Node* aNode)
{
	if (aNode != NULL) {
		CarData.push_back(aNode->Car);
		if (aNode->left != NULL && aNode->right != NULL) {
			BTreeData(aNode->left);
			BTreeData(aNode->right);
		}
		else if (aNode->left != NULL && aNode->right == NULL) {
			BTreeData(aNode->left);
		}
		else if (aNode->left == NULL && aNode->right != NULL) {
			BTreeData(aNode->right);
		}
	}
}

BST::BST()
{
	root = NULL;
}

void BST::Insert(CarSetting* Car)
{
	if (root != NULL) {
		Insert(Car, root);
	}
	else {
		root = new Node(Car);
		root->left = NULL;
		root->right = NULL;
	}
}

Node* BST::SearchPersonalKey(string data)
{
	return SearchPersonalKey(data, root);
}

Node* BST::SearchOwnerName(string data)
{
	return SearchOwnerName(data, root);
}

void BST::inOrderDisplaySetting()
{
	inOrderDisplaySetting(root);
}

void BST::inOrderSoundSetting()
{
	inOrderSoundSetting(root);
}

void BST::inOrderGeneralSetting()
{
	inOrderGeneralSetting(root);
}

void BST::inOrderAllSetting()
{
	inOrderAllSetting(root);
}

void BST::deleteNode(string data)
{
	deleteNode(data, root);
}

void BST::SearchOwnerNameData(string data)
{
	SearchOwnerNameData(data, root);
}

void BST::BTreeData()
{
	BTreeData(root);
}
