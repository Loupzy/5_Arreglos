#pragma once
#include <cstdlib>

//arreglo de floats
class Arreglo
{
private:
	//numero de elementos del array
	size_t m_count=0;

	//apuntador del comienzo [0] del arreglo
	int* data; 

public:
	size_t count()
	{
		return m_count;
	}

	//ctor
    Arreglo(size_t _size)
    {
        data = (int*)malloc(_size * sizeof(int));
        m_count = _size;

        //limpiar la basura
        memset(data, 0, m_count * sizeof(int));
        print();
    }

    //setter de posicion en el arreglo
    void setval(size_t index, int value)
    {
        if (index > m_count)
        {
            std::cout << "Error: index > arreglo count \n";
            return;
        }
        else
        {
            *(data + index) = value;
        }
    }

    int getval(size_t index)
    {
        if (index > m_count)
        {
            std::cout << "Error: index > arreglo count \n";
            return 0;
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

    //redimensionar arreglo
    bool SetSize(size_t newSize)
    {
        //crear nuevo espacio de memoria
        void* buffer = malloc(newSize * sizeof(int));

        if (buffer != NULL)
        {
            memcpy(buffer, data, newSize * sizeof(int));

            data = (int*)buffer;
            m_count = newSize;
            return 1;
        }
        else
        {
            std::cout << "ERROR no se puede redimensionar arreglo \n";
            return 0;
        }
    }


};

