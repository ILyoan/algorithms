#ifndef ILYOAN_ALGORITHMS_SET_BITSET_H
#define ILYOAN_ALGORITHMS_SET_BITSET_H

namespace set
{

typedef<typename T>
class BitSet<T>
{
public:
    typedef void(*BitSetCallback)(const T& set);

    // Return size of bit
    virtual int size() = 0;
    
    // Return true if k-th bit is on
    virtual bool isBitOn(int k) = 0;
    // Return true if k-th bit is off
    virtual bool isBitOff(int k) = 0;

    // Turn k-th bit on
    virtual void turnOn(int k) = 0;
    // Turn k-th bit off
    virtual void turnOff(int k) = 0;
    // Toggle k-th bit
    virtual void toggleBit(int k) = 0;

    // Turn all bits on
    virtual void turnAllOn() = 0;
    // Turn all bits off
    virtual void turnAllOff() = 0;
    // Toggle all bits
    virtual void toggleAll() = 0;

    // Iterate all subset of current set.
    virtual void iterSubset(BitSetCallback cb) const = 0;
    
    // Union
    virtual T getUnion(const T& rhs) const = 0;
    // Intersection
    virtual T getInter(const T& rhs) const = 0;
    // Difference
    virtual T getDiff(const T& rhs) const = 0;
    // Symmetric difference
    virtual T getSymDiff(const T& rhs) const = 0;
};

} // namespace set

#endif
