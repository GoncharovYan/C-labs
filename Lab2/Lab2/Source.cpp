#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <windows.h>
#include <thread>
#include <mutex>

using namespace std;

#define CRT_SECURE_NO_WARNINGS
#define N 60

mutex mtx;

int graphic[N][N];

void Print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graphic[i][j] == 0)
                printf(" ");
            if (graphic[i][j] == 1)
                printf("x");
            if (graphic[i][j] == 2)
                printf(".");
            printf(" ");
        }
        printf("\n");
    }
}
class Planet
{
private:
    double r;
    double m;
    int x, y;//координаты центра
    int x_graph, y_graph;
public:
    Planet(double r, int x, int y, double m) {
        this->r = r; this->x = x; this->y = y; this->m = m;
    }

    void drow_planet() {
        for (double t = 0; t <= 2 * acos(-1); t += 0.1) {
            x_graph = (static_cast<int>((r)*cos(t)) + 0.5) + x;
            y_graph = (static_cast<int>((r)*sin(t)) + 0.5) + y;
            if (x_graph >= 0 && x_graph < N && y_graph >= 0 && y_graph < N)
                graphic[x_graph][y_graph] = 1;
        }
    }
    void drow_moving_planet(int long_of_planets, Planet sun) {
        for (double t = 0; t <= 2 * acos(-1); t += 0.1) {
            x = (static_cast<int>((long_of_planets)*cos(t)) + 0.5) + sun.get_x();
            y = (static_cast<int>((long_of_planets)*sin(t)) + 0.5) + sun.get_y();
            if (x >= 0 && x < N && y >= 0 && y < N) {
                for (double t = 0; t <= 2 * acos(-1); t += 0.1) {
                    x_graph = (static_cast<int>((r)*cos(t)) + 0.5) + x;
                    y_graph = (static_cast<int>((r)*sin(t)) + 0.5) + y;
                    if (x_graph >= 0 && x_graph < N && y_graph >= 0 && y_graph < N)
                        graphic[x_graph][y_graph] = 2;
                }
            }
            mtx.lock();
            Print();
            mtx.unlock();
            this_thread::sleep_for(chrono::milliseconds(200));
            if (x >= 0 && x < N && y >= 0 && y < N) {
                for (double t = 0; t <= 2 * acos(-1); t += 0.1) {
                    x_graph = (static_cast<int>((r)*cos(t)) + 0.5) + x;
                    y_graph = (static_cast<int>((r)*sin(t)) + 0.5) + y;
                    if (x_graph >= 0 && x_graph < N && y_graph >= 0 && y_graph < N)
                        graphic[x_graph][y_graph] = 0;
                }
            }
            //Sleep(1000);
            system("cls");
        }
    }
    void set_r(double r)
    {
        this->r = r;
    }
    void set_m(double m)
    {
        this->m = m;
    }
    void set_xy(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
    }
    double get_r()
    {
        return r;
    }
    double get_m()
    {
        return m;
    }
};

int main()
{

    Planet sun(8, 25, 25, 10000);
    Planet sputnik(5, 10, 10, 10);
    Planet sputnic2(3, 10, 10, 10);
    sun.drow_planet();
    thread t(&Planet::drow_moving_planet, sputnik, 30, sun);
    thread t2(&Planet::drow_moving_planet, sputnic2, 20, sun);
    t.join();
    t2.join();
}