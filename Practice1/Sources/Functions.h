#pragma once

#include <qcolor.h>

int clamp(int value, int max, int min);

//���������� �����, ������������ ����������� std::sort
bool compareColors(const QColor& abc, const QColor& b);