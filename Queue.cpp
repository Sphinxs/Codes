
#include <iostream>

using namespace std;

template <class tp>
class Queue
{
  private:
    int size;

    tp *vector;

    template <class t>
    friend std::ostream &operator<<(std::ostream &, const Queue<t> &);

  public:
    Queue()
    {
        this->size = 0;

        this->vector = new tp[this->size];
    }

    Queue(const int size)
    {
        this->size = size;

        this->vector = new tp[this->size];
    }

    Queue(const Queue<tp> &obj)
    {
        if (this->size > 0)
            delete[] vector;

        this->size = obj.size;

        this->vector = new tp[this->size];

        for (int counter = 0; counter < this->size; counter++)
            this->vector[counter] = obj.vector[counter];
    }

    ~Queue(void)
    {
        delete[] this->vector;
    }

    Queue<tp> &operator=(const Queue<tp> &obj)
    {
        if (&obj != this)
        {
            if (obj.size != this->size)
            {
                this->size = obj.size;

                delete[] this->vector;

                this->vector = new tp[this->size];
            }

            for (int counter = 0; counter < this->size; counter++)
                this->vector[counter] = obj.vector[counter];
        }
    }

    tp &operator[](int indice)
    {
        if (indice < 0 || indice > this->size)
            exit(1);

        return this->vector[indice];
    }

    int getSize(void)
    {
        return this->size;
    }

    void enqueue(const tp item)
    {

        tp *cache = new tp[this->size + 1];

        for (int counter = 0; counter < this->size; counter++)
            cache[counter] = this->vector[counter];

        cache[this->size++] = item;

        delete[] this->vector;

        vector = cache;
    }

    tp dequeue(void)
    {
        tp value = this->vector[0];

        this->size--;

        tp *cache = new tp[this->size];

        for (int counter = 0; counter < this->size; counter++)
            cache[counter] = this->vector[counter];

        delete[] this->vector;

        this->vector = cache;

        return value;
    }

    void show(void)
    {
        for (int counter = 0; counter <= this->size - 1; counter++)
            std::cout << "\n"
                      << this->vector[counter] << "\n";
    }
};

template <class t>
std::ostream &operator<<(std::ostream &output, const Queue<t> &obj)
{
    output << obj.vector[0];

    return output;
}

int main()
{
    return 0;
}