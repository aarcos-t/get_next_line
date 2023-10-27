#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line_utils.c"

char *get_next_line(int fd)
{
    size_t      i;
    char        *line;
    static char *reminder;
    static char *buffer[BUFFER_SIZE + 1]

    reminder = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    i = read(fd, buffer, BUFFER_SIZE);
    while (i > 0)
    {
        buffer[i] = '\0';
        reminder = ft_strjoin(reminder, buffer);
        line = read_line(&reminder);
        if (line)
            return (line);
        i = read(fd, buffer, BUFFER_SIZE);
    }
    if (reminder)
    {
        line = ft_strdup(reminder);
        free (reminder);
        reminder = NULL;
    }
    return (line);
}

char *read_line(**reminder)
{
    size_t i;
    char *str;
    char *new_line;

    i = 0;
    new_line = ft_strchr(*reminder, '\n');
    if (new_line)
    {
        str = malloc(sizeof(char) * (new_line - *reminder + 2));
        if (!str)
            return (NULL);
        while (new_line[i] != '\0')
        {   str[i] = new_line[i];
            i++;
        }
        str[i] = '\n';
        str[i + 1] = 0;
        return (str);
    }
    else
    return (NULL);
}

int main ()
{
    char x[554334];

    fd = "archivo.txt";
    x = get_next_line(fd);
    printf(%s, x);
}