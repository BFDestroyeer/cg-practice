#include "Data.h"

Data::Data()
{
    min = 0;
    max = 0;
    width = 0;
    height = 0;
    depth = 0;
    density = nullptr;
}

Data::Data(const std::string& path)
{
    min = 0;
    max = 0;
    width = 0;
    height = 0;
    depth = 0;
    density = nullptr;
    this->load(path);
}

short Data::getMin()
{
    return min;
}

short Data::getMax()
{
    return max;
}

int Data::getWidth()
{
    return width;
}

int Data::getHeight()
{
    return height;
}

int Data::getDepth()
{
    return depth;
}

int Data::load(const std::string& path)
{
    std::ifstream file;
    file.open(path, std::ios::binary);
    if (!file.is_open()) return 1;

    void* buffer[4];
    file.read((char*) buffer, sizeof(int));
    width = *((int*)buffer);
    file.read((char*)buffer, sizeof(int));
    height = *((int*)buffer);
    file.read((char*)buffer, sizeof(int));
    depth = *((int*)buffer);
    file.read((char*)buffer, 3 * sizeof(float));

    size_t size = (size_t)width * (size_t)height * (size_t) depth;
    if (density != nullptr) delete[] density;
    density = new short[size];
    max = 0; min = INT16_MAX;
    for (size_t i = 0; i < size; i++)
    {
        file.read((char*)buffer, sizeof(short));
        density[i] = *((short*)buffer);
        if (density[i] < min) min = density[i];
        if (density[i] > max) max = density[i];
    }
    return 0;
}

char Data::operator[](size_t id) const
{
    if (id < (size_t)width * (size_t)height * (size_t)depth)
    {
        return density[id];
    }
    else
    {
        throw "WRONG INDEX";
    }
}