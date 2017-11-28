//
//  washingMachine.h
//  command_pattern
//
//  Created by William McCarthy on 11/14/17.
//  Copyright © 2017 William McCarthy. All rights reserved.
//

#ifndef washingMachine_h
#define washingMachine_h

#include "onOffDevice.h"


class washingMachine : public onOffDevice {
public:
    washingMachine(const std::string& name="", bool isOn=false)
    : onOffDevice(name, "washingMachine", "washing", "off", isOn) {}
    
    friend std::ostream& operator<<(std::ostream& os, const washingMachine& wm) {
        return os << dynamic_cast<const onOffDevice&>(wm);
    }
};



#endif /* washingMachine_h */
