#pragma once
#include <cstdlib>

class ArregloFloat
{
private:
	//numero de elementos del array
	size_t m_count = 0;

	//apuntador del comienzo [0] del arreglo
	float* data;

public:
	size_t count()
	{
		return m_count;
	}

	//ctor
	ArregloFloat(size_t _size)
	{
		data = (float*)malloc(_size);   //void*
		m_count = _size;

		//limpiar la basura
		//memset necesita el tamano en bytes, entonces 
		//multiplicar por 4 (un float usa 4 bytes)
		memset(data, 0, m_count * 4);
		print();
	}

	//setter de posicion en el arreglo
	void setval(size_t index, float value)
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

	float getval(size_t index)
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
			//std::cout << "[" << i << "] = " << getval(i) << "\n";
			printf("[%i] = %E \n", i, getval(i));
		}
	}

	//redimensionar arreglo
	bool SetSize(size_t newSize)
	{
		//crear nuevo espacio de memoria
		void* buffer = malloc(newSize);

		if (buffer != NULL)
		{
			memcpy(buffer, data, newSize * 4);

			data = (float*)buffer;
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
