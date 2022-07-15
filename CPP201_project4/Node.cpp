#include "Node.h"

Node::Node(CarSetting* car)
{
	Car = new CarSetting();
	Car = car;
	left = NULL;
	right = NULL;
}
