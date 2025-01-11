#include <fcntl.h>  // For open()
#include <stdio.h>  // For printf()
#include "libft.h"

int main(void)
{
    // Open a file for reading
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    // Read and print each line using get_next_line
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s", line); // Print the line
        free(line);              // Free the line after printing
    }

    // Close the file
    close(fd);
    return 0;
}