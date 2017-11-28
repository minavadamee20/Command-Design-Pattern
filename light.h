//
//  light.h
//  command_pattern
//
//

#ifndef light_h
#define light_h

#include "onOffDevice.h"


class light : public onOffDevice {
public:
    light(const std::string& name="", bool isOn=false)
    : onOffDevice(name, "light", "on", "off", isOn) {}
    
    friend std::ostream& operator<<(std::ostream& os, const light& li) {
        return os << dynamic_cast<const onOffDevice&>(li);
    }
};

#endif /* light_h */
