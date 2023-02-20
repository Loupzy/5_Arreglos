#pragma once
#include <cstdlib>

//arreglo de floats
template <typename T>
class ArregloTemplate
{
private:
    //numero de elementos del array
    size_t m_count = 0;

    //apuntador del comienzo [0] del arreglo
    T* data;

public:
    size_t count()
    {
        return m_count;
    }

    // constructor
    ArregloTemplate(size_t _size)
    {
        data = (T*)malloc(_size * sizeof(T));
        m_count = _size;

        // clear the garbage
        memset(data, 0, m_count * sizeof(T));
        print();
    }

    //setter de posicion en el arreglo
    void setval(size_t index, T value)
    {
        if (index >= m_count)
        {
            std::cout << "Error: index >= array count \n";
            return;
        }
        else
        {
            *(data + index) = value;
        }
    }
    //redimensionar arreglo
    T getval(size_t index)
    {
        if (index >= m_count)
        {
            std::cout << "Error: index >= array count \n";
            return T();
        }
        else
        {
            return *(data + index);
        }
    }


    void print()
    {
        for (int i = 0; i < m_count; i++)
        {
            printf("[%i] = %d \n", i, getval(i));
        }
    }

    // resize the array
    bool SetSize(size_t newSize)
    {
        //crear nuevo espacio de memoria
        void* buffer = malloc(newSize * sizeof(T));

        if (buffer != NULL)
        {
            memcpy(buffer, data, newSize * sizeof(T));

            data = (T*)buffer;
            m_count = newSize;
            return 1;
        }
        else
        {
            std::cout << "ERROR: unable to resize array \n";
            return 0;
        }
    }
};




