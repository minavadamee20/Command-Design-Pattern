//
//  command_pattern_main.cpp
//  command_pattern
//
//

#include <iostream>
#include "simpleRemoteControl.h"
#include "notSoSimpleRemoteControl.h"
#include "remoteControl.h"

#include "light.h"
#include "garageDoor.h"
#include "stereo.h"
#include "ceilingFan.h"

#include "securityAlarm.h"
#include "washingMachine.h"
#include "deviceCommands.h"

#include "macro.h"



int main(int argc, const char * argv[]) {
	simpleRemoteControl* src = new simpleRemoteControl(new deviceCommand<light>(new light("living room"), DEVICEON));
	std::cout << *src << "\n";

	src->setCommand(new deviceCommand<garageDoor>(new garageDoor("main house"), DEVICEON));
	std::cout << *src << "\n";
	std::cout << "pressing button: ";
	src->buttonPressed();
	std::cout << std::endl << std::endl;

	ceilingFan* cf = new ceilingFan("BR1");
	ceilingFan* cf2 = new ceilingFan("den", false, MEDIUM);

	cf2->setHigh();
	std::cout << *cf << " " << *cf2 << "\n";

	notSoSimpleRemoteControl* nssrc = new notSoSimpleRemoteControl(new deviceCommand<ceilingFan>(new ceilingFan("kitchen"), DEVICEON));
	std::cout << *nssrc << "\n";
	std::cout << "pressing button: ";
	nssrc->buttonPressed();
	std::cout << std::endl << "undoing button: ";
	nssrc->undoButtonPressed();
	std::cout << std::endl << std::endl;

	securityAlarm* sa = new securityAlarm("whole house");
	std::cout << *sa << "\n";

	washingMachine* wm = new washingMachine("laundry room");
	std::cout << *wm << "\n";

	remoteControl* rc = new remoteControl();
	std::cout << *rc << "\n";



	deviceCommand<light>* lightOn = new deviceCommand<light>(new light("kitchen"), DEVICEON);
	deviceCommand<garageDoor>* gdOpen = new deviceCommand<garageDoor>(new garageDoor("garage"), DEVICEON);
	deviceCommand<stereo>* stereoOn = new deviceCommand<stereo>(new stereo("living room"), DEVICEON);



	rc->setCommand(0, new deviceCommand<light>(new light("kitchen"), DEVICEON));
	rc->setCommand(1, new deviceCommand<light>(new light("MasterBedRoom"), DEVICEON));
	rc->setCommand(2, new deviceCommand<garageDoor>(new garageDoor("main house"), DEVICEON));
	rc->setCommand(3, new deviceCommand<stereo>(new stereo("game room"), DEVICEON));
	rc->setCommand(4, new deviceCommand<ceilingFan>(new ceilingFan("kitchen"), DEVICEON));
	rc->setCommand(5, new deviceCommand<washingMachine>(new washingMachine("laundry room"), DEVICEON));
	rc->setCommand(6, new deviceCommand<securityAlarm>(new securityAlarm("whole house"), DEVICEON));
	std::cout << *rc << "\n\n";

	rc->executeCommands({ 1, 3, 2, 5, 4 });
	rc->undoCommands({ 1, 3, 2, 5, 4 });




	macroCommand mc({ lightOn, gdOpen, stereoOn });
	std::cout << mc << std::endl << std::endl;
	mc.execute();
	rc->setCommand(6, &mc);
	rc->buttonPressed(6);

	rc->undoLastCommand();
	rc->redoLastCommand();




	std::cout << "\npushing rc's macroc command button...\n";
	

	std::cout << "\n\t\t...done.\n";
	return 0;
}
