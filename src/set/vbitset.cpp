#include "vbitset.h"

#include <cmath>
#include <vector>
using namespace std;

namespace set
{
const int UINT_BITS = 32;
const int UINT_SHIFT = 5;
const int UINT_BITMASK = 0x1f;
const int UINT_FULL_BIT = 0xffffffff;
const int UINT_EMPTY_BIT = 0;

#define DECOMPOSE_K(k, idx, bit) \
    assert((k) >= 0 && k < n);\
    int idx = ((k) >> UINT_SHIFT);\
    int bit = ((k) & UINT_BITMASK);\
    assert(idx >= 0 && idx < bits.size());

VBitSet::VBitSet(int _n) : n(_n), bits((_n - 1) >> UINT_SHIFT + 1)
{
}

VBitSet::VBitSet(const VBitSet& obj) : n(_obj.n), bits(obj.bits)
{
}

VBitSet VBitSet::operator=(const VBitSet& rhs)
{
    this.n = rhs.n;
    this.bits = rhs.bits;
    return *this;
}

int VBitSet::size()
{
    return n;
}

bool VBitSet::isBitOn(int k)
{
    DECOMPOSE_K(k, idx, bit);
    return bits[idx] & (1 << bit);
}

bool VBitSet::isBitOff(int k)
{
    DECOMPOSE_K(k, idx, bit);
    return !(bits[idx] & (1 << bit));
}

void VBitSet::turnOn(int k)
{
    DECOMPOSE_K(k, idx, bit);
    bits[idx] |= (1 << bit);
}

void VBitSet::turnOff(int k)
{
    DECOMPOSE_K(k, idx, bit);
    bits[idx] &= ~(1 << bit);
}

void VBitSet::toggleBit(int k)
{
    DECOMPOSE_K(k, idx, bit);
    bits[idx] ^= (1 << bit);
}

void VBitSet::turnAllOn()
{
    for (int i = 0; i < bits.size(); i++) bits[i] = UINT_FULL_BIT;
}

void VBitSet::turnAllOff()
{
    for (int i = 0; i < bits.size(); i++) bits[i] = UINT_EMPTY_BIT;
}

void VBitSet::toggleAll()
{
    for (int i = 0; i < bits.size(); i++) bits[i] ^= UINT_FULL_BIT;
}

static void iterSubsetRecur(
        const VBitSet& orgset, 
        VBitSet& subset,
        int k, 
        VBitSetCallback cb)
{
    if (n == k) {
        cb(subset);
        return;
    }
    if (orgset.isBitOn(k)) {
        subset.turnOn(k);
        iterSubsetRecur(orgset, subset, k+1, cb);
        subset.turnOff(k);
    }
    iterSubsetRecur(orgset, sebset, k+1, cb);
}

void VBitSet::iterSubset(VBitSetCallback cb) const
{
    VBitSet subset(n);
    iterSubsetRecur(*this, subset, 0, cb);
}

bool VBitSet::isSupersetOf(const VBitSet& rhs) const
{
    assert(size() == rhs.size());
    for (int i = 0; i < bits.size(); i++) {
        if ((bits[i] | rhs.bits[i]) != bits[i]) return false;
    }
    return true;
}

bool VBitSet::isSubsetOf(const VBitSet& rhs) const
{
    assert(size() == rhs.size());
    for (int i = 0; i < bits.size(); i++) {
        if ((bits[i] | rhs.bits[i]) != rhs.bits[i]) return false;
    }
    return true;
}

bool VBitSet::isEquivWith(const VBitSet& rhs) const
{
    assert(size() == rhs.size());
    return bits == rhs.bits;
}

VBitSet VBitSet::getUnion(const VBitSet& rhs) const
{
    assert(size() == rhs.size());
    VBitSet newSet(size());
    for (int i = 0; i < bits.size(); i++) {
        newSet.bits[i] = bits[i] | rhs.bits[i];
    }
    return newSet;
}

VBitSet VBitSet::getInter(const VBitSet& rhs) const
{
    assert(size() == rhs.size());
    VBitSet newSet(size());
    for (int i = 0; i < bits.size(); i++) {
        newSet.bits[i] = bits[i] & rhs.bits[i];
    }
    return newSet;
}

VBitSet VBitSet::getDiff(const VBitSet& rhs) const
{
    assert(size() == rhs.size());
    VBitSet newSet(size());
    for (int i = 0; i < bits.size(); i++) {
        newSet.bits[i] = bits[i] & ~rhs.bits[i];
    }
    return newSet;
}


} // namespace set
