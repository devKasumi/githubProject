#pragma once
#include "CarSetting.h"

using namespace std;

class Node
{
public:
	CarSetting* Car;
	Node* left;
	Node* right;
	Node(CarSetting* car);
};

