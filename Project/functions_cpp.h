#pragma once

#include <string>

constexpr int populationSize = 200;

const std::string target = "To be or not to be";
const std::string genes = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";

int randomNum(int start, int end);

char mutatedGene();

std::string createGnome();
