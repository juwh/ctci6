#ifndef ONE_AWAY_H_
#define ONE_AWAY_H_

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

bool OneEditReplace(std::string s1, std::string s2);
bool OneEditInsert(std::string s1, std::string s2);
bool OneEditAway(std::string first, std::string second);
bool OneEditAwayMerged(std::string first, std::string second);
void Test(const std::string& a, const std::string& b, bool expected);

#endif // ONE_AWAY_H_