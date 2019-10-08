// Copyright 2017 Hakan Metin - LIP6

#ifndef SATTOOLS_PROPAGATOR_H_
#define SATTOOLS_PROPAGATOR_H_

#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <utility>

#include "sattools/Literal.h"
#include "sattools/Clause.h"
#include "sattools/Trail.h"
#include "sattools/IntTypeIndexedVector.h"

namespace sat {

// Forward declaration
class Trail;
class Clause;

class Propagator {
 public:
    Propagator();
    ~Propagator();

    void resize(unsigned int num_vars);

    bool addClause(Clause *clause, Trail *trail);
    bool addClause(const std::vector<Literal>& literals, Trail *trail);
    bool addLearntClause(const std::vector<Literal>& literals, Trail *trail);
    // bool addSBPClause(const std::vector<Literal>& literals, Trail *trail);

    bool propagate(Trail *trail, Clause **conflict);
    void untrail(unsigned int trail_index) {
        _propagation_trail_index =
            std::min(_propagation_trail_index, trail_index);
    }

    void attachClause(Clause *clause, Trail *trail);
    void detachClause(Clause *clause);

    Clause *conflictClause() const { return _conflict; }
    Clause *reasonClause(unsigned int index) const { return _reasons[index]; }

    void setPropagatorId(unsigned int id) { _id = id; }

    std::string debugString() const;

 private:
    int _id;
    unsigned int _propagation_trail_index;
    Clause *_conflict;

    struct Watch {
        Watch() {}
        Watch(Clause *c, Literal b) : clause(c), blocking_literal(b) {}
        Clause *clause;
        Literal blocking_literal;
    };

    ITIVector<LiteralIndex, std::vector<Watch>> _watchers;
    std::vector<Clause*> _reasons;

    void attachOnFalse(Literal literal, Literal blocking, Clause *clause);
    bool propagateOnFalse(Literal false_literal, Trail *trail,
                          Clause **conflict);
};


}  // namespace sat


#endif  // SATTOOLS_PROPAGATOR_H_
/*
 * Local Variables:
 * mode: c++
 * indent-tabs-mode: nil
 * End:
 */
