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

int Data::load(const std::string& path, char direction)
{
    std::ifstream file;
    file.open(path, std::ios::binary);
    if (!file.is_open()) return 1;
    if (direction == 'z')
    {
        file.read((char*)&width, sizeof(width));
        file.read((char*)&height, sizeof(height));
        file.read((char*)&depth, sizeof(depth));
        file.read((char*)&x, sizeof(x));
        file.read((char*)&y, sizeof(y));
        file.read((char*)&z, sizeof(z));

        int size = width * height * depth;
        if (density != nullptr) delete[] density;
        density = new short[size];
        max = 0; min = INT16_MAX;
        for (int i = 0; i < size; i++)
        {
            file.read((char*)(density + i), sizeof(short));
            if (density[i] < min)
            {
                min = density[i];
            }
            if (density[i] > max) 
            {
                max = density[i];
            }
        }
        file.close();
        return 0;
    }
    else if (direction == 'x')
    {
        void* buffer[4];
        file.read((char*)buffer, sizeof(int));
        width = *((int*)buffer);
        file.read((char*)buffer, sizeof(int));
        height = *((int*)buffer);
        file.read((char*)buffer, sizeof(int));
        depth = *((int*)buffer);
        file.read((char*)buffer, 3 * sizeof(float));

        size_t size = (size_t)width * (size_t)height * (size_t)depth;
        if (density != nullptr) delete[] density;
        density = new short[size];
        max = 0; min = INT16_MAX;
        for (size_t  z = 0; z < depth; z++)
        {
            for (size_t y = 0; y < height; y++)
            {
                for (size_t x = 0; x < width; x++)
                {
                    file.read((char*)buffer, sizeof(short));
                    density[y * depth * width + z * width + x] = *((short*)buffer);
                    if (density[y * depth * width + z * width + x] < min)min = *((short*)buffer);
                    if (density[y * depth * width + z * width + x] > max) max = *((short*)buffer);
                }
            }
        }
        int temp = height;
        height = depth;
        depth = temp;
        return 0;
    }
    else
    {
        void* buffer[4];
        file.read((char*)buffer, sizeof(int));
        width = *((int*)buffer);
        file.read((char*)buffer, sizeof(int));
        height = *((int*)buffer);
        file.read((char*)buffer, sizeof(int));
        depth = *((int*)buffer);
        file.read((char*)buffer, 3 * sizeof(float));

        size_t size = (size_t)width * (size_t)height * (size_t)depth;
        if (density != nullptr) delete[] density;
        density = new short[size];
        max = 0; min = INT16_MAX;
        for (size_t z = 0; z < depth; z++)
        {
            for (size_t y = 0; y < height; y++)
            {
                for (size_t x = 0; x < width; x++)
                {
                    file.read((char*)buffer, sizeof(short));
                    density[x * depth * height + z * height + y] = *((short*)buffer);
                    if (density[x * depth * height + z * height + y] < min) min = *((short*)buffer);
                    if (density[x * depth * height + z * height + y] > max) max = *((short*)buffer);
                }
            }
        }
        int temp = height;
        height = depth;
        depth = width;
        width = temp;
        return 0;
    }
}

float Data::getX()
{
    return x;
}

float Data::getY()
{
    return y;
}

float Data::getZ()
{
    return z;
}

short Data::operator[](size_t id) const
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