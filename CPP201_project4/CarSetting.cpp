#include "CarSetting.h"

CarSetting::CarSetting()
{
	display = new Display();
	sound = new Sound();
	general = new General();
}

CarSetting::~CarSetting()
{
}

Display* CarSetting::getDisplay()
{
	return this->display;
}

Sound* CarSetting::getSound()
{
	return this->sound;
}

General* CarSetting::getGeneral()
{
	return this->general;
}

void CarSetting::setDisplay(Display* data)
{
	this->display = data;
}

void CarSetting::setSound(Sound* data)
{
	this->sound = data;
}

void CarSetting::setGeneral(General* data)
{
	this->general = data;
}
