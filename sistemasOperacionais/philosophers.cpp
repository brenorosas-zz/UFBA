void think();
void take_fork(int i);
void put_fork(int i);
void eat();
void down(int i);
void up(int i);

#define N 5
int mutex = 1;
void philosopher(int i)
{
    while (true)
    {
        think();
        down(mutex);
        take_fork(i);
        take_fork((i + 1) % N);
        eat();
        put_fork(i);
        put_fork((i + 1) % N);
        up(mutex);
    }
}