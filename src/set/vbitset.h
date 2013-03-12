#ifndef ILYOAN_ALGORITHMS_SET_VBITSET_H
#define ILYOAN_ALGORITHMS_SET_VBITSET_H

#include "bitset.h"

#include <vector>
using namespace std;

namespace set
{

typedef void(*VBitSetCallback)(const VBitSet& set);

class VBitSet : public BitSet<VBitSet>
{
public:
    VBitSet(int n);
    VBitSet(const VBitSet& obj);
    VBitSet operator=(const VBitSet& rhs);

    // Return size of bit
    int size();

    // Return true if k-th bit is on
    bool isBitOn(int k);
    // Return true if k-th bit is off
    bool isBitOff(int k);

    // Turn k-th bit on
    void turnOn(int k);
    // Turn k-th bit off
    void turnOff(int k);
    // Toggle k-th bit
    void toggleBit(int k);

    // Turn all bits on
    void turnAllOn();
    // Turn all bits off
    void turnAllOff();
    // Toggle all bits
    void toggleAll();

    // Iterate all subset of current set.
    void iterSubset(VBitSetCallback cb) const;

    // Return true if the set is a superset of another
    bool isSupersetOf(const VBitSet& rhs) const;
    // Return true if the set is a subset of another
    bool isSubsetOf(const VBitSet& rhs) const;
    // Return true if the set is equivalent with another
    bool isEquivWith(const VBitSet& rhs) const;

    // Union
    VBitSet getUnion(const VBitSet& rhs) const;
    // Intersection
    VBitSet getInter(const VBitSet& rhs) const;
    // Difference
    VBitSet getDiff(const VBitSet& rhs) const;
    // Symmetric difference
    VBitSet getSymDiff(const VBitSet& rhs) const;

private:
    int n;
    vector<unsigned int> bits;
};

} // namespace set

#endif
