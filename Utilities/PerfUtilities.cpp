/**============================================================================
Name        : PerfUtilities.h
Created on  : 21.11.2023
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : Utilities.h
============================================================================**/

#include "PerfUtilities.h"
#include <iostream>
#include <iomanip>


PerfUtilities::ScopedTimer::~ScopedTimer()
{
    const std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> time_span = duration_cast<std::chrono::duration<double>>(end - start);

    std::cout << std::left << std::setw(24) << benchmarkName << ":  ";
    std::cout << time_span.count() << " seconds.\n";
}