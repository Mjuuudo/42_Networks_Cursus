/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:15:21 by abait-ou          #+#    #+#             */
/*   Updated: 2024/03/13 11:19:04 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SIGUSR2 = 1
// SIGUSR1 = 0
#include "../Minitalk.h"
void Signal_Sender(pid_t target_process_id, char character_to_be_sent)
{
    int bits_sent = 7;

    while (Bits_Sent >= 0)
    {
        if (((character_to_be_sent >> bits_sent) & 1))
        {
            if (kill(target_process_id, SIGUSR2) == -1)
            {
                exit(1);
            }
        }
        else
        {
            if (kill(target_process_id, SIGUSR1) == -1)
            {
                exit(1);
            }
        }
        bits_sent--;
        usleep(400);
    }
}

int main(int argc, char *argv[])
{
    pid_t target_process_id;
    char *message;
    int counter = 0;

    if (argc != 3)
    {
        printf(stderr, "Usage: %s <Target_PID> <Message>\n", argv[0]);
        return 1;
    }

    target_process_id = ft_atoi(argv[1]);
    message = argv[2];

    while (message[counter])
    {
        Signal_Sender(target_process_id, message[counter]);
        counter++;
    }

    usleep(150);
    return 0;
}

