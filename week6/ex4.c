#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void pressed_sig_usr_1()
{
    printf("SIGUSR1 has pressed\n");
}

void pressed_sig_stop()
{
    printf("SIGSTOP has pressed\n");
}

// Kill show nothing, so it means that this is unhandalable
void pressed_sig_kill()
{
    printf("SIGKILL has pressed\n");
}

void pressed_ctrl_c()
{
    printf("SIGINT has pressed\n");
}

void main()
{
    signal(SIGINT, pressed_ctrl_c);
    signal(SIGKILL, pressed_sig_kill);
    signal(SIGSTOP, pressed_sig_stop);
    signal(SIGUSR1, pressed_sig_usr_1);
    while(1)
    {
        sleep(1);
    }
}
