// Copyright 2019 Oudin Rémi -- LIP6

#ifndef SATTOOLS_RESTARTPOLICY_H_
#define SATTOOLS_RESTARTPOLICY_H_

namespace sat {

    class RestartPolicy {
        public:
            explicit RestartPolicy() {}
            virtual ~RestartPolicy() {}
            virtual bool shouldRestart(unsigned int progress) = 0;
    };
}

#endif // SATTOOLS_RESTARTPOLICY_H_


