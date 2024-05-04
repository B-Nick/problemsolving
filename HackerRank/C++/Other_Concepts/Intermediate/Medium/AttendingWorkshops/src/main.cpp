#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

//#define MY_INIT

struct Workshop final
{
    int start_time {};
    int duration {};
    int finish_time {};

#ifdef MY_INIT
    bool operator< (const Workshop &other) const
    {
        return start_time == other.start_time ?
                   duration < other.duration : start_time < other.start_time;
    }
#else   // MY_INIT
    bool operator> (const Workshop &other) const
    {
        return finish_time > other.finish_time;
    }
#endif   // MY_INIT
};

#if !defined (MY_INIT)
bool greaterST(const Workshop &a, const Workshop &b)
{
    return a.start_time > b.start_time;
}
#endif  // MY_INIT

    struct Available_Workshops final
    {
        Available_Workshops(const int n_)
            : n {n_}, workshops {new Workshop[n_]} {}
        Available_Workshops(const Available_Workshops &other)
            : n {other.n}, workshops {new Workshop[other.n]}
        {
            for (int i = 0; i < n; ++i)
            {
                workshops[i] = other.workshops[i];
            }
        }
        Available_Workshops(Available_Workshops &&other) = default;

        ~Available_Workshops() {delete[] workshops;}

        Available_Workshops &operator= (const Available_Workshops &other)
        {
            if (this != &other)
            {
                if (n != other.n)
                {
                    n = other.n;
                    delete[] workshops;
                    workshops = new Workshop[n];
                }
                for (int i = 0; i < n; ++i)
                {
                    workshops[i] = other.workshops[i];
                }
            }
            return *this;
        }
        Available_Workshops &operator= (Available_Workshops &&other) = default;

        int n {};
        Workshop *workshops {nullptr};
    };

    Available_Workshops *initialize(int start_time[], int duration[], int n)
    {
        if (n < 1 || n > 100000) throw std::invalid_argument("Invalid workshop count");

        Available_Workshops *result = new Available_Workshops(n);
        for (int i = 0; i < n; ++i)
        {
            if (start_time[i] < 0 || start_time[i] > 1000)
            {
                throw std::invalid_argument("Invalid start time");
            }
            if (duration[i] < 0 || duration[i] > 1000)
            {
                throw std::invalid_argument("Invalid duration");
            }

            result -> workshops[i].start_time = start_time[i];
            result -> workshops[i].duration = duration[i];
            result -> workshops[i].finish_time = start_time[i] + duration[i];
        }
        return result;
    }

#ifdef MY_INIT
int CalculateMaxWorkshops(Available_Workshops *const ptr)
{
    if (!ptr)
    {
        throw std::invalid_argument("Null Available_Workshops");
    }
    std::sort(ptr -> workshops, ptr -> workshops + ptr -> n);
    int currFinish {ptr -> workshops[0].finish_time};
    int count {1};

    for (int i = 1; i < ptr -> n; ++i)
    {
        if (ptr -> workshops[i].start_time < currFinish)    // overlaps
        {
            if (ptr -> workshops[i].finish_time < currFinish)   // take the shortest
            {
                currFinish = ptr -> workshops[i].finish_time;
            }
        }
        else
        {
            ++count;
            currFinish = ptr -> workshops[i].finish_time;
        }
    }
    return count;
}
#else   // MY_INIT

// Single-Interval Scheduling Maximization
int CalculateMaxWorkshops(Available_Workshops *const ptr)
{
    if (!ptr)
    {
        throw std::invalid_argument("Null Available_Workshops");
    }
    int count {0};
    int n = ptr -> n;
    while (n)
    {
        // min heap by finish_time
        std::make_heap(ptr -> workshops, ptr -> workshops + n, std::greater<>());
        const int currWorkshopFT = ptr -> workshops[0].finish_time;
        ++count;
        //std::pop_heap(ptr -> workshops, ptr -> workshops + n, std::greater<>());
        std::exchange(ptr -> workshops[0], ptr -> workshops[n - 1]);
        --n;
        if (!n) break;
        // find and remove intersecting
        // min heap by start_time
        std::make_heap(ptr -> workshops, ptr -> workshops + n, greaterST);
        bool found {true};
        while (n && found)
        {
            if (ptr -> workshops[0].start_time < currWorkshopFT)
            {
                std::pop_heap(ptr -> workshops, ptr -> workshops + n, greaterST);
                --n;
            }
            else found = false;
        }
    }
    return count;
}

#endif  // MY_INIT

int main(int, char**) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

/*
    for (int i = 0; i < ptr -> n; ++i)
    {
        std::cout << "(" << ptr -> workshops[i].start_time << ", " << ptr -> workshops[i].finish_time << ") ";
    }
    std::cout << std::endl;
*/
