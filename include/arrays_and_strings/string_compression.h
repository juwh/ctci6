#ifndef STRING_COMPRESSION_H_
#define STRING_COMPRESSION_H_

#include <sstream>
#include <string>

std::string CompressBad(std::string str);
std::string Compress(std::string str);
int CountCompression(std::string str);
std::string CompressAdvanced(std::string str);

#endif // STRING_COMPRESSION_H_