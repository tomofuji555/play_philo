#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static const int num_philosophers = 5;
static const int num_meals = 3;

struct threadinfo
{
    int id;
    pthread_mutex_t *left;
    pthread_mutex_t *right;
};

/* ... */

static void think(int id)
{
    printf("%d is thinking\n", id);
    usleep(get_think_time());
}

static void eat(int id, pthread_mutex_t *left, pthread_mutex_t *right)
{
    pthread_mutex_lock(left);
    pthread_mutex_lock(right);
    printf("%d is eating\n", id);
    usleep(get_eat_time());
    pthread_mutex_unlock(left);
    pthread_mutex_unlock(right);
}

static void *philosopher(void *arg)
{
    struct threadinfo *tip = arg;

    for (int i = 0; i < num_meals; i++)
    {
        think(tip->id);
        eat(tip->id, tip->left, tip->right);
    }
    return NULL;
}

int main(void)
{
    pthread_mutex_t forks[num_philosophers];
    pthread_t philosophers[num_philosophers];
    struct threadinfo ti[num_philosophers];

    for (int i = 0; i < num_philosophers; i++)
    {
        pthread_mutex_init(&forks[i], NULL);
        ti[i].id = i;
        ti[i].left = &forks[i];
        ti[i].right = &forks[(i + 1) % num_philosophers];
        pthread_create(&philosophers[i], NULL, philosopher, (void *)&ti[i]);
    }
    for (int j = 0; j < num_philosophers; j++)
        pthread_join(philosophers[j], NULL);
    return 0;
}
