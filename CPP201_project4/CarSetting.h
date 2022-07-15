#pragma once
#include "Setting.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"

using namespace std;


class CarSetting : public Setting
{
public:
	CarSetting();
	~CarSetting();
	Display* getDisplay();			// lay ra con tro doi tuong Display
	Sound* getSound();				// lay ra con tro doi tuong Sound
	General* getGeneral();			// lay ra con tro doi tuong General 

	void setDisplay(Display* data); // set con tro doi tuong Display
	void setSound(Sound* data);		// set con tro doi tuong Sound
	void setGeneral(General* data);	// set con tro doi tuong General
private:
	Display* display;
	Sound* sound;
	General* general;
};

