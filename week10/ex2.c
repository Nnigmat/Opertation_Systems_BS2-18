#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

int main()
{
    DIR *tmp = opendir("/home/ngm/Code/University/Os/week10/tmp");
    if (tmp == NULL)
    {
        printf("error");
        return -1;
    }

    struct dirent *dp;
    struct array {
        int len;
        struct node {
            __ino_t ino;
            int count;
            char file_names[100][100];
        } i_nodes[100];
    } array;

    array.len = 0;

    while ((dp = readdir(tmp)) != NULL)
    {
        for (int i = 0; i <= array.len; i++)
        {
            if (dp->d_ino == array.i_nodes[i].ino)
            {
                strcpy(array.i_nodes[i].file_names[array.i_nodes[i].count], dp->d_name);
                array.i_nodes[i].count++;
                break;
            }
            else
            {
                array.i_nodes[array.len].ino = dp->d_ino;
                strcpy(array.i_nodes[i].file_names[0], dp->d_name);
                array.i_nodes[array.len].count = 1;
                array.len++;
                break;
            }
        }
    }

    closedir(tmp);

    for (int i = 0; i < array.len; i++)
    {
        if (array.i_nodes[i].count > 1)
        {
            printf("%lu - files: ", array.i_nodes[i].ino);
            for (int j = 0; j < array.i_nodes[i].count; j++)
                printf("%s ", array.i_nodes[i].file_names[j]);
            printf("\n");
        }
    }
}
