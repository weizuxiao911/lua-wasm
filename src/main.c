#include <stdio.h>
#include <emscripten.h>
#include <string.h>

typedef void (*PrintFunc)(const char *);

void process_input(const char *input, PrintFunc print_func)
{
    if (strcmp(input, "exit\n") == 0)
    {
        exit(EXIT_SUCCESS);
    }
    if (strncmp(input, "echo ", 5) == 0)
    {
        print_func(input + 5);
    }
    else
    {
        print_func("Unknown command: ");
        print_func(input);
    }
}

void print(const char *msg)
{
    EM_ASM({ Module.print($0); }, msg);
}

int main()
{
    // 初始化文件系统
    EM_ASM({
        FS.mkdir('/data');
    });

    // 写入文件
    EM_ASM({
        FS.writeFile('/data/file.txt', 'foobar');
        console.log('file stat =>', FS.stat('/data/file.txt'));
        console.log('file read =>', FS.readFile('/data/file.txt', {encoding : 'utf8'}));
    });

    return EXIT_SUCCESS;
}
