#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

char *system_make(char *path)
{
	char cc[4] = "cc ";
	char args[9] = " -o run";
	char res[1024];

	strcat(res, cc);
	strcat(res, path);
	strcat(res, args);
	printf("%s\n", res);
	return (strdup(res));
}

char* strjoin(const char* str1, const char* str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t totalLen = len1 + len2 + 1;

    char* result = malloc(totalLen * sizeof(char));
    if (!result)
        return NULL;
    strcpy(result, str1);
    strcat(result, str2);
    return (result);
}

int	main(void)
{
	int	fd_edit;
	// int	fd_script;
	char code1[1024] = "\nprecmd () {\n\tawk 'BEGIN {printf \"FUCK YOU\\n\"}';\n}\n\n";
	// char *temp = "#include <stdio.h>\n\nint\tmain(void) {\n\tprintf(\"FUCK YOU\\n\");\n\treturn (0);\n}\n";
	char *path;
	char buf[1024];

	if (getcwd(buf, sizeof(buf)) == NULL)
		return (-1);
	path = strjoin(getenv("HOME"), "/.zshrc");
	fd_edit = open(path, O_RDWR | O_CREAT | O_APPEND, 0777);
	write(fd_edit, code1, strlen(code1));
	// write(fd_edit, buf, strlen(buf));
	free (path);
	path = NULL;
	// path = strjoin(getenv("HOME"), "/new.c");
	// fd_script = open(path, O_RDWR | O_CREAT | O_TRUNC, 0777);
	// write(fd_script, temp, strlen(temp));
	// system(system_make(path));
	// unlink(path);
	// printf("%s\n", buf);
	// printf("%d\n", fd_edit);
}