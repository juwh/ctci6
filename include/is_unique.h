#ifndef IS_UNIQUE_H // include guard
#define IS_UNIQUE_H

#include <algorithm>
#include <bitset>
#include <string>
#include <vector>

#pragma once

bool IsUniqueChars(const std::string &str);
bool IsUniqueCharsBit(const std::string &str);
bool IsUniqueCharsManual(const std::string &str);
bool IsUniqueCharsSort(std::string str);

#endif