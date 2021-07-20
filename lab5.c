#include <stdio.h>
#include <elevator.h>

enum elevatorState { ElevatorState_DoorsFullyClosed, ElevatorState_DoorsAreOpening, ElevatorState_DoorsFullyOpen, ElevatorState_DoorsAreClosing, ElevatorState_MovingBetweenFloors };
typedef enum elevatorstate ElevatorState;
int main(int argc, char* argv[])
{
    int     event;
    int i = 0;
    ElevatorState  state = ElevatorState_DoorsFullyClosed;

    // Begin the main loop. This loops forever; it has no terminating condition.
    for (;;)
    {
        // Get any pending event, if one exists
        event = elevatorGetEvent();




        // See what we got
        switch (event)
        {
        case 0:// Nothing has happened


        // There is no pending event. We have nothing to do.
            break;

        case 1:        // UP button was pressed
            // The "UP" (Floor 2) button has been pressed. Begin moving up.
            if (state != ElevatorState_DoorsAreOpening && state != ElevatorState_DoorsFullyOpen && state != ElevatorState_DoorsAreClosing && state != ElevatorState_MovingBetweenFloors)
            {
                elevatorUp();
                state = ElevatorState_MovingBetweenFloors;
            }
            break;

        case 2:        // DOWN button was pressed
            // The "DOWN" (Floor 1) button has been pressed. Begin moving down.
            if (state != ElevatorState_DoorsAreOpening && state != ElevatorState_DoorsFullyOpen && state != ElevatorState_DoorsAreClosing && state != ElevatorState_MovingBetweenFloors)
            {
                elevatorDown();
                state = ElevatorState_MovingBetweenFloors;
            }
            break;

        case 3:        // OPEN button was pressed
            // The "OPEN" button has been pressed. Open the doors.

            if (state != ElevatorState_MovingBetweenFloors)
            {
                elevatorOpenDoors();
                state = ElevatorState_DoorsAreOpening;

            }

            break;

        case 4:        // CLOSE button was pressed
            // The "CLOSE" button has been pressed. Close the doors.
            if (state != ElevatorState_MovingBetweenFloors)
                elevatorCloseDoors();
            state = ElevatorState_DoorsAreClosing;

            break;

        case 5:        // Elevator reached the second floor
            printf("The elevator is at floor 2\n");
            elevatorOpenDoors();
            state = 0;
            break;

        case 6:        // Elevator reached the first floor
            printf("The elevator is at floor 1\n");
            elevatorOpenDoors();
            state = 0;
            break;

        case 7:        // Elevator doors are now at the fully open position
            printf("The elevator doors are fully open\n");
            state = ElevatorState_DoorsFullyOpen;
            break;

        case 8:        // Elevator doors are now at the fully closed position
            printf("The elevator doors are fully closed\n");
            state = ElevatorState_DoorsFullyClosed;

            break;



        case 100:      // Timer: one second has elapsed since last Timer event
            printf("Tick\n");
            if (state == ElevatorState_DoorsFullyOpen)
            {
                i++;
                if (i == 3)
                {
                    elevatorCloseDoors();
                    i = 0;
                }
            }

            break;
        }
    }

    // The loop above never ends. We never get here.
    return 0;
}
