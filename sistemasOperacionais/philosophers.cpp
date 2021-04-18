void think();
void take_fork(int i);
void put_fork(int i);
void eat();
void down(int i);
void up(int i);

#define N 5
int mutex = 1;
int hashi[5] = {1, 1, 1, 1, 1};
void philosopher(int i)
{
    while (true)
    {
        down(mutex);
        think();
        down(hashi[i]);
        take_fork(i);
        down(hashi[(i + 1) % N]);
        take_fork((i + 1) % N);
        up(mutex);
        eat();
        down(mutex);
        put_fork(hashi[i]);
        up(hashi[i]);
        put_fork((i + 1) % N);
        up(hashi[(i + 1) % N]);
        up(mutex);
    }
}