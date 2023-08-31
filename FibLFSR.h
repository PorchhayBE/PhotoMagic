/**
 * FibLFSR.h - LFSR header file
 * 
 * Date: 01/30/2022
 * 
 * Reuse From ps1a
 * 
 * Created by: Porchhay Be
 */

#pragma once
#include <string>

class FibLFSR {
 public:
    FibLFSR(std::string seed);  // constructor to create LFSR with the given initial seed
    int step();  // simulate one step and return the // new bit as 0 or 1
    int generate(int k);  // simulate k steps and return // k-bit integer
    int getLength();
    std::string getBitSeed();
 private:
    std::string bitSeed;
    int length;
};


