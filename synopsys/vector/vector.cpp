#include <iostream>
#include <stdexcept>

template <typename T>
class Vector
{
	private:

		T *data;
		size_t size;
		size_t capacity;

	public:

		Vector()
		{
			size = 0;
			capacity = 1;
			data = new T[capacity];
		}

		Vector(const Vector& other)
		{
			size = other.size;
			capacity = other.capacity;
			data = new T[capacity];
			for(size_t i = 0; i < size; i++)
			{
				data[i] = other.data[i];
			}
		}

		~Vector()
		{
			delete[] data;
			data = nullptr;
		}

		void pushback(T value)
		{
			if(size == capacity)
			{
				size_t new_capacity = capacity * 2;
				T *new_data = new T[new_capacity];
				
				for(size_t i = 0; i < size; i++){
						new_data[i] = data[i];
				}

				delete[] data;
				data = new_data;
				capacity = new_capacity;
			}
			
			data[size++] = value;
		}

		void popback()
		{
			if(size > 0) size--;
			else
				std::cout <<"The vector is empty.";
		}

        void print_vector() const
        {
            for(size_t i = 0; i < size; i++)
            {
                std::cout << data[i];
                if(i == size - 1) std::cout << ". \n";
                else std::cout << ", ";
            }
        }


		T& operator[](size_t index)
		{
			if(index >= size) throw std::out_of_range("Index must be smaller than size.");
			return data[index];
		}


		Vector& operator=(const Vector& other)
		{
				if(this == &other) return *this;

				size = other.size;
				capacity = other.capacity;
				delete[] data;

				data = new T[capacity];
				for(size_t i = 0; i < size; i++)
				{
					data[i] = other.data[i];
				}

				return *this;
		}

		
		Vector operator+(const Vector& other) const 
		{
			Vector result;
			if(this -> size != other.size)
			{
				std::cout<<"Vectors must have the same size.\n";
				return result;
			}

			for(size_t i = 0; i < this -> size; i++)
			{
				result.pushback(this->data[i] + other.data[i]);
			}

			return result;
		}


		Vector operator-(const Vector& other) const 
		{
			Vector result;
			if(this -> size != other.size)
			{
				std::cout<<"Vectors must have the same size.\n";
				return result;
			}

			for(size_t i = 0; i < size; i++)
			{
				result.pushback(this->data[i]-other.data[i]);
			}

			return result;
		}


		Vector operator*(const Vector& other) const 
		{
			Vector result;
			if(this -> size != other.size)
			{
				std::cout<<"Vectors must have the same size.\n";
				return result;
			}

			for(size_t i = 0; i < size; i++)
			{
				result.pushback(this->data[i] * other.data[i]);
			}

			return result;
		}

		Vector operator/(const Vector& other) const 
		{
			Vector result;
			if(this -> size != other.size)
			{
				std::cout<<"Vectors must have the same size!!!\n";
				return result;
			}

			for(size_t i = 0; i < size; i++)
			{
				if(other.data[i] != 0) result.pushback(this->data[i]/other.data[i]);
				else std::cout<<"The denominator (" << i << "th element of the 2nd vector) must not be 0. \n";
			}

			return result;
		}



		size_t size_of_vector() const
		{
			return size;
		}

		size_t capacity_of_vector() const
		{
			return capacity;
		}

};

int main()
{
	Vector<int> v1;
	v1.pushback(10);
	v1.pushback(20);
	v1.pushback(30);
    v1.pushback(40);
	v1.pushback(50);
    std::cout << "v1 values: \n";
    v1.print_vector();
    v1.popback();
    std::cout << "v1 values after popback: \n";
    v1.print_vector();

	Vector<int> v2;	
	v2.pushback(5);
	v2.pushback(10);
	v2.pushback(15);
    v2.pushback(20);
	v2.pushback(25);
    std::cout << "v2 values: \n";
    v2.print_vector();
    v2.popback();
    std::cout << "v2 values after popback: \n";
    v2.print_vector();

	Vector<int> v3 = v1 + v2;
	Vector<int> v4 = v1 - v2;
	Vector<int> v5 = v1 * v2;	
	Vector<int> v6 = v1 / v2;

	std::cout<< "Results of + - * / operations: \n";
    v3.print_vector();
    v4.print_vector();
    v5.print_vector();
    v6.print_vector();

    return 0;
}
