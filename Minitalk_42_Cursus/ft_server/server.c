#include "../Minitalk.h"
// SIGUSR1 = 0
// SIGUSR2 = 1
void Signal_handler(int signum)
{
    static int Bits_recieved = 0;
    static char Charachter_recieved = 0;

    Charachter_recieved = (Charachter_recieved << 1) | (signum == SIGUSR2);
    Bits_recieved++;
    if (Bits_recieved == 8)
    {
        ft_putstr_fd(&Charachter_recieved, 1);
        Bits_recieved = 0;
        Charachter_recieved = 0;
    }
}
int main(int argc, char **argv)
{
    struct sigaction  sig;
    pid_t Process_Id;

    Process_Id = getpid();
    ft_putstr_fd("Hello ! The Process Id For THis Program Is : ", 1);
    ft_putnbr_fd(Process_Id, 1);
    ft_putchar_fd('\n',1);
	
    sig.sa_handler = Signal_handler;
	sigemptyset(&sig.sa_mask);
    // sig.sa_flags(0);
    if (sigaction(SIGUSR1, &sig, NULL))
        return (1);
    if (sigaction(SIGUSR2, &sig, NULL))
        return (1);
    while (1)
    {
        ;
    }
    return (0);

}
