//od  Created by Sima Vlad Grigore on 12/07/2020.
//  Copyright © 2020 Sima Vlad Grigore. All rights reserved.
//

#include <stdio.h>
#include "thread_pool/thread_pool.h"

static void execute_task(void *argument, PoolNotifier notifier, void(*completion)(PoolNotifier));

int main()
{
    int tt5 = 5;
    Task *t5 = init_task(NULL, &tt5, execute_task);
    int tt4 = 4;
    Task *t4 = init_task(t5, &tt4, execute_task);
    int tt3 = 3;
    Task *t3 = init_task(t4, &tt3, execute_task);
    int tt2 = 2;
    Task *t2 = init_task(t3, &tt2, execute_task);
    int tt1 = 1;
    Task *t1 = init_task(t2, &tt1, execute_task);
    int tt0 = 0;
    Task *t0 = init_task(t1, &tt0, execute_task);
    
    ThreadPool *pool = init_thread_pool(3, t0, 6);
    wait_all_threads(pool);
    
    printf("Finished first batch \n");
    
    int tt11 = 11;
    Task *t11 = init_task(NULL, &tt11, execute_task);
    int tt10 = 10;
    Task *t10 = init_task(t11, &tt10, execute_task);
    int tt9 = 9;
    Task *t9 = init_task(t10, &tt9, execute_task);
    int tt8 = 8;
    Task *t8 = init_task(t9, &tt8, execute_task);
    int tt7 = 7;
    Task *t7 = init_task(t8, &tt7, execute_task);
    int tt6 = 6;
    Task *t6 = init_task(t7, &tt6, execute_task);
    
    update_thread_pool_tasks(pool, t6, 6);
    awake_threads(pool);
    wait_all_threads(pool);
    release_thread_pool(pool);
    
    printf("Finished second batch \n");
    
    return 0;
}

static void execute_task(void *argument, PoolNotifier notifier, void(*completion)(PoolNotifier))
{
    printf("Executed task with argument id %d \n", *((int*)argument));
    completion(notifier);
}
