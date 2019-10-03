// Copyright 2019 Oudin Rémi

#include "sattools/Logging.h"
#include "sattools/RestartPolicyLuby.h"

namespace sat {
    LubyRestartPolicy::LubyRestartPolicy() :
        RestartPolicy(),
        _rank(1),
        luby({1,1})
         {
    }

    LubyRestartPolicy::~LubyRestartPolicy() {}

    bool LubyRestartPolicy::shouldRestart(unsigned int progress) {
        if (progress == luby._currentLuby) {
            computeNextLuby();
            return true;
        }
        return false;
    }

    void LubyRestartPolicy::computeNextLuby() {
        ((luby._currentHelper & - luby._currentHelper) == luby._currentLuby) ?  luby = {luby._currentHelper +1, 1} :
            luby = {luby._currentHelper, 2 * luby._currentLuby};
    }
}
