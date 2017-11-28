//
//  stereo.h
//  command_pattern
//
//  Created by William McCarthy on 11/12/17.
//  Copyright © 2017 William McCarthy. All rights reserved.
//

#ifndef stereo_h
#define stereo_h

enum MODE { CD, DVD, RADIO };

class stereo : public onOffDevice {
public:
    stereo(const std::string& name ="", bool isOn=false, MODE mode=CD, size_t volume = 5)
    : onOffDevice(name, "stereo", "playing", "off", isOn), mode_(mode), volume_(volume) {}
    
    void setCD()    { mode_ = CD; }
    void setDVD()   { mode_ = DVD; }
    void setRadio() { mode_ = RADIO; }
    
    MODE mode() const { return mode_; }
    
    void on()   {  setCD();     setVolume(11);  onOffDevice::on();  }       // overrides onOffDevice's on()
    void off()  {  setRadio();  setVolume(2);   onOffDevice::off(); }       // ditto...
    
    std::string modeToString() const {      // overrides superclass modeToString
        std::stringstream ss;
        ss << "(";
        if (!isOn()) { ss << offMeans(); }
        else {
            switch(mode_) {
                case CD:    ss << "CD";           break;
                case DVD:   ss << "DVD";          break;
                case RADIO: ss << "RADIO";        break;
                default:    ss << "unknown mode"; break;
            }
        }
        ss << ")";
        return ss.str();
    }
    size_t volume() const { return volume_; }
    void setVolume(size_t volume) { volume_ = volume; }

    friend std::ostream& operator<<(std::ostream& os, const stereo& st) {
        return os << dynamic_cast<const onOffDevice&>(st) << ",volume=" << st.volume_ << ")";
    }
private:
    bool isOn_;
    MODE mode_;
    size_t volume_;
};


#endif /* stereo_h */
