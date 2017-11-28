//
//  garageDoor.h
//  command_pattern
//
//

#ifndef garageDoor_h
#define garageDoor_h

#include "onOffDevice.h"


class garageDoor : public onOffDevice {
public:
    garageDoor(const std::string& name="", bool isOn=false)
    : onOffDevice(name, "garageDoor", "open", "closed", isOn) {}

    friend std::ostream& operator<<(std::ostream& os, const garageDoor& gd) {
        return os << dynamic_cast<const onOffDevice&>(gd);
    }                                                          
};

#endif /* garageDoor_h */
