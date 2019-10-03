// Copyright 2017 Hakan Metin - LIP6

#ifndef SATTOOLS_LUBYRESTARTPOLICY_H_
#define SATTOOLS_LUBYRESTARTPOLICY_H_

#include "sattools/RestartPolicy.h"

struct Luby {
    unsigned int _currentHelper;
    unsigned int _currentLuby;
};

namespace sat {
    class LubyRestartPolicy : public RestartPolicy {
        public:
            explicit LubyRestartPolicy();
            virtual ~LubyRestartPolicy();
            virtual bool shouldRestart(unsigned int progress);

        private:
            unsigned int _rank;
            struct Luby luby;

           void computeNextLuby();
    };
}
#endif

