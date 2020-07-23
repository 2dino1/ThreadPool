A small implementation of a thread pool that simulates the execution of an async queue. 

You can:
1. Schedules task for execution.
2. Wait for all tasks.
3. Queue up for tasks for execution after a specific batch has finished.
3. Awake the thread pool(created threads) if more tasks are scheduled.
4. Exit the thread pool to clean the memory afterwards. 
