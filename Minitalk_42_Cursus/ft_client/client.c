#include "../Minitalk.h"
// SIGUSR1 = 0
// SIGUSR2 = 1
void Signal_Sender(pid_t Target_Process_id, char Character_To_Be_Sent)
{
    int Bits_Sent = 7;

    while (Bits_Sent >= 0)
    {
        if (((Character_To_Be_Sent >> Bits_Sent) & 1))
        {
            if (kill(Target_Process_id, SIGUSR2) == -1)
            {
                perror("Error sending signal");
                exit(1);
            }
        }
        else
        {
            if (kill(Target_Process_id, SIGUSR1) == -1)
            {
                perror("Error sending signal");
                exit(1);
            }
        }
        Bits_Sent--;
        usleep(400);
    }
}

int main(int argc, char *argv[])
{
    pid_t Target_Process_Id;
    char *message;
    int Counter = 0;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <Target_PID> <Message>\n", argv[0]);
        return 1;
    }

    Target_Process_Id = ft_atoi(argv[1]);
    message = argv[2];

    while (message[Counter])
    {
        Signal_Sender(Target_Process_Id, message[Counter]);
        Counter++;
    }

    usleep(150);
    return 0;
}

