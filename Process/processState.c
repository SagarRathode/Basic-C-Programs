#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define process states using an enum

typedef enum 
{
    NEW,        // Process is created
    READY,      // Process is ready to run
    RUNNING,    // Process is running
    BLOCKED,    // Process is blocked, waiting for an event
    TERMINATED  // Process has finished execution
} ProcessState;

// Define a struct to represent a process

typedef struct 
{
    int pid;              // Process ID
    ProcessState state;   // Current state of the process
} Process;

// Function to print the current state of the process

const char* state_to_string(ProcessState state)
{
    	switch (state) 
	{
        case NEW: return "New";
        case READY: return "Ready";
        case RUNNING: return "Running";
        case BLOCKED: return "Blocked";
        case TERMINATED: return "Terminated";
        default: return "Unknown";
    	}
}

// Function to simulate process state transition

void process_transition(Process *p, ProcessState new_state)
{
    printf("Process %d: %s -> %s\n", p->pid, state_to_string(p->state), state_to_string(new_state));
    p->state = new_state;
    sleep(3);
}

// Simulating a process lifecycle with state transitions

void simulate_process_lifecycle(Process *p) 
{
    // New state -> Ready state
    process_transition(p, READY);

    // Ready state -> Running state
    process_transition(p, RUNNING);
    
    // Simulate process being blocked (e.g., waiting for I/O)
    process_transition(p, BLOCKED);

    // Blocked state -> Ready state (event occurs, unblocking process)
    process_transition(p, READY);

    // Ready state -> Running state again
    process_transition(p, RUNNING);
    
    // Finally, process terminates
    process_transition(p, TERMINATED);
}

int main() 
{
    // Create a new process
    Process p1 = {1, NEW};  // Initial state is NEW

    // Print the initial state
    printf("Process %d initial state: %s\n", p1.pid, state_to_string(p1.state));

    // Simulate the process lifecycle
    simulate_process_lifecycle(&p1);

    return 0;
}

