//
//  securityAlarm.h
//  command_pattern
//
//  Created by William McCarthy on 11/14/17.
//  Copyright © 2017 William McCarthy. All rights reserved.
//

#ifndef securityAlarm_h
#define securityAlarm_h

#include "onOffDevice.h"


class securityAlarm : public onOffDevice {
public:
    securityAlarm(const std::string& name="", bool isOn=false)
    : onOffDevice(name, "securityAlarm", "armed", "disarmed", isOn) {}
    
    friend std::ostream& operator<<(std::ostream& os, const securityAlarm& sa) {
        return os << dynamic_cast<const onOffDevice&>(sa);
    }
};

#endif /* securityAlarm_h */
