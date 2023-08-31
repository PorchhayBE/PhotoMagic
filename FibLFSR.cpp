/**
 * FibLFSR.cpp - LFSR implemenation
 * 
 * Date: 01/30/2022
 * 
 * Reuse From ps1a
 * 
 * Created by: Porchhay Be
 */

#include "FibLFSR.h"
#include <string>
#include <sstream>
#include <iostream>


FibLFSR::FibLFSR(std::string seed) {
    bitSeed = seed;
    length = bitSeed.length();
}

int FibLFSR::getLength()
{
    return length;
}

std::string FibLFSR::getBitSeed()
{
    return bitSeed;
}

int FibLFSR::step() {
    int bit = 0;
    // Position of Begin, End, and Tap
    int begin = length-16;
    int end = length-1;
    int tap13 = length-14;
    int tap12 = length-13;
    int tap10 = length-11;

    // XOR gate
    // if XOR begin, tap13, tap12, tap10 are true, then bit = 1, otherwise, bit = 0;
    if ((bitSeed[begin]^bitSeed[tap13]^bitSeed[tap12]^bitSeed[tap10])) {
        bit = 1;
    }

    // convert bit to char
    std::string bits;
    std::stringstream ss1;
    ss1 << bit;
    ss1 >> bits;

    bitSeed = bitSeed.substr(begin+1, end) + bits;  // make new string by shifting

    return bit;
}

int FibLFSR::generate(int k) {
    int num = 0;
    for (int i = 0; i < k; i++) {
        num = 2*num+step();
    }
    return num;
}
