#include "my.h"
#include "task.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        system("PAUSE");
        return 1;
    }
    while (1)
    {
        printf("Menu:\nTask 1 - 3:\nRead file 4\nEnd my mega super puper respect project - 0: ");
        int task = check_int(0, 4);
        int amount;
        switch (task)
        {
            case 1:
                write_num_to_file(argv[1], &amount);
                break;
            case 2:
                how_many_num(argv[1]);
                break;
            case 3:
                shift_num_in_file(argv[1], amount);
                break;
            case 4:
                read_file(argv[1]);
                break;
            case 0:
                return 0;
            default:
                puts("Error");
        }
    }
}
