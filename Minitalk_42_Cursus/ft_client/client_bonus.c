#include "../Minitalk.h"

// SIGUSR1 = 0
// SIGUSR2 = 1

void Signal_Sender(pid_t Target_Process_id, char Charecter_To_Be_Sent)
{
    
    int Bits_Sended;

   
    Bits_Sended = 7;
    while (Bits_Sended >= 0)
    {
		
        if (((Charecter_To_Be_Sent >> Bits_Sended) & 1))
		{
			if (kill(Target_Process_id, SIGUSR2) == -1)
				exit (1);
		} 
        else
		{
			if (kill(Target_Process_id, SIGUSR1) == -1)
				exit (1);
		}
        Bits_Sended--;
        usleep(400);
    }
}

void Incoming_Signal_Handler(int signum)
{
    (void)signum;
    ft_putstr_fd("Bravo 6 Going Dark !", 1);
}

int main(int argc, char *argv[])
{
    pid_t   Target_Process_Id;
    char    *message;
    int     Compteur;

	if (argc != 3)
	{
		ft_putstr_fd("Please Make Sure That You have Pass the Target PID and Your Message !", 1);
		return (1);
	}

    Compteur = 0;
    Target_Process_Id = ft_atoi(argv[1]);
    message = argv[2];
    signal(SIGUSR2, &Incoming_Signal_Handler);
    while (message[Compteur])
    {
        Signal_Sender(Target_Process_Id, message[Compteur]);
        Compteur++;
    }
    Signal_Sender(Target_Process_Id, '\0');
    usleep(150);
    return (0);
}


