# <b>File Manipulation</b>

This folder contains two tasks which are about file manipulation using system calls. The details of the tasks are as follows:

## <b>File-Manipulation-Using_Fputs_Fgets_Calls</b>

In this task, contents of one file are copied into the other file. System calls Fputs and Fgets are used
to perform this task. Name of both the .txt files are taken from the user as input.

### <b>Functions</b>

#### <b>fgets()</b>

```
int fgets(const char *str size,int n, file *stream)
• str − This is the pointer to an array of chars where the string read is stored.
• n − This is the maximum number of characters to be read (including the final
null-character). Usually, the length of the array passed as str is used.
• stream − This is the pointer to a FILE object that identifies the stream where
characters are read from.
```

#### <b>fputs()</b>

```
int fputs(const char *str, FILE *stream)
• str − This is the pointer to an array of chars where the string read is stored.
• stream − This is the pointer to a FILE object that identifies the stream
where characters are write in.
```

## <b>File-Manipulatio-Using_read_write_calls</b>

This file includes a program that reads data from file given by user as input and outputs data on console. Read and Write system calls are used in this task.

### Functions

#### <b>Read()</b>

```
Size_t read (int fd, void*buf, size_t cnt)
• fd: file descripter
• buf: buffer to read data from
• cnt: length of buffer
```

#### <b>Write()</b>

```
Size_t write(int fd, void *buf, size_t cnt);
• Parametersfd: file descripter
• buf: buffer to write data to
• cnt: length of buffer
```

## Run

Use following commands to run it on linux based operating system,

To create executable file, execute following command.

```
    make ./fileName
```

To run exe file, execute following command

```
    ./fileName
```

## Programming Language

- C
