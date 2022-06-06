/*
** EPITECH PROJECT, 2021
** lib my
** File description:
** my char in list
*/

int my_char_in_list(char character, char *list)
{
    for (int i = 0; list[i]; i++) {
        if (character == list[i])
            return i;
    }
    return (-1);
}
