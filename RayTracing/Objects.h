#pragma once

#include <qvector3d.h>

struct Sphere
{
    QVector3D position;
    float radius;
    QVector3D color;
    int material_idx;
};