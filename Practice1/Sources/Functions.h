#pragma once

#include <qcolor.h>

int clamp(int value, int max, int min);

//Сравнивает цвета, соответсвует требованиям std::sort
bool compareColors(const QColor& abc, const QColor& b);